#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cctype>
#include <sstream>
#include <cmath>

void test01()
{
    std::vector<std::string> names;
    std::vector<double> scores;
    std::string name{};
    double score{};
    char choice{'N'};
    do
    {
        std::cout << "Enter name: ";
        std::getline(std::cin, name);
        names.push_back(name);

        std::cout << "Enter score: ";
        std::cin >> score;
        scores.push_back(score);

        std::cout << "Continue? N/Y: " << std::endl;
        std::cin >> choice;
        std::cin.ignore(); // ! 清除输入缓冲区中的换行符
        choice = std::toupper(choice);
    } while (choice == 'Y');

    size_t max_name_length{};
    for (size_t i{}; i < names.size(); ++i)
    {
        max_name_length = (max_name_length >= names[i].length()) ? max_name_length : names[i].length();
    }

    size_t max_score_length{};
    for (size_t i{}; i < scores.size(); ++i)
    {
        max_score_length = (max_score_length >= std::to_string(scores[i]).length()) ? max_score_length : std::to_string(scores[i]).length();
    }
    max_name_length += 3;
    max_score_length += 3;
    std::cout << std::setw(max_name_length) << "Name" << std::setw(max_score_length) << "Score"
              << std::setw(max_name_length) << "Name" << std::setw(max_score_length) << "Score"
              << std::setw(max_name_length) << "Name" << std::setw(max_score_length) << "Score"
              << std::endl;
    for (size_t i{}; i < names.size(); ++i)
    {
        std::cout << std::setw(max_name_length) << names[i] << std::setw(max_score_length) << scores[i];
        if ((i + 1) % 3 == 0)
            std::cout << std::endl;
    }
}

void test02()
{
    std::string text{};
    std::cout << "enter a sentence and stop with '*' " << std::endl;
    std::getline(std::cin, text, '*');

    std::vector<std::string> words;
    std::vector<size_t> words_counts;
    std::string seperators{" ,;:.!?'\""};
    size_t start{text.find_first_not_of(seperators)};
    size_t word_max_length{}; // for output
    while (start != std::string::npos)
    {
        size_t end = text.find_first_of(seperators, start + 1);
        if (end == std::string::npos)
            end = text.length(); // ! text end with no seperator
        std::string word = text.substr(start, end - start);

        bool exist_word = false;
        for (size_t i{}; i < words.size(); ++i)
        {
            if (words[i] == word)
            {
                words_counts[i]++;
                exist_word = true;
                break;
            }
        }
        if (exist_word == false)
        {
            word_max_length = (word_max_length >= word.length()) ? word_max_length : word.length();
            words.push_back(word);
            words_counts.push_back(1);
        }
        start = text.find_first_not_of(seperators, end + 1);
    }

    // output
    const size_t next_line{3};
    for (size_t i{}; i < next_line; ++i)
    {
        std::cout << std::left << std::setw(word_max_length + 3) << "word" << std::right << std::setw(8) << "count" << " ";
    }
    std::cout << std::endl;

    for (size_t i{}; i < words.size(); ++i)
    {
        std::cout << std::left << std::setw(word_max_length + 3) << words[i] << std::right << std::setw(8) << words_counts[i] << " ";
        if ((i + 1) % next_line == 0)
            std::cout << std::endl;
    }
    if (words.size() % next_line == 0)
        std::cout << std::endl;
}

void test03() // ! 要注意要提前分割单词，否则存在包含关系，an 匹配到 want，变成 w**t
{
    std::string text{};
    std::cout << "Enter a sentence end with *" << std::endl;
    std::getline(std::cin, text, '*');
    std::string wordWantToReplace{};
    std::cout << "Enter the word you want to replace: ";
    std::cin >> wordWantToReplace;

    for (auto &ch : wordWantToReplace) // 变为小写
    {
        ch = std::tolower(ch);
    }
    size_t wordWantToReplaceLength{wordWantToReplace.length()};

    std::string text_upper{};
    for (size_t i{}; i < text.length(); ++i)
    {
        text_upper += std::tolower(text[i]); // tolower(ch) 如果 ch 不是大写字母，直接返回 ch
    }

    std::string separators{" ,;:.?!'\""};
    size_t start = text_upper.find_first_not_of(separators);
    while (start != std::string::npos)
    {
        size_t end = text_upper.find_first_of(separators, start + 1);
        if (end == std::string::npos)
            end = text_upper.length();
        std::string word = text_upper.substr(start, end - start);
        if (word.length() == wordWantToReplace.length() && word == wordWantToReplace)
            text.replace(start, wordWantToReplaceLength, wordWantToReplaceLength, '*');
        start = text_upper.find_first_not_of(separators, end + 1);
    }
    std::cout << text << std::endl;
}

