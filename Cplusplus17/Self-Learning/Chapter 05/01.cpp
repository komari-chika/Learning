#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::setw;

int main()
{

    // 数组定义
    double temperatures[366];
    temperatures[3] = 99.0;

    unsigned int height[6];

    unsigned int height1[6]{26, 37, 47, 55, 62, 75}; // 初始化，未初始化的值为0，bool类型为false

    // size_t 是 C++ 中的一种无符号整数类型
    // 通常用于计数或者大小，全名是 "size type"
    for (size_t i{0}; i < 6; ++i)
    {
        // cout << height1[i] << endl;
        height[i] = height1[i];
    }

    // 避免幻数
    // 使用常量 const
    const size_t size{12};
    double rainfall[size]{1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
    double copy[size]{};

    for (size_t i{0}; i < size; ++i)
    {
        copy[i] = rainfall[i];
    }

    // 确定数组的大小
    // 1. std::size 更优先用
    // 2. sizeof(array)/sizeof(array[0])
    // cout << std::size(rainfall) << endl;
    // cout << sizeof(rainfall)/sizeof(rainfall[0]) << endl;

    // for (size_t i{}; i < std::size(rainfall); ++i)
    // {
    //     cout << rainfall[i] << endl;
    // }

    // 浮点数控制 for 循环
    // for (double radius{2.5}; radius <= 20; radius += 2.5)
    // {
    // }

    // 逗号运算符
    // 逗号运算符的语法形式是 expr1, expr2，其中 expr1 和 expr2 是两个表达式。
    // 逗号运算符会依次计算 expr1 和 expr2，并返回 expr2 的值
    // int i{1};
    // int value1{1};
    // int value2{1};
    // int value3{1};
    // cout << (value1 += ++i, value2 += ++i, value3 += ++i) << endl;
    // value1 =
    // 输出为 5 ， 复合表达式的值是 这一复合系列最右边的表达式的值，即 value3 的值
    // 把运算符结合到for循环
    // cout << setw(8) << "n" << setw(8) << "sum" << setw(12) << "fb" << endl;
    // for (unsigned long long n{1}, sum{1}, fb{1}; n <= 10; ++n, sum += n, fb *= n)
    // {

    //     cout << setw(8) << n << setw(8) << sum << setw(12) << fb << endl;
    // }

    // 基于范围的 for 循环
    // for (range_declaration : range_expression)
    // range_declaration 标识了一个变量，会被赋予范围中的每一个值，并且在每次迭代后被赋予新的值
    // range_expression 表示数据源的范围
    // 同时可以使用 auto 让编译器推断 x 的正确类型
    // int values[10]{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    // int total{10};
    // for (auto x : values)
    // {
    //     cout << x << endl;
    // }
    // 注意，x 只是被赋予值，修改 x 并不会修改 values 中的值

    // do-while 用于需要进行提前检查的情况
    // 同时 do-while 要求在语句后加上 ;
    // 注意，while 不需要 ；
    // do{
    //     body
    // }while(condition);

    // while(condition){

    // }

    // 跳过循环
    // 1. continue 开始下一次循环
    // 2. break 结束当前循环

    // 无符号数做循环上限时应当注意，0被减去1后会变成很大的数
    // unsigned count{0}；
    // for (size_t i = 0; i < count - 1; ++i)
    // {
    //     /* code */
    // }
    // 修改方案
    // 1. 进行循环前检查 count 是否为 0
    // 2. 改变逻辑
    // for (size_t i = 0; i + 1 < count; ++i)
    // {
    //     /* code */
    // }
    // 3. 强制类型转换
    // for (size_t i = 0; i < static_cast<int>(count) - 1; ++i)
    // {
    //     /* code */
    // }

    // 字符数组 即 char 类型的数组
    // 可以是 一个字符数组，每个元素存储一个字符；也可以是一个 字符串
    // 字符串的结尾用一个特定的字符串终止字符 '\0' 表示，称之为 C 样式 的空字符
    char vowels[5]{'a', 'e', 'i', 'o', 'u'};
    char vowels2[6]{'a', 'e', 'i', 'o', 'u'}; // 未指定初始化值，会被初始化为 '\0'
    char vowels3[]{'a', 'e', 'i', 'o', 'u'};  // 编译器会指定初始化数组个数为 5
    // 还可以声明一个 char 类型的数组，并初始化为一个字符串字面量：
    char name[10]{"Mae West"}; // 0-7是字符，8、9 是 '\0'，其中 8 是这个字符串的末尾，9是因为未初始化
    char name1[]{"Mae West"};  // 编译器决定，这次有 9 个字符，
    char vowels4[]{"aeiou"};
    cout << sizeof(vowels4) << endl; // 答案 6
    cout << sizeof(vowels) << endl;  // 答案 5
    // 可以使用标准输出流，直接输出 char 类型的数组，直到 '\0'为止
    cout << vowels4 << endl;
    char vowels5[]{"aeiouee"};
    cout << vowels5 << endl;

    // cin 流中的 getline() 用于获取输入包含空格的输入，不能使用 >>，因为任何空格都会终止该运算符的输入操作
    // 三个参数：1.存储输入的位置 2.存储的最大字符数，
    // 3.一个可选参数，用于指定 '\n' 的替代字符，此时回车键不再终止输入
    // cin.getline()  这个句点称为：直接成员选择运算符，用于访问类对象的成员
    const size_t max_length{100};
    char text[max_length]{};

    // cin.getline(text, max_length);
    // std::cout << "text:" << text << std::endl;

    return 0;
}