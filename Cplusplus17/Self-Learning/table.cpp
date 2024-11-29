#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

// 简单表格
void printTable(const std::vector<std::string>& headers, const std::vector<std::vector<std::string>>& data) {
    // 打印表头
    for (const auto& header : headers) {
        std::cout << std::setw(15) << std::left << header;
    }
    std::cout << std::endl;

    // 打印分隔行
    for (size_t i = 0; i < headers.size(); ++i) {
        std::cout << std::setw(15) << std::setfill('-') << "" << std::setfill(' ');
    }
    std::cout << std::endl;

    // 打印数据
    for (const auto& row : data) {
        for (const auto& item : row) {
            std::cout << std::setw(15) << std::left << item;
        }
        std::cout << std::endl;
    }
}
// 带有对齐的表格
void printAlignedTable(const std::vector<std::string>& headers, const std::vector<std::vector<int>>& data) {
    // 打印表头
    for (const auto& header : headers) {
        std::cout << std::setw(10) << std::left << header;
    }
    std::cout << std::endl;

    // 打印分隔行
    for (size_t i = 0; i < headers.size(); ++i) {
        std::cout << std::setw(10) << std::setfill('-') << "" << std::setfill(' ');
    }
    std::cout << std::endl;

    // 打印数据
    for (const auto& row : data) {
        for (const auto& item : row) {
            std::cout << std::setw(10) << std::right << item;
        }
        std::cout << std::endl;
    }
}

// 动态表格宽度
void printDynamicTable(const std::vector<std::string>& headers, const std::vector<std::vector<std::string>>& data) {
    // 计算列宽
    std::vector<size_t> widths(headers.size(), 0);
    for (size_t i = 0; i < headers.size(); ++i) {
        widths[i] = headers[i].size();
    }
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            if (row[i].size() > widths[i]) {
                widths[i] = row[i].size();
            }
        }
    }

    // 打印表头
    for (size_t i = 0; i < headers.size(); ++i) {
        std::cout << std::setw(widths[i]) << std::left << headers[i];
    }
    std::cout << std::endl;

    // 打印分隔行
    for (const auto& width : widths) {
        std::cout << std::setw(width) << std::setfill('-') << "" << std::setfill(' ');
    }
    std::cout << std::endl;

    // 打印数据
    for (const auto& row : data) {
        for (size_t i = 0; i < row.size(); ++i) {
            std::cout << std::setw(widths[i]) << std::left << row[i];
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::string> headers = {"Name", "Age", "City"};
    std::vector<std::vector<std::string>> data = {
        {"Alice", "30", "New York"},
        {"Bob", "25", "Los Angeles"},
        {"Charlie", "35", "Chicago"}
    };
    printTable(headers, data);

    std::vector<std::string> headers1 = {"ID", "Score", "Rank"};
    std::vector<std::vector<int>> data1 = {
        {1, 85, 1},
        {2, 75, 2},
        {3, 65, 3}
    };
    printAlignedTable(headers1, data1);

    std::vector<std::string> headers2 = {"Name", "Occupation", "Location"};
    std::vector<std::vector<std::string>> data2 = {
        {"Alice", "Engineer", "San Francisco"},
        {"Bob", "Designer", "New York"},
        {"Charlie", "Teacher", "Chicago"}
    };

    printDynamicTable(headers2, data2);
    return 0;
}
