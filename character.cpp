/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Character class implementation.
 * *Character is an abstract base class for Vampire, Barabrian, BlueMen,
 * *Medusa, and HarryPotter. Character maintains member variables of
 * *attack, defense, armor, and strength. Pure virtual member functions are
 * *attack and defense.
 * ************************************************************************/

#include <iostream>

#include "character.hpp"

using std::cout;
using std::endl;


string Character::getDescription()
{
   return description;
} 

int Character::getStrength()
{
   return strength;
}

int Character::getTempStrength()
{
   return tempStrength;
}

int Character::getArmor()
{
   return armor;
}


