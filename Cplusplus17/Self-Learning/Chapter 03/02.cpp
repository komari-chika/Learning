#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 变量生存期

    // 1. 在代码块声明的非静态变量具有自动的存储持续时间，被称为自动/局部变量，从
    //    声明它时存在，代码块结尾(右花括号 })消失
    // 2. 使用 static 关键字定义的变量具有静态的存储持续时间，从
    //    声明它时存在，程序结束时消失
    // 3. 运行期间分配内存的变量具有动态的存储持续时间，从
    //    创建时存在，释放内存销毁时消失
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << "*" << i << "=" << i * j << "\t";
        }
        cout << endl;
    }

    // 作用域
    // 全局变量
    // 在所有代码块和类外部定义的变量称为全局变量
    // 只有全局变量有默认的初始值，没有初始化时为0
    // 

    return 0;
}