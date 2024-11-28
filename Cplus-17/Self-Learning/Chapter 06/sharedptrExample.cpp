#include <iostream>
#include <memory>
#include <vector>
#include <iomanip>
#include <cctype>

int main()
{
    // 创建指向存储温度的容器的指针
    // 一个 vector 容器包含多个 shared_ptr 指针
    // 每一个 shared_ptr 指针指向一个存储类型的 double 的 vector 容器
    std::vector<std::shared_ptr<std::vector<double>>> records;
    size_t day{1}; // 第一天
    while (true)
    {
        // std::shared_ptr<std::vector<double>> dayRecords{std::make_shared<std::vector<double>>()};
        auto dayRecords{std::make_shared<std::vector<double>>()}; // 指向每一天的温度容器的指针
        records.push_back(dayRecords);                            // 把 当天温度容器 对应的指针 放入总容器
        std::cout << "输入第 " << day++ << " 天的温度，用空格分开，以 1000 结束" << std::endl;
        while (true)
        {
            double temperature{};
            std::cin >> temperature;
            if (temperature == 1000.0)
                break;
            dayRecords->push_back(temperature); // (*dayRecords).push_back(temperature)
        }
        std::cout << "是否输入下一天的温度？('Y' or 'N')" << std::endl;
        char answer{};
        std::cin >> answer;
        if (std::toupper(answer) == 'N')
            break;
    }

    day = 1; // 注意，这里不是初始化了，不能用 {}
    std::cout << std::fixed << std::setprecision(2) << std::endl;
    for (auto record : records)
    {
        double total{};
        size_t count((*record).size());
        std::cout << "\n 第 " << day++ << " 天的温度" << ":\n";
        for (size_t i{}; i < count; ++i)
        {
            std::cout << (*record)[i] << " ";
            total += (*record)[i];
        }
        // 这里的 for 循环可以用 auto，temp 值是每一天中记录的每一个温度
        // for (auto temp : *record)
        // {
        //     total += temp;
        //     std::cout << temp << " ";
        // }
        
        std::cout << "\n平均温度：" << total / count << std::endl;
    }

    return 0;
}
