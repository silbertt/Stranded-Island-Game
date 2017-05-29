/**********************************************
**Program Filename: brush.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'brush'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "brush.hpp"
#include "beach.hpp"
#include "smallpond.hpp"
#include "cliff.hpp"
#include "DiceRoll.hpp"

using std::cin;
using std::cout;
using std::endl;

/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'brush'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Brush::moveArea()
{
    //obtain user direction and set room options for area struct


    Room *n = new SmallPond;
    Room *s = new Cliff;
    Room *e = new Beach;

    //set new struct
    currentLoc = new Area(n, s, e, NULL);
    int choice;
    //display connected areas
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->north->getAreaName() << endl;
    cout << "2. South: " << currentLoc->south->getAreaName() << endl;
    cout << "3. East: " << currentLoc->east->getAreaName() << endl;
    cin >> choice;
    //let user choose where to move to
    if(choice == 1)
    {
        return currentLoc->north;
    }
    if(choice == 2)
    {
        return currentLoc->south;
    }
    if(choice == 3)
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
void Brush::menu()
{
    //new room to be able to get the item in area
    Room *b = new Brush;
    //area information and menu
    cout << "'It's so stinking hot here this brush would probably help to make a good fire." << endl;
    cout << "I better be careful here though as I've seen a few snakes and can't tell if" << endl;
    cout << "they're poisonous or not'\n" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Add Brush to your bag?" << endl;
    cout << "2. Try to kill a snake?" << endl;
    cout << "3. Main Menu" << endl;
    cin >> menuOpt;

    //if user would like to add item to bag
    if(menuOpt == 1)
    {
        std::string bags;
        bags = b->getItem();
        bagItem = bags;
    }
    //if user would like to hunt
    if(menuOpt == 2)
    {
        Roll die(5,2);
        //for probability of injury v health
        if(die.rollDie() <= 8)
        {
            cout << "'Oh no, this could be bad, that snake bit me and I'm not" << endl;
            cout << "sure if it was poisonous'\n" << endl;
            cout << "You have sustained 6 damage points" << endl;
            healthDamage = -6;
        }
        else
        {
            cout << "'WOW, I can't believe I caught a snake!'\n" << endl;
            cout << "You have gained 3 health points" << endl;
            healthDamage = 3;
        }
    }
    //to return to main menu
    if(menuOpt == 3)
    {

    }
}

std::string Brush::addItem()
{
    return bagItem;
}

int Brush::getHealthDamage()
{
    return healthDamage;
}
