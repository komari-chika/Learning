#include <iostream>
#include <string_view>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <optional>

// 函数返回值
// 1. 返回指针
//      - 必须包含 nullptr，或者 调用函数中仍然有效的地址
//      ! 不要返回函数中在 栈上分配 的 自动局部变量 的地址
// 例如
// int *func(int a, int b)
// {
//     if (a > b)
//         return &a; // 错误
//     else
//         return &b; // 错误
// }
// 上面的例子中，a 和 b 都是局部变量，在函数结束时会被销毁，因此返回它们的地址是未知且危险的

// 可以把参数定义为指针，如下所示
int *func(int *a, int *b)
{
    if (*a > *b)
        return a;
    else
        return b;
}
// 返回一个数组中最小值的指针
// 注意输入数组是 const 类型数组
// ! 编译器不允许一个 非 const 指针，指向 const 数组的元素
const double *smallest(const double data[], size_t count)
{
    if (!count)
        return nullptr;
    size_t indexMin{};
    for (size_t i{}; i < count; ++i)
    {
        if (data[i] < data[indexMin])
            indexMin = i;
    }
    return &data[indexMin];
}

// 将数组的每一个值都加上 delta，然后返回数组的地址
// 可以搭配 smallest 函数，使所有元素都是非负数
double *shiftRange(double data[], size_t count, double delta)
{
    for (size_t i{}; i < count; ++i)
    {
        data[i] += delta;
    }
    return data;
}

// 寻找最大值
const double *largest(const double data[], size_t count)
{
    if (!count)
        return nullptr;
    size_t indexMax{};
    for (size_t i{}; i < count; ++i)
    {
        if (data[i] > data[indexMax])
            indexMax = i;
    }
    return &data[indexMax];
}

// 把值映射到 0 - 1
double *shiftScale(double data[], size_t count, double divisor)
{
    if (!divisor)
        return data; // 不能除以 0
    for (size_t i{}; i < count; ++i)
    {
        data[i] /= divisor;
    }
    return data;
}

// 把二者合一
double *normalize(double data[], size_t count)
{
    return shiftScale(data, count, *(largest(shiftRange(data, count, -*smallest(data, count)), count)));
}

// 2. 返回引用
//      - 返回指针为空时，解引用空指针会出现失败
//      ! 不要返回函数内部 自动局部变量 的引用（类似之前的指针）

// 返回引用，允许在赋值操作的左边使用函数调用
std::string &larger(std::string &s1, std::string &s2)
{
    // 返回是 对 std::string 的引用
    // ! 返回类型是 非 const 引用，故而不能用 const 引用参数
    // 即 不能由窄变宽 const 不能变为 非 const
    return s1 > s2 ? s1 : s2;
}

// 3. 返回值 和 输出参数
// 现代 C++ 中，更推荐 返回值，尤其是复制对象的成本很高时
// ! 但是对于 数组 和 std::array<> 时还是更推荐 输出参数

// 4. auto 返回类型
// ! 返回类型必须一致
// auto getFirstLetter(std::string_view text){
//     if(text.empty()) return " ";
//     else return text.substr(0,1); // 推导出的返回类型 "std::basic_string_view<char, std::char_traits<char>>" 与之前推导出的类型 "const char *" 冲突C/C++(2546)
// }
// 上面的函数 第一个返回类型是 字符串字面量，是 const char*
//           第二个是 string_view 的子字符串，仍然是 string_view
// ! 二者不一致，不合法

// ! 简单准则
// auto 总是被推断为 一个值，即使将一个引用 赋值给 auto，它仍然是复制该值
// 显式使用 auto& , 或者 const auto&
// 这条规则对局部变量仍然适用

// 5. 使用 可选值
// 考虑函数 findLastInString
int findLastInString(std::string_view string, char char_to_find, int start_index);
// 该函数用于 从给定的启示索引 start_index 开始, 在给定的字符串 string 从后向前搜索字符 char_to_find 最后一次出现的索引
// ! 当搜索不到时，返回 -1；或者当传送 -1 或者 任何负值 作为 start_index 时，搜索整个字符串
// C++ 17 标准库中提供了 optional<>
// 可以显式的将 参数 或者 返回值 声明为可选值
// 例如
std::optional<int> findLastInString(std::string_view string, char char_to_find, std::optional<int> start_index);
std::optional<int> readConfigurationOverride(std::string_view file_name, std::string_view over_ride_name);
// std::optional<int> 显式声明为任何可选的 int 值
/*
  std::optional 核心总结：
  1. 表示值的可选性：值可能存在，也可能为空（使用 std::nullopt 表示空）。
  2. 函数返回值的最佳选择：
    - 避免返回特殊值（如 -1、nullptr）。
    - 提供显式语义，表明返回值是否有效。
  3. 常用方法：
    - has_value() 或 bool 转换：检查是否有值。
    - value()：获取值，空值时抛出异常。
    - value_or(default)：取值或返回默认值，推荐使用。
    - reset()：清空值。
  4. 解引用操作：
    - opt 获取值。
    - opt-> 访问成员，适用于类类型。
  5. 支持比较操作：直接比较存储值，空值与任何值均不相等。
  6. 注意：
    - 避免滥用，不适合频繁动态分配场景。
    - 尽量用 value_or 提供默认值，减少显式检查。
*/

