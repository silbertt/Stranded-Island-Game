/**********************************************
**Program Filename: cave.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'cave'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "cave.hpp"
#include "jungle.hpp"
#include "cliff.hpp"
#include "waterfall.hpp"


using std::cin;
using std::cout;
using std::endl;

/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'cave'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Cave::moveArea()
{
    //obtain user direction and set room options for area struct
    Room *n = new Jungle;
    Room *w = new Cliff;
    Room *e = new Waterfall;

    currentLoc = new Area(n, NULL, e, w);
    int choice;

    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->north->getAreaName() << endl;
    cout << "2. East: " << currentLoc->east->getAreaName() << endl;
    cout << "3. West: " << currentLoc->west->getAreaName() << endl;
    cin >> choice;

    if(choice == 1)
    {
        return currentLoc->north;
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
void Cave::menu()
{
    //variables to be used
    int option;
    int first;
    int second;
    int third;
    Room *s = new Cave;

    //area info and menu
    cout << "'Wow, this place is crazy, it's so dark" << endl;
    cout << "It's tough to tell if there is anything in here" << endl;
    cout << "Oh, wait, I think I see something written on the wall" << endl;
    cout << "Hieroglyphics? crazy.  Someone must have been here too" << endl;
    cout << "There is a piece of flint on the ground, but no sign of" << endl;
    cout << "a fire... Strange'\n" << endl;
    cout << "1. Add the flint to the bag" << endl;
    cout << "2. Read the hieroglyphics" << endl;
    cout << "3. Main Menu" << endl;
    cin >> option;

    //if they would like to add the spear to the bag
    if(option == 1)
    {
        std::string bags;
        bags = s->getItem();
        bagItem = bags;
    }
    //if they would like to read the hieroglyphics
    if(option == 2)
    {
        //have user input code to decipher, code is what was at the firepit
        cout << "'It's just pictures, maybe I can decipher it'" << endl;
        cout << "To decipher the code you must guess a three digit combination" << endl;
        cout << "of integers 1-9" << endl;
        cout << "Please enter the combination followed by hitting enter" << endl;
        cin >> first;

        //if code is correct
        if(first == 295)
        {
            cout << "Congratulations you have decoded the hieroglyphics" << endl;
            cout << "'It looks like is shows a fire on a cliff?" << endl;
            cout << "Maybe I need to have a fire on the cliff" << endl;
            cout << "to be rescued, lets see if it says anything else" << endl;
            cout << "It looks like a person carrying a few items..." << endl;
            cout << "Is that a fire starter, flint, and some brush?" << endl;
            cout << "Maybe I need those items and to be at the cliff" << endl;
            cout << "to be rescued?'\n" << endl;
        }
        else
        {
            cout << "I'm sorry that combination is incorrect\n" << endl;
        }
    }
    //to return to the main menu
    if(option == 3)
    {

    }
}

std::string Cave::addItem()
{
    return bagItem;
}

int Cave::getHealthDamage()
{
    return healthDamage;
}


