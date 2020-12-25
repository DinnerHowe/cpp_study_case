#include <iostream>
#include <thread>
#include <unistd.h>
#include <chrono>

void ThreadProc(const std::string &name, const int &timer, const int &num)
{
  std::cout << "子线程" << name << "开始"
            << " num: " << num << std::endl;
  if (num >= 0)
  {
    std::this_thread::sleep_for(std::chrono::seconds(timer));
  }
  std::cout << "子线程" << name << "结束"
            << " num: " << num << std::endl;
}

std::thread t1, t2;

int main()
{
  std::cout << "=========主线程开始=========" << std::endl;
  t1 = std::thread([] { ThreadProc("test 1", 1, -1); });
  t2 = std::thread([] { ThreadProc("test 2", 5, -1); });
  if (t1.joinable())
  {
    t1.detach();
  }
  if (t2.joinable())
  {
    t2.detach();
  }
  int i = 0;
  while (i < 2)
  {
    std::cout << "=========主线程loop start=========: " << i << std::endl;
    t1 = std::thread([i] { ThreadProc("test 1", 2, i); });
    t2 = std::thread([i] { ThreadProc("test 2", 5, i); });
    std::thread t3(ThreadProc, "test 3", 1, i);
    if (t1.joinable())
    {
      t1.detach();
    }
    if (t2.joinable())
    {
      t2.detach();
    }
    if (t3.joinable())
    {
      t3.detach();
    }
    ++i;
    std::cout << "=========主线程loop end=========: " << i << std::endl;
  }
  sleep(10);
  std::cout << "=========主线程结束=========" << std::endl;
  return 0;
}