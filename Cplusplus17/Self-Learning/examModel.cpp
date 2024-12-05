#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

void test01() { std::cout << "test01 called" << std::endl; }
void test02() { std::cout << "test02 called" << std::endl; }
void test03() { std::cout << "test03 called" << std::endl; }
void test04() { std::cout << "test04 called" << std::endl; }
void test05() { std::cout << "test05 called" << std::endl; }
void test06() { std::cout << "test06 called" << std::endl; }
void test07() { std::cout << "test07 called" << std::endl; }
void test08() { std::cout << "test08 called" << std::endl; }

int main()
{
    size_t number = 1;

    switch (number)
    {
        case 1:
            test01();
            break;
        case 2:
            test02();
            break;
        case 3:
            test03();
            break;
        case 4:
            test04();
            break;
        case 5:
            test05();
            break;
        case 6:
            test06();
            break;
        case 7:
            test07();
            break;
        case 8:
            test08();
            break;
        default:
            std::cerr << "Invalid number" << std::endl;
            break;
    }

    return 0;
}