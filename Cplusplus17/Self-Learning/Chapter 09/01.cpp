#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>
#define DEBUG_MODE true // 定义宏 DEBUG_MODE
// #define DEBUG_MODE false

// 函数模板
// ! 函数模板本身不是函数定义
// ! 函数模板的参数一般是 参数类型，如 int, string，还可以是 维度

// 1. 函数模板示例如下
template <typename T>
T larger1(T a, T b)
{
    return a > b ? a : b;
}
// 关键字 template 把这段代码标识为模板
// 关键字 typename 把 T 标识为 类型,typename 也可以写成 class，但不推荐
// 模板参数放在 关键字 template 后面的尖括号中，如果有多个模板参数，用逗号隔开

// ! C++ 模板的编译是一个延迟实例化的过程。模板本身并不是实际的函数或类，它只是一种“蓝图”。只有当模板被具体使用（即实例化）时，编译器才会生成实际的代码
// ! 通常，模板的声明和定义会一起放在头文件中，避免编译时找不到定义的问题。这也是为什么很多模板库（如 STL）都是头文件库的原因。

// 2. 函数模板的实例
// ! 当你调用模板函数时，编译器会根据函数调用的 实参类型 来自动推断模板参数 T 的具体类型
// ! 然后根据推断出来的类型 T，将模板函数的定义实例化为一个特定类型的函数。
/*
例如：
larger(3.5, 2.1);
上面的函数中，实参是两个 double 类型的值，编译器会推断 T 是 double 类型，编译器会生成如下代码：
double larger(double a, double b)
{
    return a > b ? a : b;
}
*/

// 3. 模板类型参数
// 模板类型参数可用在：模板函数的签名，返回类型和函数体的任何位置
// T&, const T&, T*, T[][3], std::vector<T>，都是合法的
// 上面的 larger() 函数也可以使用 std::string 来实例化，但是传送值会造成不必要的麻烦，可以使用引用传递
template <typename T>
const T &larger2(const T &a, const T &b)
{
    return a > b ? a : b;
}
// 上面的 larger() 非常类似于 algorithm 头文件里面的 std::max() 函数，用于返回两个值中的较大者
// 同样的还有 std::min() 函数

// 4. 显式指定函数模板类型
/*
! 编译器不能创建有不同参数类型的模板实例。一个实参可以转换为另一个实参的类型，但必须显式编写这种转换，编译器不自动生成该代码。
可以定义模板，允许模板参数有不同的类型，后面将会讨论
*/
// 使用 <T> 显式的实例化函数模板

// 5. 函数模板的特例
// 可以定义模板的特例，用于包含模板实参是指针类型的情况
// ! 特例的定义 必须放在 原始模板的声明或定义 之后
// 不使用特例
template <typename T>
T *larger3(T *a, T *b)
{
    return *a > *b ? a : b;
}

#if DEBUG_MODE
// ! 创建特例
// ! 首先 template 的 模板参数 为空
template <>
// ! 其次，要指明实例化时的参数类型，即在函数名后添加 <T>, T 是特例对应的类型
int *larger1<int *>(int *a, int *b)
{
    return *a > *b ? a : b;
}
#endif

int main(int argc, char *argv[])
{
    // 使用 <T> 显式的实例化函数模板
    std::cout << larger1<double>(3.2, 2) << std::endl; // 3.2
    std::cout << larger1<int>(3.2, 2) << std::endl;    // 3， 编译器隐式转换为 int

    // 用指针作为实参
    int a{2}, b{3};
    std::cout << *larger1(&a, &b) << std::endl; // ! 在没有定义模板特例（DEBUG_MODE）之前，输出有误
    // 传入的是a，b的地址，因此类型推断为 int*
    // ! 然后 比较指针地址 (a > b) 而非 指针所指向的值

    std::cout << *larger3(&a, &b) << std::endl; // 正确输出 3

    return 0;
}