#include<iostream>
#include<string>
#include<vector>
using namespace std;
// f(n) = 2* f(n-1) - f(n-3)
int niuNiuNumbers(int year){
    if(year == 1) return 1;
    else if(year == 2) return 2;
    else if(year == 3) return 3;
    else if(year == 4) return 4;
    else return (2 * niuNiuNumbers(year - 1) - niuNiuNumbers(year - 3));
}

int main()
{
    std::vector<int> outputs;
    int input;
    while(true){
        std::cin >> input;
        if(input == 0) break;
        outputs.push_back(niuNiuNumbers(input));
    }
    
    
    for(auto output:outputs){
        std::cout << output << std::endl;
    }
    
    return 0;   
}