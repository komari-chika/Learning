#include <iostream>
#include <limits>
// 提前声明
using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 隐式类型转换，由窄阈向宽阈转黄，以下顺序由宽到窄
    /*
        long double
        double
        float
        unsigned long long
        long long
        unsigned long
        long
        unsigned int
        int
    */
    // char signed char unsigned char short unsigned short 总是至少转换为 int
    unsigned int a{20};
    int b{30};
    // cout << a - b << endl; // 由于隐式转换，int --> unsigned int,  (-10)U = 4294967286

    // 显示转换
    // 语法 static_cast<type_to_convert_to> (表示式)，表示把表达式类型的值转换为尖括号里面的值
    // 静态检查在编译，动态检查在运行，static_cast 表示要静态检查
    double c{-10.9};
    int d{static_cast<int>(c)};
    // cout << d << endl;
    unsigned int e{static_cast<unsigned int>(c)};
    // cout << e << endl;

    // 确定数值上下限
    // 使用 numeric_limits<类型>::max()
    // // limits 库
    cout << "double_max : " << std::numeric_limits<double>::max() << endl       // 最大
         << "double_lowest : " << std::numeric_limits<double>::lowest() << endl // 最小
         << "double_min : " << std::numeric_limits<double>::min() << endl       // 最小的正数，浮点数独有
         << "double_max : " << std::numeric_limits<double>::max() << endl
         << "double_max : " << std::numeric_limits<double>::max() << endl;

    // numeric_limits<> 函数
    // numeric_limits<type_name>::digits  浮点：获取尾数二进制数字的位数 整形：获取除符号位外二进制数字位数
    // 注意，digits尾部没有括号
    cout << std::numeric_limits<double>::digits << endl
         << std::numeric_limits<int>::digits << endl;

    // numeric_limits<type_name>::infinity/quiet_NaN
    // 获取 infinity/NaN 值 , type_name 为整形时不会编译！
    // 注意!!! infinity 与 NaN 尾部有括号!!!
    double double_infinity = std::numeric_limits<double>::infinity();
    float float_negetive_infinity = std::numeric_limits<float>::infinity();
    long double no_a_number = std::numeric_limits<long double>::quiet_NaN();
    cout << "double_infinity : " << double_infinity << endl
         << "float_negetive_infinity : " << float_negetive_infinity << endl
         << "no_a_number : " << no_a_number << endl;
    // int int_infinity = std::numeric_limits<int>infinity(); // 错误的
}
