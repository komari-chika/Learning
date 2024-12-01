#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#include <psapi.h>
// 通用测试函数
template <typename Func, typename... Args>
void test_function(const std::string &name, Func func, Args... args);

// 递归函数
// 1. 斐波拉契数列 
// 时间复杂度 O(2^n)
size_t fb1(size_t n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fb1(n - 1) + fb1(n - 2);
}

// 时间复杂度 O(n)
size_t fb2(size_t n)
{
    if (n == 1 || n == 2)
        return 1;

    std::vector<size_t> fb_numbers(n, 0);
    fb_numbers[0] = 1;
    fb_numbers[1] = 1;

    for (size_t i = 2; i < n; ++i)
    {
        fb_numbers[i] = fb_numbers[i - 1] + fb_numbers[i - 2];
    }
    return fb_numbers[n - 1];
}

// 2. 幂运算
// 时间复杂度 O(n)
double power1(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return x * power1(x, n - 1);
    else
        return 1.0 / power1(x, -n);
}

// 幂运算 - 快速幂
// 时间复杂度 O(log n)
double power2(double x, int n)
{
    if (n == 0)
        return 1;
    double half = power2(x, n / 2);
    if (n % 2 == 0)
        return half * half;
    else if (n > 0)
        return x * half * half;
    else
        return (1.0 / x) * half * half;
}




int main()
{
    size_t n = 46;
    // std::cout << "Testing Fibonacci functions:" << std::endl;
    // test_function("fb1", fb1, n);
    // test_function("fb2", fb2, n);
    // fb1 took 7.04295 seconds and used 4505600 bytes of memory, result = 1836311903
    // fb2 took 6.5e-06 seconds and used 4591616 bytes of memory, result = 183631190

    double x = 2.0;
    int exp = 10;
    // std::cout << "\nTesting Power functions:" << std::endl;
    // test_function("power1", power1, x, exp);
    // test_function("power2", power2, x, exp);
    // power1 took 2e-07 seconds and used 4591616 bytes of memory, result = 1024
    // power2 took 1e-07 seconds and used 4591616 bytes of memory, result = 1024

    return 0;
}

// 测试函数
template <typename Func, typename... Args>
/**
 * @brief 测量给定函数的执行时间和内存使用情况。
 * 
 * @tparam Func 要测量的函数类型。
 * @tparam Args 要传递给函数的参数类型。
 * @param name 表示被测量函数名称的字符串。
 * @param func 要测量的函数。
 * @param args 要传递给函数的参数。
 * 
 * 该函数测量提供的函数执行所需的时间
 * 以及当前进程在执行期间的内存使用情况。它会打印
 * 执行时间（以秒为单位）和内存使用量（以字节为单位）。如果函数有
 * 非void返回类型，它还会打印函数的结果。
 */
void test_function(const std::string &name, Func func, Args... args)
{
    auto start = std::chrono::high_resolution_clock::now();
    auto result = func(args...);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;

    PROCESS_MEMORY_COUNTERS memCounter;
    GetProcessMemoryInfo(GetCurrentProcess(), &memCounter, sizeof(memCounter));
    SIZE_T memoryUsage = memCounter.WorkingSetSize;

    std::cout << name << " took " << duration.count() << " seconds and used "
              << memoryUsage << " bytes of memory";
    if constexpr (!std::is_void_v<decltype(result)>)
    {
        std::cout << ", result = " << result;
    }
    std::cout << std::endl;
}