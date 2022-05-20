#include "/home/anjk/Workspace/PRIVATE/gitHub/reminder_CPP/pointers/headers/basics.hpp"
#include <iostream>

namespace basics {
    void showBasicsInfo() {
    
    int p1 = 1;
    int *p2 = &p1;
    int **p3 = &p2;

    std::cout << "p1:  adres - " << p1  << std::endl;
    std::cout << "&p1: adres - " << &p1 << std::endl;
    std::cout << "p2:  adres - " << p2  << " p2 holds address of p1 " << std::endl;
    std::cout << "&p2: adres - " << &p2 << "          address of p2 " << std::endl;

    std::cout << "p3:  adres - " << p3  << " p3 holds address of p2" << std::endl;
    std::cout << "&p3: adres - " << &p3 << "          address of p3" << std::endl;

    std::cout << "Value of **p3: " << **p3 << std::endl;
    std::cout << "Value of *p3: "  <<  *p3 << std::endl;

    }
}
