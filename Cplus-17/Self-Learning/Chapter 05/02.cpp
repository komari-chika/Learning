#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 多维数组
    double carrots[3][4]{}; // 中括号里面，第一个参数是行，第二个参数是列
    // carrots[0][0] carrots[0][1] carrots[0][2] carrots[0][3]
    // carrots[1][0] carrots[1][1] carrots[1][2] carrots[1][3]
    // carrots[2][0] carrots[2][1] carrots[2][2] carrots[2][3]

    // 遍历输出
    for (size_t i{}; i < std::size(carrots); ++i) // std::size(carrots) 等同于 sizeof(carrots) / sizeof(carrots[0])
    {
        for (size_t j{}; j < std::size(carrots[0]); ++j)
        {
            cout << carrots[i][j] << " ";
        }
        cout << endl;
    }

    // 数组的维度使用const size_t 修饰
    const size_t nrows{3}; // row 行
    const size_t ncols{4}; // column 列
    int carrotss[nrows][ncols]{};

    // 三维数组时
    // 一年52星期，一星期七天，每天记录三次温度
    const size_t weeknumbs{52};
    const size_t days{7};
    const size_t times{3};
    double tem[weeknumbs][days][times]{};
    // 注意，所有的索引值都是从 0 开始，即：
    // 0 - 51, 0 - 6, 0 - 2
    // 循环：
    size_t imax = sizeof(tem) / sizeof(tem[0]);
    size_t jmax = sizeof(tem[0]) / sizeof(tem[0][0]);
    size_t kmax = sizeof(tem[0][0]) / sizeof(tem[0][0][0]);

    // for (size_t i{}; i < imax; ++i)
    // {
    //     for (size_t j{}; j < jmax; ++j)
    //     {
    //         for (size_t k{}; k < kmax; ++k)
    //         {
    //             cout << tem[i][j][k] << " ";
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }
    // 或者
    for (size_t i{}; i < std::size(tem); ++i)
    {
        for (size_t j{}; j < std::size(tem[0]); ++j)
        {
            for (size_t k{}; k < std::size(tem[0][0]); ++k)
            {
                cout << tem[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // 初始化时，没有被初始化的元素会被置 0

    // 数组的第一个值可以让编译器设定
    double carrotsss[][3]{
        {2, 3},
        {1},
        {3, 5, 6}};

    // 多维字符数组
    char stars[][80]{
        "Fatty Arbuckle",
        "Clara Bow",
        "Lassie",
        "Slim Pickens",
        "Boris Karloff",
        "Mae West",
        "Oliver Hardy",
        "Greta Garbo"};
    return 0;
}
