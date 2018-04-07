/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description:Vampire class header.
 * *Vampire is derived from Character. Vampire includes speial ability of
 * *charm. When charm is envoked, there is a 50/50 chance the attacker
 * *will not actually attack.
 * ************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <string>

#include "character.hpp"

using std::string;

class Vampire: public Character
{

   public:
      const int ATT_SIDES = 12;
      const int DEF_SIDES = 6; 
      const int CHARM_CHANCE = 2; 
      int totalResult;
      int defendRoll; 
      int totalDamage;
 
      Vampire();
      int attackPly();
      void defensePly(int attackAmt);
      int getTotalAttResult();
      int getTotalDefResult();
      int getTotalDamage();
};

#endif 
