
#pragma once
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
 public:
  explicit ThreadPool(const size_t& threads_num);
  ~ThreadPool();

  template<class F, class... Args> //任务入队
  auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

 private:
  std::vector< std::thread > workers_;            //线程队列，每个元素为一个Thread对象
  std::queue< std::function<void()> > tasks_;     //任务队列，每个元素为一个函数对象

  std::mutex queue_mutex_;                        //互斥量
  std::condition_variable condition_;             //条件变量
  bool stop_;                                     //停止
};

// 构造函数，把线程插入线程队列，插入时调用embrace_back()，用匿名函数lambda初始化Thread对象
inline ThreadPool::ThreadPool(const size_t& threads_num) : stop_(false) {
  for(size_t i = 0; i < threads_num; ++i) {
    workers_.reserve(workers_.size() + 1);
    workers_.emplace_back( [this] {
      for(;;) {
        // task是一个函数类型，从任务队列接收任务
        std::function<void()> task;
        {
          //给互斥量加锁，锁对象生命周期结束后自动解锁
          std::unique_lock<std::mutex> lock(this->queue_mutex_);

          //（1）当匿名函数返回false时才阻塞线程，阻塞时自动释放锁。
          //（2）当匿名函数返回true且受到通知时解阻塞，然后加锁。
          this->condition_.wait(lock,[this]{
            return this->stop_ ||!this->tasks_.empty();
          });
          if(this->stop_ && this->tasks_.empty()) {return;}
          //从任务队列取出一个任务
          task = std::move(this->tasks_.front());
          this->tasks_.pop();
        }                            // 自动解锁
        task();                      // 执行这个任务
      }
    });
  }
}

// 添加新的任务到任务队列
template<class F, class... Args>
inline auto ThreadPool::enqueue(F&& f, Args&&... args)
    -> std::future<typename std::result_of<F(Args...)>::type> {
  // 获取函数返回值类型
  using return_type = typename std::result_of<F(Args...)>::type;

  // 创建一个指向任务的只能指针
  auto task = std::make_shared< std::packaged_task<return_type()> >(
          std::bind(std::forward<F>(f), std::forward<Args>(args)...));

  std::future<return_type> res = task->get_future();
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);  //加锁
    if(stop_) {
      throw std::runtime_error("enqueue on stopped ThreadPool");
    }
    tasks_.emplace([task](){ (*task)(); });          //把任务加入队列
  }                                                   //自动解锁
  condition_.notify_one();                             //通知条件变量，唤醒一个线程
  return res;
}

// 析构函数，删除所有线程
inline ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop_ = true;
  }
  condition_.notify_all();
  for(std::thread &worker: workers_) {
    worker.join();
  }
}