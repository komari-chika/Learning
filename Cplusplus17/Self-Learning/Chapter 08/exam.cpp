#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <string_view>
#include <limits>
/*
1. 编写一个函数 validate_input()，它接收两个整数参数，表示要输入的整数的上下限。
它还应接收第三个参数，该参数是描述输入的字符串，用于在提示用户输入时使用。
该函数应提示输入的值应在前两个参数指定的范围之内，并包含标识输入值类型的字符串。
该函数应检查输入并一直提示用户输入值，直到输入的值有效为止。
在程序中使用 validate_input()函数，获取用户的生日并以下面的格式输出：
例如：November 21, 2012

程序应实现为由单独的函数 month()、year() 和 day() 管理相应数值的输入。
不要忘记闰年——2017年2月29日是不允许输入的！
*/
void test01();
int validate_input(int lower, int upper, std::string_view input_type);
int year();
int month();
int date(int year, int month);

/*
2.编写一个函数,要求读取字符串或字符数组作为输入,并反转它的顺序。使用什么类型的参数最好?
用main()函数测试该函数，提示用户输入一个字符串，反转其顺序，再输出反转后的字符串。
*/
void test02();

/*
3.编写一个程序，它接收 2~4 个命令行实参。如果用少于2个或多于4个的实参调用该程序，就输出一条消息，告诉用户应怎么做，然后退出。如果实参的个数是正确的，就输出它们，一行输出一个参数。
*/
void test03();

int main()
{
    size_t number = 1;

    // 创建函数指针数组
    void (*testFunctions[])() = {test01, test02, test03};

    // 检查number是否在有效范围内
    if (number > 0 && number <= sizeof(testFunctions) / sizeof(testFunctions[0]))
    {
        // 调用相应的测试函数
        testFunctions[number - 1]();
    }
    return 0;
}

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
