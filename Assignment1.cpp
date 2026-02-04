#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

double bohr(int Z, int n_initial, int n_final, std::string units) {
    const double rydberg_energy = 13.6; // in eV
    double energy_shift = ((1/pow(n_final,2))-(1/pow(n_initial,2))); // calculates 1/n_final^2 - 1/n_initial^2
    double energy_difference = rydberg_energy * pow(Z,2)  * energy_shift; // calculates the energy difference
    if (units == "J"){
        return energy_difference * 1.6e-19;
    }
    else if (units == "eV"){
        return energy_difference;
    }
    else{
        std::cout << "Valid unit of energy not given.";
    }
}

void procedure(){
    // declaring variables
    int Z; // atomic number
    int n_initial; //initial energy level
    int n_final; //final energy level
    std::string units; //units in "J" or "eV"
    
    // while loop that validates atomic number input
    while (true) {
        std::cout << "Enter the atomic number Z: \n";
        if (!(std::cin >> Z)){
            std::cout << "Invalid input, please enter an integer. \n"; //rejects non-integer inputs
            std::cin.clear(); //resets input state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards bad input
            continue;
        }
        if (Z>0) break;
        std::cout << "Invalid input, atomic number must be greater than 0. \n"; //rejects integer if less than 0
    }

    while (true) {
        while (true) {
            std::cout << "Enter the initial energy state: \n";
            if (!(std::cin >> n_initial)){
                std::cout << "Invalid input, please enter an integer. \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        
        while (true) {
            std::cout << "Enter the final energy state: \n";
            if (!(std::cin >> n_final)){
                std::cout << "Invalid input, please enter an integer. \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
            else break;
        }
        if (n_final<n_initial) break;
        std::cout << "Invalid input, the final energy state cannot be higher than the initial energy state. \n";
    }

    while (true) {
        std::cout << "Enter the units: J/eV \n";
        if (!(std::cin >> units)){
            std::cout << "Invalid input, please enter a string. \n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        if ((units == "J")||(units == "eV")) break;
        std::cout << "Invalid input, please enter a valid unit of measurement. \n";

    }

    std::cout << "The energy difference is " << bohr(Z,n_initial,n_final,units) << " " << units << ".\n"; //prints the energy difference
}

int main() {
    std::string carry_on = "Y";
    // while loop if the user wants to run procedure multiple times
    while (carry_on == "Y"){
        procedure(); // void function that does input validation and returns energy difference
        std::cout << "Would you still like to carry on?: Y/N ";
        std::cin >> carry_on;
    }
}