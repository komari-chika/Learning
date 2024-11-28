#include <iostream>
#include <iomanip> // 注意包含这个头文件
#include <cmath>
// 提前声明
using std::cin;
using std::cout;
using std::endl;

int main()
{
    double pi{3.141592653589793};
    // 数学函数
    // abs(arg) 绝对值
    // ceil(arg) 大于等于arg的最小整数  ceil(3.6)=4  ceil(-3.6)=-3
    // floor(arg) 小于等于arg的最大整数 floor(3.6)3  floor(-3.6)=-4
    // exp(arg)  e^arg
    // pow(arg1, arg2)  arg1^arg2
    // sqrt(arg)  arg开平方
    round(1.123); //四舍五入arg

    // 输出格式化
    // 要使用头文件<iomanip> !!!!!!
    // 1. 输出流操作
    // std::fixed 设置浮点数的显示为定点格式（小数形式）
    // std::scientific 设置为科学计数法
    // std::defaultfloat 设置为默认的浮点表示方法

    // dec、hex、oct 分别对应 16 10 8进制

    // left、right 左对齐与右对齐

    // 2. 参数化操作

    // setprecision
    // 如果是 defaultfloat ，则设置整个浮点数位数
    cout << std::defaultfloat << std::setprecision(4) << pi << endl;
    // 如果是 fixed/scientific，则设置小数位数
    cout << std::fixed << std::setprecision(4) << pi << endl;
    cout << std::scientific << std::setprecision(4) << pi << endl;
    // setw 设置输出字段的宽度
    cout << std::defaultfloat << std::setw(10) << pi << endl;
    // setfill 设置字段填充字符
    cout << std::setw(10) << std::setfill('*') << pi << endl;
}
