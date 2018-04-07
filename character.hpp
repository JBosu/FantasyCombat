/***************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: Character class header.
 * *Character is an abstract base class for Vampire, Barabrian, BlueMen,
 * *Medusa, and HarryPotter. Character maintains member variables of
 * *attack, defense, armor, and strength. Pure virtual member functions are
 * *attack and defense.
 * ************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

using std::string;

class Character
{
   protected:
      int attack;
      int defense;
      int armor;
      int strength;
      int tempStrength;
      string description;


   public:
      virtual int attackPly()=0;
      virtual void defensePly(int attackAmt)=0;
      virtual int getTotalAttResult()=0;
      virtual int getTotalDefResult()=0;
      virtual int getTotalDamage()=0; 
      string getDescription();
      int getStrength();
      int getTempStrength();
      int getArmor();
};

#endif
 
