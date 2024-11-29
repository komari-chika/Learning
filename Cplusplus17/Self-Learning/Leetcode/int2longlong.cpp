#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 函数：将代码中的 int 替换为 long long
string replaceIntWithLongLong(const string& code) {
    string result;
    bool inString = false; // 用于标识是否在字符串中
    bool inComment = false; // 用于标识是否在块注释中

    for (size_t i = 0; i < code.size(); i++) {
        if (inComment) { // 在块注释中
            result += code[i];
            if (i > 0 && code[i - 1] == '*' && code[i] == '/') {
                inComment = false; // 块注释结束
            }
            continue;
        }

        if (!inString && i + 1 < code.size() && code[i] == '/' && code[i + 1] == '*') {
            inComment = true; // 块注释开始
            result += "/*";
            i++;
            continue;
        }

        if (!inString && i + 1 < code.size() && code[i] == '/' && code[i + 1] == '/') {
            result += code.substr(i); // 直接保留行内注释
            break;
        }

        if (code[i] == '"') {
            inString = !inString; // 切换字符串状态
        }

        if (!inString && i + 2 < code.size() && code.substr(i, 3) == "int" &&
            (i == 0 || !isalnum(code[i - 1])) &&
            (i + 3 == code.size() || !isalnum(code[i + 3]))) {
            result += "long long"; // 替换 int 为 long long
            i += 2; // 跳过 "int" 的后两个字符
        } else {
            result += code[i];
        }
    }

    return result;
}

// 测试函数
int main() {
    // 测试用例
    vector<string> testCases = {
        "int a;", 
        "int main() {", 
        "    int b = 5;", 
        "    printf(\"int is not replaced inside string\");", 
        "    // This is an int in a comment", 
        "    /* This is a block comment with int inside */", 
        "    return 0;", 
        "}"
    };

    // 输出原始代码和替换后的代码
    cout << "Original Code:" << endl;
    for (const string& line : testCases) {
        cout << line << endl;
    }

    cout << "\nModified Code:" << endl;
    for (const string& line : testCases) {
        cout << replaceIntWithLongLong(line) << endl;
    }

    return 0;
}
