#include <iostream>
#include <unordered_map>
#include <math.h>
//TODO:
int main(int argc, char **argv)
{
	//定义一个map
	std::unordered_map<std::string, int> hash_map;
	hash_map.insert({"1", 8});
	hash_map.insert({"2", 12});
	hash_map.insert({"3", 53});
	hash_map.insert({"4", 33});
	hash_map.insert({"5", 11});
	hash_map.insert({"6", 2});
	hash_map.insert({"7", 3});

	auto iter = hash_map.begin();
	int min = INFINITY;
	std::string min_id;
	while (iter!=hash_map.end())
	{
		if (iter->second < min)
		{
			min = iter->second;
			min_id = iter->first;
		}
	++iter;
	}
	std::cout << "min is:   " << min_id << " : " << hash_map[min_id] << std::endl;

	std::unordered_map<int, int> test_map;
	test_map.insert({0,1});
	test_map.insert({1,2});
    test_map.clear();

	//std::cout << test_map[-1] << std::endl;
	//std::cout << test_map[2] << std::endl;
	std::cout << std::boolalpha <<test_map.empty() << std::endl;
    std::cout << test_map.count(0) << std::endl;
	//std::cout << test_map[1] << std::endl;
}
