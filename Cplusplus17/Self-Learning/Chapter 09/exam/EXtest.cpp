#include "exercise.h"
#include <iostream>

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