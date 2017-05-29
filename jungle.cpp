/**********************************************
**Program Filename: jungle.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'jungle'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "jungle.hpp"
#include "WWRM.hpp"
#include "smallpond.hpp"
#include "cave.hpp"
#include "waterfall.hpp"
#include "DiceRoll.hpp"

using std::cin;
using std::cout;
using std::endl;

/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'jungle'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Jungle::moveArea()
{
    //obtain user direction and set room options for area struct
    Room *n = new WWRM;
    Room *s = new Cave;
    Room *w = new SmallPond;
    Room *e = new Waterfall;

    //create struct
    currentLoc = new Area(n, s, e, w);
    int choice;

    //output areas connected to current location
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North:" << currentLoc->north->getAreaName() << endl;
    cout << "2. South: " << currentLoc->south->getAreaName() << endl;
    cout << "3. East: " << currentLoc->east->getAreaName() << endl;
    cout << "4. West: " << currentLoc->west->getAreaName() << endl;
    cin >> choice;
    //choose where to move to
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
    if(choice == 4)
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
void Jungle::menu()
{
    //variables to be used in function
    int option;
    Room *s = new Jungle;
    Roll monkeys(5,2);
    //menu and area information
    cout << "'This place is creepy, it's so dense and all I can" << endl;
    cout << "hear is the howler monkeys.  It looks like there is wood" << endl;
    cout << "and coconuts here though but it might be dangerous to stay" << endl;
    cout << "too long'\n" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Add wood to the bag" << endl;
    cout << "2. Eat a coconut" << endl;
    cout << "3. Main Menu" << endl;
    cin >> option;

    //if they would like to add the wood to the bag
    if(option == 1)
    {
        std::string bags;
        bags = s->getItem();
        bagItem = bags;
        //to determine if random attack by monkeys
        if(monkeys.rollDie() > 6)
        {
            cout << "Ahhhh, the monkeys are attacking me" << endl;
            cout << "You sustained 3 damage from the monkey attack\n" << endl;
            healthDamage = -3;
        }
    }
    //to eat coconuts
    if(option == 2)
    {
        counter++;
        cout << "Those coconuts are delicious, at least I know where" << endl;
        cout << "a food source is now, but I can't stay here for long" << endl;
        cout << "your health has increased by 1\n" << endl;
        healthDamage = 1;
        //first attack after 2nd time you eat but then every five times
        if(counter % 5 == 2)
        {
            cout << "'I must have outstayed my welcome...'" << endl;
            cout << "Ouch, theses monkeys are no joke'" << endl;
            cout << "You have sustained 3 damage from the attack" << endl;
            healthDamage = -3;
        }
    }
    //to return to main menu
    if(menuOpt == 3)
    {

    }
}

std::string Jungle::addItem()
{
    return bagItem;
}

int Jungle::getHealthDamage()
{
    return healthDamage;
}



