#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>

void test01() { }
void test02() { }
void test03() { }
void test04() { }
void test05() { }
void test06() { }
void test07() { }
void test08() { }

int main()
{
    size_t number = 1;

    // 创建函数指针数组
    void (*testFunctions[])() = { test01, test02, test03, test04, test05, test06, test07, test08 };

    // 检查number是否在有效范围内
    if (number > 0 && number <= sizeof(testFunctions) / sizeof(testFunctions[0]))
    {
        // 调用相应的测试函数
        testFunctions[number - 1]();
    }
    return 0;
}