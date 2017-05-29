/**********************************************
**Program Filename: beach.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'beach'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "firepit.hpp"
#include "brush.hpp"
#include "smallpond.hpp"
#include "beach.hpp"
#include "DiceRoll.hpp"


using std::cin;
using std::cout;
using std::endl;

/*****************************************
**Function:moveArea
**Description: This function allows the user
**to move to connected parts of the island
**Parameters: none
**Pre-Conditions: user is on 'beach'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* Beach::moveArea()
{
    //obtain user direction and set room options for area struct
    Firepit *n = new Firepit;
    Brush *s = new Brush;
    SmallPond *e = new SmallPond;

    //set area struct
    currentLoc = new Area(n, s, e, NULL);
    int choice;

    //give user options of connected areas
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->north->getAreaName() << endl;
    cout << "2. South: " << currentLoc->south->getAreaName() << endl;
    cout << "3. East: " << currentLoc->east->getAreaName() << endl;
    cin >> choice;

    //return user choice
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
void Beach::menu()
{
    //set new room to beach
    Room *b = new Beach;
    int option;
    //area information and options
    cout << "'It's scorching out here in the sun, I hope I can find" << endl;
    cout << "some shade soon. It looks like there happens to be" << endl;
    cout << "a spear here.  I wonder if people do live on the island?" << endl;
    cout << "It looks like there might be some sort of fish in the" << endl;
    cout << "shallows as well that could be nice food source, but" << endl;
    cout << "I'm not sure if they're dangerous or not'\n" << endl;
    cout << "What would you like to do?" << endl;
    cout << "1. Add the spear to the bag" << endl;
    cout << "2. Try to catch some fish" << endl;
    cout << "3. Main Menu" << endl;
    cin >> option;

    //if they would like to add the spear to the bag
    if(option == 1)
    {
        std::string bags;
        bags = b->getItem();
        bagItem = bags;
    }
    //allow user to try to catch fish
    if(option == 2)
    {
        //create Roll object for probability
        Roll chance(5, 2);
        cout << "'Those fish look pretty mean out there, but" << endl;
        cout << "They could provide some food.  I'm going for it...'\n" << endl;

        //if roll is less than or equal to 5
        if(chance.rollDie() <= 5)
        {
            cout << "'OUCH!!!, I've got blood running down my leg, I better" << endl;
            cout << "get out of the water'\n" << endl;
            cout << "You have sustained 3 damage points from attempting to fish" << endl;
            healthDamage = -3;
        }
        else
        {
            cout << "'Yes, some food! That was tough but worth it\n" << endl;
            cout << "You have gained 3 health points" << endl;
            healthDamage = 3;
        }
     }
     //allow user to return to main menu
     if(option == 3)
     {

     }
}

std::string Beach::addItem()
{
    return bagItem;
}

int Beach::getHealthDamage()
{
    return healthDamage;
}


