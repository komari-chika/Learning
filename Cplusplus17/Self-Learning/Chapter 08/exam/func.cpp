#include <string>
#include <string_view>
#include <iostream>
#include <limits>
#include <vector>
#include <iomanip>
#include <memory>
#include <optional>
#include <cmath>
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

// test06()
void test06()
{
    // std::cout << "Input grades line by line, and stop with a negetive number" << std::endl;
    // std::vector<double> grades;
    // double grade;
    // while (true)
    // {
    //     std::cin >> grade;
    //     if (std::cin.fail())
    //     {
    //         std::cout << "invalid number" << std::endl;
    //         std::cin.clear();
    //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    //         continue;
    //     }
    //     if (grade < 0)
    //         break;
    //     grades.push_back(grade);
    // }

    // std::vector<double> grades{1, 23, 2, 77, 5, 1, 5, 1};
    // sortGrades(grades, 0, grades.size() - 1);
    // std::array<std::optional<double>, 5> Max{fiveMaxGrade(grades)};
    // std::array<std::optional<double>, 5> Min{fiveMinGrade(grades)};

    std::vector<std::vector<double>> gradess{
        {1, 23, 2, 77, 5, 1, 5, 1},
        {4, 3, 2},
        {}};
    for (auto grades : gradess)
    {
        sortGrades(grades, 0, grades.size() - 1);
        // std::array<std::optional<double>, 5> Max{fiveMaxGrade(grades)};
        // std::array<std::optional<double>, 5> Min{fiveMinGrade(grades)};
        displayVector(grades);
        showNumbers("fiveMaxGrade", fiveMaxGrade(grades));
        showNumbers("fiveMinGrade", fiveMinGrade(grades));
        showNumber("averageGrade", averageGrade(grades));
        showNumber("medianGrade", medianGrade(grades));
        showNumber("standardDeviation", standardDeviation(grades));
        showNumber("variance", variance(grades));
        std::cout << std::endl;
    }
}

void swapGrade(double &a, double &b)
{
    double temp = a;
    a = b;
    b = temp;
}

void sortGrades(std::vector<double> &grades)
{
    sortGrades(grades, 0, grades.size() - 1);
}

void sortGrades(std::vector<double> &grades, int start, int end)
{
    if (start < end)
    {
        double pivot{grades[end]};
        int i{start - 1};
        for (int j{start}; j <= end; ++j)
        {
            if (grades[j] < pivot)
            {
                i++;
                swapGrade(grades[i], grades[j]);
            }
        }

        swapGrade(grades[i + 1], grades[end]);

        if (i > start)
            sortGrades(grades, start, i);
        if (i + 1 < end)
            sortGrades(grades, i + 2, end);
    }
}

std::array<std::optional<double>, 5> fiveMaxGrade(std::vector<double> grades)
{
    std::array<std::optional<double>, 5> Max{};
    size_t length{grades.size()};
    if (length <= 5)
    {
        for (size_t i{}; i < length; ++i)
        {
            Max[i] = grades[i];
        }
    }
    else
    {
        for (size_t i{}; i < 5; ++i)
        {
            Max[i] = grades[length - 5 + i];
        }
    }
    return Max;
}

std::array<std::optional<double>, 5> fiveMinGrade(std::vector<double> grades)
{
    size_t length = (grades.size() <= 5) ? grades.size() : 5;
    std::array<std::optional<double>, 5> Min{};
    for (size_t i{}; i < length; ++i)
    {
        Min[i] = grades[i];
    }
    // 由于 std::array 是默认初始化的
    // 剩余的元素默认已经是 std::nullopt，所以不需要额外处理
    return Min;
}

std::optional<double> averageGrade(std::vector<double> grades)
{
    if (grades.empty())
        return std::nullopt;
    double total;
    for (const auto &grade : grades)
    {
        total += grade;
    }
    return total / grades.size();
}

std::optional<double> medianGrade(std::vector<double> grades)
{
    size_t gradesSize{grades.size()};
    std::optional<double> median{};
    if (gradesSize == 0)
        return std::nullopt;
    if (gradesSize % 2 == 0)
    {
        median = (grades[gradesSize / 2 - 1] + grades[gradesSize / 2]) / 2;
    }
    else
    {
        median = grades[gradesSize / 2];
    }
    return median;
}

std::optional<double> variance(std::vector<double> grades)
{
    if (grades.empty())
        return std::nullopt;
    double avg{averageGrade(grades).value()};
    double total{};
    for (auto grade : grades)
    {
        total += std::pow(grade - avg, 2);
    }
    return total / grades.size();
}

