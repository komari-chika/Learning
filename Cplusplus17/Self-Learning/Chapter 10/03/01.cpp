#include <iostream>

// 使用 ## 运算符拼接变量名
#define VAR(name) int var_##name = 10;

// 使用 ## 运算符拼接函数名
#define FUNC(name) void func_##name() { std::cout << "Function " #name << " called!" << std::endl; }

// 使用 # 运算符打印变量名
#define PRINT_VAR(name) std::cout << "Value of var_" #name << ": " << var_##name << std::endl;

// 在 main 函数之前定义函数 func_A 和 func_B
FUNC(A)
FUNC(B)

int main() {
    // 定义变量 var_a 和 var_b
    VAR(a)
    VAR(b)

    // 打印变量的值
    PRINT_VAR(a)  // 输出: Value of var_a: 10
    PRINT_VAR(b)  // 输出: Value of var_b: 10

    // 调用函数
    func_A();  // 输出: Function A called!
    func_B();  // 输出: Function B called!
    
    return 0;
}
