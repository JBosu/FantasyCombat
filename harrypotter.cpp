/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: HarryPotter class implementation.
 * *HarryPotter is derived from Character.
 * *Special ability of Hogwarts allows Harry Potter to recover from his
 * *first death and recover to a strength of 20. 
 * ************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "harrypotter.hpp"

using std::cout;
using std::endl; 
using std::string;

HarryPotter::HarryPotter()
{
   armor = 0;
   strength = 10;
   description = "HarryPotter";
   life = 1;

   unsigned seed = time(0);
   srand(seed);
}

//calculate attack amount to apply to opponent
int HarryPotter::attackPly()
{
   int die1Result;
   int die2Result;

   die1Result = rand() % DIE_SIDES + 1;
   die2Result = rand() % DIE_SIDES + 1;

   totalResult = die1Result + die2Result; 

   return totalResult;
}

//defense roll
//if Harry Potter dies on his first life, special ability
//Hogwarts is envoked and he gains a second life with
//strength of 20
void HarryPotter::defensePly(int attackAmt)
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
  
   if(strength <= 0 && life == 1)
   {
      cout << "**Hogwarts invoked - Harry Potter lives again**" << endl;
      strength = 20;
      life = 2; 
   } 
}

int HarryPotter::getTotalAttResult()
{
   return totalResult;
}

int HarryPotter::getTotalDefResult()
{
   return defendRoll;
}

int HarryPotter::getTotalDamage()
{
   return totalDamage;
}
