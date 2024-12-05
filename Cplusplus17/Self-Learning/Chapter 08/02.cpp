#include <iostream>
#include <string_view>
#include <vector>
#include <iomanip>
#include <cctype>
#include <cmath>

// 默认实参值
// 不需要特殊参数时，使用默认参数
// ! 只能在一个地方指定，通常建议将默认值放在函数声明中
void show_error(std::string_view message = "Program Error.")
{
    std::cout << message << std::endl;
}
// 以上等同于 void show_error(const std::string& message = "Program Error.")
// ! 注意，必须添加const，否则不能编译

// 多个默认值
// 显示一个或多个数据值，允许一行显示多个数据值
// 函数声明
void show_data(const int data[], size_t count = 1, std::string_view title = "Data Values", size_t width = 10, size_t perLine = 5);

// 函数定义
void show_data(const int data[], size_t count, std::string_view title, size_t width, size_t perLine)
{
    std::cout << title << std::endl;

    // output values
    for (size_t i{}; i < count; ++i)
    {
        std::cout << std::setw(width) << data[i];
        if ((i + 1) % perLine == 0)
            std::cout << std::endl;
    }
    std::cout << std::endl;
}

// main() 函数参数说明：
// 1. int main(int argc, char* argv[])
//    - argc: 命令行参数的数量（包括程序名），总是 >= 1。
//    - argv: 字符串指针数组，存储每个命令行参数。
//      - argv[0]: 程序名（完整路径或名称）。
//      - argv[1] 至 argv[argc-1]: 用户输入的参数。
//      - argv[argc]: 始终为 nullptr，标志参数结束。
// 2. 示例：
//    命令行输入: program.exe arg1 arg2
//    argc = 3
//    argv = ["program.exe", "arg1", "arg2", nullptr]

// 常见用法：
// 1. 输出命令行参数数量和内容。
// 2. 解析命令行输入（文件路径、选项等）。
// 3. 将参数从 C 字符串 (char*) 转换为 std::string 或其他类型。

// 例子
// int main(int argc, char* argv[])
// {
//     std::cout << "Number of command-line arguments: " << argc << std::endl;
//     for (int i{}; i < argc; ++i)
//         std::cout << "Argument " << i << ": " << argv[i] << std::endl;
//     return 0;
// }
// 假设程序编译后为 02.exe 运行后输出为： 
// Number of command-line arguments: 1
// Argument 0: 02.exe


int main()
{
    show_error();                   // 调用默认参数
    show_error("Something wrong."); // 使用特定参数

    // void show_data(const int data[], size_t count = 1, std::string_view title = "Data Values", size_t width = 10, size_t perLine = 5);
    int values[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    show_data(values, 5, "First 5 values", 6, 2); 
    show_data(values, 10, "All values", 6, 2);    
    show_data(values, 10, "All values");          
    show_data(values, 10);                        
    show_data(values);   
    int dataItem{-99};
    show_data(&dataItem);                         
    // ! 注意，只能省略参数列表的尾部参数，不能省略头部参数


    return 0;
}