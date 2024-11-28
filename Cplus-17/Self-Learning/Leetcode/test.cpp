#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;

void test_01()
{
    double a;
    std::cin >> a;
    double answer{a};
    double last_answer{a};
    double wucha{0.00001};
    if (a == 0)
        std::cout << "0" << std::endl;
    else
    {
        do
        {
            last_answer = answer;
            answer = (last_answer + a / last_answer) / 2;
            // std::cout << abs(last_answer - answer) << std::endl;
        } while (abs(last_answer - answer) >= wucha);
        std::cout << std::fixed << std::setprecision(3) << answer << std::endl;
    }
}

void test_02()
{
    size_t answer{};
    // std::vector<size_t> numbers;
    int n{};
    std::cin >> n;
    for (size_t i{1}; i <= n; ++i)
    {
        size_t number{i};
        bool greatnumber{true};
        bool odd{true};
        while (number != 0)
        {
            if ((odd && number % 2 == 0) || (!odd && number % 2 == 1)) // 奇数位为偶数，偶数位为奇数，则不符合要求
            {
                greatnumber = false;
                break;
            }
            odd = !odd;
            number /= 10;
        }
        if (greatnumber)
        {
            answer++;
            // numbers.push_back(i);
        }
    }
    // std::cout << numbers.size() << std::endl;
    std::cout << answer << std::endl;
}

namespace test03
{
    template <typename T>
    std::vector<T> inputNumber(const size_t maxlength)
    {
        T number;
        std::vector<T> numbers;
        size_t count{};
        while (count < maxlength)
        {
            std::cin >> number;
            numbers.push_back(number);
            count++;
        }
        return numbers;
    }

    template <typename T>
    void swapTwoNumber(std::vector<T> &numbers, size_t first_index, size_t second_index)
    {
        T temp = numbers[first_index];
        numbers[first_index] = numbers[second_index];
        numbers[second_index] = temp;
    }

    template <typename T>
    void displayNumbers(const std::vector<T> &numbers)
    {
        for (auto number : numbers)
        {
            std::cout << number << std::endl;
        }
    }

    template <typename T>
    void sort(std::vector<T> &numbers, size_t start, size_t end)
    {
        if (start >= end)
            return;
        size_t mid = start + (end - start) / 2;
        T pivot = numbers[start]; // 基准值
        size_t p_low{start + 1}, p_high{end};
        while (p_low <= p_high)
        {
            while (p_low <= p_high && numbers[p_low] <= pivot)
                ++p_low;
            while (p_low <= p_high && numbers[p_high] > pivot)
                --p_high;
            if (p_low < p_high)
                swapTwoNumber(numbers, p_low, p_high);
        }
        swapTwoNumber(numbers, start, p_high);
        // 递归处理分区
        if (p_high > 0) // 避免 size_t underflow
            sort(numbers, start, p_high - 1);
        sort(numbers, p_high + 1, end);
    }

    template <typename T>
    void sort(const size_t maxlength)
    {
        std::vector<T> numbers = inputNumber<T>(maxlength);
        sort(numbers, 0, numbers.size() - 1);
        displayNumbers<T>(numbers);
    }
} 

int main()
{
    test03::sort<size_t>(10);
}
