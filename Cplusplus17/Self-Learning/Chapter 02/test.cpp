#include <iostream>
#include <limits>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;

int main()
{
    while (1)
    {
        const double pi{3.141592653589793238};
        double radius{};
        int width;
        cout << "请输入圆的半径与结果所需位数：" << endl;
        cin >> radius >> width;
        double area = pi * radius * radius;
        cout << "半径为 " << radius << " 的圆的面积为：" << fixed << setprecision(width) << area << endl;
    }
    return 0;
}
