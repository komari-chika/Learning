#include <iostream>
#include "exam.h"
#include "func.cpp"
int main(int argc, char *argv[])
{
    size_t number = 5;

    switch (number)
    {
    case 1:
        test01();
        break;
    case 2:
        test02();
        break;
    case 3:
        test03(argc, argv);
        break;
    case 4:
        test04();
        break;
    case 5:
        test05();
        break;
    default:
        std::cerr << "Invalid test number" << std::endl;
        break;
    }

    return 0;
}
