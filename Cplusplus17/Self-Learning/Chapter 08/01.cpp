#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <array>
#include <string_view>
// return x^n
// ! <cmath> 头文件中的数学函数更加高效
double power(double x, int n)
{
    double result{1};
    if (n >= 0)
    {
        while (n > 0)
        {
            result *= x;
            n--;
        }
    }
    else
    {
        while (n < 0)
        {
            result *= x;
            n++;
        }
        result = 1 / result;
    }
    return result;
}

template <typename T> // 函数模板
T changeNumber(T *number)
{
    T add{10};
    *number += add;
    return *number;
}

// 计算数组平均值
// 1. 直接传入数组
double avg(double numbers[], size_t count)
{
    double sum{};
    // ! 不能通过 numbers 来确定的 count 的大小
    for (size_t i{}; i < count; ++i)
    {
        sum += numbers[i];
    }
    return sum / count;
}

// 2. 传入指针
double pavg(double *numbers, size_t count)
{
    double sum{};
    for (size_t i{}; i < count; ++i)
    {
        sum += *(numbers + i); // 也可以写作 sum += numbers[i];
    }
    return sum / count;
}

// 3. count 指针函数
double constPointerAvg(const double *numbers, size_t count)
{
    double sum{};
    for (size_t i{}; i < count; ++i)
    {
        sum += numbers[i];
    }
    return sum / count;
}

// 4. 多维数组
double multNumbers(double numbers[][4], size_t row_count)
{
    double total{};
    size_t column_count = std::size(numbers[0]);
    for (size_t i{}; i < row_count; ++i)
    {
        for (size_t j{}; j < column_count; ++j)
        {
            total += numbers[i][j];
        }
        // for(auto number : numbers[i]){
        //     total += number;
        // }
        // 这样写也可以，避免幻数
    }
    return total / (row_count * column_count);
}

// 5. 引用传递和参数传递对比
void changeItByPointer(double *number)
{
    *number += 10;
}
void changeItByReference(double &number)
{
    number += 10;
}

// 6. 引用传递数组
double avg_ref(const double (&numbers)[10]) // ! 注意，这里可以使用 10
{
    double sum{};
    for (size_t i{}; i < 10; ++i)
    {
        sum += numbers[i];
    }
    return sum / 10;
}

// 7. <array>容器
double avgArrayList(const std::array<double, 10> &numbers)
{
    double sum{};
    for (auto number : numbers)
    {
        sum += number;
    }
    return sum / numbers.size();
}

// 8. 引用和隐式转换
void double_it(double &it) { it *= 2; }
void print_it(const double &it) { std::cout << it << std::endl; }

