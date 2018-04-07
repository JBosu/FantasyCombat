/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Barbarian class header.
 * *Barbarian is derived from Character. Has no special ability. 
 * ************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <string>

#include "character.hpp"

using std::string;

class Barbarian: public Character
{

   public:
      const int DIE_SIDES = 6; 
      int totalResult;
      int defendRoll; 
      int totalDamage;
 
      Barbarian();
      int attackPly();
      void defensePly(int attackAmt);
      int getTotalAttResult();
      int getTotalDefResult();
      int getTotalDamage();
};

#endif 
