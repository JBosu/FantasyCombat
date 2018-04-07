/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Barbarian class implementation.
 * *Barbarian is derived from Character.
 * ************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "barbarian.hpp"

using std::cout;
using std::endl; 
using std::string;

Barbarian::Barbarian()
{
   armor = 0;
   strength = 12;
   description = "Barbarian";

   unsigned seed = time(0);
   srand(seed);
}

//calculate attack amount to apply to opponent 
int Barbarian::attackPly()
{
   int die1Result;
   int die2Result;

   die1Result = rand() % DIE_SIDES + 1;
   die2Result = rand() % DIE_SIDES + 1;

   totalResult = die1Result + die2Result; 

   return totalResult;
}

//defense - no special ability
void Barbarian::defensePly(int attackAmt)
{
   int die1DefResult;
   int die2DefResult;
   tempStrength = strength;

   die1DefResult = rand() % DIE_SIDES + 1;
   die2DefResult = rand() % DIE_SIDES + 1;
  
   defendRoll = die1DefResult + die2DefResult;

   if((attackAmt - defendRoll - armor) > 0)
   {
      totalDamage = attackAmt - defendRoll - armor;  
   }
   else
   {
      totalDamage = 0;
   }
   
   strength = strength - totalDamage;
}

int Barbarian::getTotalAttResult()
{
   return totalResult;
}

int Barbarian::getTotalDefResult()
{
   return defendRoll;
}

int Barbarian::getTotalDamage()
{
   return totalDamage;
}
