#include "yaml-cpp/yaml.h" 
#include <iostream>
#include <vector>

int main()
{
    std::string model_path = getenv("HOME");
    std::string path(model_path);
    // std::string model_path = std::string(std::getenv("HAD"));
    // std::cout << model_path << std::endl;
    auto yaml_path = model_path + "/yaml/topomap_error_lanes.yaml";

    YAML::Node config = YAML::LoadFile(yaml_path.c_str());
    auto lc_config = config["lane_change"];
    auto normal = lc_config["lanes_type"]["normal"];
    auto cross = lc_config["lanes_type"]["cross"];
    double acc = lc_config["acc"].as<double>();
    double step = lc_config["step"].as<double>();
    double interval = lc_config["interval"].as<double>();
    
    double front_collision_time = lc_config["front_collision_time"].as<double>();
    double side_collision_time = lc_config["side_collision_time"].as<double>();
	int predect_deepth = lc_config["predect_deepth"].as<int>();

	std::vector<int> temp_normal;
	std::vector<int> temp_cross;

    std::cout << "normal: ";
    for(auto i : normal)
    {
        std::cout << i.as<int>() << " ";
        temp_normal.emplace_back(i.as<int>());
    }
    std::cout <<""<< std::endl;
    std::cout << "cross: ";
    for(auto i : cross)
    {
        temp_cross.emplace_back(i.as<int>());
        std::cout << i.as<int>() << " ";
    }
    std::cout <<""<< std::endl;
	std::cout << "acc: " << acc << std::endl;
	std::cout << "step: " << step << std::endl;
	std::cout << "interval: " << interval << std::endl;
	std::cout << "predect_deepth: " << predect_deepth << std::endl;
	std::cout << "front_collision_time: " << front_collision_time << std::endl;
	std::cout << "side_collision_time: " << side_collision_time << std::endl;
    return 0;
}




