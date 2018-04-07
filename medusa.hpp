/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Medusa class header.
 * *Medusa is derived from Character.
 * *Has a special ability of Glare. When glare is envoked the opponent
 * *dies immediately unless a vampire charm is envoked. Harry Potter
 * *can envoke Hogwarts to recover from Glare on its first death.
 * *Glare is envoked by rolling 12.
 * ************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <string>

#include "character.hpp"

using std::string;

class Medusa: public Character
{

   public:
      const int DIE_SIDES = 6; 
      const int GLARE = 100;
      int totalResult;
      int defendRoll; 
      int totalDamage;
 
      Medusa();
      int attackPly();
      void defensePly(int attackAmt);
      int getTotalAttResult();
      int getTotalDefResult();
      int getTotalDamage();
};

#endif 
