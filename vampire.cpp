/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Vampire class implementation.
 * *Vampire is derived from Character. Vampire includes speial ability of
 * *charm. When charm is envoked, there is a 50/50 chance the attacker
 * *will not actually attack.
 * ************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "vampire.hpp"

using std::cout;
using std::endl; 
using std::string;

Vampire::Vampire()
{
   armor = 1;
   strength = 18;
   description = "Vampire";

   unsigned seed = time(0);
   srand(seed);
}

//calculate attack amount to apply to opponent
int Vampire::attackPly()
{
   int die1Result;

   die1Result = rand() % ATT_SIDES + 1;

   totalResult = die1Result;

   return totalResult;
}

//Vampire uses charm ability during half of the attacks
//against it. Charm keeps the attacker from attacking
void Vampire::defensePly(int attackAmt)
{
   int charm = rand() % CHARM_CHANCE +1;
   tempStrength = strength;
 
   //if charm = 1, no attack, if 2, attack occurs
   if(charm == 1)
   {
      cout << "**CHARM invoked, no attack damage**" << endl;
      totalDamage = 0;
      strength = strength - totalDamage;
   }    
   else
   {
      int die1DefResult;
      tempStrength = strength;

      die1DefResult = rand() % DEF_SIDES + 1;
  

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
}

int Vampire::getTotalAttResult()
{
   return totalResult;
}

int Vampire::getTotalDefResult()
{
   return defendRoll;
}

int Vampire::getTotalDamage()
{
   return totalDamage;
}
