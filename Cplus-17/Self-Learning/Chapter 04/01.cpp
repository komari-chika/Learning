#include <iostream>
#include <iomanip>
// #include <cctype>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // bool 类型默认是false
    bool isValid{true};
    bool isFalse{};

    // std::boolalpha 可以把布尔值输出变成 false 和 true

    // cctype 头文件提供了函数用于分类字符
    char c{'a'};
    cout << std::boolalpha;
    cout << isupper(c); // 大写字母
    islower(c);         // 小写字母
    isalpha(c);         // 大/小写字母
    isdigit(c);         // 数字
    isxdigit(c);        // 16进制数字
    isalnum(c);         // 字母/数字
    isspace(c);         // 空白 '' \n \r \f \t \v
    isblank(c);         // 空格
    ispunct(c);         // 标点符号
    isprint(c);         // 可打印字符，即 大小写字母、数字、标点符号
    iscntrl(c);         // 控制符/不可打印字符
    isgraph(c);         // 图形字符，除空格以外的所有可打印字符

    // 以上函数返回值为 int 类型，因为函数来自 C 标准库
    // 大小写转换 tolower(c), toupper(c)

    // 一般用 if(c),if(!c) 而不是 if(c == true), if(c != true)

    // 与位运算符不同，二元逻辑运算符是短路运算符
    // && 出现 false 就停， || 出现 true 就停
    // 所以将成本最低的放在最前面

    // 条件运算符
    // c = a > b ? a : b; 取 a，b中的较大者
    // (逻辑表达式) ? (表达式) : (表达式)
    // divisor ? (devidend / divisor) : 0; 保证分母不为0

    // cout << (a < b ? "a is less than b." : (a == b ? "a is equal to b." : "a is greater than b."))

    // switch 语句
    // switch (c)
    // {
    // case /* constant-expression */:
    //     /* code */
    //     break;

    // default:
    //     break;
    // }
    // 只能对int，long，unsigned int，char，enum使用 switch 语句
    // 没有写break会发生贯穿，如果是故意这样写 可以在原来的break位置加上 [[fullthrough]]

    // c++ 17 引入一个额外的作用域，将局部变量绑定到if语句
    // if(initialization ; condition)
    if (auto lower{static_cast<char>(std::tolower(c))}; lower >= 'a' && lower <= 'z')
    {
        cout << "lower" << endl;
    }
    // 等同于
    {
        auto lower{static_cast<char>(std::tolower(c))};
        if (lower >= 'a' && lower <= 'z')
        {
            cout << "lower" << endl;
        }
        else
        {
            cout << lower;
        }
    }
    // 初始化的变量在 else 中也能访问，但在之外不存在
    return 0;
}