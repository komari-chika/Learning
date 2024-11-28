#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{

    // 运算符的左右相关性指的是计算方向
    // 左相关是运算符从左往右计算，右相关指的是从右向左计算
    // 左相关  绝大多数为左相关
    // 右相关  一元运算符、赋值运算符、条件运算符

    // 注意，没有数学运算符或者位运算符可以作用于比 int 更小的整数类型，
    // 如果操作数是 short 或者 char，总是会被隐式的转换为 int
    // 下面代码必须用强制类型转换
    unsigned short number{16387};
    auto result1{static_cast<unsigned short>(number << 2)};
    auto result2{number << 2};
    cout << result1 << endl
         << result2 << endl;

    // 枚举类型
    enum class Day
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    Day day{Day::Monday};
    // 注意需要使用类型转换，标准io不能识别Day类型
    cout << static_cast<int>(day) << endl; // 输出为0，因为枚举类型默认从0开始
    enum class Day1
    {
        Monday = 1,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday,
        Sunday
    };
    Day1 day1{Day1::Monday};
    cout << static_cast<int>(day1) << endl;
    cout << static_cast<int>(Day1::Sunday) << endl;

    // 可以给第一个枚举类型成员赋值
    // 枚举类型成员不一定有唯一值，成员的值可以相同
    // 也可以根据 已定义的枚举成员 来定义 新的枚举成员

    // !! 枚举成员的值只能是常量，不能是变量

    // 枚举成员的类型规范放在枚举类型名的后面，用冒号隔开
    enum class Punctuation : char
    {
        Comma = ',',
        Exclamation = '!',
        Question = '?'
    };

    // 类型别名使用 using 关键字
    using LL = unsigned long long;
    LL a{111};
    // 等同于 typedef unsigned long long LL，但是不推荐使用
    return 0;
}