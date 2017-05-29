/**********************************************
**Program Filename: wreckage.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'wreckage'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "wreckage.hpp"
#include "firepit.hpp"
#include "WWRM.hpp"
#include "DiceRoll.hpp"


using std::cin;
using std::cout;
using std::endl;


/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'wreckage'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Wreckage::moveArea()
{
    //obtain user direction and set room options for area struct
    Room *s = new Firepit;
    Room *e = new WWRM;

    currentLoc = new Area(NULL, s, e, NULL);
    int choice;

    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. South: " << currentLoc->south->getAreaName() << endl;
    cout << "2. East: " << currentLoc->east->getAreaName() << endl;
    cin >> choice;

    if(choice == 1)
    {
        return currentLoc->south;
    }

    if(choice == 2)
    {
        return currentLoc->east;
    }

}

/*****************************************
**Function:menu
**Description: This function allows the
**user to choose what to do on a particular
**area of the island
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: various, add item to bag,
**increase or decrease health, view info
******************************************/
void Wreckage::menu()
{
    //variables to be used in function
    int option;
    Room *s = new Wreckage;
    Roll metal(5,2);
    //area info and menu
    cout << "'This isn't how I got here, somebody else must" << endl;
    cout << "must have crashed here a while ago from the looks" << endl;
    cout << "of it.  It looks like the radio is still in it but" << endl;
    cout << "is broken.  Maybe I can try to fix it" << endl;
    cout << "There is a lot of scrap metal too but I'm not" << endl;
    cout << "sure that I should touch it'\n" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Add the broken radio to the bag" << endl;
    cout << "2. See if anything is in the scrap metal" << endl;
    cout << "3. Main Menu" << endl;
    cin >> option;

    //if they would like to add the broken radio to the bag
    if(option == 1)
    {
        std::string bags;
        bags = s->getItem();
        bagItem = bags;
    }
    //to see if there is anything in the metal
    if(option == 2)
    {
        //to set a low chance of getting the item without getting hurt
        if(metal.rollDie() <= 2)
        {
            cout << "'Yes, a first aid kit, I'll patch myself up'" << endl;
            cout << "You have gained 8 health points\n" << endl;
            healthDamage = 8;
        }
        else
        {
            int scrap;
            //user gets hurt but still has chance to get item
            cout << "'Ouch, that was a bad idea I think there is something" << endl;
            cout << "in there but not sure if its worth it to try and get'" << endl;
            cout << "You have sustained 2 damage points\n" << endl;
            healthDamage = -2;
            //small game to see if they get the item
            cout << "Would you like to try and get what's in the metal?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cin >> scrap;

            //if they want to try and get the item
            if(scrap == 1)
            {
                int guess1;
                int guess2;
                int answer;
                int userAnswer;
                Roll tough(30,3);
                Roll mean(4,1);
                guess1 = tough.rollDie();
                guess2 = mean.rollDie();
                //have them answer question to determine whether they get the item
                cout << "'It looks like there is a first aid kit in there" << endl;
                cout << "I'm not sure how much health it will provide but" << endl;
                cout << "am guessing it is substantial' \n" << endl;
                cout << "To get the first aid kit you must answer the below question" << endl;
                cout << "What does " << guess1 << " modulus " << guess2 << " equal?" << endl;
                answer = guess1 % guess2;
                cin >> userAnswer;
                //if the answer if correct
                if(userAnswer == answer)
                {
                    cout << "Congratulations you have received the first aid kit!" << endl;
                    cout << "It is worth 8 health points\n" << endl;
                    healthDamage = 8;
                }
                //if answer is wrong
                else
                {
                    cout << "I'm sorry that is incorrect" << endl;
                    cout << "The correct answer was " << answer << endl;
                }
            }
        }
    }
    //to return to the main menu
    if(menuOpt == 3)
    {

    }
}

std::string Wreckage::addItem()
{
    return bagItem;
}

int Wreckage::getHealthDamage()
{
    return healthDamage;
}

