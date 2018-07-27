#include <iostream>
using namespace std;

void isInCross(const int& method)
{

    switch(method)
    {
        case 1:
            std::cout << "1111" << std::endl;
            break;
        case 2:
            std::cout << "2222" << std::endl;
            break;

        default:
            std::cout << "0000" << std::endl;
            break;
    }
}

int main(int argc, char **argv)
{
    isInCross(1);
    return 0;
}
