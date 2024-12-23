#include <iostream>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>

// 6. 函数模板与重载
template <typename T>
T larger1(T a, T b)
{
    // std::cout << "Call : " << "T larger1(T a, T b)" << std::endl;
    return a > b ? a : b;
}

// ! 定义同名的其他函数，就可以重载函数模板
// 比如针对 larger1() 函数的 int* 类型，不使用 特例 而是 函数
// int *larger1(int *a, int *b)
// {
//     return *a > *b ? a : b;
// }

// ! 还可以重载模板
template <typename T>
// 返回数组中的最大值
T larger1(const T data[], size_t count)
{
    // std::cout << "Call : " << "T larger1(const T data[], size_t count)" << std::endl;
    T max_number{data[0]};
    for (size_t i{1}; i < count; ++i)
    {
        max_number = max_number > data[i] ? max_number : data[i];
    }
    return max_number;
}

template <typename T>
// 返回向量中的最大值
T larger1(const std::vector<T> &data)
{
    // std::cout << "Call : " << "T larger1(const std::vector<T> &data)" << std::endl;
    T max_number{data[0]};
    for (auto val : data)
    {
        max_number = max_number > val ? max_number : val;
    }
    return max_number;
}
// ! 注意，上面两个重载函数只有 输入数据不为空才可以

// 还可以使用指针
// ! 注意，它只能使用指针类型来初始化
template <typename T>
T *larger1(T *a, T *b)
{
    // std::cout << "Call : " << "T *larger1(T *a, T *b)" << std::endl;
    return *a > *b ? a : b;
}

int main(int argc, char *argv[])
{

    int big_int{17011983}, small_int{10};
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
              << larger1(big_int, small_int) << std::endl;
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
              << *larger1(&big_int, &small_int) << std::endl;

    const char text[]{"A nod is as good as a wink to a blind horse."};
    std::cout << "Largest character in \"" << text << "\" is '"
              << larger1(text, std::size(text)) << "'" << std::endl;

    std::vector<std::string> words{"The", "higher", "the", "fewer"};
    std::cout << "The largest word in words is \"" << larger1(words)
              << '"' << std::endl;

    std::vector<double> data{-1.4, 7.3, -100.0, 54.1, 16.3};
    std::cout << "The largest value in data is " << larger1(data) << std::endl;
    return 0;
}