/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: HarryPotter class header.
 * *HarryPotter is derived from Character.
 * *Special ability of Hogwarts allows Harry Potter to recover from his
 * *first death and recover to a strength of 20. 
 * ************************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include <string>

#include "character.hpp"

using std::string;

class HarryPotter: public Character
{

   public:
      const int DIE_SIDES = 6; 
      int totalResult;
      int defendRoll; 
      int totalDamage;
      int life;
 
      HarryPotter();
      int attackPly();
      void defensePly(int attackAmt);
      int getTotalAttResult();
      int getTotalDefResult();
      int getTotalDamage();
};

#endif 
