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
    int remainder = 0;
    int tempResult = 0;
    std::list<int> result;
    int size;
    auto num1Ptr = num1.end();
    std::advance(num1Ptr, -1);
    auto num2Ptr = num2.end();
    std::advance(num2Ptr, -1);

    //determining size for loop
    if (num1.size() > num2.size()){
        size = num1.size() + 1;
    }
    else {
        size = num2.size() + 1;
    }

    for (int i = 0; i < size; i++){
        //adding the three numbers together
        tempResult = *num1Ptr + *num2Ptr + remainder;

        //pushing front the last digit of remainder
        result.push_front(tempResult%10);

        //getting the remainder
        remainder = (tempResult/10)%10;

        //iterating the num1Ptr
        if (i < num1.size() - 1){
            std::advance(num1Ptr, -1);
        }
        else if (i == num1.size() - 1){
            *num1Ptr = 0;
        }

        //iterating the num2Ptr
        if (i < num2.size() - 1){
            std::advance(num2Ptr, -1);
        }
        else if (i == num2.size() - 1){
            *num2Ptr = 0;
        }
    }

    //ensure there are no leading 0's
    while (result.front() == 0){
        result.pop_front();
    }

    return result;
    
}

std::list<int> BigNumCalc::sub(std::list<int> num1, std::list<int> num2){

}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){

}