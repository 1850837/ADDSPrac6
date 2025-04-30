#include "BigNumCalc.h"
#include <iostream>

int main(){

    BigNumCalc a;

    // std::list<int> b = a.buildBigNum("300076895");
    // auto b_front = b.begin();

    // for (int i = 0; i < b.size(); i++){
    //     std::cout << *b_front << " ";
    //     std::advance(b_front, 1);
    // }
    // std::cout << "\n";

    std::list<int> num1 = a.buildBigNum("52983741982");
    std::list<int> num2 = a.buildBigNum("238974120");

    std::list<int> result = a.add(num1, num2);
    auto resultFront = result.begin();

    for (int i = 0; i < result.size(); i++){
        std::cout << *resultFront;
        std::advance(resultFront, 1);
    }
    std::cout << "\n";

    return 0;
}