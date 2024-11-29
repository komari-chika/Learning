#include <iostream>
#include <array>
#include <vector>
#include <cmath>
#include <iomanip>
// test 1
void test_1(int n)
{
    int i{1};
    while (i <= n)
    {
        if (i % 2 != 0)
        {
            std::cout << i << "^2 = " << pow(i, 2) << std::endl;
        }
        ++i;
    }
}

void test_2()
{
    std::cout << "Enter numbers to calculate sum and average (enter 'Y' to stop): " << std::endl;

    int number{};
    int sum{};
    int count{};
    float avg{};

    while (true)
    {
        std::cout << "Enter number: ";
        std::cin >> number;
        sum += number;
        ++count;

        char choice{};
        std::cout << "Stop? (Y/N): ";

        while (std::cin >> choice)
        {
            if (std::isalpha(choice))
            {
                choice = std::toupper(choice); // 转为大写，避免大小写问题
                if (choice == 'Y' || choice == 'N')
                    break;
            }
            std::cout << "Invalid input. Please enter 'Y' or 'N': ";
        }

        if (choice == 'Y')
        {
            break;
        }
    }

    if (count > 0) // 避免除以零的情况
    {
        avg = static_cast<float>(sum) / count;
    }

    std::cout << "Sum = " << sum << std::endl
              << "Average = " << avg << std::endl;
}

void test_3()
{
    std::cout << "Enter a line of words (end with '#'): " << std::endl;
    unsigned count{};
    char ch{};
    do
    {
        std::cin >> ch;
        ++count;
    } while (ch != '#');
    --count;
    std::cout << "The input has " << count << " non-space characters." << std::endl;
}

void test_4()
{
    std::cout << "input string" << std::endl;
    size_t count{};
    const size_t max_input{1000};
    char input_string[max_input];
    std::cin.getline(input_string, max_input);
    for (size_t i{}; i < max_input && input_string[i] != '\0'; ++i)
    {
        ++count;
    }
    std::cout << count << std::endl;

    // for (size_t i{count - 1}; i >= 0; --i)
    // {
    //     std::cout << input_string[i];
    // } 这是错误的！！size_t 是无符号的，所以这个循环永远为真
    //   可以给 i 加上 static_cast<signed>
    for (size_t i = count; i > 0; --i)
    {
        std::cout << input_string[i - 1];
    }
}

void test_5()
{
    std::cout << "input string" << std::endl;
    size_t count{0};
    const size_t max_input{1000};
    char input_string[max_input];
    std::cin.getline(input_string, max_input);

    while (input_string[count] != '\0')
    {
        count++;
    }
    size_t left{0};
    size_t right{static_cast<int>(count) - 1};
    while (right >= 0 && left < right)
    {
        char temp = input_string[left];
        input_string[left++] = input_string[right];
        input_string[right--] = temp;
    }
    size_t i{0};
    while (input_string[i] != '\0')
    {
        std::cout << input_string[i];
        ++i;
    }

    // while(input_string[]){

    // }
}

void test_6()
{
    std::vector<int> input_number;
    std::cout << "input max_number" << std::endl;
    int number{};
    std::cin >> number;
    for (int i{1}; i <= number; ++i)
    {
        input_number.push_back(i);
    }
    size_t size = input_number.size();
    size_t cout_count{0};
    // for (size_t i{0}; i < input_number.size(); ++i)
    // {
    //     int i_number = input_number.at(i);
    //     if (i_number % 7 == 0 && i_number % 3 == 0)
    //     {
    //         continue;
    //     }
    //     std::cout << std::setw(6) << i_number;
    //     cout_count++;
    //     if (cout_count % 10 == 0)
    //     {
    //         std::cout << std::endl;
    //     }
    // }
    for (auto value : input_number)
    {
        if (value % 7 == 0 || value % 3 == 0)
            continue;
        std::cout << std::setw(6) << value;
        if (++cout_count % 10 == 0)
            std::cout << std::endl;
    }
}

void test_7()
{

    std::vector<unsigned> product_ids;
    std::vector<size_t> product_numbers;
    std::vector<float> product_prices;

    while (true)
    {
        std::cout << "show table , enter product information or QUIT? (S/E/Q)" << std::endl;
        char choice{};
        while (true)
        {
            std::cin >> choice;
            if (!std::isalpha(choice))
                std::cout << "Invaild Input!" << std::endl;
            else if (std::toupper(choice) != 'Q' && std::toupper(choice) != 'S' && std::toupper(choice) != 'E')
                std::cout << "Invaild Input!" << std::endl;
            else
                break;
        }

        char Big_choice = std::toupper(choice);
        if (Big_choice == 'Q')
            break;
        else if (Big_choice == 'S')
        {
            // 打印表头
            std::cout << std::setw(10) << "Product"
                      << std::setw(12) << "Quantity"
                      << std::setw(15) << "Unit Price"
                      << std::setw(15) << "Cost"
                      << std::endl;

            double total_cost = 0; // 总计成本

            // 输出每个产品信息
            for (size_t i = 0; i < product_ids.size(); ++i)
            {
                double cost = product_numbers[i] * product_prices[i];
                total_cost += cost;

                // 按照对齐规则输出每行数据
                std::cout << std::setw(10) << product_ids[i]
                          << std::setw(12) << product_numbers[i]
                          << std::setw(10) << "$" << std::fixed << std::setprecision(2)
                          << std::setw(5) << product_prices[i]
                          << std::setw(10) << "$" << std::setw(5) << cost
                          << std::endl;
            }

            // 输出总计
            std::cout << std::setw(40) << "Total Cost: "
                      << std::setw(5) << "$" << std::fixed << std::setprecision(2)
                      << total_cost << std::endl;
        }
        else if (Big_choice == 'E')
        {
            unsigned product_id{};
            size_t product_number{};
            float product_price{};
            std::cout << "enter product_id: " << std::endl;
            std::cin >> product_id;
            product_ids.push_back(product_id);

            std::cout << "enter product_number: " << std::endl;
            std::cin >> product_number;
            product_numbers.push_back(product_number);

            std::cout << "enter product_price: " << std::endl;
            std::cin >> product_price;
            product_prices.push_back(product_price);
        }
        else
        {
            std::cout << "unknown error" << std::endl;
        }
    }
}

void test_8()
{
    const size_t max_fb{93};
    using ULL = unsigned long long;
    std::array<ULL, max_fb> Fb{};
    Fb.fill(0);
    ULL first{1};
    ULL second{1};
    Fb[0] = first;
    Fb[1] = second;
    size_t count{2};
    while (Fb[max_fb - 1] == 0)
    {
        Fb[count] = Fb[count - 1] + Fb[count - 2];
        count++;
    }
    for (auto fb_number : Fb)
    {
        std::cout << std::right <<std::setw(20) << fb_number << std::endl;
    }
}

int main()
{
    // {
    //     int n{};
    //     std::cout << "Test 1: enter N" << std::endl;
    //     std::cin >> n;
    //     test_1(n);
    // }

    // test_2();

    // test_3();

    // test_4();

    // test_5();

    // test_6();

    // test_7();

    test_8();

    return 0;
}