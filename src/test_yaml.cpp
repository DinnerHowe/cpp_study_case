#include "yaml-cpp/yaml.h" 
#include <iostream>
#include <vector>

int main()
{
    std::string model_path = getenv("HOME");
    std::string path(model_path);
    auto yaml_path = model_path + "/yaml/test.yaml";
    YAML::Node config = YAML::LoadFile(yaml_path.c_str());
    auto f = lc_config["test"]["test_f"];
    auto s = lc_config["test"]["test_s"];

    double test_double = lc_config["test_double"].as<double>();
    
	std::vector<int> temp_f;
	std::vector<int> temp_s;

    std::cout << "test_f: ";
    for(auto i : f)
    {
        std::cout << i.as<int>() << " ";
        temp_f.emplace_back(i.as<int>());
    }
    std::cout <<""<< std::endl;
    std::cout << "test_s: ";
    for(auto i : cross)
    {
        temp_s.emplace_back(i.as<int>());
        std::cout << i.as<int>() << " ";
    }
    std::cout <<""<< std::endl;

	std::cout << "test_double: " << test_double << std::endl;
    return 0;
}




