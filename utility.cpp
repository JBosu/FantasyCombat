/***************************************************************************
 * *Program Name: Utilitiy functions 
 * *Author: Jonathan Baldwin
 * *Date: 1/16/2018
 * *description: implementation for various utility functions  
 * ************************************************************************/  

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <ctime>
#include <climits>

#include "utility.hpp"
//#include "character.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stoi;
using std::stringstream;



void printAttackSummary(Character *ptrA, Character *ptrD, int rnd)
{
   cout << "Round " << rnd << " Summary" << endl;
   cout << "-------------------------------" << endl; 
   cout << "Attacker type: " << ptrA->getDescription() << endl; 
   cout << "Defender type: " << ptrD->getDescription() << ", "  
        << "Armor: " << ptrD->getArmor() << ", "
        << "Strength: " << ptrD->getTempStrength() << endl;
   cout << "Attacker's roll: " << ptrA->getTotalAttResult() << endl;
   cout << "Defender's roll: " << ptrD->getTotalDefResult() << endl;
   cout << "Total damage to defender: " << ptrD->getTotalDamage() << endl;
   cout << "Defender's updated strength: " << ptrD->getStrength() << endl;
   cout << endl;
}


void setPlayer(int pType)
{




}



//displays a menu for input 
void displayStartMenu()
{
   cout << endl;   
   cout << "Welcome to Zoo Tycoon" << endl;
   cout << "To begin you must by 1 or 2 each of tigers, penguins, and turtles." << endl;   
   cout << "1 - Play game" << endl;
   cout << "2 - Exit game" << endl; 
}

//display a two-option menu 
bool getEndMenu()
{
   string input;
   int selection;
   bool choice; 
   
   cout << endl;   
   cout << "End of game - would you like to play again?" << endl;
   cout << "1 - Yes, play again." << endl;
   cout << "2 - No, quit." << endl;
   
   while((getline(cin, input)) && 
         (input != "1" && input != "2"))
   {
      cout << "Invalid entry, please re-enter" << endl;
   }  
   selection = stoi(input);
   
   if(selection == 1)
   {
      choice = true;
   }
   else
   {
      choice = false;
   }

   return choice;
}

//if valid input is not entered, it reprompts the user for valid input. 
int getStartMenuSelection()
{
   string input;
   int selection;
   
   cout << "1 - Vampire" << endl;
   cout << "2 - Barbarian" << endl; 
   cout << "3 - Blue Men" << endl; 
   cout << "4 - Medusa" << endl; 
   cout << "5 - Harry Potter" << endl; 


   while((getline(cin, input)) && 
         (input != "1" && input != "2" && input != "3" && input != "4" && input != "5" ))
   {
      cout << "Invalid entry, please re-enter" << endl;
   }  
   selection = stoi(input);
   return selection;
}

int getPositiveInt()
{
   bool errFlag = false;
   string input;
   int validInt;
   const int MIN = 1;
   
   do
   {
      getline(cin, input);
      stringstream sStream(input);

      if(sStream >> validInt && !(sStream >> input))
      {
         if(validInt < MIN || validInt > INT_MAX)
         {
            cout << "Not a valid int, must re-enter: " << endl;
         }
         else
         {
            errFlag = true; 
         }
      }
      else
      {
         cout << "Not a valid int, must re-enter: " << endl; 
      }
   }while(errFlag == false);
   
   return validInt;
}

int getZeroPosInt()
{
   bool errFlag = false;
   string input;
   int validInt;
   const int MIN = 0;
   
   do
   {
      getline(cin, input);
      stringstream sStream(input);

      if(sStream >> validInt && !(sStream >> input))
      {
         if(validInt < MIN || validInt > INT_MAX)
         {
            cout << "Not a valid int, must re-enter: " << endl;
         }
         else
         {
            errFlag = true; 
         }
      }
      else
      {
         cout << "Not a valid int, must re-enter: " << endl; 
      }
   }while(errFlag == false);
   
   return validInt;

}


//if valid input is not entered, it reprompts the user for valid input. 
int getEndMenuSelection()
{
   string input;
   int selection;
  // getline(cin, input);
   cout << "Select an option:" << endl;
   cout << "1 - Continue and play another day." << endl;
   cout << "2 - Quit" << endl;
   while((getline(cin, input)) && 
         (input != "1" && input != "2"))
   {
      cout << "Invalid entry, please re-enter" << endl;
   }  
   selection = stoi(input);
   return selection;
}


//validates integer input within a given range
//Cite: primarily from Canvas conversation @86 Long Le
int validateIntRange(string promptIn, int min, int max)
{
   bool errFlag = false;
   string input;
   int validInt;

   do
   {
      cout << promptIn << endl;
      getline(cin, input);
      stringstream sStream(input);

      if(sStream >> validInt && !(sStream >> input))
      {
         if(validInt < min || validInt > max)
         {
            cout << "Not a valid int, must re-enter: " << endl;
         }
         else
         {
            errFlag = true; 
         }
      }
      else
      {
         cout << "Not a valid int, must re-enter: " << endl; 
      }
   }while(errFlag == false);
   
   return validInt;
}

//validate general int - any size within int range
int validateInt()
{
   bool errFlag = false;
   string input;
   int validInt;

   do
   {
      getline(cin, input);
      stringstream sStream(input);

      if(sStream >> validInt && !(sStream >> input))
      {
         if(validInt < INT_MIN || validInt > INT_MAX)
         {
            cout << "Not a valid int, must re-enter: " << endl;
         }
         else
         {
            errFlag = true; 
         }
      }
      else
      {
         cout << "Not a valid int, must re-enter: " << endl; 
      }
   }while(errFlag == false);
   
   return validInt;
}


int getRandEvent()
{
   unsigned seed;  
   int result;
   const int N = 4; 
   seed = time(0);
   srand(seed);

   result = rand() % N + 1;
   return result;
}

 
int getRandAnimal()
{
   unsigned seed;  
   int result;
   const int N = 3;
   seed = time(0);
   srand(seed);

   result = rand() % N + 1;
   return result;
}

int getRandBonus()
{
   unsigned seed;  
   int result;
   const int MIN = 250;
   const int MAX = 500; 
   seed = time(0);
   srand(seed);

   result = rand() % 250 + 250;
   return result;
}

