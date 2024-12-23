#pragma once
#define DEBUG 1
#include<string_view>
/*
Exercise 9-1.
In C++ 17, the Standard Library algorithm header gained the handy std::clamp() function template.
The expression clamp(a,b,c) is used to clamp the value a to a given closed interval [b, c].
That is, if a is less than b, the result of the expression will be b; and if a is greater than c, the result will be c; otherwise, if a lies within the interval [b, c],clamp() simply returns a.
Write your own my clamp() function template and try it with a little test program.
*/
void Ex9_1();
template <typename T>
T clamp(T a, T b, T c);

template <typename T>
T clamp(T a, T b, T c)
{
    if (a < b)
        return b;
    else if (a > c)
        return c;
    else
        return a;
}

/*
Exercise 9-2.
Alter the last lines of Ex9_01's main() function as follows.

/------------------------------------Ex9_01.cpp------------------------------------/
#include <iostream>
#include <string>

template <typename T>
T larger(T a, T b); // Function template prototype

int main()
{
    std::cout << "Larger of 1.5 and 2.5 is " << larger(1.5, 2.5) << std::endl;
    std::cout << "Larger of 3.5 and 4.5 is " << larger(3.5, 4.5) << std::endl;

    int big_int{17011983}, small_int{10};
    std::cout << "Larger of " << big_int << " and " << small_int << " is "
              << larger(big_int, small_int) << std::endl;

    ! CHANGE HERE !  
    std::string a_string{"A"}, z_string{"Z"};
    std::cout << "Larger of \"" << a_string << "\" and \"" << z_string << "\" is "
              << '"' << larger(a_string, z_string) << '"' << std::endl;
    ! CHANGE HERE !
}

template <typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}
/--------------------------------------------------------------------/


! /-------------CHANGE-------------/
const auto a_string = "A", z_string = "Z";
std::cout << "Larger of " << a_string << " and "
          << z_string << " is "
          << larger(a_string, z_string)
          << std::endl;
! /----------------------------/


! If you now run the program, you may very well get the following output 
(if not, try rearranging the order in which a_string and z_string are declared):

Larger of 1.5 and 2.5 is 2.5
Larger of 3.5 and 4.5 is 4.5
Larger of 17011983 and 10 is 17011983
Larger of A and Z is A

! What's that? "A" is larger than "z"? Can you explain exactly what went wrong? Can you fix it?

Hint: To compare two character arrays, you could perhaps first convert them to another
string representation.!
*/
void Ex9_2();
template<typename T>
T larger(T a, T b);

#if DEBUG == 0
template<typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}
#elif DEBUG
template<typename T>
T larger(T a, T b)
{
    return a > b ? a : b;
}

template<>
const char* larger(const char* a, const char* b)
{
    
    std::string aa{a};
    std::string bb{b};
    if(aa > bb) return a;
    else return b;
    // 也可以使用 <cstring> 头文件中的 strcmp() 函数
    // std::strcmp(a, b) 会逐个字符比较 a 和 b，并返回一个值。
    // 如果 a 的字典顺序大于 b，则返回大于零的值
    // return std::strcmp(a, b) > 0 ? a : b;
}

#endif