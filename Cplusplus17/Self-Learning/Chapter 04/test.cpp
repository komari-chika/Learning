#include <iostream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;

int ex_2(int big, int small)
{
    if (!isdigit(big) && !isdigit(small) && big <= 0 && small <= 0)
    {
        cout << "feifa";
        return 0;
    }
    int temp = big;
    big = big >= small ? big : small;
    small = temp < small ? temp : small;
    // cout << big << small;
    if (small % big)
        cout << big << " is " << small << "'s beishu";

    return 0;
}




int main()
{

    // int big{0};
    // int small{0};

    // cin >> big >> small;
    // ex_2(big, small);
    return 0;
}