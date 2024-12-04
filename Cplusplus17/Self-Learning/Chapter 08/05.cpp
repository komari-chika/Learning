#include <iostream>
#include <vector>
#include <chrono>
#include <windows.h>
#include <psapi.h>
#include <optional>
#include <algorithm>
// 通用测试函数
template <typename Func, typename... Args>
void test_function(std::optional<bool> coutResult, const std::string &name, Func func, Args... args);
// 随机生成含有 n 个 double 类型的 vector
std::vector<double> generateRandomVector(size_t n);

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

// 快速幂 时间复杂度 O(log n)
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

// 快速排序
// 时间复杂度 O(nlogn)
// n 为每次分区寻找 基准值 索引花费
// log n 为划分花费

void swap(std::vector<double> &numbers, size_t index1, size_t index2)
{
    double temp = numbers[index1];
    numbers[index1] = numbers[index2];
    numbers[index2] = temp;
}

// 下面是四种分区方式
// 以 start 为基准值
int partition1(std::vector<double> &numbers, int start, int end)
{
    double pivot = numbers[start];
    int i = end + 1; // i 是数组中，所有 大于基准值 的 数 中的 最前一个数的索引
                     // 3 2 6 5 8 9 7 假如是经过分区后，那么此时 i = 2，指向 6
    for (int j = end; j > 0; --j)
    {
        if (numbers[j] > pivot) // 当前位置的 数 比 基准值大
        {
            i--;                 // i 指向前一个数
            swap(numbers, i, j); // 交换两个数
        }
    }
    swap(numbers, i - 1, start); // 将 基准值 与 i 指向的后一位数交换
    return i - 1;                // 返回基准值位置
}

int partition2(std::vector<double> &numbers, int start, int end)
{
    double pivot = numbers[start];
    int i = start;
    for (int j = start + 1; j <= end; ++j)
    {
        if (numbers[j] < pivot)
        {
            i++;
            swap(numbers, i, j);
        }
    }
    swap(numbers, i, start);
    return i;
}

// 以 end 为基准值
int partition3(std::vector<double> &numbers, int start, int end)
{
    double pivot = numbers[end];
    int i = start - 1; // i 是数组中，所有 小于基准值 的 数 中的 最后一个数的索引
                       // 3 2 6 5 8 9 7 假如是经过分区后的结果，那么此时 i = 3，指向 5
    for (int j = start; j < end; ++j)
    {
        if (numbers[j] < pivot) // 当前位置的 数 比 基准值小
        {
            i++;                 // i 指向后一个数
            swap(numbers, i, j); // 交换两个数
        }
    }
    swap(numbers, i + 1, end); // 将 基准值 与 i 指向的后一位数交换
    return i + 1;              // 返回基准值位置
}

int partition4(std::vector<double> &numbers, int start, int end)
{
    double pivot = numbers[end];
    int i = end;
    for (int j = end - 1; j >= 0; --j)
    {
        if (numbers[j] > pivot)
        {
            i--;
            swap(numbers, i, j);
        }
    }
    swap(numbers, i, end);
    return i;
}

void quickSort(std::vector<double> &numbers, int start, int end)
{
    if (start < end)
    {
        int pi = partition1(numbers, start, end); // 分区后 返回基准值索引
        // int pi = partition2(numbers, start, end);
        // int pi = partition3(numbers, start, end);
        // int pi = partition4(numbers, start, end);
        quickSort(numbers, start, pi - 1);
        quickSort(numbers, pi + 1, end);
    }
}
std::vector<double> quickSort1(std::vector<double> &numbers)
{
    quickSort(numbers, 0, numbers.size() - 1);
    return numbers;
}

// 冒泡排序
// 时间复杂度 O(n^2)
void bubbleSort(std::vector<double> &numbers)
{
    size_t n = numbers.size();
    for (size_t i = 0; i < n - 1; ++i)
    {
        for (size_t j = 0; j < n - i - 1; ++j)
        {
            if (numbers[j] > numbers[j + 1])
            {
                swap(numbers, j, j + 1);
            }
        }
    }
}
std::vector<double> bubbleSort1(std::vector<double> &numbers)
{
    bubbleSort(numbers);
    return numbers;
}

int main()
{
    // size_t n = 46;
    // std::cout << "Testing Fibonacci functions:" << std::endl;
    // test_function(std::nullopt, "fb1", fb1, n);
    // test_function(std::nullopt,"fb2", fb2, n);
    // fb1 took 7.04295 seconds and used 4505600 bytes of memory, result = 1836311903
    // fb2 took 6.5e-06 seconds and used 4591616 bytes of memory, result = 1836311903

    // double x = 2.0;
    // int exp = 10;
    // std::cout << "\nTesting Power functions:" << std::endl;
    // test_function("power1", power1, x, exp);
    // test_function("power2", power2, x, exp);
    // power1 took 2e-07 seconds and used 4591616 bytes of memory, result = 1024
    // power2 took 1e-07 seconds and used 4591616 bytes of memory, result = 1024

    std::vector<double> randomNumbers = generateRandomVector(50000);
    std::cout << "\nTesting Sort functions:" << std::endl;
    std::vector<double> randomNumbers1 = randomNumbers;
    std::vector<double> randomNumbers2 = randomNumbers; // 确保一致性
    test_function(false, "quickSort with random numbers", quickSort1, randomNumbers1);
    test_function(false, "bubbleSort with random numbers", bubbleSort1, randomNumbers2);
    // quickSort with random numbers took 1.64331 seconds and used 6582272 bytes of memory
    // bubbleSort with random numbers took 12.3157 seconds and used 6664192 bytes of memory

    return 0;
}

// 测试函数
/**
 * @brief 测量给定函数的执行时间和内存使用情况。
 *
 * @tparam Func 要测量的函数类型。
 * @tparam Args 要传递给函数的参数类型。
 * @param coutResult 是否输出结果的可选参数。
 * @param name 表示被测量函数名称的字符串。
 * @param func 要测量的函数。
 * @param args 要传递给函数的参数。
 *
 * 该函数测量提供的函数执行所需的时间
 * 以及当前进程在执行期间的内存使用情况。它会打印
 * 执行时间（以秒为单位）和内存使用量（以字节为单位）。如果函数有
 * 非void返回类型，它还会打印函数的结果。
 */
template <typename Func, typename... Args>
void test_function(std::optional<bool> coutResult, const std::string &name, Func func, Args... args)
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
    coutResult = coutResult.value_or(true);
    if (coutResult.value()) // ! 如果这里是 if(coutResult) 是检查是否有值，即使是 false， 结果仍然为 true
    {
        if constexpr (!std::is_void_v<decltype(result)>)
        {
            if constexpr (std::is_same_v<decltype(result), std::vector<double>>)
            {
                std::cout << ", " << std::endl
                          << "result = [ ";
                for (const auto &val : result)
                {
                    std::cout << val << " ";
                }
                std::cout << "]";
            }
            else
            {
                std::cout << ", result = " << result;
            }
        }
    }
    std::cout << std::endl;
}

// 随机生成含有 n 个 double 类型的 vector
std::vector<double> generateRandomVector(size_t n)
{
    std::vector<double> numbers(n);
    std::generate(numbers.begin(), numbers.end(), []()
                  { return static_cast<double>(rand()) / RAND_MAX * 100; });
    return numbers;
}