/**********************************************
**Program Filename: smallpond.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'small pond'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include <iostream>

#include "smallpond.hpp"
#include "beach.hpp"
#include "jungle.hpp"
#include "brush.hpp"
#include "DiceRoll.hpp"

using std::cin;
using std::cout;
using std::endl;

/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'small pond'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* SmallPond::moveArea()
{
    //obtain user direction and set room options for area struct

    //set connected rooms
    Room *s = new Brush;
    Room *w = new Jungle;
    Room *e = new Beach;

    //create struct
    currentLoc = new Area(NULL, s, e, w);
    int choice;

    //output options to move to
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. South: " << currentLoc->south->getAreaName() << endl;
    cout << "2. East: " << currentLoc->east->getAreaName() << endl;
    cout << "3. West: " << currentLoc->west->getAreaName() << endl;
    cin >> choice;
    //obtain user choice
    if(choice == 1)
    {
        return currentLoc->south;
    }
    if(choice == 2)
    {
        return currentLoc->east;
    }
    if(choice == 3)
    {
        return currentLoc->west;
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
void SmallPond::menu()
{
    //room instance to pass item if user would like to add it to bag
    Room *s = new SmallPond;
    //dice class variable
    Roll water(5,2);
    //area info and menu
    cout << "'Ahh, a pond, this water looks good but I'm not sure" << endl;
    cout << "if it's safe to drink.  It looks like there is some sort of" << endl;
    cout << "book on the edge of the water.  Why would a 'radio manual'" << endl;
    cout << "be out here?  That's strange.'" << endl;
    cout << "1. Add the radio manual to your bag" << endl;
    cout << "2. Drink the water" << endl;
    cout << "3. Main Menu" << endl;
    cin >> menuOpt;

    //if user would like to add the radio manual to bag
    if(menuOpt == 1)
    {
        std::string bags;
        bags = s->getItem();
        bagItem = bags;
    }
    //if user would like to drink the water
    if(menuOpt == 2)
    {
        //for chances of getting sick v health
        if(water.rollDie() <= 5)
        {
            cout << "'Wow, that tastes amazing and I feel okay'" << endl;
            cout << "You have gained 2 health points\n" << endl;
            healthDamage = 2;
        }
        else
        {
            cout << "Oh no, I think I'm going to be sick" << endl;
            cout << "You have sustained 4 damage points" << endl;
            healthDamage = -4;
        }
    }
    //to return to the main menu
    if(menuOpt == 3)
    {

    }
}

std::string SmallPond::addItem()
{
    return bagItem;
}

int SmallPond::getHealthDamage()
{
    return healthDamage;
}
