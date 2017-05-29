/**********************************************
**Program Filename: firepit.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'firepit'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>
#include<string>

#include "firepit.hpp"
#include "beach.hpp"
#include "wreckage.hpp"

using std::cin;
using std::cout;
using std::endl;


/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'firepit'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Firepit::moveArea()
{
     //obtain user direction and set room options for area struct


    Room *s = new Beach;
    Room *n = new Wreckage;

    //set new Area struct
    currentLoc = new Area(n, s, NULL, NULL);
    int choice;

    //output connected areas
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->north->getAreaName() << endl;
    cout << "2. South: " << currentLoc->south->getAreaName() << endl;
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
void Firepit::menu()
{
    //new room item to be able to add item if user chooses
    Room *b = new Firepit;
    //area information and menu
    cout << "'Well it looks like someone was here at some point," << endl;
    cout << "unfortunately the fire is out and all that's in the pit" << endl;
    cout << "is some charred wood which I don't think would be of much use," << endl;
    cout << "I might be able to use a rock from the ring though'" << endl;
    cout << "Whoa, what's that?  It looks like there is a message on" << endl;
    cout << "one of the rock'\n" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Add a rock to your bag" << endl;
    cout << "2. Read message on rock" << endl;
    cout << "3. Main Menu" << endl;
    cin >> menuOpt;

    //if they would like to add item to bag
    if(menuOpt == 1)
    {
        std::string bags;
        bags = b->getItem();
        bagItem = bags;
    }
    //if they would like to read the message
    if(menuOpt == 2)
    {
        cout << "                 ****MESSAGE****" << endl;
        cout << "'Day 39 and it seems like no hope.  I made it to the cliff" << endl;
        cout << "with the fire starter and flint, but still didn't get rescued." << endl;
        cout << "I'm not sure what to do now as the Wildlings have become more aggressive." << endl;
        cout << "I'm nervous I might not last much longer." << endl;
        cout << "295, 295, 295, 295'\n" << endl;
        cout << "'Well that was strange, seems like the numbers from" << endl;
        cout << "the show 'Lost' or something strange'\n" << endl;

    }
    //if they would like to go to the main menu
    if(menuOpt == 3)
    {

    }
}

std::string Firepit::addItem()
{
    return bagItem;
}

int Firepit::getHealthDamage()
{
    return healthDamage;
}
