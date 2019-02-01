#include <iostream>
#include <vector>
#include <map>

int number = 10;

int sum(int number1, int number2);


int main() {

    std::map<std::string, int> namesOfAges;

    namesOfAges ["Snocc"]= 38;
    namesOfAges ["Gergo"]= 27;

    std::cout<<sum(namesOfAges["Gergo"], namesOfAges["Snocc"])<<std::endl;

    int scafterten = sum(namesOfAges["Snocc"], number);
    int grgafterten = sum(namesOfAges["Gergo"], number);

    std::cout<<"Guys after ten years: "<<"Snocc: "<< scafterten<<" "<<"Gergo: "<<grgafterten<< std::endl;

    std::vector<std::map<std::string, int>> vec = {namesOfAges};

    for (int i = 0; i < vec.size; i++){



    }

    return 0;
}

int sum(int number1, int number2) {

    int sum = number1 + number2;



    return sum;
}
