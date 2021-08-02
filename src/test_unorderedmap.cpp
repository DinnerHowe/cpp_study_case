#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>
#include <chrono>
#include <unordered_map>

int main(int argc, char **argv)
{
  std::unordered_map<int, int> data;
  data[1] = 0;
  data[2] = 1;
  data[4] = 0;
  data[5] = 1;
  data[6] = 1;
  data[7] = 0;
  data[8] = 1;
  data[9] = 1;
  for (auto it = data.begin(); it != data.end(); ++it)
  {
    std::cout << it->second << ", ";
  }
  std::cout << "end" << std::endl;

  for (auto it = data.begin(); it != data.end();)
  {
    if (it->second != 2)
    {
      it = data.erase(it);
    }
    else
    {
      it++;
    }
  }
  for (auto it = data.begin(); it != data.end(); ++it)
  {
    std::cout << it->second << ", ";
  }
  std::cout << "end" << std::endl;
  return 0;
}
