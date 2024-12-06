#ifndef EXAM_H // 检查宏是否未定义
#define EXAM_H // 定义宏

#include <string>
#include <vector>
#include <string_view>
#include <array>
#include <optional>

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
2.编写一个函数，要求读取字符串或字符数组作为输入，并反转它的顺序。使用什么类型的参数最好?
用 main() 函数测试该函数，提示用户输入一个字符串，反转其顺序，再输出反转后的字符串。
*/
void test02();
std::string reverseInput(std::string_view input);

/*
3.编写一个程序，它接收 2~4 个命令行实参。如果用少于2个或多于4个的实参调用该程序，就输出一条消息，告诉用户应怎么做，然后退出。如果实参的个数是正确的，就输出它们，一行输出一个参数。
*/
void test03(int argc, char *argv[]);

/*
Exercise 8-4.
Create a function, plus(), that adds two values and returns their sum.
Provide overloaded versions to work with int, double, and strings, and test that they
work with the following calls:
const int n {plus(3,4)};
const double d {plus(3.2,4.2)};
const string s {plus("he","llo")};
const string s1 {"aaa"};
const string s2 {"bbb"};
const string s3 {plus(s1, s2)};

Can you explain why the following doesn't work?
const auto d {plus(3, 4.2)};
  ! This won't compile because there is more than one overloaded plus() function for the arguments.
  ! The compiler will not choose so there must be a unique match with a function signature.
*/
void test04();
int plus(const int a, const int b);
double plus(const double a, const double b);
std::string plus(std::string_view a, std::string_view b);

/*
Exercise 8-5.
Define a function that checks whether a given number is prime(质数).
Your primal check does not have to be efficient; any algorithm you can think of will do.
In case you have forgotten,
! a prime number is a natural number strictly greater than 1 and
! with no positive divisors other than 1 and itself.
Write another function that generates a vector<> with all natural numbers less or equal to a first number and starting from another. By default it should start from 1.
Create a third function that given a vector<> of numbers outputs another vector<> containing all the prime numbers it found in its input.

Use these three functions to create a program that prints out all prime numbers less or equal to a number chosen by the user (print, for instance. 15 primes per line).
Note: in principle, you do not need any vectors to print these prime numbers; obviously, these extra functions have been added for the sake of the exercise.
*/
void test05();
bool checkIsPrime(size_t n);
std::vector<size_t> generateNumbers(size_t max_number, size_t start_number = 1);
std::vector<size_t> findAllPrime(std::vector<size_t> input_numbers);

void test06();
void swapGrade(double &a, double &b);
void sortGrades(std::vector<double> &grades);
void sortGrades(std::vector<double> &grades, int start, int end);
std::array<std::optional<double>, 5> fiveMaxGrade(std::vector<double> grades);
std::array<std::optional<double>, 5> fiveMinGrade(std::vector<double> grades);
std::optional<double> averageGrade(std::vector<double> grades);
std::optional<double> medianGrade(std::vector<double> grades);
std::optional<double> standardDeviation(std::vector<double> grades);
std::optional<double> variance(std::vector<double> grades);
void displayVector(std::vector<double> numbers);
void showNumbers(std::string_view description, const std::array<std::optional<double>, 5> &numbers);
void showNumber(std::string_view description, const std::optional<double> &number);
#endif // HEADER_FILENAME_H