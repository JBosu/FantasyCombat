/****************************************************************************
 * *Program Name: Fantasy Combat Game
 * *Author: Jonathan Baldwin
 * *Date: 2/13/2018
 * *Description: ./play to run 
 * *Game is comprised of a base class, Character, and subclasses of vampire,
 * *barbarian, bluemen, medusa and harry potter. Each character type has 
 * *unique strength, armor, attack and defense values, and some have special
 * *ability. The game is played between two characters until one runs out of
 * *strength points and dies.
 * *************************************************************************/

#include <iostream>
#include <string>

#include "utility.hpp"
#include "character.hpp"
#include "barbarian.hpp"
#include "vampire.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
   bool playAgain = false;
 
   do
   { 
      int p1Type = 0;
      int p2Type = 0;
      int p1Attack = 0;
      int p2Attack = 0;
      int p1Defense = 0;   
      int p2Defense = 0;
      bool continuePlay = true;
      int round = 1;
      Character *p1Ptr = nullptr;
      Character *p2Ptr = nullptr;
   
      //select the type of character for each player 
      for(int i = 0; i < 2; i++)
      {
         cout << "Select a character for Player " << i + 1 << ":" << endl;
            if(i == 0)
            {
               p1Type = getStartMenuSelection();
                  if(p1Type == 1)
                  {
                     p1Ptr = new Vampire; 
                  }
                  else if(p1Type == 2)
                  {
                     p1Ptr = new Barbarian;
                  }
                  else if(p1Type == 3)
                  {
                     p1Ptr = new BlueMen;
                  }
                  else if(p1Type == 4)
                  {
                     p1Ptr = new Medusa;
                  }
                  else
                  {
                     p1Ptr = new HarryPotter;
                  }
            } 
            else
            {
               p2Type = getStartMenuSelection();
                  if(p2Type == 1)
                  {
                     p2Ptr = new Vampire;
                  }
                  else if(p2Type == 2)
                  {
                     p2Ptr = new Barbarian;
                  }
                  else if(p2Type == 3)
                  {
                     p2Ptr = new BlueMen;
                  }
                  else if(p2Type == 4)
                  {
                     p2Ptr = new Medusa;
                  }
                  else
                  {
                     p2Ptr = new HarryPotter;
                  }
            }
      } 

      //attack / defense loop
      //runs simulation until one character dies 
      do
      {
         p1Attack = p1Ptr->attackPly();
         p2Ptr->defensePly(p1Attack);
         cout << "Player 1 Attack: ";
         printAttackSummary(p1Ptr, p2Ptr, round);

         if(p2Ptr->getStrength() <= 0)
         {
            cout << "Player 1 wins, game over." << endl;
            continuePlay = false;
         }  
         else
         {
            p2Attack = p2Ptr->attackPly();
            p1Ptr->defensePly(p2Attack);
            cout << "Player 2 Attack: ";
            printAttackSummary(p2Ptr, p1Ptr, round);
         
            if(p1Ptr->getStrength() <= 0)
            {
               cout << "Player 2 wins, game over." << endl;
               continuePlay = false;
            } 
         } 

         round++;
    
      }while(continuePlay == true);

      //clear memory after simulation
      delete p1Ptr;
      p1Ptr = nullptr;
      delete p2Ptr;
      p2Ptr = nullptr;

      //prompt user to end or play again
      playAgain = getEndMenu();
      
   }while(playAgain == true);

   return 0;
} 

