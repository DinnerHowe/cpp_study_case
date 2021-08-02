

#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>

int main(int argc, char **argv)
{

    std::cout << std::hypot(1, 1) << std::endl;
    std::cout << std::hypot(-1, 1) << std::endl;
    std::cout << std::hypot(1, -1) << std::endl;
    std::cout << std::hypot(-1, -1) << std::endl;
    std::cout << std::hypot(0, -1) << std::endl;
    std::cout << std::hypot(-1, 0) << std::endl;
    std::cout << std::hypot(0, 0) << std::endl;

    std::vector<int> visited_node_;
    visited_node_.reserve(100000);
    visited_node_.clear();
    std::cout << "visited_node_ capacity: " << visited_node_.capacity() << std::endl;
}