// 举例
std::optional<size_t> findLast(std::string_view string, char to_find, std::optional<size_t> start_index = std::nullopt)
{
    if (string.empty())                                     // string is empty
        return std::nullopt;                                // or return std::optional<size_t>{};
                                                            // or return {};
    size_t index = start_index.value_or(string.size() - 1); // index = start_index or index = string.size() - 1
    // start_index 是一个 std::optional<size_t>：
    // 可能包含一个值，也可能为空（std::nullopt）。
    // 这里，start_index 用来表示可选的搜索起始位置。
    // start_index.value_or(default_value) 方法的作用：
    // 如果 start_index 包含值，则返回该值。
    // 如果 start_index 是空的（std::nullopt），则返回 default_value（string.size() - 1）。
    while (true)
    {
        if (string[index] == to_find)
            return index;
        if (index == 0)
            return std::nullopt; // 没找到
        --index;
    }
}

// 6. 静态变量
// 使用 static 关键字修饰
// 定义的 static 变量一直存在直到程序结束为止，它可以在多个函数之间传递数据
unsigned int nextInteger(){
    static unsigned int count{0};
    // 第一次执行 包含 static 的语句时，会创建 count 并且初始化为 0
    // ! 之后再执行该语句就没有效果了
    // ! 静态变量只在 第一次调用函数 时 创建并初始化一次
    // ! 静态变量不初始化时，默认为0；但局部变量不初始化将包含垃圾值
    return ++count;
}

// 内联函数
// inline 关键字
inline int larger(int m, int n){
    return (m > n) ? m : n;
}
// 如果函数内部代码少且结构简单，那么调用函数造成的开销(返回地址、参数信息的保留入栈)要比直接插入函数体要高得多
// 因此 inline 用于建议该 函数调用 使用 函数体替换，但具体到是否采纳建议，还是由编译器决定
// ! 把函数指定为内联函数，函数的定义就必须可以在调用函数的每个源文件可以用
// ! 因此内联函数的定义一般在头文件(.h)中，而不是源文件(.c)中


int main()
{
    // 1. 返回指针
    int a = 1, b = 2;
    *func(&a, &b) = 3; // 把较大值的值置为 3，即 b = 3
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    // std::cout << *smallest(data, 5) << std::endl; // 解引用返回值

    size_t count{std::size(data)};
    // shiftRange(data, count, -(*smallest(data, count)));
    // // 运行后变为 0 1 2 3 4
    // shiftScale(data, count, *largest(data, count));
    // // 运行后变为 0 0.25 0.5 0.75 1

    normalize(data, count); // 运行后变为 0 0.25 0.5 0.75 1

    // 2. 返回引用
    std::string str1{"abcx"};
    std::string str2{"abcy"};
    larger(str1, str2) = "abcz"; // ! 可以作为左值
                                 // 此时 str2 = abcz

    // 5. std::optional<>
    const auto string = "Growing old is mandatory; growing up is optional."; // const char*
    const std::optional<size_t> found_a{findLast(string, 'a')};              // a = 46
    if (found_a)
        std::cout << "found_a:" << *found_a << std::endl;
    const auto found_b{findLast(string, 'b')}; // b = std::nullopt
    if (found_b.has_value())
        std::cout << "found_b: " << found_b.value() << std::endl;
    // const size_t found_c{findLast(string, 'c')}; // ! 错误，std::optional<size_t> 不能转换为 size_t
    const auto found_early_i{findLast(string, 'i', 10)};
    if (found_early_i != std::nullopt) // i = 4
        std::cout << "found_early_i: " << *found_early_i << std::endl;
    // 以上包含 3 种方法检查 findLast() 函数 返回的 optional<> 是否被赋值
    //    - 1. 让编译器将 optional<> 转换为 布尔值
    //    - 2. 调用 has_value() 函数
    //    - 3. 将 optional<> 与 nullopt 比较

    // 以及两种方法提取 optional<> 的值
    //    - 1. * 运算符
    //    - 2. 调用 value() 函数

    return 0;
}