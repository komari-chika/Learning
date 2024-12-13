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

/*
Exercise 8-7.
The so-called Fibonacci function is popular among lecturers in computer science and mathematics for introducing recursion. This function has to compute the nth number from the famous Fibonacci sequence, named after ltalian mathematician Leonardo of Pisa, known also as Fibonacci.This sequence of positive integer numbers is characterized by the fact that every number after the first two is the sum of the two preceding ones.

For n > 1, the sequence is defined as follows:
1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181...
! For convenience, computer scientists mostly define an additional zeroth Fibonacci number as zero.
! Write a function to compute the nth Fibonacci number recursively. Test it with a simple program that prompts the user for how many numbers should be computed and then prints them out one by one, each on a different line.

Extra: While the naive recursive version of the Fibonacci function is very elegant-the code matches nearly verbatim with common mathematical definitions it is notorious for being very slow. lf you ask the computer to compute, say, 100 Fibonacci numbers. you'll notice that it becomes noticeably slower and slower as n becomes larger. Do you think you can rewrite the function to use a loop instead of recursion? How many numbers can you correctly compute now?

Hint: in each iteration of the loop, you'll naturally want to compute a next number. To do this, all you need are the previous two numbers. So, there should be no need to keep track of the full sequence in, for instance, a vector<>.
*/
void test07();
unsigned long long Fibonacci1(size_t n);
unsigned long long Fibonacci2(size_t n);
unsigned long long Fibonacci3(size_t n);

/*
Exercise 8-8.
lf written using a more mathematical notation, the power() functions we wrote in Ex8_01 and especially Ex8 17 both essentially compute a power(x,n) for n > 0, as follows:
power(x,n) = x * power(x, n - 1)
           = x * (x * power(x, n - 2))
           = x * (x * (x * ...(x * x)...)))

Clearly, this method reguires exactly n - 1 multiplications. lt may surprise you, but there is another, much more effective way. Suppose n is even; then you know the following:
power(x, n) = power(x, n / 2) * power(x, n / 2)
As both operands of this multiplication are identical, you need to compute this value only once. That is, you have just reduced the computation of power(x, n) to that of power(x, n / 2), which obviously at most requires half as many multiplications. 
Moreover, because you can now apply this formula recursively, you'll need even far fewer multiplications than that only something in the order of log2(n) to be exact.
To give you an idea, this means that for n in the order of 1000, you only need in the order of 10 multiplications! Can you apply this idea to create a more efficient recursive version of power()? 
You can start from the program in Ex8_17.cpp.
Note: This principle is something you'll often see in recursive algorithms. In each recursive call, you reduce a problem to a problem of half the size. lf you think back, you'll realize that we applied the same principle in the quicksort algorithm as well. for instance. Because this solution strategy is that common, it also has a name; it's called divide and conquer, after the famous phrase of Julius Caesar.
*/
void test08();
double power1(double x, int n);
double power2(double x, int n);


/*
Exercise 8-9. 
Modify the solution of Exercise 8-8 such that it counts the number of times the call power(1.5,1000) performs a multiplication. 
Do so by replacing each multiplication with a helper function mult() that takes two arquments, prints a message of how many multiplications have been performed thus far, and then simply returns the product of both arguments. 
Use at least one static variable.
*/
void test09();
double power3(double x, int n);
double power4(double x, int n);
double mult3(double num1, double num2);
double mult4(double num1, double num2);
#endif // HEADER_FILENAME_H