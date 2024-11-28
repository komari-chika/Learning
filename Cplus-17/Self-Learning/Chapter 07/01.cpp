#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>
#include <cctype>
#include <string>

using namespace std::string_literals;

int main()
{
    // 之前知道 char[] 可以存储以 空字符结尾 的字符串（C 样式）
    // C++ 标准库 string 头文件定义了 std::string 类型
    // string 类型由 一个类（准确来说是类模板）定义

    // 1. 定义
    std::string empty;                              // 不包含字符的字符串
    std::string Kobe{"Manba out! What can I say!"}; // 以空字符终止

    // 将 std::string 类型转换为 C 样式字符串
    const char *Kobe_c_str = Kobe.c_str(); // 使用函数 c_str()
    char *Kobe_c_str1 = Kobe.data();       // 使用 data()
    // c_str() 必然转换成 const char* ，不能被指针修改，只能访问
    // data() 在 C++ 17 之前也是转换成 const char* ，从 C++ 17 开始会转换成 char*

    // length() 函数可以获取 不包含行尾空字符 的字符串长度
    std::cout << Kobe.length() << std::endl; // 字符串长度为 10 而不是 11

    // 2. 更多初始化方法
    // 2.1 std::string stringName{"string", N}  从 string 第一个字符开始 截取 N 个字符
    std::string partKobe1{"Manba out! What can I say!", 7}; // partKobe = "Manba o";
    // std::cout << partKobe;

    // 2.2 std::string stringName(N, 'char') 初始化为 N 个 char 字符的 字符串
    // !!!! 这里是 圆括号！！！！
    // !!!! 只能用 单引号！！！里面只能是单个字符
    std::string kobePart(42, 'k');
    std::cout << kobePart << std::endl;

    // 2.3 通过已有的 string 对象提供初始值
    std::string partKobe2{Kobe};
    // 或者 std::string newString(existString, first, length)
    // 表示 newString 在 exitString 截取一段字符串：从 exitString[first] 开始，长度为 length，然后进行初始化
    // ！！！注意，第三个参数为 length，是要求截取的长度，不是截取的最后一个字符的索引
    // 最后一个字符的索引应该是：first + length;
    std::string partKobe3{Kobe, 0, 12};
    std::cout << partKobe2 << std::endl;
    std::cout << partKobe3 << std::endl;

    // cin 输入
    // std::string name;
    // std::cout << "Enter your Name: ";
    // std::cin >> name;
    // std::cout << "Your name: " << name << std::endl;
    // 代码会读取字符，直到遇到第一个空白字符为止，然后结束输入

    // 3. string 对象操作
    // 3.1 互相赋值
    std::string momoka{"momoka"};
    std::string nina{"nina"};
    // momoka = nina;
    // nina = "hina"; // 此时 momoka = "nina", nina = "hina"

    // 3.2 连接字符串
    // 3.2.1 使用 + 可以链接字符串
    std::string GBC{momoka + " " + nina + " H!"}; // 这里对 + 运算符进行了运算符重载
    // !!!! 注意，不能用 + 连接两个 字符串字面量（不是std::string 类型的变量）
    // + 运算符 其中的 一个 操作数必须是 std::string 类型的变量
    // std::string wrongConnect{"rupa" + " " + nina}; // 错误
    // 上面的可以写成
    std::string rightConnect1{"rupa " + nina}; // 合并两个字符串字面量
    std::string rightConnect2{"rupa"
                              "" +
                              nina};                             // 省略 + ，编译器会把序列中的 两个及以上 字符串字面量 连接成一个 字符串字面量
    std::string rightConnect3{"rupa" + (" " + nina)};            // 使用圆括号，先计算后面的部分
    std::string rightConnect4{std::string{"rupa"} + " " + nina}; // 将其中一个字符串字面量转换成 std::string 对象
    std::string rightConnect5{"rupa"s + " " + nina};             // 在文件开头加上 using namespace std::string_literals; 然后在 字符串字面量 后加 s ，可以将其转换成 std::string 对象，类似整数字面量加 u 创建 无符号数一样

    // 可以使用 std::string 的 append() 对象替代 += 运算符
    std::string goodRelation{"good:"};
    goodRelation.append(momoka).append(" ").append(nina).append(" rupa");
    std::cout << goodRelation << std::endl;
    // append() 有更多参数
    std::string KKobe{"~~~ Manba,out!Hahaha...What can I say?...~~~"};
    std::string KobeSay{"Kobe say:"};
    // string.append(str, subpos, sublen);
    // 从字符串 str 的位置 subpos 开始，截取长度为 sublen 的子串，追加到当前字符串
    
    KobeSay.append(KKobe, 3, 14); // 同上面2.3一致：3 表示开始字符索引，14 表示截取长度
    KobeSay.append(3, '!');       // 增加 3 个 ！
    std::cout << KobeSay << std::endl;

    // 3.2.2 链接字符串和单个字符
    // 其他操作和上面类似
    // ! 两个字符用 + 连接并不会成为一个字符串，而是把字符的 ascii码 相加
    std::string sentence{};
    sentence += ',' + ' ';
    std::cout << sentence << std::endl; // 这里输出不是 ", "，而是 'L'
                                        // 因为 ',' = 44, ' ' = 32, 44+32 = 76 = 'L'
    // 下面这样写就没有问题
    sentence = "";
    sentence = sentence + ',' + ' ';

    // 3.2.3 连接字符串和数字
    const std::string result_string{"The result equals:"};
    double result{3.14};
    //  std::cout << result_string + result << std::endl;   // 这里会编译报错
    // 数字会被视为 ASCII 码
    // 例如
    std::string song_title{"summer of '"};
    // song_title += 69; // 69 对应 E
    // std::cout << song_title << std::endl;  // summer of 'E

    // C++ 中，必须显式的把这些值转换为字符串
    // ! 可以使用 std 头文件的 tostring() 函数
    std::cout << result_string + std::to_string(result) << std::endl;
    std::cout << song_title + std::to_string(69) << std::endl;

    // 3.3 访问字符串的字符
    // 同数组操作，使用[] + 索引访问
    // for (size_t i{}; i < Kobe.length(); ++i)
    // {
    //     Kobe[i] = std::toupper(Kobe[i]);   // 全部转换为大写
    // }
    // string 对象也是一个范围，可以使用 auto
    // 同时使用 引用 修改
    for (auto &ch : Kobe)
    {
        ch = std::toupper(ch);
    }
    std::cout << Kobe << std::endl;

    // 计算输入字符串中元音和辅音的个数
    std::cout << "Enter sentence: " << std::endl;
    std::string text;
    std::getline(std::cin, text); 
    // ! std::cin、std::cin.getline() 以及 std::getline()的区别
    // cin 在读取字符串时，它遇到空格或者换行符的时候就会结束此次读取
    // std::cin.getline() 同 std::getline() 都会读取一行，即包含空格
    // ! 不同的是
    // std::cin.getline() 两个参数： string，maxLength
    // std::getline() 两个参数: std::cin, string
    // ! std::getline() 更优，它不需要指定读取字符串的最大长度
    size_t ycount{};
    size_t fcount{};
    for (const auto ch : text)
    {
        if (std::isalpha(ch))
        {
            switch (std::tolower(ch))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ycount++;
                break;
            default:
                fcount++;
                break;
            }
        }
    }
    std::cout << text + "\nhas:\n" + std::to_string(ycount) + " yuanyin and " + std::to_string(fcount) + " fuyin." << std::endl;

    // 3.4 访问子字符串
    // ! string.substr(index , length) 
    // ! length 可省略，直接返回指定索引到最后一位的子字符串
    std::string bigstring{"hhhahhhaoweqwgq"};
    std::string substring1{bigstring.substr(2,6)};
    std::string substring2{bigstring.substr(6,100)}; // ! 超出范围，只截取到最后一位
    std::cout << substring1 << std::endl;
    std::cout << substring2 << std::endl;
    // ! 如果 index 超出范围，即 index >= string.length()，会抛出 std::out_of_range 异常
    std::string wrongSubString{bigstring.substr(20)}; // 超出范围
    return 0;
}