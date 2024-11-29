#include <string>
#include <iostream>
#include <vector>
#include <typeinfo>
// ! 函数重载
// 1. 函数重载允许一个程序中的 若干函数 使用相同的名称，只要它们的 参数列表 不同即可。
// ! 编译器依靠 函数的签名 来 区分函数，函数的签名 是 函数名及其参数列表 的组合
// 满足以下条件的之一，两个同名函数就是不同的:
//  - 1. 参数的数量不同。
//  - 2. 至少有一对 对应参数 的类型不同。
// ! 返回类型不是函数签名的一部分，因此不能仅通过返回类型来区分函数
// ! 参数名 也不是函数签名一部分
// 以下 largest() 函数 是 重载函数

// double 数组 中的最大值
double largest(const double data[], size_t count);

// double vector容器 中的最大值
double largest(const std::vector<double> &data);

// int vector容器 中的最大值
int largest(const std::vector<int> &data);

// std::string vector 容器 中的最大值
std::string largest(const std::vector<std::string> &words);

// ! 以上内容可以使用 函数模板替换
template <typename T>
T largest(const std::vector<T> &datas);

// 2. 重载和指针参数
// 指向不同类型的指针 是不同的，以下两个函数是不同的函数
int largest(int *pvalues, size_t count);
int largest(double *pvalues, size_t count);
// ! 注意， int* 与 int[] 参数类型相同
// int largest(int values[],size_t count); 与第一个是同一个函数
// int largest(int values[100], size_t count); 与第一个也是同一个函数

// 3. 重载与引用参数
// ! 不能把 参数类型是 data_type 的函数，重载为 data_type&，如下
// void do_it(std::string number);
// void do_it(std::string& number);

double larger(double a, double b);
long &larger(long &a, long &b);
// long larger(const long &a, const long &b);

// 4. 重载与 const 参数
// ! const 与 非const 参数的唯一区别 是 为引用定义参数 还是 为指针定义参数

// ! 下面的函数原型没有区别
// long larger(long a, long b);
// const long larger(const long a, const long b);
// ! 实参在按值传送时，定义为 const 是毫无意义的
// !!! 注意，可以在函数声明时增加 const ，这样可以避免实参在函数作用域内被修改
/*
    long larger(const long a, const long b)
    {
        ...
    }
*/
// 4.1 重载 与 const 指针参数
// type* 与 const type* 对应 两个不同的函数
long *larger(long *a, long *b);
const long *larger(const long *a, const long *b);
// ! const 表示该指针 指向常量，禁止修改指针指向的值

// 与上面相反，以下两个函数是同一个函数
// long *larger(long *const a, long * const b);
// const long *larger(const long *const a, const long *const b);
// ! 在指针被定义为 const 后，指针的指向不能修改
// ! 而指针指向的值也是 const，这说明函数内部不可能出现任何有关的 重新赋值的操作

// 4.2 重载 与 const 引用参数
// 引用参数在声明为 const 时，在本质上已经是常量，因此 const T& 与 T& 总是不同的
// ! 下面两个函数是 重载的
long &larger(long &a, long &b);
long larger(const long &a, const long &b);

int main()
{
    double values[]{1.5, 44.6, 13.7, 21.2, 6.7};
    std::vector<int> numbers{15, 44, 13, 21, 6, 8, 5, 2};
    std::vector<double> data{3.5, 5, 6, -1.2, 8.7, 6.4};
    std::vector<std::string> names{"Charles Dickens", "Emily Bronte", "Jane Austen",
                                   "Henry James", "Arthur Miller"};
    /*
    在 C++ 中，如果同时定义了模板函数和普通函数，并且它们的名称相同，
    ! 那么在调用时，编译器会优先选择普通函数。
    ! 如果没有找到匹配的普通函数，才会考虑模板函数。
    */
    // 调用 普通重载函数
    largest(values, std::size(values));
    largest(numbers);
    largest(data);
    largest(names);

    // 调用 函数模板
    std::vector<size_t> template_numbers{0, 1, 2, 3, 4, 5, 67};
    largest(template_numbers);

    // 重载与引用参数
    double a_double{1.5}, b_double{2.5};
    int a_int{15}, b_int{25};
    larger(a_double, b_double); // 调用 double larger(double a, double b)
    // larger(static_cast<long>(a_int), static_cast<long>(b_int));
    // ! 这里调用的不是 long &larger(long &a, long &b)，而是double larger(double a, double b)
    // 虽然传入的 int 类型 转换成了 long 类型，但是它是包含相同值的临时位置
    // ! 编译器不会使用 临时地址 来初始化 对 非 const 值的引用
    // 可以使用 long larger(const long &a, const long &b)

    // const 指针重载
    long x{10}, y{20};
    const long cx{10}, cy{20};
    // 调用非 const 指针重载函数
    long z{*larger(&x, &y)};
    // 调用 const 指针重载函数
    const long cz{*larger(&cx, &cy)};
    // 编译器不会把 const 值 传递给 非 const 指针参数的函数
}

double largest(const double data[], size_t count)
{
    double max{data[0]};
    for (size_t i{}; i < count; ++i)
        if (data[i] > max)
            max = data[i];
    std::cout << "double largest(const double data[], size_t count): " << max << std::endl;
    return max;
}
double largest(const std::vector<double> &data)
{
    double max{data[0]};
    for (auto value : data)
        if (value > max)
            max = value;
    std::cout << "double largest(const std::vector<double> &data): " << max << std::endl;
    return max;
}
int largest(const std::vector<int> &data)
{
    int max{data[0]};
    for (auto value : data)
        if (value > max)
            max = value;
    std::cout << "int largest(const std::vector<int> &data): " << max << std::endl;
    return max;
}
std::string largest(const std::vector<std::string> &words)
{
    std::string max_word{words[0]};
    for (auto word : words)
        if (word > max_word)
            max_word = word;
    std::cout << "std::string largest(const std::vector<std::string> &words): " << max_word << std::endl;
    return max_word;
}
// 用模板代替
template <typename T>
T largest(const std::vector<T> &datas)
{
    T max_data{datas[0]};
    for (auto data : datas)
        if (data > max_data)
            max_data = data;
    std::cout << "T largest(const std::vector<T> &datas): " << max_data << std::endl;
    return max_data;
}

// 重载和指针参数
int largest(int *pvalues, size_t count)
{
    int max{pvalues[0]};
    for (size_t i{}; i < count; ++i)
        if (pvalues[i] > max)
            max = pvalues[i];
    std::cout << "int largest(int* pvalues, size_t count): " << max << std::endl;
    return max;
}
int largest(double *pvalues, size_t count)
{
    double max{pvalues[0]};
    for (size_t i{}; i < count; ++i)
        if (pvalues[i] > max)
            max = pvalues[i];
    std::cout << "int largest(double* pvalues, size_t count): " << max << std::endl;
    return static_cast<int>(max);
}

// 重载与引用参数
double larger(double a, double b)
{
    std::cout << "double larger(double a, double b)" << std::endl;
    return (a > b) ? a : b;
}

long &larger(long &a, long &b)
{
    std::cout << "long &larger(long &a, long &b)" << std::endl;
    return (a > b) ? a : b;
}
// long larger(const long &a, const long &b)
// {
//     return (a > b) ? a : b;
// }

// const 指针重载
long *larger(long *a, long *b)
{
    std::cout << "long *larger(long *a, long *b)" << std::endl;
    return (*a > *b) ? a : b;
}

const long *larger(const long *a, const long *b)
{
    std::cout << "const long *larger(const long *a, const long *b)" << std::endl;
    return (*a > *b) ? a : b;
}