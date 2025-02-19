#include <iostream>
#include <iomanip>
// #include "Power.cpp"
// #include "Range.cpp"

// 外部变量
double power(double x, int n);

// int power_range; // 这里不对，报错  error: redefinition of 'int power_range'，即重定义
// ! 根本原因： 这里的不仅是变量声明，还是变量定义
// ! 全局变量定义是没有使用初始化列表，就会初始化为 0，此时等效于：int power_range{};

// ODR 不允许同一个变量有两个定义，因此需要告诉编译器，power_range 对于当前转化单元是 外部定义，需要使用 extern 关键字声明
extern int power_range;
//
// extern const int power_range;

int main()
{
    // 增加外部定义的变量 power_range
    for (int i{-power_range}; i <= power_range; ++i)
        std::cout << std::setw(10) << power(8.0, i);
    std::cout << std::endl;
    return 0;
}