void test04()
{
    std::cout << "enter two word, separated by space" << std::endl;
    std::string text1{};
    std::string text2{};
    std::cin >> text1 >> text2;
    bool is_huiwen{true};
    if (text1.length() != text2.length())
    {
        is_huiwen = false;
    }
    else
    {
        size_t length = text1.length();
        for (size_t i{}, j{length - 1}; i < length; ++i, --j)
        {
            if (std::tolower(text1[i]) != std::tolower(text2[j]))
            {
                is_huiwen = false;
                break;
            }
        }
    }
    std::cout << std::boolalpha << is_huiwen << std::endl;
}

void test05()
{
    std::cout << "enter two text, both end with \\n"
              << std::endl;
    std::string text1{};
    std::string text2{};
    std::getline(std::cin, text1, '\n');
    std::getline(std::cin, text2, '\n');
    std::string separators{" ,;:.!?'\""};
    bool is_huiwen{true};
    size_t start1 = text1.find_first_not_of(separators);
    size_t start2 = text2.find_last_not_of(separators);
    while (start1 != std::string::npos && start2 != std::string::npos)
    {
        if (std::tolower(text1[start1]) != std::tolower(text2[start2]))
        {
            is_huiwen = false;
            break;
        }
        start1 = text1.find_first_not_of(separators, start1 + 1);
        start2 = text2.find_last_not_of(separators, start2 - 1);
    }
    if (start1 != std::string::npos || start2 != std::string::npos)
    {
        is_huiwen = false;
    }
    std::cout << std::boolalpha << is_huiwen << std::endl;
}

void test06()
{
    std::cout << "text:" << std::endl;
    std::string text{};
    std::getline(std::cin, text);

    std::cout << "alpha:" << std::endl;
    std::string alphabet{};
    std::getline(std::cin, alphabet);

    std::vector<std::string> output{};
    std::vector<char> alphabets;

    for (size_t i{}; i < alphabet.length(); ++i)
    {
        if (isalpha(alphabet[i]))
        {
            alphabet[i] = std::tolower(alphabet[i]);
            if (alphabet.find(alphabet[i]) < i)
                continue;
            else
                alphabets.push_back(alphabet[i]);
        }
    }

    std::string separators{" ,:;.!?'\""};
    for (size_t i{}; i < alphabets.size(); ++i)
    {
        output.push_back(std::string(1, alphabets[i]) + " : ");
        size_t start = text.find(alphabets[i]);
        while (start != std::string::npos)
        {
            size_t end = text.find_first_of(separators, start + 1);
            if (end == std::string::npos)
                end = text.length();
            size_t true_start{};
            // if (start == 0)
            //     true_start = 0;
            // else
            true_start = start - 1;

            if (start != 0 && std::isalpha(text[true_start])) // 是字母
            {
                start = text.find_first_not_of(separators, end + 1);
                continue;
            }
            else
            {
                std::string word = text.substr(start, end - start);
                if (std::tolower(word[0]) == output[i][0])
                    output[i] += word + " ";
                start = text.find_first_not_of(separators, end + 1);
            }
        }
    }
    for (auto line : output)
    {
        std::cout << line << std::endl;
    }
}

void test07()
{
    std::cout << "enter number, separated by space, end with #" << std::endl;
    std::string numbersString{};
    std::getline(std::cin, numbersString, '#');
    // std::string numbersString{"83.4 12.3 34.4 63.5 2.6 34 325"};
    std::stringstream numbersStringStream{numbersString};

    double total{};

    while (numbersStringStream)
    {
        double number{};
        numbersStringStream >> number;
        total += number;
    }
    std::cout << total << std::endl;
}

void test08()
{
    std::string numbers{};
    std::cout << "Enter a sequence of numbers terminated by #:\n";

    // 收集用户输入
    while (true)
    {
        std::string number{};
        std::cin >> number;
        if (number == "#")
            break;
        numbers += number + ' ';
    }

    double sum = 0.0; // 累积和
    std::string number{};

    for (char ch : numbers)
    {
        if (ch == ' ') // 遇到空格，处理当前数字
        {
            if (!number.empty()) // 避免空数字
            {
                sum += std::stod(number); // 直接用 std::stod，统一处理
                number.clear();           // 清空当前数字
            }
        }
        else
        {
            number += ch; // 累加当前字符
        }
    }

    std::cout << "Sum of numbers: " << sum << std::endl;
}

int main()
{
    size_t number = 8;

    switch (number)
    {
    case 1:
        test01();
        break;
    case 2:
        test02();
        break;
    case 3:
        test03();
        break;
    case 4:
        test04();
        break;
    case 5:
        test05();
        break;
    case 6:
        test06();
        break;
    case 7:
        test07();
        break;
    case 8:
        test08();
        break;
    default:
        break;
    }
    return 0;
}