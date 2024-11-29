#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    size_t n{};
    cin >> n;
    vector<vector<int>> numberss;
    size_t q{};
    cin >> q;
    for(size_t i{};i<n;++i){
        size_t k;
        cin >> k;
        vector<int> numbers;
        int number{};
        for(size_t j{};j<k;j++){
            cin >> number;
            numbers.push_back(number);
        }
        numberss.push_back(numbers);
    }
    vector<int> answers;
    for(size_t i{};i<q;++i){
        size_t ss{};
        cin >> ss;
        size_t s{};
        cin >> s;
        answers.push_back(numberss.at(ss).at(s));
    }
    for(auto answer:answers){
        cout << answer << endl;
    }
        
    return 0;
}
