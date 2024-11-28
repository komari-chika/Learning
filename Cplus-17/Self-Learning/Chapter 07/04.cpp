#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

int main()
{
    // 3.7 修改字符串

    // 3.7.1 插入
    {
        std::string phrase{"01234567890123456789"};
        std::string words{"abcdefghijklmn"};
        // ! string1.insert(index1, string2)
        // 在 string1[index1] 【之前】 插入 string2

        phrase.insert(14, words); // [...90123abcdefghijklmn456...]

        // ! string1.insert(index1, string2, index2, length2)
        // 在 string1[index1] 【之前】 插入 子字符串 string2[index2, index2 + length2 - 1]
        phrase.insert(13, words, 8, 5); //[...9012ijklm345...]

        // ! string1.insert(index, c_string2, length2)
        // 在 string1[index1] 【之前】 插入 c_string2[0, length - 1]
        // ! c_string2
        // ! 注意这里是字符串字面量
        // ! 不能使用 string1.insert(index, string2, index2)，这里是上文省略了 length，插入 string2[index2, string2.length() - 1]
        phrase.insert(9, "abcdefghijklmn", 4); //[...678abcd901...]

        // ! string1.insert(index1, times, char)
        // 在 string1[index] 之前 插入 times 个 char
        phrase.insert(5, 4, 'o'); //[...234ooo567...]
    }

    // 3.7.2 替换
    {
        std::string phrase{"01234567890123456789"};
        std::string words{"abcdefghijklmn"};
        // ! string1.replace(index1, length1, c_string2)
        // 把 string1[index1, index1 + length1 - 1] 替换 为 c_string2
        phrase.replace(3, 4, "abcd"); // [012abcd789...]

        // ! string1.replace(index1, length1, string2, index2, length2)
        // ! length1 不一定等于 length2
        // 如果 length1 > length2，替换后的字符串会变短，因为移除了更多的字符。
        // 如果 length1 < length2，替换后的字符串会变长，因为插入了更多的字符
        //  把 string1[index1, index1 + length1 - 1] 替换 为 string2[index2, index2 + length2 - 1]
        phrase.replace(10, 5, words, 4, 5); // [d789efghi567..]
        // phrase.replace(10, 5, words, 4, 8); // [d789efghijkl567..]

        // ! string1.replace(index1, length1, times, char)
        // 把 string1[index1, index1 + length1 - 1] 替换 为 times 个 char 字符
        // ! 同上，length1 不必相等 times
        phrase.replace(17, 2, 2, 'o'); // [...456oo9]
    }

    // 3.7.3 删除
    { // ! string1.erase(index1, length1)
        // 从 string1 中删除 string1[index1, index1 + length1 - 1]

        // ! string1.erase(length1)
        // 从 string1 中删除 string1[0, length1 - 1]

        // ! string1.erase()
        // 删除整个 string1

        // erase() 一般和 find() 搭配使用
        // 先找到目标单词，然后删除

        std::string text{"A rose is a rose is a rose."};
        std::string word{"rose"};
        size_t start_word_index = text.find(word);
        while (start_word_index != std::string::npos)
        {
            text.erase(start_word_index, word.length());
            start_word_index = text.find(word, start_word_index + word.length());
        }
        text.erase(4);
        text.erase();
    }
    return 0;
}
