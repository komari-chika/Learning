#include <string>
#include <string_view>
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include "exam.h"
// test01
void test01()
{
    const std::string months[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    while (1)
    {
        int input_year = year();
        int input_month = month();
        int input_date = date(input_year, input_month);

        std::cout << months[input_month - 1] << " " << input_date << ", " << input_year << std::endl;
    }
}

int validate_input(int lower, int upper, std::string_view input_type)
{
    int input;
    std::cout << "请输入" << input_type << ": [" << lower << ", " << upper << "]" << std::endl;
    while (!(std::cin >> input) || input < lower || input > upper)
    {
        std::cin.clear();                                                   // clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore invalid input
        std::cout << "无效输入，请输入" << input_type << ": [" << lower << ", " << upper << "]" << std::endl;
    }
    return input;
}

int year()
{
    const unsigned short low_year{1900};
    const unsigned short high_year{2024};
    return validate_input(low_year, high_year, "year");
}

int month()
{
    int low_month{1};
    int high_month{12};
    return validate_input(low_month, high_month, "month");
}

int date(int year, int month)
{
    // Days in month:               Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec
    const int month_max_date[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int low_date = 1;
    int high_date = month_max_date[month - 1];
    int fb{2};
    // Check for leap year if the month is February
    if (month == fb)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            high_date = 29;
        }
    }
    return validate_input(low_date, high_date, "date");
}

// test02()
void test02()
{
    std::cout << "input a string and end with '#' : " << std::endl;
    std::string input_string;
    std::getline(std::cin, input_string, '#');
    std::cout << reverseInput(input_string) << std::endl;

    char c_str[]{"abcdefg"}; // C-style string
    std::cout << reverseInput(c_str) << std::endl;

    std::cout << reverseInput("dawdfgaw") << std::endl;
}

std::string reverseInput(std::string_view input_string)
{
    std::string input_string_copy{input_string};
    size_t left{}, right{input_string.length() - 1};
    while (left < right)
    {
        char temp = input_string[left];
        input_string_copy[left] = input_string[right];
        input_string_copy[right] = temp; // swap
        left++;
        right--;
    }
    return input_string_copy;
}

// test03()
void test03(int argc, char *argv[])
{
    if (argc < 3 || argc > 5)
    {
        std::cout << "参数的数量需要在 [2,4] 之间" << std::endl;
        return;
    }
    else
    {
        for (size_t i{1}; i < argc; ++i)
        {
            std::cout << argv[i] << " ";
        }
        std::cout << std::endl;
    }
}

// test04()
void test04()
{
    const int n{plus(3, 4)};
    const double d{plus(3.2, 4.2)};
    const std::string s{plus("he", "llo")};
    const std::string s1{"aaa"};
    const std::string s2{"bbb"};
    const std::string s3{plus(s1, s2)};
    // const auto d {plus(3,4.2)};
    std::cout << "plus(3, 4) returns " << n << std::endl;
    std::cout << "plus(3.2, 4.2) returns " << d << std::endl;
    std::cout << "plus(\"he\", \"llo\") returns " << s << std::endl;
    std::cout << "With s1 as \"" << s1 << "\" and s2 as \"" << s2 << "\"" << std::endl;
    std::cout << "plus(s1, s2) returns " << s3 << std::endl;
}
inline int plus(const int a, const int b)
{
    return a + b;
}
inline double plus(const double a, const double b)
{
    return a + b;
}
// const std::string plus(const std::string a, const std::string b)
// {
//     return a + b;
// }
inline std::string plus(std::string_view a, std::string_view b)
{
    // return s1 + s2; does not compile in this case,
    // because there is no addition operator (+) for string_view.
    // Therefore, you first have to turn the operands into std::strings...
    return std::string{a} + std::string{b};
}

// test05()
void test05()
{

    size_t max_number;
    const size_t newline{15};
    const size_t max_Width{6};
    while (1)
    {
        std::cout << "Input a natural number greater than 1" << std::endl;
        std::cin >> max_number;
        std::vector<size_t> numbers{findAllPrime(generateNumbers(max_number))};
        std::cout << "All prime numbers lower than " << max_number << " : " << std::endl;
        for (size_t i{}; i < numbers.size(); ++i)
        {
            std::cout << std::setw(max_Width) << numbers[i] << " ";
            if ((i + 1) % newline == 0)
                std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

bool checkIsPrime(size_t n)
{
    bool result{true};
    if (n <= 1)
    {
        result = false;
    }
    else if (n == 2)
    {
        result = true;
    }
    else if (n % 2 == 0)
    {
        result = false;
    }
    else
    {
        for (size_t i{3}; i * i <= n; i += 2)
        {
            if (n % i == 0)
            {
                result = false;
                break;
            }
        }
    }
    return result;
}

std::vector<size_t> generateNumbers(size_t max_number, size_t start_number)
{
    size_t length;
    if (max_number < start_number)
        length = 0;
    else
        length = max_number - start_number + 1;
    std::vector<size_t> numbers(length);
    for (size_t i{}; i < length; ++i)
    {
        numbers[i] = start_number + i;
    }
    return numbers;
}

std::vector<size_t> findAllPrime(std::vector<size_t> input_numbers)
{
    std::vector<size_t> output_numbers;
    for (auto number : input_numbers)
    {
        if (checkIsPrime(number))
            output_numbers.push_back(number);
    }
    return output_numbers;
}