std::optional<double> standardDeviation(std::vector<double> grades)
{
    if (grades.empty())
        return std::nullopt;
    return std::sqrt(variance(grades).value());
}

void displayVector(std::vector<double> numbers)
{
    std::cout << "displayVector : ";
    for (auto number : numbers)
    {
        std::cout << number << " ";
    }
    std::cout << std::endl;
}

void showNumbers(std::string_view description, const std::array<std::optional<double>, 5> &numbers)
{
    std::cout << description << " : ";
    for (auto &number : numbers)
    {
        if (number)
            std::cout << number.value() << ' ';
    }
    std::cout << std::endl;
}

void showNumber(std::string_view description, const std::optional<double> &number)
{
    std::cout << description << " : ";
    if (number)
        std::cout << number.value();
    std::cout << std::endl;
}

// test07()
void test07()
{
    size_t n;

    std::cout << "Enter n: ";
    std::cin >> n;
    Fibonacci1(n);
    std::cout << std::endl;
    Fibonacci2(n);
    std::cout << std::endl;
    std::cout << Fibonacci3(n) << std::endl;
}

unsigned long long Fibonacci1(size_t n)
{
    if (n == 1 || n == 2)
    {
        std::cout << "Fibonacci1(" << n << ") = 1" << std::endl;
        return 1;
    }
    else
    {

        std::cout << "Fibonacci1(" << n << ") = " << "Fibonacci1(" << n - 1 << ") + Fibonacci1(" << n - 2 << ")" << std::endl;
        return Fibonacci1(n - 1) + Fibonacci1(n - 2);
    }
}

unsigned long long Fibonacci2(size_t n)
{
    std::vector<unsigned long long> fb_numbers(n);
    fb_numbers[0] = 1;
    std::cout << "Fibonacci2(1)" << std::endl;
    fb_numbers[1] = 1;
    std::cout << "Fibonacci2(2)" << std::endl;
    for (size_t i{2}; i < n; ++i)
    {
        std::cout << "Fibonacci2(" << i + 1 << ") = " << "Fibonacci2(" << i << ") + Fibonacci2(" << i - 1 << ")" << std::endl;
        fb_numbers[i] = fb_numbers[i - 1] + fb_numbers[i - 2];
    }
    return fb_numbers[n - 1];
}

unsigned long long Fibonacci3(size_t n)
{
    unsigned long long fb_1{1};
    unsigned long long fb_2{1};
    unsigned long long fb_n_2{fb_1}, fb_n_1{fb_2}, fb_n{fb_1};
    for (size_t i{2}; i < n; ++i)
    {
        fb_n = fb_n_2 + fb_n_1;
        fb_n_2 = fb_n_1;
        fb_n_1 = fb_n;
    }
    return fb_n;
}

// test08()
void test08()
{
    double x;
    int n;
    std::cout << "Input double(x) and int(n):" << std::endl;
    std::cin >> x >> n;
    std::cout << "power1(" << x << ", " << n << ") = " << power1(x, n) << std::endl;
    std::cout << "power2(" << x << ", " << n << ") = " << power2(x, n) << std::endl;
}

double power1(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return x * power1(x, n - 1);
    else
        return 1 / power1(x, -n);
}

double power2(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 1 / power2(x, -n);
    else
    {
        double half = power2(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else
            return x * half * half;
    }
}

// test09()
void test09()
{
    double x;
    int n;
    std::cout << "Input double(x) and int(n):" << std::endl;
    std::cin >> x >> n;

    std::cout << "power3(x, n) : " << std::endl;
    power3(x, n);
    std::cout << "power4(x, n) : " << std::endl;
    power4(x, n);
}

double power3(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n > 0)
        return mult3(x, power3(x, n - 1));
    else
        return 1 / power3(x, -n);
}

double power4(double x, int n)
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 1 / power4(x, -n);
    else
    {
        double half = power4(x, n / 2);
        if (n % 2 == 0)
            return mult4(half, half);
        else
            return mult4(x, mult4(half, half));
    }
}

double mult3(double num1, double num2)
{
    static size_t mult_count3{};
    mult_count3++;
    std::cout << "power3() already use " << mult_count3 << " times multiply." << std::endl;
    return num1 * num2;
}

double mult4(double num1, double num2)
{
    static size_t mult_count4{};
    mult_count4++;
    std::cout << "power4() already use " << mult_count4 << " times multiply." << std::endl;
    return num1 * num2;
}