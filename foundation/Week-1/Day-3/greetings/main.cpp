#include <iostream>
#include <string>
void greet (std::string x);
int main() {
    std::string al = "Greenfox";
    greet(al);
    return 0;
}
void greet(std::string x){
    std::cout << "Greetings dear, " << x << std::endl;
}
