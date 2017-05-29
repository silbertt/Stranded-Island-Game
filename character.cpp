/**********************************************
**Program Filename: character.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves to hold data
**on the character in the game
**Input: items to add to their bag, health items,
**location
**Output: location and health
**********************************************/

#include<iostream>
#include<vector>
#include "character.hpp"
#include "room.hpp"

using std::cin;
using std::cout;
using std::endl;

Character::Character(int h, Room *l)
{
    setHealth(h);
    setLocation(l);
}

void Character::setHealth(int h)
{
    health = h;
}

int Character::getHealth()
{
    return health;
}

void Character::setLocation(Room *l)
{
    location = l;
}

std::string Character::getLocation()
{
    return location->getAreaName();
}

/*****************************************
**Function:addItem
**Description: This function takes a string
**and adds it to a vector of items as
**long as it is not oversized
**Parameters: string
**Pre-Conditions: none
**Post-Conditions: string gets added to vector
******************************************/
void Character::addItem(std::string s)
{
    //if bag is empty add item
    if(bag.empty())
    {
        cout << "You have added " << s << " to your bag" << endl;
        bag.push_back(s);
    }

    //if bag is not empty
    else if(bag.size() > 2)
    {
        cout << "Uh-oh, it looks like the bag is full" << endl;
    }
    else
    {
        bag.push_back(s);
        cout << "You have added the item: " << s << " to your bag" << endl;
    }
}


/*****************************************
**Function:areaMove
**Description: This function decreases
**the users health by one every time
**they move areas
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: health decreased by 1
******************************************/
void Character::areaMove()
{
    health--;
}

/*****************************************
**Function:viewItems
**Description: This function allows the user to view
**items currently in their bag
**Parameters: none
**Pre-Conditions: none
**Post-Conditions: displays items in bag
******************************************/
void Character::viewItems()
{
    cout << "Items currently in your bag are:" << endl;
    cout << "********************************" << endl;
    //for loop to display all items
    for(int i = 0; i < bag.size(); i++)
    {
        cout << bag[i] << endl;
    }

}

/*****************************************
**Function:removeItem
**Description: This function allows the user
**to remove items from their bag
**Parameters: string
**Pre-Conditions: item in bag
**Post-Conditions: item removed from bag
******************************************/
void Character::removeItem(std::string r)
{
    //for loop to iterate through bag
    for(int i = 0; i < bag.size(); i++)
    {
        //if the bag and string match remove the item
        if(r == bag[i])
        {
            cout << "You have removed the item: " << bag[i] << " from your bag" << endl;
            bag.erase(bag.begin() + i);
        }
    }
}


/*****************************************
**Function:itemIdUsed
**Description: This function checks to see if an
**item is already in the bag
**Parameters:string
**Pre-Conditions: none
**Post-Conditions: returns true or false dependent
**on if the item is in the bag
******************************************/
bool Character::itemIdUsed(std::string code)
{
    //to iterate through the bag
    for(int i = 0; i < bag.size(); i++)
    {
        //if there is a match
        if(code == bag[i])
        {
            return false;
            break;
        }
    }
    return true;
}
