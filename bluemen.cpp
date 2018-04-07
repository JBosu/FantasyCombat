/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: BlueMen class implementation.
 * *BlueMen is derived from Character.
 * *Special ability of stonger attack when healthy. For each 4 points of
 * *damage to Blue men, they lose one defense die.
 * ************************************************************************/
#include <iostream>
#include <string>
#include <ctime>
#include "bluemen.hpp"

using std::cout;
using std::endl; 
using std::string;

BlueMen::BlueMen()
{
   armor = 3;
   strength = 12;
   description = "BlueMen";
   defDieCount = 3;
  
   unsigned seed = time(0);
   srand(seed);
}

//calulate attack amount to apply to opponent
int BlueMen::attackPly()
{
   int die1Result;
   int die2Result;

   die1Result = rand() % ATT_SIDES + 1;
   die2Result = rand() % ATT_SIDES + 1;

   totalResult = die1Result + die2Result; 

   return totalResult;
}

//special defnse ability. When strong, Blue Men defend with three die
//but for each strength loss of four points, Blue Men lose one 
//defense dice
void BlueMen::defensePly(int attackAmt)
{
   int die1DefResult;
   int die2DefResult;
   int die3DefResult;
   tempStrength = strength;

   if(tempStrength > 8)
   {
      die1DefResult = rand() % DEF_SIDES + 1;
      die2DefResult = rand() % DEF_SIDES + 1;
      die3DefResult = rand() % DEF_SIDES + 1;
      defendRoll = die1DefResult + die2DefResult + die3DefResult;
   }
   else if(tempStrength > 4 && tempStrength < 9) 
   {
      die1DefResult = rand() % DEF_SIDES + 1;
      die2DefResult = rand() % DEF_SIDES + 1;
      defendRoll = die1DefResult + die2DefResult;
   }
   else
   {
      die1DefResult = rand() % DEF_SIDES + 1;
      defendRoll = die1DefResult; 
   } 

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

int BlueMen::getTotalAttResult()
{
   return totalResult;
}

int BlueMen::getTotalDefResult()
{
   return defendRoll;
}

int BlueMen::getTotalDamage()
{
   return totalDamage;
}
