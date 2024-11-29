#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <array>
int main()
{

    // 容器
    // std::array<T,N>
    // 表示 类型为 T 的 N 个元素的固定序列
    std::array<double, 100> values{}; // 默认为 0
    // fill() ，把所有元素设置为某个给定的值
    values.fill(0);
    // size()，返回元素个数
    values.size();
    // 访问元素
    // 1. 同标准数组使用 []
    // 2. 使用 at() 函数，在访问的基础上会检查是否超出合法范围，如果超出会报错 std::out_of_range
    values[0];
    // 求和
    {
        int sum{};
        for (size_t i{}; i < values.size(); ++i)
        {
            // sum += values[i];
            sum += values.at(i);
        }
    }
    {
        int sum{};
        for (auto value : values)
        {
            sum += value;
        }
    }
    // array 上的操作
    // 1. 只要容器大小相同，存储元素类型相同，便可以直接进行大小比较
    // == != > <
    std::array<double, 4> these{1.0, 2.0, 3.0, 4.0};
    std::array<double, 4> those{1.0, 2.0, 3.0, 4.0};
    std::array<double, 4> them{1.0, 2.0, 3.0, 5.0};
    std::cout << (these == those) << std::endl;
    std::cout << (these != them) << std::endl;
    std::cout << (these <= them) << std::endl;
    // == 逐一比较，所有 对应 元素必须全部相同
    // != 至少有一对不同
    // > >= < <= 这些运算符会逐个比较数组元素，
    //           直到发现不同的元素
    //           如果找到了不同的元素，则根据它们的大小返回比较结果

    // 同样的，只要两个容器大小和元素类型都相同，便可以把一个容器赋予给另一个容器
    // 此外 array容器 可以存储在其他容器中
    std::array<std::array<int, 3>, 3> triplets{};
    std::vector<std::array<int, 3>> tripletss{};

    // 将 std::array 转换为 C 风格数组，这可以通过 std::array::data() 方法
    std::array<int, 3> arr = {1, 2, 3};
    int *c_arr = arr.data();

    
    // std::vector<T>

    return 0;
}
