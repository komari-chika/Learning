#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

int main()
{
    // 3.5 比较字符串
    {
        // 可以使用比较符号：< <= > >= != ==
        // 操作数将逐一比较其中的字符，直到找到不同的字符，或者到达一个/两个操作数的结尾
        // 在找到不同的字符后，将根据 asiic 码的数值进行比较，返回比较结果
        // ! 比较使用的算法技术是 字典序
        std::string word1{"age"};
        std::string word2{"beauty"};
        std::cout << (word1 < word2) << std::endl; // 1
    }

    // 读取名字，然后按升序排列
    {
        std::vector<std::string> names;
        std::string input_name;
        char answer{};
        do
        {
            std::cout << "Enter name: ";
            std::cin >> input_name;
            names.push_back(input_name);
            std::cout << "Continue? Y/N" << std::endl;
            std::cin >> answer;
        } while (std::toupper(answer) == 'Y');

        bool sorted{false};
        do
        {
            sorted = true; // 提前置为真，如果后面没有发生排序动作，则证明已完成排序
            for (size_t i{1}; i < names.size(); ++i)
            {
                if (names[i - 1] > names[i]) // 前一个元素比后一个元素大，
                {
                    names[i].swap(names[i - 1]); // swap() 交换函数
                    // swap() 函数等价于：
                    // temp = names[i];
                    // names[i] = names[i - 1];
                    // names[i - 1] = temp;
                    // ! 大多数标准库类型都提供了 swap() 函数，除了 std::string
                    // ! std 名称空间还定义了一个非成员函数模板 swap(names[i],names[i - 1]);
                    sorted = false; // 仍然发生过交换
                }
            }
        } while (!sorted);

        // 寻找最长的名字长度 方便列表
        size_t maxLength{};
        for (auto const &name : names)
            maxLength = (maxLength >= name.length()) ? maxLength : name.length();

        const size_t setwWidth(maxLength + 2);
        size_t count{};

        std::cout << "升序排列你输入的名字：\n";
        for (auto const &name : names)
        {
            std::cout << name << " ";
            if ((++count) % 5 == 0)
                std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // 3.5.1 compare() 函数
    // string1.compare(string2)
    // 返回 string1 与 string2 的比较结果
    // string1 > string2,  string1.compare(string2) > 0
    // string1 < string2,  string1.compare(string2) < 0
    // string1 = string2,  string1.compare(string2) = 0

    // ! compare() 还可以比较 string 对象的一个子字符串和实参
    // string1.compare(index, length, string2 )
    // 表示从 string[index] 开始，包含 length 个字符，然后与 string2 比较
    std::string word1{"A jackhammer"};
    std::string word2{"jackhammer"};
    std::cout << word1.compare(2, word2.length(), word2) << std::endl;
    // std::cout << word2.compare(word1.substr(2));

    // ! 可以使用 compare() 函数来搜索子字符串
    std::string text{"Peter piper picked a peck of pickled pepper."};
    std::string tragetWord{"pick"};

    for (size_t i{}; i <= text.length() - tragetWord.length(); ++i)
    {
        if (text.compare(i, tragetWord.length(), tragetWord) == 0)
        {
            std::cout << "match at the index of " << i << std::endl;
        }
    }

    // ! compare() 还可以有 5 个参数
    // string1.compare(index1, length1, string2, index2, length2);
    // string1[index1, index1 + length1 - 1] 比较 string2[index2, index2 + length - 1]
    std::string text1{"Got to pick a pocket or two"};
    std::cout << text << std::endl
              << text1 << std::endl;

    for (size_t i{}; i < text.length() - 3; ++i)
    {
        if (text.compare(i, 4, text1, 7, 4) == 0) // 匹配的单词是 pick
        {
            std::cout << "find the match word ";
            for (size_t j{7}; j <= 7 + 4; ++j)
            {
                std::cout << text1[j];
            }
            std::cout << "at the index of " << i << std::endl;
        }
    }

    // ! compare() 还可以指定使用的字符个数
    // string1.compare(index1, length1, string2, length2)
    // ! 注意，这里 string2 从零开始，即 index2 = 0
    // string1[index1, index1 + length1 - 1] 比较 string2[0, index2 - 1]
    // 上个循环中变成 if (text.compare(i, 4, "picked", 4) == 0)

    // ! 与 substr() 相比
    // substr() 代码更加简洁易懂，但是需要创建临时的子字符串，效率较低
    // compare() 更高效，但不易懂
    
    return 0;
}