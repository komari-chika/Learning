#include <iostream>

int main()
{
    // 以整形int为例
    // 4 字节  -2^31 ~ 2^31-1
    // 定义时使用 {} () = , 也可使用表达式
    int a{1}, b(2), c = 3, d{a + b}, e(3 + 1);
    std::cout << a << b << c << d << e << std::endl;

    // 0 初始化
    int counter {0};
    int counter_1 {}; // 二者等价

    // const 定义不能被修改的变量
    const unsigned int toe_count {10};
    std::cout << toe_count << std::endl;
    return 0;
}