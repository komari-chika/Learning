#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 动态内存分配
    // 栈 和 堆（自由存储区）
    // new / delete 位于堆
    // double *pvalue{};
    // pvalue = new double;
    // *pvalue = 3.14;

    // pvalue = new double{3.14};

    double *pvalue{new double{3.14}};

    // double *pvalue {new double{}}; 初始化指向 0.0
    // double *pvalue{}; 初始化为 nullptr

    delete pvalue;
    // 此时仅仅释放了 pvalue 指向的内存，那块内存可以被其他变量使用
    // 此时 pvalue 中存储的地址非法，pvalue 称之为 悬挂指针
    // 因此总是在释放(delete)后，将指针置为空指针
    pvalue = nullptr;
    // 对于值为 nullptr 的指针执行 delete 是无害的

    // 数组动态内存分配
    double *data{new double[100]};           // 包含未初始化的垃圾值
    double *data1{new double[100]{}};        // 全为 0.0
    int *one_two_three{new int[3]{1, 2, 3}}; // [1,2,3]

    // 注意，编译器不能推断出 动态分配内存的数组的维数
    // int *one_two_three{new int[]{1, 2, 3}} 错误的
    delete[] data; // [] 十分重要，表示删除的是 一整个数组 而 不是一个指针()
    data = nullptr;
    delete[] data1;
    data1 = nullptr;
    delete[] one_two_three;
    one_two_three = nullptr;

    // 多维数组
    // C++ 不支持有多个动态维数的多维数组
    size_t rows{}, columns{};
    std::cin >> rows >> columns;
    // auto carrots{new double[rows][columns]{}} // 错误的，不允许指定多维

    auto carrots{new double[rows][4]{}}; // 可以指定一维，等同于
    // double (*carrots)[4]{new double[rows][4]{}}; // 这里的 () 不能掉
    // 上面表示
    // carrots 是一个指针，指向一个大小为4的数组，即每一行有4个元素，但是行数不固定，由 row 确定
    // delete[] carrots;

    // 可以用循环来创建：
    double **carrots_for{new double *[rows]};
    // carrots_for 是一个 二级 指针，指向一个包含 rows 个 一级 指针的数组；
    // 每一个 一级 指针指向包含 columns 个 double 类型元素的数组
    for (size_t i{}; i < rows; ++i)
    {
        carrots_for[i] = new double[columns]{};
    }
    // 记得删除
    for (size_t i{}; i < rows; ++i)
    {
        delete carrots_for[i];
    }
    delete[] carrots_for;

    // 通过指针选择成员
    // 下面再自由存储区创建了容器
    auto *pdata{new std::vector<int>{}};
    // auto* = std::vector<int>*
    // 也可以使用 取地址 符号：
    // std::vector<int> data;
    // auto* pdata1{&data};

    // 要访问指针指向的元素需要解引用符号
    // 因此添加元素语句：
    (*pdata).push_back(66); // 注意，必须添加圆括号，因为 . 运算符优先级高于 *
    // 这样写很麻烦，C++ 提供了 -> 用于替换，它的作用是先解除指针的引用，再选择对象的成员
    // 称为 箭头运算符 或者 间接成员选择运算符
    pdata->push_back(77);

    return 0;
}
