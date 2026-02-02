#include <iostream>
#include <string>
#include <vector>
#include <cmath>

double bohr(int Z, int n_initial, int n_final, std::string units) {
    const double rydberg_energy = 13.6; // in eV
    double energy_shift = ((1/pow(n_final,2))-(1/pow(n_initial,2))); // calculates 1/n_initial^2 - 1/n_final^2
    double energy_difference = rydberg_energy * pow(Z,2)  * energy_shift; // calculates the energy difference
    return energy_difference;
}

int main() {
    double test = bohr(2,3,1,"eV");
    std::cout << "The energy difference is " << test << "eV.\n"; // outputs the energy diff
}