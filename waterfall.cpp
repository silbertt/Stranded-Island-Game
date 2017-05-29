/**********************************************
**Program Filename: waterfall.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'waterfall'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/


#include<iostream>

#include "waterfall.hpp"
#include "jungle.hpp"
#include "cave.hpp"
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
**Pre-Conditions: user is on 'waterfall'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Waterfall::moveArea()
{
    //obtain user direction and set room options for area struct
    Room *n = new WWRM;
    Room *s = new Cave;
    Room *w = new Jungle;

    //set new struct
    currentLoc = new Area(n, s, NULL, w);
    int choice;

    //output data to user
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->north->getAreaName() << endl;
    cout << "2. South: " << currentLoc->south->getAreaName() << endl;
    cout << "3. West: " << currentLoc->west->getAreaName() << endl;
    cin >> choice;
    //have user choose where to move on the island
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
void Waterfall::menu()
{
    //variables to use in function
    int option;
    Room *s = new Waterfall;
    Roll drink(5,2);

    //area information and menu
    cout << "'Wow, this place is amazing, it's got to be" << endl;
    cout << "the biggest waterfall I've ever seen." << endl;
    cout << "I bet it's safe to drink to but I need to" << endl;
    cout << "get it right where it reaches the pond at" << endl;
    cout << "at the bottom.  There's some sort of fish" << endl;
    cout << "in there too.  Wait, is that what I think" << endl;
    cout << "think it is? A fire starter?" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Drink some water" << endl;
    cout << "2. Try to catch some fish" << endl;
    cout << "3. add fire starter to bag" << endl;
    cout << "4. Main Menu" << endl;
    cin >> option;

    //if they would like to add the spear to the bag
    if(option == 1)
    {

        cout << "Oh No, I didn't realize those were piranha's." << endl;
        cout << "Hopefully I don't disturb them" << endl;
        //to set chance of getting injured
        if(drink.rollDie() <= 3)
        {
            cout << "'They're getting to close... Ahhh'" << endl;
            cout << "You sustained 6 damage while trying escape\n" << endl;
            healthDamage = -6;
        }
        else
        {
            cout << "'It looks like they're keeping to themselves'" << endl;
            cout << "You gained 3 health from the clean drinking water\n" << endl;
            healthDamage = 3;
        }
    }
    //if user would like to try to catch fish
    if(option == 2)
    {
        cout << "'Those piranha's are no joke, I'll give it a try though'" << endl;

        //set low probability of catching fish
        if(drink.rollDie() >= 8)
        {
            cout << "'Yes! I can't believe I caught one, it almost bit my hand off" << endl;
            cout << "but I got it!'" << endl;
            cout << "You gained 6 health from catching a fish\n" << endl;
            healthDamage = 6;
        }
        else
        {
            cout << "'Well I knew my chances were good, but didn't expect to lose a finger." << endl;
            cout << "You sustained 6 damage point from trying to catch a piranha\n" << endl;
            healthDamage = -6;
        }

    }
    //if user would like to add firestarter to bag
    if(option == 3)
    {
        std::string bags;
        bags = s->getItem();
        bagItem = bags;
    }

    //if user would like to return to the main menu
    if(option ==4)
    {

    }

}

std::string Waterfall::addItem()
{
    return bagItem;
}

int Waterfall::getHealthDamage()
{
    return healthDamage;
}

