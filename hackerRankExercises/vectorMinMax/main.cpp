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

    }
    return evenNumbers;
}
//ASCII
//

void reverseName(std::string inputName)
{
    std::string name = inputName;
    char temp;
    int j = inputName.size()-1;
    for (int i = 0; i < inputName.size()/2; ++i) {
        temp = name[i];
        name[i] = name[j - i];
        name[j-i] = temp;
    }
    std::cout<< name << std::endl;

}

// SZORZÓTÁBLA

std::vector<std::vector<int>> function(int number)
{
    std::vector<std::vector<int>> resultMatrix(number, std::vector<int>(number));
    int size = number;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            resultMatrix[i][j] = (i+1)*(j+1);
        }
    }
    return resultMatrix;
}

std::vector<int> bubbleSort(std::vector<int> inputVector)
{
    std::vector<int> resultVector = inputVector;

    for (int i = 0; i < resultVector.size()-1; ++i) {
        for (int j = 0; j < resultVector.size()-1-i; ++j) {
            if(resultVector[j] > resultVector [j + 1]){
                int temp = resultVector [j];
                    resultVector[j] = resultVector[j + 1];
                    resultVector[j + 1] = temp;

            }
        }
    }
    return resultVector;
}

void stringReverse ( std::string input)
{
    std::string result = input;
    int lenght = result.length();
    char temp;
    for (int i = 0; i < result.length()/2; ++i) {
        temp = result[i];
        result[i] = result[lenght - i -1];
        result[lenght - i -1] = temp;
    }
    std::cout<< result<<std::endl;
}

int main() {
/*
    std::string myName = "Tamas Nemeth";
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
        std::cout << testVector.imgPath[l]<<std::endl;
    }

    reverseName(myName);
*/

    int number = 3;

    std::vector<std::vector<int>> szorzotabla(number, std::vector<int>(number));
    szorzotabla = function(number);

    for (int i = 0; i < szorzotabla.size(); ++i) {
        for (int j = 0; j < szorzotabla.size(); ++j) {
            std::cout<< szorzotabla[i][j]<< " ";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;

    std::vector<int> vectorToSort = {33, 58, 124, 321, 87, 99, 4, 5, 2, 75, 23, 44, 19};
    std::vector<int> sortedVector = bubbleSort(vectorToSort);

    for (int k = 0; k < sortedVector.size(); ++k) {
        std::cout<< sortedVector[k]<< " ";
    }
    std::cout<<std::endl;

    std::string name = "samohT";
    stringReverse(name);

    return 0;
}