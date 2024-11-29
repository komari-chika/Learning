#include <iostream>
#include <vector>
#include <array>
#include <iomanip>
#include <memory>

int main()
{
    // 原始指针和智能指针
    // 智能指针不能递增、递减

    // 智能指针由标准库的 memory 头文件中的模板定义
    // 1. unique_ptr<T>
    // 唯一，不会有两个及以上的 unique_ptr<T> 指向相同的地址
    // unique_ptr<T> 不可复制
    // std::unique_ptr<double> pdata{new double{100.0}};
    // 现在更常用 std::make_unique<T>()，C++14引入
    // 注意，是圆括号
    // std::unique_ptr<double> pdata{std::make_unique<double>(100.0)};
    // 与 auto 结合
    auto pdata{std::make_unique<double>(100.0)};

    // 解引用
    *pdata = 200.0;

    std::cout << *pdata << std::endl;
    // 通过get()，可与获取指针内的地址，以16进制输出
    std::cout << pdata.get() << std::endl;

    // 指向数组的唯一指针
    const size_t n{100};
    // std::unique_ptr<double[]> pvalues{new double[n]};
    auto pvalues{std::make_unique<double[]>(n)};
    for (size_t i{}; i < n; ++i)
    {
        pvalues[i] = i + 1;
    }
    for (size_t i{}; i < n; ++i)
    {
        std::cout << std::setw(5) << pvalues[i] << ' ';
        if ((i + 1) % 10 == 0)
            std::cout << std::endl;
    }
    // 建议使用 vector<T> 而不是 unipue_ptr<T[]>

    // reset() 函数可以把 任意类型智能指针 包含的指针指向 括号内的值
    // 括号为空时置为 nullptr
    pvalues.reset();
    std::unique_ptr<int> mynumber;
    // std::unique_ptr<int> mynumber{}; 这两种都是置为nullptr
    mynumber.reset(new int{123}); // 修改指向

    // release() 用于将智能指针转换为原始指针
    int *raw_ptr = mynumber.release();
    // !!! 注意删除
    delete raw_ptr;
    // reset 与 release 二者都会将智能指针置为 nullptr，
    // 区别在于，reset 会释放原来指向的内存，但是 release 不会，因此
    // !!!!! release 时一定要保存得到的原始指针，否则这块内存会泄露

    // 2. shared_ptr<T>
    // 允许多个 shared_ptr<T> 对象指向同一个内存地址
    // 在任意时刻，都能知道 包含给定地址 的 std::shared_ptr<T> 指针的数量（引用计数）
    // 同 unique_ptr<T> 类似
    std::shared_ptr<int> pshared{std::make_shared<int>(123)};
    *pshared = 888;                               // 解引用
    auto autopShared{std::make_shared<int>(456)}; // 智能指针
    std::shared_ptr<int> pshared1{pshared};       // 使用其他的 shared_ptr<T> 指针初始化

    // 也可以做指针复制
    // std::shared_ptr<int> psharedData{new int{10}};
    std::shared_ptr<int> psharedData{std::make_shared<int>(10)};
    std::shared_ptr<int> psharedData2; // 包含空指针
    psharedData2 = psharedData;
    std::cout << *psharedData << std::endl;
    std::cout << *psharedData2 << std::endl;
    // std::cout << *(psharedData.get()) << std::endl;

    
    return 0;
}
