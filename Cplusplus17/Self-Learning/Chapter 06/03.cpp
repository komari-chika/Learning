#include <iostream>
#include <vector>
#include <array>
#include <iomanip>

int main()
{
    // 动态内存分配 的 危害
    // 1. 悬挂指针 与 多次释放
    // delete 后，指针变量仍然包含 自由存储区 中的地址
    // 这时解引用该指针，会读取到意外值
    // 同时 多次 delete 同一个已释放的指针，也会带来灾难性影响

    // 2. 分配与释放的不一致
    // new 对应 delete，new[] 对应 delete[]

    // 3. 内存泄漏
    // 没有及时 delete
    // 指针变量在作用域之后不可访问，在离开该作用域时应该使用delete

    // 内存分配黄金准则
    // 在日常编码中，不要直接使用 new、new[]、delete 和 delete[]运算符
    // 总是应该使用 std:vector<>容器(来替换动态数组)或智能指针(来动态分配对象并管理其生存期)。
    // 这些高级替代方法比低级的内存管理方法安全得多，可立即清除程序中的所有悬挂指针、多次释放、分配/释放不匹配和内存泄漏问题。


    return 0;
}
