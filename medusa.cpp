/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Medusa class implementation.
 * *Medusa is derived from Character.
 * *Has a special ability of Glare. When glare is envoked the opponent
 * *dies immediately unless a vampire charm is envoked. Harry Potter
 * *can envoke Hogwarts to recover from Glare on its first death.
 * *Glare is envoked by rolling 12.
 * ************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "medusa.hpp"

using std::cout;
using std::endl; 
using std::string;

Medusa::Medusa()
{
   armor = 3;
   strength = 8;
   description = "Medusa";

   unsigned seed = time(0);
   srand(seed);
}

//calculate attack amount to apply to opponent
//If a 12 is rolled, Glare is envoked
int Medusa::attackPly()
{
   int die1Result;
   int die2Result;

   die1Result = rand() % DIE_SIDES + 1;
   die2Result = rand() % DIE_SIDES + 1;

   totalResult = die1Result + die2Result; 

   if(totalResult == 12)
   {
      cout << "**GLARE invoked**" << endl;
      totalResult = totalResult + GLARE;
   }

   return totalResult;
}

//defense against attack
void Medusa::defensePly(int attackAmt)
{
   int die1DefResult;
   tempStrength = strength;

   die1DefResult = rand() % DIE_SIDES + 1;
  
   defendRoll = die1DefResult;

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

int Medusa::getTotalAttResult()
{
   return totalResult;
}

int Medusa::getTotalDefResult()
{
   return defendRoll;
}

int Medusa::getTotalDamage()
{
   return totalDamage;
}
