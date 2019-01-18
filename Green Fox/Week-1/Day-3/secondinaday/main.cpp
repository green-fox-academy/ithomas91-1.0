#include <iostream>


// Write a program that prints the remaining seconds (as an integer) from a
// day if the current time is represented by the variables


int main(int argc, char* args[]) {

    int currentHours = 14;
    int currentMinutes = 34;
    int currentSeconds = 42;


    int day = 24;
    int hour = 60;
    int minutes = 60;

    int lefthours = (day - currentHours);
    int leftminutes = (hour - currentMinutes);
    int leftseconds = (minutes - currentSeconds);

    int inseconds = ((lefthours * 60 * 60)+(leftminutes * 60)+ (leftseconds));



    std::cout <<"Time left of the day: "<< lefthours<< " hours "<<leftminutes <<" minutes " << leftseconds<<" seconds"<< std::endl<<std::endl;

    std::cout << "All together in seconds: "<< inseconds <<std::endl;

    return 0;
}


