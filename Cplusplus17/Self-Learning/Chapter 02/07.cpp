#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    // 字符变量
    // 变量声明
    char letter;            // 没有初始化，垃圾值
    char yes{'Y'}, no{'N'}; // 使用字符初始化
    char ch{33};            // 使用整数初始化，使用 ascii码查找，对应 ！。注意，整数必须处于 char 值域内
    // char 类型可以参与运算
    char CHAR{'A'};
    cout << CHAR << endl;
    CHAR++;
    cout << CHAR << endl;
    CHAR += 3;
    cout << CHAR << endl;

    cout << "ch is \'" << CHAR
         << "\' which is code " << std::hex
         << std::showbase << static_cast<int>(CHAR) << endl;

    // wchar_t (widechar)
    // 宽字符，存储实现方式支持的最大拓展字符集中的所有成员
    // 定义宽字符字面量时，要在字面量的字母前加上字母L
    wchar_t widechar{L'Z'};
    wchar_t create_widechar{'L\x0438'}; // 单引号内部为转译序列，指定字符代码的16进制显示
    // 标准库提供了 wcin 和 wcout处理 wchar_t 类型的输入输出
    std::wcout << widechar << endl
               << create_widechar << endl;
    
    // char16_t、char32_t 可以更好的处理国际字符，分别为 16 位宽字符和 32 位宽字符
    char16_t letter16{u'B'}; 
    char16_t cyr16{u'\x0438'};
    char32_t letter32{U'B'};
    char32_t cyr32{U'\x0438'};

    // auto 关键字
    // auto 关键字告诉编译器应该推断类型
    auto m{10};
    auto n{200UL};
    auto pi{3.141592};
    // 以上仅供参考，非常不推荐这样做，定义变量时应该显著显式的指出变量的类型！

    return 0;
}