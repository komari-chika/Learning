#include <iostream>

#include "exercise.h"
#include "EXtest.cpp"

int main()
{
    const size_t n = 2;
    switch (n)
    {
    case 1:
        Ex9_1();
        break;
    case 2:
        Ex9_2();
        break;
    default:
        break;
    }

    return 0;
}