#include <iostream>

int main()
{
    // 用花括号赋值, 等效于 answer = 42
    int answer{42};

    // 命名必须以字母或者下划线开头
    int ex_1;
    int _ex_2;
    // 不推荐 int __ex_3

    // 转义字符
    /*
        \n 换行
        \f 换页
        \t 水平制表
        \v 垂直制表
        \b 退格
        \r 回车
        \a 警告
        \\ 反斜杠
        \' 单引号
        \" 双引号

    */
    std::cout << "\"Least \'said\' \\ \n \t\t soonest \'mended\'.\"";
    return 0;
}