// 9. std::string_view
void find_words(std::vector<std::string> &words, std::string_view str, std::string_view separators)
{
    size_t start = str.find_first_not_of(separators);
    while (start != std::string::npos)
    {
        size_t end = str.find_first_of(separators, start + 1);
        if (end == std::string::npos)
            end = str.length();
        // words.push_back(str.substr(start, end - start));
        // ! 注意，这里str.substr() 得到的是 std::string_view 类型，但是
        // ! 编译器拒绝将 std::string_view 转换为 std::string
        // ! 所以这里需要显式的 std::string{..} 初始化
        words.push_back(std::string{str.substr(start, end - start)});
        start = str.find_first_not_of(separators, end + 1);
    }
}
int main()
{
    // main() 必须在 全局名称空间 命名
    // 调用栈 保存了所有函数调用的信息，以及传送给每个函数的数据的详细信息

    // 1. 函数定义
    // return_type function_name(parameter_list)
    // {
    //      code for function
    // }
    {
        // std::cout << "input x n" << std::endl;
        // double x{};
        // int n;
        // std::cin >> x >> n;
        // std::cout << "power(" << x << "," << n << ") = " << power(x, n) << std::endl;
        float number{3.0f};
        const double result{power(number, 2)}; // ! 这里发生隐式类型转换，float -> double
                                               // 因为 double 表示的位数是 float 的两倍，所以安全
    }

    // 2. 函数体
    // ! 函数体中定义的变量都是局部变量，在函数调用结束后就不存在了
    // 其中例外的是 static 变量

    // 3. 返回值
    // return 语句把 return 的值返回到 调用函数的 位置
    // 如果返回类型是 void， 返回语句应该写成 : "return;" ，表示没有返回值，或者不写

    // ! 在使用函数之前需要声明
    // 或者定义函数原型
    /*
        double power(double x, int n);  // ! 函数原型
        // 可以省略参数名 double power(double, n)
        // 但是不推荐，不能弄清除参数的作用
        int main(){
            ...
        }

        double power(double x, int n)
        {
            ...
        }
    */

    // ! 值传递
    // 1. 使用指针修改传入的参数
    double number{3.0};
    std::cout << changeNumber(&number) << std::endl;
    // double *pnumber{&number};
    // std::cout << changeNumber(pnumber) << std::endl;

    // 2. 传递数组
    double numbers[8]{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
    size_t count{8};
    std::cout << avg(numbers, count) << std::endl;
    std::cout << pavg(numbers, count) << std::endl;
    // ! double avg(double numbers[], size_t count);
    // ! double avg(double* numbers, size_t count);
    // ! 上面的两个函数签名完全等价
    // ! double avg(double numbers[10], size_t count); 注意，该函数签名也与上面的两个完全等价，这样写非常错误
    // ! 向函数传递一维数组时，绝对不能指定维数

    // 3. const 指针
    // double(const double* numbers, size_t count);
    // ! 只访问数组元素的值，不需要修改时，最好使用 const 修饰传入的指针

    // 4. 多维数组
    // double(double numbers[][4], size_t count);
    // ! 第一个位置需要空缺，第二个可以保留
    double twoDementions[][4] = {{1, 2, 3, 4},
                                 {5, 6, 7, 8},
                                 {1, 2, 3, 4}}; // 初始化要用花括号

    size_t row_count{std::size(twoDementions)};
    std::cout << multNumbers(twoDementions, row_count) << std::endl;

    // 5. 引用传递
    // ! 参数使用引用传递时，直接访问调用函数的 实参值
    // 这样不需要对实参的值进行复制，可以节省开销，提高性能
    // 引用传递和参数传递对比
    // void changeItByPointer(double *number);
    // void changeItByReference(double &number);
    // 最明显的区别：传送指针，需要使用地址运算符获得一个值的地址，然后在函数内解引用访问该值
    //             引用则不需要
    // ! 以上单指语法区别，实际上编译器会按照编译指针的形式，来编译引用

    // ! 使用指针实参和引用实参的指导原则
    //      1. 如果允许 nullptr 实参，用 指针
    //      2. 引用实参 可能导致不容易看出 函数可能会修改值，
    //         如果从上下文/函数名 不能看出函数会修改实参，用指针
    //      3. 一般建议使用 const 修饰 引用实参，并且优于 const 修饰 指针

    // 6. 输入输出参数
    //      1. 输入参数： 作用仅仅是传值，原参数的值不会变动
    //      2. 输出参数： 顾名思义，在函数内部定义，用于输出的参数
    //      3. 输入-输出参数: 一个参数作为输入参数，在函数内部被修改后又作为输出参数
    //                       ! 一般不推荐输入-输出参数，最好新定义输出参数
    // ! 输入参数，要么是 const 的引用传递，要么是按值传送

    // 7. 引用传递数组
    // ! 与值传递和指针传递不同，引用传递可以传递 精确的数组大小
    // double avgRef(const double(&numbers)[10]);
    // ! 注意，圆括号是必须有的，否则编译器会解释为 对 double 值的引用的数组，会导致编译错误
    // ! 并且必须注明数组的长度
    // 此时，尝试传送不同长度的数组会导致编译错误
    // 通过引用传递的数组，在函数内还可作为 sizeof(),std::size()，的参数
    // 可以使用 <array> 容器代替
    // double avgArrayList(const std::array<double,4> & numbers);
    //                      常量 |     参数类型      |

    // 8. 引用和隐式转换

    // 编译器常常会进行隐式转换，例如将 int 转换为 double
    {
        int i{};
        double d{};
        // ...
        d = i; // 隐式转换，将 int 转换为 double
    }

    {
        double d{123};
        double_it(d);
        print_it(d);

        int i{456};
        // double_it(i); 错误，不会编译
        print_it(i);
        // ! 非 const 引用（double&）要求类型严格匹配，且不能绑定到临时对象。
        //   由于 int 类型的 i 需要转换为 double，这种转换会生成临时对象，而非 const 引用无法绑定到临时对象，因此编译失败
        // ! 相比之下，print_it(i) 使用的是 const 引用（const double&），允许绑定到临时对象，
        //   编译器会将 i 转换为临时 double（456.0），因此可以正常编译和运行
    }

    // 9. 新的 const string 引用 std::string_view
    // 前面提到，对于不需要修改自己操作的 std::string 的函数，应该将对应的输入参数修改为 const std::string& 类型
    // 例如
    // void find_words(vector<string> & words, const string &str, const string &separators);

    // 但是，const string& 类型的参数仍然会带来问题
    {
        std::string text{"Hello World"};
        std::vector<std::string> words;
        // std::string separators{" ,;:.!?'\""};
        // find_words(words, text, " ,;:.!?'\"");  // 没有提前声明，直接传入 separators 字符串
        // 此时传入的 字符串字面量是 const char[] 类型，而参数是 const string & 类型，
        // 编译器进行了隐式转换，引用了某个临时的 std::string 对象
        // 与避免复制的目的发生冲突
        // ! 我们不想使用 const char*, 因为还需要单独传送字符串的长度，并且无法使用 std::string 提供的许多函数
    }
    // ! 对此，C++ 17 引入了新的 string_view 类型，存在于 string_view 头文件定义的一个类型
    // 它非常类似于 const std::string
    // ! 但是任何时候都不能通过它们的公共接口修改它们封装的字符串，即可以查看但是不能修改
    // 在隐式或者显示的创建时，std::string 会复制字符，std::string_view 不会
    // ! 记住，总是为输入参数使用 string_view，而不是 const std::string &
    // 针对 find_word 修改
    // void find_word(vector<string>& words, std::string_view str, std::string_view separators);
    // ! 编译器拒绝将 std::string_view 转换为 std::string (隐式转化)

    // std::string_view 没有提供 c_str() , 但提供了 data() 
    // 都是将 std::string_view 转换为 C 风格字符串（const char*）
    // 不能使用 "+" 运算符来连接 string_view 字符串，不过可以先将其转化为 std::string 类型

    
    
    
    return 0;
}