#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52



        int semester = (17 * 5);
        int dailyhours = 6 ;
        int total_hours = (dailyhours * semester);

    std::cout << "An attandee is spending " << total_hours << " hours with coding."   << std::endl;

            int avarage = (total_hours * 100) / (52 * 17);

    std::cout << "Percentage of coding hours is " << avarage << "%." << std::endl;


    return 0;
}