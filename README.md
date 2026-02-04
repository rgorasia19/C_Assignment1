# Assignment 1 - The Bohr Atom
## Description
This program calculates the energy difference for an electronic transitions in a hydrogen-like atom using the Bohr Model with the following equation : 
<p align=center> $E = 13.6 Z^2 (\frac{1}{n_{final}^2} - \frac{1}{n_{initial}^2})$.
<p align=justify>The user provides the atomic number, initial and final energy states, and the desired units. 

## Compilation
Compile using a standard C++ compiler, for example:
```bash
g++ -std=c++17 Assignment1.cpp -o Assignment1.exe
```
## Execution
Run the program using:
```bash
./Assignment1.exe
```
## Input Validation
- Atomic number must be a positive integer
- Energy levels must be an integer
- Final energy level must be lower than the initial energy level
- Energy units must be J or eV

## Assumptions
- There are no relativistic effects
- The Bohr model is valid
