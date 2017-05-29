/**********************************************
**Program Filename: cliff.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'cliff'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "cliff.hpp"
#include "brush.hpp"
#include "cave.hpp"
#include "DiceRoll.hpp"


using std::cin;
using std::cout;
using std::endl;


Room* Cliff::moveArea()
{
    //obtain user direction and set room options for area struct
    Room *n = new Brush;
    Room *e = new Cave;

    currentLoc = new Area(n, NULL, e, NULL);
    int choice;

    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->north->getAreaName() << endl;
    cout << "2. East: " << currentLoc->east->getAreaName() << endl;
    cin >> choice;

    if(choice == 1)
    {
        return currentLoc->north;
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
void Cliff::menu()
{
    //variables to be used
    Roll cloud(3,1);
    int cloudNum;
    int guess;
    int option;
    Room *s = new Cliff;

    //area info and user menu and small game
    cout << "'Wow, the view up here is incredible I can see forever." << endl;
    cout << "Is that what I think it is?! A battery? What a strange" << endl;
    cout << "Place for that to be.  What was that? I heard something." << endl;
    cout << "That doesn't look like a normal cloud, it's moving to fast," << endl;
    cout << "making too much noise!'\n" << endl;
    cout << "Before proceeding you must defeat the 'dark cloud'" << endl;
    cout << "To defeat the dark cloud you must correctly guess a number" << endl;
    cout << "The cloud is thinking of a number between 1-3, if you" << endl;
    cout << "guess incorrectly there will be consequences" << endl;
    cout << "Please enter your number:" << endl;
    cin >> guess;

    cloudNum = cloud.rollDie();
    //if guess is correct
    if(cloudNum == guess)
    {
        //allow user to add item to bag
        cout << "Congratulations the 'dark cloud' is gone for now.  You may now" << endl;
        cout << "collect any items at the cliff\n" << endl;
        cout << "Would you like to add the batteries to your bag?" << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        cin >> option;

        //if user would like to add item to bag
        if(option == 1)
        {
            std::string bags;
            bags = s->getItem();
            bagItem = bags;
        }
    }
    //if guess is incorrect
    else
    {
        cout << "You have guessed the incorrect number" << endl;
        cout << "The 'dark cloud' struck you with lightning" << endl;
        cout << "causing 8 damage points" << endl;
        healthDamage = -8;
    }

}

std::string Cliff::addItem()
{
    return bagItem;
}

int Cliff::getHealthDamage()
{
    return healthDamage;
}

