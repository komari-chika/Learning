#include <iostream>
#include <vector>
#include <array>
#include <iomanip>

int main()
{
    // 引用
    // 可以把引用当作 其引用的变量的 变量名 的替代
    double data{3.14};
    double &rData{data};  // 引用
    double *pdata{&data}; // 指针

    std::cout << data << " " << rData << std::endl; // 地址相同，都是 data 变量的地址
    std::cout << &data << " " << &rData << std::endl;

    rData += 2.5; // 指针需要 解引用 才能访问变量的值，引用不许要
    *pdata += 2.5;

    double other_data{5.0};
    // 指针可以修改指向的变量，引用不可以
    rData = other_data;  // 相当于 data = other_data，rData 仍然是 data 的引用
    pdata = &other_data; // pdata 指针修改指向的目标

    // 综上可以看出，引用可以看作是一个 不能修改指向变量的指针，即指针常量
    // double &rData{data}; 等价于
    double *const constpData{&data};

    // 存在对 const 变量的引用
    const double data2{11.4514};
    const double &rdata2{data2}; // 等价于 指向常量 的 常量指针
    const double *const pdata2(&data2);

    // 在 for 循环使用 引用变量
    double sum{0.0};
    unsigned count{0};
    double temperatures[]{1.0, 2.0, 3.0, 4.0, 5.0};
    for (auto t : temperatures)
    {
        sum += t;
        count++;
    }
    std::cout << "Avg T(C):" << sum / count << std::endl;
    // 在每次迭代时，t 被 初始化为 当前数组元素的值，从第一个数组元素开始，
    // **不修改元素本身，只是一个副本，与元素有相同的值**
    // 如果使用引用就可以修改元素数组：
    const double C2F{9.0 / 5.0}; // 摄氏度 转 华氏摄氏度
    for (auto &t : temperatures)
    {
        t = (t + 32.0) * C2F;
        sum += t;
        count++;
    }
    std::cout << "Avg T(F):" << sum / count << std::endl;

    // 这样做效率很高，不需要进行对象的复制
    // 如果给变量使用引用但是不需要修改值，要使用const修饰
    for (const double &t : temperatures)
        std::cout << std::setw(6) << t;
    std::cout << std::endl;
    return 0;
}
