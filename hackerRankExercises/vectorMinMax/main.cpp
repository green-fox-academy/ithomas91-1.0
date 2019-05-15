#include <iostream>
#include <vector>
#include "struct.h"

typedef enum
{
    EVEN,
    ODD

} typeNumbers_t;

int lookMin(std::vector<int> inputVector)
{
    int min = UINT8_MAX;
    for (int i = 0; i < inputVector.size(); ++i) {
        if(inputVector[i] < min ){
            min = inputVector[i];
        }
    }
    return min;
}
int lookMax(std::vector<int> inputVector)
{
    int max = 0;
    for (int i = 0; i < inputVector.size(); ++i) {
        if(inputVector[i] > max){
            max = inputVector[i];
        }
    }
    return max;
}

std::vector<int> insertionSort(std::vector<int> inputMatrix)
{
    std::vector<int> resultVector = inputMatrix;
    for (int i = 0; i < resultVector.size(); ++i) {
        int temp = resultVector[i];
        int j = i - 1;
        while (j >= 0 && resultVector[j] > temp) {
            resultVector[j + 1] = resultVector[j];
            j--;
        }
        resultVector[j + 1] = temp;

    }
    return resultVector;
}

std::vector<int> sortNumbersEvenOdd(std::vector<int> inputVector, typeNumbers_t typeOfNumbers)
{
    std::vector<int> oddNumbers;
    std::vector<int> evenNumbers;
    if(typeOfNumbers == ODD){
        for (int i = 0; i < inputVector.size(); ++i) {
            if(inputVector[i] % 2 == 1){
                oddNumbers.push_back(inputVector[i]);
            }
        }
        return oddNumbers;
    }
    if(typeOfNumbers == EVEN){
        for (int i = 0; i < inputVector.size(); ++i) {
            if(inputVector[i] % 2 == 0){
                evenNumbers.push_back(inputVector[i]);
            }
        }
        return evenNumbers;
    }
}
//ASCII
//

int main() {


    std::vector<int> numberVector = {-5, -3, -1, 1, 3, 1452, 11, 5, 66, 34, 89, 111, 54};
    int minimumNumber = lookMin(numberVector);
    int maximumNumber = lookMax(numberVector);
    std::vector<int> resultVector = insertionSort(numberVector);
    std::vector<int> oddNumbers = sortNumbersEvenOdd(numberVector, ODD);
    std::vector<int> evenNumbers = sortNumbersEvenOdd(numberVector, EVEN);


    std::cout<< "The smallest integer oft the vector is: " << minimumNumber << "\nThe maximum number is : "
    << maximumNumber << std::endl;

    for (int i = 0; i < resultVector.size(); ++i) {
        std::cout << resultVector[i] << " " ;
    }
    std::cout<<std::endl;

    for (int j = 0; j < oddNumbers.size(); ++j) {
        std::cout << oddNumbers[j] << " ";
    }
    std::cout<<std::endl;

    for (int k = 0; k < evenNumbers.size(); ++k) {
        std::cout<< evenNumbers[k] << " ";
    }
    std::cout<<std::endl;

    std::string imageName1 = "IMG_123";
    std::string imageName2 = "IMG_321";


    test_t testVector;
    testVector.imgPath.push_back(imageName1);
    testVector.imgPath.push_back(imageName2);

    for (int l = 0; l < 2; ++l) {
        std::cout << testVector.imgPath[l];
    }


    return 0;
}