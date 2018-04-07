/**************************************************************************
 * *Program Name: utility functions
 * *Author: Jonathan Baldwin
 * *Date: 1/18/2018
 * *Description: Header file for various utility functions.
 * ************************************************************************/

#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <string>

#include "character.hpp"

using std:: string;


void displayStartMenu();
bool getEndMenu();
int getStartMenuSelection();
int getEndMenuSelection();
int validateIntRange(string promptIn, int min, int max);
int validateInt();
int getRandEvent();
int getRandAnimal();
int getRandBonus();
int getPositiveInt();
int getZeroPosInt();

void setPlayer(int pType);
void printAttackSummary(Character *ptr1, Character *ptr2, int rnd);

#endif
