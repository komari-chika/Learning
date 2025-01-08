#include <iostream>
#include <iomanip>
// #include "Power.cpp"  // 加上这行才能运行

// 外部函数
// 源文件 a.cpp 中的 函数调用 与 源文件 b.cpp 中的 函数定义 之间的链接由链接程序建立。
// ! 函数名在默认情况下具有 外部链接属性
// 如果函数没有在调用它的转换单元中定义，编译器就会把它标记为外部的，让链接程序处理
double power(double x, int n);

int main()
{
    for (int i{-3}; i <= 3; ++i)
        std::cout << std::setw(10) << power(8.0, i);
    std::cout << std::endl;
    return 0;
}