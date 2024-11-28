#include <iostream>
#include <vector>
#include <string>

int main()
{
    // definition
    // long *pnumber{nullptr}; // 定义指针时总是初始化，如果不知道具体的值，就赋值 nullptr

    // 指针大小总是固定的，是目标平台 可寻址内存 的大小
    std::cout << "sizeof(double): " << sizeof(double) << std::endl    // 8
              << "sizeof(char): " << sizeof(char) << std::endl        // 1
              << "sizeof(double*): " << sizeof(double *) << std::endl // 8
              << "sizeof(char*): " << sizeof(char *) << std::endl;    // 8

    // 地址运算符 &
    // 获取变量的地址
    long number{12345L};
    long *pnumber{&number};
    long height{114514L};
    pnumber = &height;

    // 通过 auto 判断指针指向值的对应的类型，推荐使用 auto* 指明指针
    // auto autopnumber{&height};
    auto *autopnumber{&height};

    // char 类型的指针
    // char* pproverb{"A miss is as good as a mile."}; // 不能这样写，字符串字面量是常量，不能被修改
    const char *pproberb{"A miss is as good as a mile."};

    // 指针数组：一个数组，里面是多个指针，这些指针指向const char类型
    const char *pstars[]{
        "Fatty Arbuckle", "Clara Bow",
        "Lassie", "Slim Pickens",
        "Boris Karloff", "Mae West",
        "Oliver Hardy", "Greta Garbo"};
    // 这个数组内部存储的信息可以改动，但是不能修改数组指向的信息的值
    // 即
    // pstars[0] = pstars[1] ok
    // *pstars[0] = 'X';   don't ok，表达式必须是可以修改的左值
    // 如果不想让数组内部存储的信息(即这些字符串常量的地址)改动，可以使用const修饰pstars
    // const char* const pstars[]{}

    // 常量指针，指向常量的指针，指向的常量不能修改
    const int a{1};
    const int *ptr1{&a};
    // *ptr1 = 2 错误

    // 指针常量，指针的指向不能修改
    int b{0}, c{1};
    int *const ptr2{&b};
    // ptr2 = &c; 错误

    // 指针算数运算
    double values1[10]{};
    double *pvalues1{values1};
    int values2[10]{};
    int *pvaluse2{values2};
    // 指针 + 1，表示递增指向元素类型的大小
    // 指向 double，递增 8，指向int，递增 4
    ++pvalues1;
    ++pvaluse2;

    // 注意，解引用运算符优先级高于+-
    // *(pvalues1 + 1) 等同于 values[1];
    // *pvalues + 1 等同于 values[0] + 1;

    // 指针的差，仅在 指针类型相同 且 指向同一个数组时有效
    int values3[10]{0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
    int *pvalues3_1{&values3[3]};
    int *pvalues3_2(&values3[7]);
    auto diff1{pvalues3_2 - pvalues3_1}; // 4
    auto diff2(pvalues3_1 - pvalues3_2); // -4
    std::cout << diff1 << std::endl;
    std::cout << diff2 << std::endl;

    // C++ 语言规定，指针相减后的类型为 std::ptrdiff_t
    // 却决于平台，std::ptrdiff_t 通常是 int、long、long long 的别名
    // candidate prime
    return 0;
}