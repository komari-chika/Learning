#include <iostream>
#include <bitset> ///c++中控制进制的头文件

int main()
{
    // 字面量 - 任何类型的常量
    // 1. 整形字面量
    // 不同进制的前后缀，并且一般不加后缀
    // 2进制 0B/0b     [ ][U][L/LL]
    unsigned int code{0B100010011U};
    std::cout << code << std::endl; // 这里使用了bitset类来输出2进制数据

    // 8进制 0          [ ][U][L/LL]   oct
    unsigned int length{032U};
    std::cout << std::oct << length << std::endl;

    // 10进制 无/+/-   [ ][U][L/LL]  dec
    // 不能使用逗号，可以使用单引号，便于识别
    unsigned long long distance{10'000'00ULL};
    std::cout << std::dec << distance << std::endl;

    // 16进制 0X/0x  [ ][U][L/LL]   hex
    unsigned int color{0x39C5BBU};
    std::cout << std::hex << color << std::endl;
}