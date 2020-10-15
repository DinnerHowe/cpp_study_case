#include "threadpool.h"
#include <iostream>


void ServerUnit(const int& num) {
  std::cout << "AF_INET: " << num << ", thread id: " << std::this_thread::get_id() << std::endl;
}

int main(int argc, char* argv[]) {
  ThreadPool pool(4);
  while (1) {
    pool.enqueue(ServerUnit, 1);
  }
  return 0;
}
