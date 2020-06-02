#include <iostream>
#include <vector>
#include <time.h>

int main()
{
	std::string a = "[obs]-s12123_sda-aa";
    const std::string delim = "-";
    auto prefix = a.substr(0, a.find(delim));
    auto bottown = a.substr(a.find(delim)+1, a.size());
	std::cout << "prefix: " << prefix << std::endl;
	std::cout << "bottown: " << bottown << std::endl;
    return 0;
}




