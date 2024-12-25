#include <iostream>

#include "exercise.h"
#include "EXtest.cpp"

int main()
{
    const size_t n = 6;
    switch (n)
    {
    case 1:
        Ex9_1();
        break;
    case 2:
        Ex9_2();
        break;
    case 3:
        Ex9_3();
        break;
    case 4:
        Ex9_4();
        break;
    case 5:
        Ex9_5();
        break;
    case 6:
        Ex9_6();
        break;
    default:
        break;
    }
    return 0;
}