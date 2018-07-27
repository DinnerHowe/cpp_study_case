#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(int argc, char **argv)
{
    std::vector<int> a;
    a.emplace_back(1);
    a.emplace_back(2);
    a.emplace_back(3);
    a.emplace_back(4);
    //for (auto i : a){
        //std::cout<< i << std::endl;
    //}
    //a.reserve(a.size());
    //reverse(a.begin(), a.end());
    //std::cout<< "\n" << std::endl;

    std::vector<int> b;
    b.emplace_back(5);
    b.emplace_back(6);
    b.emplace_back(7);
    b.emplace_back(8);
    
    std::vector<int> c;
    c.insert(c.end(), b.begin(), b.end());
    c.insert(c.end(), a.begin(), a.end());
    a=c;
    for (auto i : a){
        std::cout<< i << std::endl;
    }
   return 0;
}
