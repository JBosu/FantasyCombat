/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: BlueMen class header.
 * *BlueMen is derived from Character.
 * *Special ability of stonger attack when healthy. For each 4 points of
 * *damage to Blue men, they lose one defense die.
 * ************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <string>

#include "character.hpp"

using std::string;

class BlueMen: public Character
{

   public:
      const int ATT_SIDES = 10;
      const int DEF_SIDES = 6;
      int defDieCount;  
      int totalResult;
      int defendRoll; 
      int totalDamage;
 
      BlueMen();
      int attackPly();
      void defensePly(int attackAmt);
      int getTotalAttResult();
      int getTotalDefResult();
      int getTotalDamage();
};

#endif 
