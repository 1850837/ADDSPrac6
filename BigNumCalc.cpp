#include "BigNumCalc.h"
#include <list>
#include <string>

std::list<int> BigNumCalc::buildBigNum(std::string numString){
    std::list<int> result;

    for (int i = 0; i < numString.size(); i++){
        result.push_back((int)numString[i] - 48);
    }

    return result;
}

std::list<int> BigNumCalc::add(std::list<int> num1, std::list<int> num2){

}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){

}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){

}