#include "BigNumCalc.h"
#include <iostream>

int main(){

    BigNumCalc a;

    std::list<int> b = a.buildBigNum("300076895");
    auto b_front = b.begin();

    for (int i = 0; i < b.size(); i++){
        std::cout << *b_front << " ";
        std::advance(b_front, 1);
    }
    std::cout << "\n";

    return 0;
}