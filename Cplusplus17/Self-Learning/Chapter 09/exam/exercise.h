#pragma once
#define DEBUG 1
#include <string_view>
#include <vector>
#include <array>
#include <optional>
#include <iomanip>
#include <random> 
/*
Exercise 9-1.
In C++ 17, the Standard Library algorithm header gained the handy std::clamp() function template.
The expression clamp(a,b,c) is used to clamp the value a to a given closed interval [b, c].
That is, if a is less than b, the result of the expression will be b; and if a is greater than c, the result will be c; otherwise, if a lies within the interval [b, c],clamp() simply returns a.
Write your own my clamp() function template and try it with a little test program.
*/
void Ex9_1();
template <typename T>
T clamp(T a, T b, T c)
{
    if (a < b)
        return b;
    else if (a > c)
        return c;
    else
        return a;
}

/*
Exercise 9-2.
Alter the last lines of Ex9_01's main() function as follows.

/------------------------------------Ex9_01.cpp------------------------------------/
#include <iostream>
#include <string>

template <typename T>
T larger(T a, T b); // Function template prototype

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int big_int{17011983}, small_int{10};
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
              << larger(big_int, small_int) << std::endl;

    ! CHANGE HERE !
    std::string a_string{"A"}, z_string{"Z"};
    std::cout << "Larger of \"" << a_string << "\" and \"" << z_string << "\" is "
              << '"' << larger(a_string, z_string) << '"' << std::endl;
    ! CHANGE HERE !
}

template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}
/--------------------------------------------------------------------/


! /-------------CHANGE-------------/
const auto a_string = "A", z_string = "Z";
std::cout << "Larger of " << a_string << " and "
          << z_string << " is "
          << larger(a_string, z_string)
          << std::endl;
! /----------------------------/


! If you now run the program, you may very well get the following output
(if not, try rearranging the order in which a_string and z_string are declared):

Larger of 1.5 and 2.5 is 2.5
Larger of 3.5 and 4.5 is 4.5
Larger of 17011983 and 10 is 17011983
Larger of A and Z is A

! What's that? "A" is larger than "Z"? Can you explain exactly what went wrong? Can you fix it?

Hint: To compare two character arrays, you could perhaps first convert them to another
string representation.!
*/
void Ex9_2();
#if DEBUG == 0
template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}
#elif DEBUG == 1
template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}

template <>
const char *larger(const char *a, const char *b)
{

    std::string aa{a};
    std::string bb{b};
    if (aa > bb)
        return a;
    else
        return b;
    // 也可以使用 <cstring> 头文件中的 strcmp() 函数
    // std::strcmp(a, b) 会逐个字符比较 a 和 b，并返回一个值。
    // 如果 a 的字典顺序大于 b，则返回大于零的值
    // return std::strcmp(a, b) > 0 ? a : b;
}
#endif

/*
Exercise 9-3.
Write a function template plus() that takes two arguments of potentially different types and returns a value equal to the sum of both arguments.

Next, make sure that plus() can be used as well to add the values pointed to by two given pointers.

Extra: Can you now make it so that you can also concatenate two string literals using
plus()?
Warning: This may not be as easy as you think!
*/
void Ex9_3();
template <typename TArg1, typename TArg2>
decltype(auto) plus(TArg1 a, TArg2 b)
{
    return a + b;
}

template <typename TArg1, typename TArg2> // overloading of plus
decltype(auto) plus(TArg1 *a, TArg2 b)
{
    return *a + *b;
}

