#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <time.h>

using namespace std;


int main(int argc, char **argv)
{
    // std::vector<int> a;
    // a.emplace_back(1);
    // a.emplace_back(2);
    // a.emplace_back(3);
    // a.emplace_back(4);

	//*****************reverse
    // for (auto i : a){
    //     std::cout<< i << std::endl;
    // }
    // // a.reserve(a.size());
    // std::reverse(a.begin(), a.end());
    // std::cout<< "\n" << std::endl;

    std::vector<int> b;
    b.emplace_back(5);
    b.emplace_back(6);
    b.emplace_back(7);
    b.emplace_back(8);
    
	//*****************insert
    std::vector<int> c;
    c.insert(c.end(), b.begin(), b.end());
    // c.insert(c.end(), a.begin(), a.end());
    // a=c;
    b.clear();
    for (auto i : c){
        std::cout<< i << std::endl;
    }
    for (auto i : b){
        std::cout << "rt" << i << std::endl;
    }

	//******************iterator
    // std::cout<< "\niterator" << std::endl;
    // for(vector<int>::iterator iter = a.begin(); iter != a.end(); iter++) 
	// {
    //     std::cout<< "a: " << *iter << std::endl;
	// } 

    // std::cout<< "\n" << std::endl;
    // for(vector<int>::reverse_iterator iter = a.rbegin(); iter != a.rend(); iter++) 
	// {
    //     std::cout<< "a reverse: "<< *iter << std::endl;
	// } 

	//******************判断末尾同元素个数
    // std::vector<int> d;
    // d.emplace_back(0);
    // d.emplace_back(0);
    // d.emplace_back(0);
    // d.emplace_back(0);
    // d.emplace_back(-1);
    // d.emplace_back(1);
    // d.emplace_back(1);
    // d.emplace_back(1);
    // d.emplace_back(1);
    // d.emplace_back(0);
    // d.emplace_back(1);
    // d.emplace_back(1);
    // d.emplace_back(1);
    // std::cout<< "\n" << std::endl;
	// int count = 1;
	// std::map<int, int> max_item;
	// max_item.clear();
	// vector<int>::reverse_iterator iter_pre = d.rbegin();
    // for(vector<int>::reverse_iterator iter = d.rbegin()+1; iter != d.rend(); iter++) 
	// {
    // 	std::cout<< "compare: "<< *iter <<" and " << *iter_pre << std::endl;
    //     if (*iter == *iter_pre)
	// 	{
	// 		count++;
	// 	}
	// 	else
	// 	{
	// 		if (max_item.count(count) != 0)
	// 		{
	// 			//max_item[count] = *iter_pre;
	// 			count = 1;
	// 		}
	// 		else
	// 		{
	// 			max_item[count] = *iter_pre;
	// 			count = 1;
	// 		}

	// 	}
	// 	iter_pre++;
	// } 
	// auto itermap = max_item.end(); itermap --;
    // std::cout<< "there is "<< itermap->first <<" item is same at " << itermap->second << std::endl;
	// auto iterbmap = max_item.begin(); iterbmap;
    // std::cout<< "there is "<< iterbmap->first <<" item is same at " << iterbmap->second << std::endl;
	// for (auto i : max_item)
	// {
    // 	std::cout<< "1 there is "<< i.first <<" item is same at " << i.second << std::endl;
	// }

	//******************erease 
    // if (!a.empty())
    // {
    //     auto a_temp = a;
    //     if (a.size() > 4)
    //     {
    //         a_temp.erase(a_temp.begin());
    //     }
    //     a = a_temp;
    // }
	// for (auto i : a)
	// {
    // 	std::cout<< "a: "<< i<< std::endl;
	// }

    //******************首位插入另一个vector
	// for (auto i : a)
	// {
    // 	std::cout<< "a: "<< i<< std::endl;
	// }
    // std::cout << "\n" << std::endl;
	// for (auto i : b)
	// {
    // 	std::cout<< "b: "<< i<< std::endl;
	// }
    // std::cout << "\n" << std::endl;
    // a.insert(a.begin(), b.begin(), b.end());
	// for (auto i : a)
	// {
    // 	std::cout<< "a: "<< i<< std::endl;
	// }

    // std::vector<int> a(2);
	// for (auto i : a)
	// {
    // 	std::cout<< "oa: "<< i<< std::endl;
	// }
    // while(1){
    //     int iDown = 0;
    //     int iin = 0;
    //     std::cin >> iDown;
    //     if ((int)iDown == 0){iin = 0;}
    //     else{iin = 1;}
    //     a.emplace_back(iin);
    //     if (a.size()>2) {a.erase(a.begin());}
    //     for (auto i : a)
    //     {
    //         std::cout<< "a: "<< i<< std::endl;
    //     }
    //     std::cout << "" << std::endl;
    // }
    // using namespace std;
    // vector<int> L;
    // L.push_back( 1 );
    // L.push_back( 2 );
    // L.push_back( 3 );
    // L.push_back( 4 );
    // L.push_back( 5 );
    // vector<int>::iterator result = find( L.begin( ), L.end( ), 5 ); //查找3
    // if ( result == L.end( ) ) //没找到        
    // cout << "No" << endl;
    // else //找到        
    // cout << "Yes" << endl;
    // vector<int> map;
    // map.assign(L.begin(), L.end());
    // std::cout << map.back() << std::endl;
    // map.pop_back();
    // std::cout << map.back() << std::endl;
    // std::cout << "=============" << std::endl;

    // for (auto i : map) {
    //   std::cout << i << std::endl;
    // }

    // //******************首位插入另一个iterta vs i++
    // std::vector<int> b;
    // for (int i = 0; i < 1e7; i++) {
    //   b.emplace_back(i);
    // }
    // clock_t time_iter = clock();
    // for (std::vector<int>::iterator i = b.begin(); i != b.end(); ++i) {
    //   continue;
    // }
    // std::cout << "iterator cost time: " << (clock() - time_iter) * 1000.0 / CLOCKS_PER_SEC<< " ms\n";

    // clock_t time_plusplus = clock();
    // for (size_t i = 0; i < b.size(); ++i) {
    //   continue;
    // }
    // std::cout << "++i cost time: " << (clock() - time_plusplus) * 1000.0 / CLOCKS_PER_SEC<< " ms\n";

    // clock_t time_iter2 = clock();
    // for (std::vector<int>::iterator i = b.begin(); i != b.end(); i++) {
    //   continue;
    // }
    // std::cout << "iterator2 cost time: " << (clock() - time_iter2) * 1000.0 / CLOCKS_PER_SEC<< " ms\n";

    // clock_t time_iter3 = clock();
    // for (auto i = b.begin(); i != b.end(); i++) {
    //   continue;
    // }
    // std::cout << "iterator3 cost time: " << (clock() - time_iter3) * 1000.0 / CLOCKS_PER_SEC<< " ms\n";

    // clock_t time_plusplus2 = clock();
    // for (size_t i = 0; i < b.size(); i++) {
    //   continue;
    // }
    // std::cout << "++i2 cost time: " << (clock() - time_plusplus2) * 1000.0 / CLOCKS_PER_SEC<< " ms\n";

    // clock_t time_iter4 = clock();
    // auto i = b.begin();
    // while(i != b.end()) {i++; continue;}
    // std::cout << "iterator4 cost time: " << (clock() - time_iter4) * 1000.0 / CLOCKS_PER_SEC<< " ms\n";

    // reserve clear resize

    // std::vector<bool> test1;
    // test1.resize(10000, true);
    // for (size_t i = 0; i < test1.size(); i++) {
    //   std::cout << "\ntest1: " << test1.at(i);
    // }
    // std::cout << std::endl;
    // std::cout << test1.size() << " ," << test1.capacity() << std::endl;
    // std::cout << "\n clear" << std::endl;
    // test1.clear();
    // for (size_t i = 0; i < test1.size(); i++) {
    //   std::cout << "\n clear test1: " << test1.at(i);
    // }
    // std::cout << std::endl;
    // std::cout << test1.size() << " ," << test1.capacity() << std::endl;
    // test1.resize(5, true);
    // test1.shrink_to_fit();
    // std::cout << test1.size() << " ," << test1.capacity() << std::endl;
    return 0;
}
