#include "BigNumCalc.h"
#include <list>
#include <string>
#include <iostream> //delete later

std::list<int> BigNumCalc::buildBigNum(std::string numString){
    std::list<int> result;

    int size = numString.size();

    for (int i = 0; i < size; i++){
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
        int num1Size = num1.size();
        if (i < num1Size - 1){
            std::advance(num1Ptr, -1);
        }
        else if (i == num1Size - 1){
            *num1Ptr = 0;
        }

        //iterating the num2Ptr
        int num2Size = num2.size();
        if (i < num2Size - 1){
            std::advance(num2Ptr, -1);
        }
        else if (i == num2Size - 1){
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
    //manage equality
    if (num1 == num2){
        std::list<int> a = {0};
        return a;
    }

    bool negative = false;      //false if num1>num2, true if num2>num1

    //working out if negative
    if (num1.size() > num2.size()){
        negative = false;
    }
    else if (num2.size() > num1.size()){
        negative = true;
    }
    else if (num1.size() == num2.size()){
        auto num1Front = num1.begin();
        auto num2Front = num2.begin();

        //compare individual numbers
        int num1Size = num1.size();
        for(int i = 0; i < num1Size; i++){
            if (*num1Front > *num2Front){
                negative = false;
                break;
            }
            if (*num2Front > *num1Front){
                negative = true;
                break;
            }
            if (num1Front == num2Front){
                std::advance(num1Front, 1);
                std::advance(num2Front, 1);
            }
        }
    }

    //calculating answer
    int remainder = 0;
    int tempResult = 0;
    std::list<int> result;
    int size;
    
    std::list<int> biggerNum;
    std::list<int> smallerNum;

    if (negative == false){
        biggerNum = num1;
        smallerNum = num2;
    }
    else if (negative == true){
        biggerNum = num2;
        smallerNum = num1;
    }

    //determining size
    size = biggerNum.size();

    //initialising ptrs
    auto biggerNumPtr = biggerNum.end();
    std::advance(biggerNumPtr, -1);
    auto smallerNumPtr = smallerNum.end();
    std::advance(smallerNumPtr, -1);

    //loop
    for (int i = 0; i < size; i++){
        tempResult = *biggerNumPtr - *smallerNumPtr - remainder;

        if (tempResult >= 0){
            result.push_front(tempResult);  //can never be greater than 1
            remainder = 0;
        }
        if (tempResult < 0){
            remainder = 1;
            result.push_front(10 + tempResult);
        }

        //iterate ptrs
        if (i < size - 1){
            std::advance(biggerNumPtr, -1);
        }
        else if (i == size - 1){
            *biggerNumPtr = 0;
        }

        //iterating the num2Ptr
        int smallNumSize = smallerNum.size();
        if (i < smallNumSize - 1){
            std::advance(smallerNumPtr, -1);
        }
        else if (i == smallNumSize - 1){
            *smallerNumPtr = 0;
        }
    }

    //deal with leading 0s
    while (result.front() == 0){
        result.pop_front();
    }

    //deal with negatives
    if (negative == true){
        int temp = result.front();
        result.pop_front();
        temp = -1 * temp;
        result.push_front(temp);
    }

    return result;

}

std::list<int> BigNumCalc::mul(std::list<int> num1, std::list<int> num2){
    std::list<int> result;

    //the case for either number being 0
    if (*num1.begin() == 0){
        result.push_back(0);
        return result;
    }
    else if (*num2.begin() == 0){
        result.push_back(0);
        return result;
    }

    //all other cases
    result = num1;

    for (int i = 0; i < *(num2.begin()) - 1; i++){
        result = add(result, num1);
    }

    return result;
}