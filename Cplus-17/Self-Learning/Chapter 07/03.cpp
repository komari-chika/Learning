#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <vector>

int main()
{
    // 3.6 搜索字符串
    // 3.6.1 find()
    // string1.find(string2)
    // ! 返回搜索到的 第一个子字符串 中的 第一个字符 的 索引
    std::string text{"Manners maketh man"};
    std::string word{"man"};
    std::cout << text.find(word) << std::endl // 15
              << text.find("Ma") << std::endl // 0
              << text.find('k') << std::endl  // 10
              << text.find('x') << std::endl; // 非法字符位置，搜索失败，返回size_t 的最大值：
                                              // std::string::npos = 2^64-1 = 18446744073709551615
    // ! npos = no position
    std::cout << std::string::npos << std::endl;
    if (text.find('x') == std::string::npos)
        std::cout << "not found" << std::endl;
    // ! 注意不要写成 if(!text.find(x))，除 0 之外，其他数值全部为 true

    // find() 参数
    // 1. string1.find(string2，index1)
    //      从 string1[index1] 开始搜索 string2
    {
        std::string sentence{"Manners maketh man"};
        std::string word{"an"};
        size_t count{};
        for (size_t i{}; i <= sentence.length() - word.length();)
        {
            size_t position = sentence.find(word, i); // 每次循环从 i 开始搜索
            if (position == std::string::npos)
                break;
            count++;
            i = position + 1; // ! 在上次找到的位置的基础上，往后移动一位，开始下一次查找
                              // 如果是写成下面的样子，表示不允许出现重复匹配
            // i = position + word.length()
            // 例如 ananans 中匹配 ana，前者 position = 0, 2，后者 position = 0
        }
        std::cout << '"' << word << "\" occurs in \"" << sentence
                  << "\" " << count << " times." << std::endl;
    }

    // 2. string1.find(c_string2, index1, length2)
    // ! c_string2
    // 从 string1[index1] 开始搜索，搜索的目标是 c_string2 的前 length2 个字符
    {
        std::string sentence{"Manners maketh man"};
        std::cout << "sentence.find(\"akat\", 1, 2) : "
                  << sentence.find("akat", 1, 2) << std::endl; // 从 sentence 的中的 第 1 个 字符开始搜索，
                                                               // 搜索目标为 "akat" 的前两个字符 "ak"
    }

    // 3.6.2 搜索任意字符集合
    {
        std::string text{"Smith, Where Jones had had \"had had\", had had \"had\"."
                         " \"Had had\" had had the examiners' approval."};
        std::string separators{" ,.\""}; // 分隔符： 空格，逗号，句号，双引号
        std::cout << text << std::endl;
        // 1. find_first_of()
        // string1.find_first_of(string2);
        // 在 字符串(string1) 中查找 给定字符集(string2) 中的字符 第一次出现的位置
        std::cout << "text.find_first_of(separators): "
                  << text.find_first_of(separators)
                  << " "
                  << text[text.find_first_of(separators)]
                  << std::endl; // 输出是 5，对应 ','

        // 2. find_last_of()
        // string1.find_last_of(string2);
        // 在 字符串(string1) 中查找 给定字符集(string2) 中的字符 最后一次 出现的位置
        std::cout << "text.find_last_of(separators): "
                  << text.find_last_of(separators)
                  << " "
                  << text[text.find_last_of(separators)]
                  << std::endl; // 输出是 94，对应 '.'

        // 3. find_first_not_of(), find_last_not_of()
        // string1.find_first_not_of(string2);
        // string1.find_last_not_of(string2);
        // 在 字符串(string1) 中查找 【不是】 给定字符集(string2) 中的字符 第一次/最后一次 出现的位置
        std::cout << "text.find_first_not_of(separators): "
                  << text.find_first_not_of(separators)
                  << " "
                  << text[text.find_first_not_of(separators)]
                  << std::endl; // 输出是 0，对应 第一个字符 'S'

        std::cout << "text.find_last_not_of(separators): "
                  << text.find_last_not_of(separators)
                  << " "
                  << text[text.find_last_not_of(separators)]
                  << std::endl; // 输出是 93，对应 第一个字符 'l'
    }

    // 例子
    // 提取输入一句话中的所有单词
    {
        std::string text;
        std::cout << "Enter some text terminated by *:\n"; //   输入一串字符，以 * 结尾
        // std::getline(std::cin, text, '*');
        text = {"uu wah,wfaf;wafherkpqfav .wkqdkwfq qkpqk.awdaapwk wrjia.amwd!fo?wj"};

        const std::string separators{" ,;:.\"!?'\n"}; // 可能出现的分隔符
        std::vector<std::string> words;               // 存储获取的单词

        size_t word_index = text.find_first_not_of(separators); // 第一个单词 的 第一个字母 的 索引
        while (word_index != std::string::npos)
        {
            size_t separator_index = text.find_first_of(separators, word_index + 1); // 从字母的下一个位置查找分隔符
            if (separator_index == std::string::npos)                                // ! 没有搜索到分隔符，直接置为搜索字符串末尾
                separator_index = text.length();
            std::string word = text.substr(word_index, separator_index - word_index); // 分割单词
            words.push_back(word);                                                    // 增加单词
            word_index = text.find_first_not_of(separators, separator_index + 1);     // 从分隔符的下一个位置查找字母
        }
        const size_t newline{5};
        size_t count{};
        size_t max_length{};
        for (size_t i{}; i < words.size(); ++i)
        {
            max_length = (max_length >= words[i].length()) ? max_length : words[i].length();
        }
        for (auto word : words)
        {
            std::cout << std::setw(max_length + 3) << word;
            count++;
            if (count % newline == 0)
                std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // 3.6.3 逆向搜索字符串
    // rfind() r 代表 reverse
    // 返回 第一个搜索到的 子字符串 的 首个字符 的索引
    {
        std::string text{"Manners maketh man"};
        std::cout << text << std::endl;
        std::string word{"an"};
        std::cout << "text.rfind(\"an\"): "
                  << text.rfind(word) << " " << text[text.rfind(word)]
                  << std::endl;
        std::cout << "text.rfind(\"man\"): "
                  << text.rfind("man") << " " << text[text.rfind("man")]
                  << std::endl;
        std::cout << "text.rfind('n'): "
                  << text.rfind('n') << " " << text[text.rfind('n')]
                  << std::endl;
    }
    return 0;
}