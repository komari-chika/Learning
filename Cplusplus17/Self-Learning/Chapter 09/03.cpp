#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>

// 7. 带有多个模板参数的函数模板
// 前面提到 larger1() 函数的 两个参数类型必须相同，否者返回类型不知，如下
/*
template<typename T1, typename T2>
??? larger(T1 a, T2 b)
{
    return a > b ? a : b;
}
*/
// ! 这里的返回类型不知

// 解决方案
// 1 ：添加额外的模板类型实参
template <typename TReturn, typename TArg1, typename TArg2>
TReturn larger(TArg1 a, TArg2 b)
{
    return a > b ? a : b;
}
// ! 此时编译器不能 推断出 返回类型 TReturn
// ! 模板实参的推断仅基于在函数实参列表中 传入的实参 来工作
// ! 因此需要自己指定 TReturn 模板实参


int main(int argc, char *argv[])
{

    // ! 一般来说，如果指定的 模板实参 比 模板参数 的数量少，编译器将推断其他实参的类型
    // 因此，下面三行是等效的
    // 它接受 double 和 int 类型的实参，并把结果转换为 size_t 类型
    std::cout << "Larger of 3.2 and 2 is " << larger<size_t>(3.2, 2) << std::endl;
    std::cout << "Larger of 3.2 and 2 is " << larger<size_t, double>(3.2, 2) << std::endl;
    std::cout << "Larger of 3.2 and 2 is " << larger<size_t, double, int>(3.2, 2) << std::endl;
    return 0;
}