// ! 下面是错误的
// template<>
// decltype(auto) plus(const char* a, const char* b)
// {
//     std::string ab{std::string{a} + std::string{b}};
//     ab.c_str();
//     return ab;
// }
/*
1. 返回值类型是 decltype(auto)：
decltype(auto) 会根据 return 语句推导实际返回的类型。
在这里，ab 是一个局部变量，其类型为 std::string。
如果返回的是 ab 本身，则推导类型是 std::string（按值返回是可以的）。

2. 错误的 ab.c_str() 调用：
这行代码仅仅调用了 ab 的 c_str() 方法，没有对返回值进行存储或返回！
它实际上什么都没做，只是获取了字符串的内部指针，但这个指针没有存储下来，也没有被返回。

3. 返回局部变量的问题：
return ab，尝试按值返回局部变量 ab，这本身是合法的，但是因为代码使用的是 decltype(auto)，实际返回类型是 std::string，而不是指针或引用。
如果期望返回 const char*，那么局部对象 ab 在函数结束时会被销毁，其 c_str() 指针变为 悬空指针 (dangling pointer)，导致未定义行为。
*/

// ! 正确解决方案
std::string plus(const char *a, const char *b)
{
    return std::string{a} + b;
}

/*
Exercise 9-4.
Write your own version of the std::size() family of functions called my_size() that work
! not only for fixed-size arrays
! but also for std::vector<> and std::array<> objects.
You are not allowed to use the sizeof() operator.
*/
void Ex9_4();

template <typename T, size_t N>
size_t my_size(const T (&a)[N]) // ! 使用引用来推断固定大小数组，见 Chapter 08/01.cpp
// 7. 引用传递数组
// ! 与值传递和指针传递不同，引用传递可以传递 精确的数组大小
{
    return N; // 返回数组大小
}

template <typename T>
size_t my_size(const std::vector<T> &a)
{
    // return a.size();
    size_t count{0};
    for (auto val : a)
        count++;
    return count;
}

template <typename T, size_t N>
size_t my_size(const std::array<T, N> &a)
{
    return N;
}

/*
Exercise 9-5.
Can you think of a way to verify that
! the compiler generates only one instance of a function template for any given argument type?
Do so for the larger() function in Ex9_01.cpp.
*/
// ! static 变量
void Ex9_5();
template <typename T1, typename T2>
decltype(auto) larger1(const T1 &a, const T2 &b)
{
    static size_t count{};
    count++;
    std::cout << "this larger1() has been called " << count << " times." << std::endl;
    return a > b ? a : b;
}

/*
Exercise 9-6.
In the previous chapter, you studied a quicksort algorithm that worked for pointers-to-strings.
Generalize the implementation of Ex8_18.cpp so that it works for vectors of any type (any type for which the < operator exists, that is).
Write a main() function that uses this to sort some vectors with different element types and outputs both the unsorted and unsorted element lists.
Naturally, you should do this by also creating a function template that streams vectors with arbitrary element types to std::cout.
*/
void Ex9_6();

// 1. std::vector<int>, std::vector<float>..
template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
int partition(std::vector<T> &values, int left, int right)
{
    T pivot{values[left]};
    int i{left};
    for (int j{left + 1}; j <= right; ++j)
    {
        if (values[j] < pivot)
        {
            i++;
            swap(values[i], values[j]);
        }
    }
    swap(values[i], values[left]);
    return i;
}

template <typename T>
void quickSort(std::vector<T> &values, int left, int right)
{
    if (left < right)
    {
        int pi = partition(values, left, right);
        quickSort(values, left, pi - 1);
        quickSort(values, pi + 1, right);
    }
}

template <typename T>
void coutVector(const std::vector<T> &values, std::string description, size_t newLine = 5, size_t wordLength = 8)
{
    std::cout << description << " : " << std::endl;
    for (size_t i{}; i < values.size(); ++i)
    {
        std::cout << std::setw(wordLength) << values[i] << " ";
        if ((i + 1) % newLine == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T>
void quickSort(std::vector<T> &values)
{
    if (values.empty())
    {
        std::cout << "invalid input" << std::endl;
        return;
    }
    else
    {
        coutVector(values, "Origin");
        quickSort(values, 0, values.size() - 1);
        coutVector(values, "Sorted");
    }
}
