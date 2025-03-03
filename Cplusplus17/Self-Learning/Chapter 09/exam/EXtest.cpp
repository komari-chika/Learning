#include "exercise.h"
#include <iostream>
#include <vector>
#include <array>
void Ex9_1()
{
    int a1 = 5, b1 = 3, c1 = 8;
    std::cout << "Clamped value of " << a1 << " between " << b1 << " and " << c1 << " is: " << clamp(a1, b1, c1) << std::endl;

    // 测试浮点数
    double a2 = 2.5, b2 = 3.0, c2 = 7.0;
    std::cout << "Clamped value of " << a2 << " between " << b2 << " and " << c2 << " is: " << clamp(a2, b2, c2) << std::endl;

    // 测试边界情况
    int a3 = 10, b3 = 3, c3 = 8;
    std::cout << "Clamped value of " << a3 << " between " << b3 << " and " << c3 << " is: " << clamp(a3, b3, c3) << std::endl;

    // 测试负数
    int a4 = -5, b4 = -8, c4 = -2;
    std::cout << "Clamped value of " << a4 << " between " << b4 << " and " << c4 << " is: " << clamp(a4, b4, c4) << std::endl;
}

void Ex9_2()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int big_int{17011983}, small_int{10};
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
              << larger(big_int, small_int) << std::endl;

    std::string a_string{"A"}, z_string{"Z"};
    std::cout << "Larger of \"" << a_string
              << "\" and \"" << z_string << "\" is "
              << '"' << larger(a_string, z_string) << '"'
              << std::endl;

    // ! 此时 auto 推断为 const char*
    const auto zz_string = "ZZ";
    const auto aa_string = "AA";

    std::cout << "Larger of "
              << "\"" << aa_string << "\"" << " and "
              << "\"" << zz_string << "\"" << " is "
              << "\"" << larger(aa_string, zz_string) << "\""
              << std::endl;
}

void Ex9_3()
{
    int a1{1};
    double a2{2.2};
    std::cout << plus(a1, a2) << std::endl;

    int *b1{&a1};
    double *b2{&a2};
    std::cout << plus(b1, b2) << std::endl;

    std::string c1{"aaa"};
    std::string c2{"bb"};
    std::cout << plus(c1, c2) << std::endl;

    const char d1[]{"aa"};
    const char d2[]{"bbb"};
    std::cout << plus("aa", "bbb") << std::endl;
    std::cout << plus(d1, d2) << std::endl;
}

void Ex9_4()
{

    std::vector<double> a1{1.1, 2.2, 3.3, 4.4, 5.5};
    std::cout << my_size(a1) << std::endl;

    std::array<int, 4> a2{1, 2, 3, 4};
    std::cout << my_size(a2) << std::endl;

    int a3[]{1, 3, 5, 6};
    std::cout << my_size(a3) << std::endl;
}

void Ex9_5()
{
    larger1(1.3, 1);
    larger1(1.3, 1);
    larger1(1.3, 1);
}

void Ex9_6()
{
    std::vector<int> a1{1, 4, 5, 3, 1, 1212, -31231};
    quickSort(a1);

    std::vector<double> a2{2.3, 4, 1, 2.2, 123, -312.3};
    quickSort(a2);

    std::vector<std::string> a3{"adef", "foejij", "dda", "zzz", "rooiuit", "dveiogh"};
    quickSort(a3);
}