//Ronak Gorasia
//University of Manchester
//February 2026
//Assignment 1 - The Bohr Atom. This program takes the atomic number Z, the initial energy state, the final energy state,
//and the desired units to calculate the energy difference for a transition in an atom. The program also carries out input 
//validation. 

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <limits>

const double rydberg_energy = 13.6; //in eV

double calculate_bohr_energy(int atomic_number, int initial_energy_state, int final_energy_state, std::string units) 
{
  double energy_shift = ((1/pow(final_energy_state,2))-(1/pow(initial_energy_state,2))); //calculates 1/final_energy_state^2 - 1/initial_energy_state^2
  double energy_difference = rydberg_energy * pow(atomic_number,2)  * energy_shift; //calculates the energy difference
  if(units == "J") return energy_difference * 1.6e-19;
  else if(units == "eV") return energy_difference;
  else std::cout << "Valid unit of energy not given.";
  return 0;
}

void energy_calculation_procedure(){
  int atomic_number;
  int initial_energy_state;
  int final_energy_state;
  std::string units;

  //while loop that validates atomic number input
  while(true) 
  { 
    std::cout << "Enter the atomic number Z: \n";
    if(!(std::cin >> atomic_number))
    {
      std::cout << "Invalid input, please enter an integer. \n"; //rejects non-integer inputs
      std::cin.clear(); //resets input state
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discards bad input
      continue;
    }
    if(atomic_number>0) break;
      std::cout << "Invalid input, atomic number must be greater than 0. \n"; //rejects integer if less than 0
    }
  //while loop that validates initial and final energy states
  while(true) 
  {
    while(true) 
    {
      std::cout << "Enter the initial energy state: \n";
      if(!(std::cin >> initial_energy_state))
      {
        std::cout << "Invalid input, please enter an integer. \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      else break;
    }
        
    while(true)
    {
      std::cout << "Enter the final energy state: \n";
      if(!(std::cin >> final_energy_state))
      {
        std::cout << "Invalid input, please enter an integer. \n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
      }
      else break;
    }
    if(final_energy_state<initial_energy_state) break; //rejects both initial and final states if the final state is larger than the initial state. 
    std::cout << "Invalid input, the final energy state cannot be higher than the initial energy state. \n";
  }

  while(true)
  {
    std::cout << "Enter the units: J/eV \n";
    if(!(std::cin >> units))
    {
      std::cout << "Invalid input, please enter a string. \n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    if((units == "J")||(units == "eV")) break;
    std::cout << "Invalid input, please enter a valid unit of measurement. \n";
  }

  std::cout << "The energy difference is " << calculate_bohr_energy(atomic_number,initial_energy_state,final_energy_state,units) << " " << units << ".\n"; //prints the energy difference
}

int main() 
{
  std::string carry_on = "Y";
  //while loop if the user wants to run procedure multiple times
  while (carry_on == "Y")
  {
    energy_calculation_procedure(); //void function that does input validation and returns energy difference
    std::cout << "Would you still like to carry on?: Y/N ";
    std::cin >> carry_on;
  }
}

