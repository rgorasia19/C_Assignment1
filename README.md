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


## Thought Process
1) Create a function that can return energy difference with given parameters.
2) Loop the energy difference function according to a user input
3) Create code that validates one input only e.g. atomic number and units
4) Create code that validates the coupled inputs of initial and final energy states.
5) Clean code to conform with house style.


## Disclosure of Delegation to Generative AI

The authors declare the use of generative AI in the research and writing process. According to the GAIDeT taxonomy (2025), the following tasks were delegated to GAI tools under full human supervision:

- Idea generation

The GAI tool used was: ChatGPT-5.1.
Responsibility for the final manuscript lies entirely with the authors.
GAI tools are not listed as authors and do not bear responsibility for the final outcomes.
Declaration submitted by: Ronak Gorasia
Additional note: ChatGPT-5.1 was used to teach me how the limits package is used in input validation for C++.
