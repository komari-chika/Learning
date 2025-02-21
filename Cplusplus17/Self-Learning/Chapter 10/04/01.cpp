#include <iostream>
#include <iomanip>
#include "power.h"

int main()
{
    for (int i{-3}; i <= 3; ++i)
    {
        std::cout << std::setw(10) << power(8.0, i);
    }
    std::cout << std::endl;
}