#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <optional>
#include <algorithm>
// 9. 模板参数的默认值
// 同函数的默认值
// ! 省略了参数名，仅声明了函数原型，常用于接口设计或占位符
// ! 省略参数名在声明中是合法的，但定义时必须提供参数名以便使用
template <typename TReturn = double, typename TArg1, typename TArg2>
TReturn larger1(const TArg1 &, const TArg2 &);

// 上面这种方式不太好，如果忘记指定 TReturn 类型，当 TArg1 类型不是 double 时仍然会返回 double 类型
// 可以仿照函数的默认值，在最末尾指定
template <typename TArg, typename TReturn = TArg>
TReturn larger2(const TArg &, const TArg &);
// 但是这样仍然不一定是个好主意

// 10. 非类型的模板函数
// 在定义模板时，非类型的模板参数 和 其他的类型参数 一起放在参数列表中
/*
! 模板参数的类型可以是:
    1. 整型，如int或long等
    2. 枚举类型，enum
    3. 对象类型的引用或指针
    4. 函数的引用或指针
    5. 类成员的指针
*/
// 编译器需要能够在编译时计算与非类型参数对应的实参。例如，对于整型参数，这意味着它们将是整型字面或是整型编译时常量。

// 判断一个数是否处于上下界
template <typename T, int upper, int lower>
bool isInRange1(const T &value)
{
    return (value <= upper) && (value >= lower);
}
// 此时如果使用浮点数调用函数
// isInrange1<0,500>(100.0)，编译失败，不能正确推断类型
// isInrange1<double,0,500>(100.0), 这样正确

// 更优的写法是把 T 放在最后面
template <int upper, int lower, typename T>
bool isInRange2(const T &value)
{
    return (value <= upper) && (value >= lower);
}
// isInrange2<0, 500>(100.0)，正确编译
// ! 此时编译器可以推断出参数类型
// !! 非类型参数放前面，类型参数放后面以简化调用

// Ch.8 讲过，函数参数为数组时，可以指定数组大小，但 传入参数的数组大小 必须等于 函数参数的数组大小
double average1(const double (&array)[10]); // 传入的数组大小必须为 10
// ! 使用函数模板
template <typename T, size_t N>
double average2(const T (&array)[N])
{
    T sum{};
    for (auto val : array)
        sum += val;
    return static_cast<double>(sum) / N;
}

int main(int argc, char *argv[])
{
    double doubles[2]{1.0, 2.0};
    std::cout << average2(doubles) << std::endl;

    double moreDoubles[]{1.0, 2.0, 3.0, 4.0};
    std::cout << average2(moreDoubles) << std::endl;

    // ! 编译器无法从指针推断出数组的大小
    // double* pointer = doubles;
    // std::cout << average(pointer) << std::endl;     

    std::cout << average2({1.0, 2.0, 3.0, 4.0}) << std::endl;

    int ints[] = {1, 2, 3, 4};
    std::cout << average2(ints) << std::endl;
}

// 默认值只能指定一处，默认是在 声明 处而非 定义
template <typename TReturn, typename TArg1, typename TArg2>
TReturn larger1(const TArg1 &a, const TArg2 &b)
{
    return a > b ? a : b;
}

template <typename TArg, typename TReturn>
TReturn larger2(const TArg &a, const TArg &b)
{
    return a > b ? a : b;
}