#include <iostream>
#include <vector>
#include <array>
#include <memory>
#include <iomanip>
#include <cctype>
#include <cmath>
void test_1()
{
    const size_t maxCount{50};
    int Odds[maxCount]{};
    int *pOdds{Odds};
    for (size_t i{}; i < maxCount; ++i)
    {
        Odds[i] = 2 * i + 1;
    }
    for (size_t i{}; i < maxCount; ++i)
    {
        std::cout << std::setw(3) << *(Odds + i) << " ";
        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
    for (size_t i{maxCount - 1}; static_cast<int>(i) >= 0; --i)
    {
        std::cout << std::setw(3) << *(Odds + i) << " ";
        if (i % 10 == 0) // 这里不需要 + 1
            std::cout << std::endl;
    }
}

void test_2()
{
    const size_t maxCount{50};
    int Odds[maxCount]{};
    int *pOdds{Odds};

    /*
    for (size_t i{}; i < maxCount; ++i) // 赋值
    {
        *(pOdds + i) = 2 * i + 1;
    }
    for (size_t i{}; i < maxCount; ++i) // 正向输出
    {
        std::cout << std::setw(3) << *pOdds++ << " "; // 这里是先输出 *pOdds 的值，然后 pOdds 再自增
        // 也可以写作：
        // std::cout << std::setw(3) << *pOdds << " ";
        // pOdds++;
        if ((1 + i) % 10 == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
    pOdds--; // 在上次循环已经越位
    for (size_t i{}; i < maxCount; ++i) // 逆向输出
    {
        std::cout << std::setw(3) << *pOdds-- << " "; // 这里是先输出 *pOdds 的值，然后 pOdds 再自减
        if ((1 + i) % 10 == 0)
            std::cout << std::endl;
    }

    */

    // 也可以使用while
    // /*
    size_t count{0};
    while (pOdds < Odds + maxCount)
    {
        *pOdds++ = 2 * count++ + 1;
    }
    pOdds = pOdds - maxCount; // 回退到最初的位置
    count = 0;
    while (pOdds < Odds + maxCount) // 指针比较
    {
        std::cout << std::setw(3) << *pOdds++ << " ";
        if ((1 + count) % 10 == 0)
            std::cout << std::endl;
        count++;
    }
    std::cout << std::endl;
    pOdds--; // 在上次循环已经越位
    count = 0;
    while (pOdds >= Odds) // 指针比较
    {
        std::cout << std::setw(3) << *pOdds-- << " ";
        if ((1 + count) % 10 == 0)
            std::cout << std::endl;
        count++;
    }
    // */
}

void test_3()
{
    size_t n{};
    std::cout << "输入整数 n: ";
    std::cin >> n;
    // double* numbers{new double[n]};
    auto numbers{new double[n]};
    for (size_t i{}; i < n; ++i)
    {
        *(numbers + i) = 1 / pow((i + 1), 2);
        // std::cout << *(numbers + i) << std::endl;
    }
    double total{};
    for (size_t i{}; i < n; ++i)
    {
        total += *(numbers + i);
    }
    std::cout << std::setprecision(15) << sqrt(total * 6) << std::endl; // 不要忘记增加位数
    delete[] numbers;
}

void test_4()
{
    size_t n{};
    std::cout << "输入整数 n: ";
    std::cin >> n;
    auto *numbers{new std::vector<double>(n)};

    for (size_t i{}; i < n; ++i)
    {
        // numbers->push_back(1 / pow((i + 1), 2));  // 错误!!!，number已经动态分配了大小为 n 的内存，不应该使用push_back，而是直接通过下标访问
        numbers->at(i) = 1 / pow((i + 1), 2);
    }
    double total{};
    for (size_t i{}; i < n; ++i)
    {
        total += numbers->at(i);
    }

    // for (size_t i{}; i < n; ++i)
    // {
    //     (*numbers)[i] = 1 / pow((i + 1), 2);
    // }
    // double total{};
    // for (auto number : *numbers)
    // {
    //     total += number;
    // }
    std::cout << std::setprecision(15) << sqrt(total * 6) << std::endl; // 不要忘记增加位数
    delete numbers;
}

void test_5()
{
    size_t n{};
    std::cout << "输入整数 n: ";
    std::cin >> n;
    auto pnumber{std::make_shared<std::vector<double>>(n)};

    for (size_t i{}; i < n; ++i)
    {

        pnumber->at(i) = 1 / pow((i + 1), 2);
    }
    double total{};
    for (size_t i{}; i < n; ++i)
    {
        total += pnumber->at(i);
    }
    std::cout << std::setprecision(15) << sqrt(total * 6) << std::endl; // 不要忘记增加位数
}

void test_6()
{
    // 同 5
}

int main()
{
    // test_1();
    // test_2();
    // test_3();
    // test_4();
    test_5();
    // test_6();

    return 0;
}
