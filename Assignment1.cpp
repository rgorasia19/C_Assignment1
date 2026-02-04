#include <iostream>
#include <string>
#include <vector>
#include <cmath>

double bohr(int Z, int n_initial, int n_final, std::string units) {
    const double rydberg_energy = 13.6; // in eV
    double energy_shift = ((1/pow(n_final,2))-(1/pow(n_initial,2))); // calculates 1/n_initial^2 - 1/n_final^2
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
    std::cout << "The energy difference is " << bohr(2,4,2,"eV") << "eV.\n";
}

int main() {
    std::string carry_on = "Y";
    while (carry_on == "Y"){
        procedure();
        std::cout << "Would you still like to carry on?: Y/N ";
        std::cin >> carry_on;
    }
}