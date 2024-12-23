#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <algorithm>

// 控制宏，用于快速切换调试模式
#define DEBUG_MODE 2 // 0: DEBUG_AUTO, 1: DEBUG_DECLTYPE, 2: DEBUG_DECLTYPE_AUTO

// 根据 DEBUG_MODE 设置其他宏的值
#if DEBUG_MODE == 0
#define DEBUG_AUTO 1
#define DEBUG_DECLTYPE 0
#define DEBUG_DECLTYPE_AUTO 0
#elif DEBUG_MODE == 1
#define DEBUG_AUTO 0
#define DEBUG_DECLTYPE 1
#define DEBUG_DECLTYPE_AUTO 0
#elif DEBUG_MODE == 2
#define DEBUG_AUTO 0
#define DEBUG_DECLTYPE 0
#define DEBUG_DECLTYPE_AUTO 1
#else
#error "Invalid DEBUG_MODE value! Set DEBUG_MODE to 0, 1, or 2."
#endif

// 8. 模板返回类型的推断

// 1. 使用 auto 来推断函数模板的返回类型
// ! 缺点：在 C++ 14 才引入
#if DEBUG_AUTO
template <typename T1, typename T2>
auto larger(T1 a, T2 b)
{
    return a > b ? a : b;
}
#endif

// 2. decltype 和 拖尾返回类型
// ! decltype(expression)，能够得到 exp 表达式的类型
// 用 decltype 重写 larger() 模板，将 return 语句的表达式放入 decltype() 中
#if DEBUG_DECLTYPE
template <typename T1, typename T2>
auto larger(T1 a, T2 b) -> decltype(a > b ? a : b)
{
    return a > b ? a : b;
}
#endif
// 上面便是 拖尾返回类型，位于函数 参数列表 的 后面
// ! 使用 auto 放在函数名前面，并非总是告诉编译器要推断返回类型，而是告诉编译器该函数模板可能存在拖尾返回类型

// 还可以用于表达式
// 以下函数用于求解两个向量的积
template <typename T1, typename T2>
auto vector_product(std::vector<T1> vec1, std::vector<T2> vec2)
{
    const auto count = std::min(vec1.size(), vec2.size());
    decltype(vec1[0] * vec2[0]) sum{}; // ! 确定求和的类型
    for (size_t i{}; i < count; ++i)
    {
        sum += vec1[i] * vec2[i];
    }
    return sum;
}

// 3. decltype 与 auto 结合
// decltype(auto) 在 C++ 14 引入
#if DEBUG_DECLTYPE_AUTO
template <typename T1, typename T2>
decltype(auto) larger(T1 a, T2 b)
{
    return a > b ? a : b;
}
#endif

int main(int argc, char *argv[])
{

#if DEBUG_AUTO
    std::cout << "larger(3, 5) = " << larger(3, 5) << std::endl;
    std::cout << "larger(3.5, 2) = " << larger(3.5, 2) << std::endl;
    std::cout << "larger(3.5, 2.7) = " << larger(3.5, 2.7) << std::endl;
#endif

#if DEBUG_DECLTYPE
    std::cout << "larger(3, 5) = " << larger(3, 5) << std::endl;
    std::cout << "larger(3.5, 2) = " << larger(3.5, 2) << std::endl;
    std::cout << "larger(3.5, 2.7) = " << larger(3.5, 2.7) << std::endl;
#endif

#if DEBUG_DECLTYPE_AUTO
    std::cout << "larger(3, 5) = " << larger(3, 5) << std::endl;
    std::cout << "larger(3.5, 2) = " << larger(3.5, 2) << std::endl;
    std::cout << "larger(3.5, 2.7) = " << larger(3.5, 2.7) << std::endl;
#endif

    // 测试 vector_product 函数
    std::cout << "\nTest vector_product function:" << std::endl;

    std::vector<int> vec1 = {1, 2, 3};
    std::vector<int> vec2 = {4, 5, 6};
    std::vector<int> vec3{};

    std::cout << "vector_product(vec1, vec2) = " << vector_product(vec1, vec2) << std::endl;

    // 如果向量为空（如 vec3），即使 vec3[0] 不存在，decltype 也不会报错，因为 decltype 只是推导类型，不会尝试访问空元素。
    std::cout << "vector_product(vec1, vec3) = " << vector_product(vec1, vec3) << std::endl;

    return 0;
}