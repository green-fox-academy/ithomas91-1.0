
#include <iostream>
#include <vector>

// Create a simple calculator application which reads the parameters from the prompt
// and prints the result to the prompt.

// It should support the following operations: +, -, *, /, % and it should support two operands.
// The format of the expressions must be: {operation} {operand} {operand}.
// Examples:
// "+ 3 3" (3 + 3 -> the result will be 6)
// "* 4 4" (4 * 4 -> the result will be 16)
// "/ 20 8" (20 / 8 -> the result will be 2)
// "% 20 8" (20 % 8 -> the result will be 4)

// It should work like this:
// Start the program
// It prints: "Please type in the expression:"
// Waits for the user input
// Print the result to the prompt
// Exit

void calculator(int userInput1, std::string operation,  int userInput2)
{
    std::cin >> userInput1;
    std::cin >> userInput2;
    std::cin >> operation;
    float result = 0;

    std::vector<std::string> operations = {"+", "-", "*", "/", "%"};
    for (int i = 0; i < operations.size(); ++i) {
        if (operation == operations[i]) {
            std::cout << userInput1, operations[i], userInput2;
        } else if (operation == "-") {
            result = userInput1 - userInput2;
        } else if (operation == "*") {
            result = userInput1 * userInput2;
        } else if (operation == "/") {
            result = userInput1 / userInput2;
        } else if (operation == "%") {
            result = userInput1 % userInput2;
        }
        std::cout << result;

    }

}

int main(int argc, char *args[])
{
    int userInput11;
    int userInput22;
    std::string operation;


    std::cout << "Please type in the expression: " << std::endl;
    std::cout << "The way has to be 1: operand, 2: operation, 3: operand." << std::endl;
    std::cin >> userInput11;
    std::cin >> userInput22;
    std::cin >> operation;
    calculator(userInput11, operation, userInput22);

    return 0;
}