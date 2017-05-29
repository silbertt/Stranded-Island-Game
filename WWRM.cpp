/**********************************************
**Program Filename: WWRM.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'unknown'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#include<iostream>

#include "WWRM.hpp"
#include "jungle.hpp"
#include "wreckage.hpp"
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
**Pre-Conditions: user is on 'unknown'
**Post-Conditions: user can be in any of the
**connected areas
******************************************/
Room* WWRM::moveArea()
{
    //obtain user direction and set room options for area struct
    Room *w = new Wreckage;
    Room *s = new Jungle;
    Room *e = new Waterfall;
    //create struct with connected areas
    currentLoc = new Area(NULL, s, e, w);
    int choice;

    //output connected areas to user
    cout << "Which part of the island would you like to go to?" << endl;
    cout << "1. North: " << currentLoc->west->getAreaName() << endl;
    cout << "2. South: " << currentLoc->south->getAreaName() << endl;
    cout << "3. East: " << currentLoc->east->getAreaName() << endl;
    cin >> choice;
    //allow user to choose where to move to
    if(choice == 1)
    {
        return currentLoc->west;
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
void WWRM::menu()
{
    //variables to be used
    int option;
    Roll damage(20,1);
    int ouch;
    int answer;
    int incorrect = 100;
    int q = 1;
    Room *s = new WWRM;
    //area information and menu
    cout << "'Whoa, this place looks very sketchy.  I hear" << endl;
    cout << "these strange noises all over, and can't tell" << endl;
    cout << "I'm not safe here... What was that!? Oh No!" << endl;
    cout << "This must be where the Wildlings live!" << endl;
    cout << "Here they come..." << endl;
    cout << "I hope I survive this'\n" << endl;
    cout << "If you can defeat them you will be rewarded" << endl;
    cout << "But if you fail you may not survive" << endl;
    cout << "To beat them you must outsmart them" << endl;
    cout << "and ace the test" << endl;

    //start test
    do
    {
        //questions and answers to questions, break if incorrect
        cout << "Question " << q << ":" << endl;
        cout << "Mt. Everest is the tallest mountain above the sea?" << endl;
        cout << "1. True" << endl;
        cout << "2. False" << endl;
        cin >> answer;
        if(answer == 1)
        {
            cout << "Correct" << endl;
            q++;
        }
        if(answer == 2)
        {
            cout << "Incorrect, you must now suffer the consequences" << endl;
            ouch = damage.rollDie();
            cout << "You have sustained " << ouch << " damage" << endl;
            cout << "and must restart the quiz or leave the area" << endl;
            healthDamage = ouch-ouch-ouch;
            answer = incorrect;
            break;

        }
        cout << "Question " << q << ":" << endl;
        cout << "Only one baseball team plays opening day at home" << endl;
        cout << "every year, what team is it" << endl;
        cout << "1. NY Yankees" << endl;
        cout << "2. Cincinnati Reds" << endl;
        cout << "3. Texas Rangers" << endl;
        cout << "4. LA Dodgers" << endl;
        cin >> answer;
        if(answer == 2)
        {
            cout << "Correct, you are still alive in this battle" << endl;
            q++;
        }
        else
        {
            cout << "Incorrect, you must now suffer the consequences" << endl;
            ouch = damage.rollDie();
            cout << "You have sustained " << ouch << " damage" << endl;
            cout << "and must restart the quiz or leave the area" << endl;
            healthDamage = ouch-ouch-ouch;
            answer = incorrect;
            break;

        }

        cout << "Question " << q << ":" << endl;
        cout << "One of the most historic National Parks in America" << endl;
        cout << "is also hiding a huge amount of magma below it's surface," << endl;
        cout << "which park is it?" << endl;
        cout << "1. Rocky Mountain National Park" << endl;
        cout << "2. Yosemite National Park" << endl;
        cout << "3. Yellowstone National Park" << endl;
        cout << "4. Grand Canyon National Park" << endl;
        cin >> answer;

        if(answer == 3)
        {
            cout << "Correct, well done. There is still one question to go" << endl;
            q++;
        }
        else
        {
            cout << "Incorrect, you must now suffer the consequences" << endl;
            ouch = damage.rollDie();
            cout << "You have sustained " << ouch << " damage" << endl;
            cout << "and must restart the quiz or leave the area" << endl;
            healthDamage = ouch-ouch-ouch;
            answer = incorrect;
            break;
        }
        cout << "Question " << q << ":" << endl;
        cout << "Which US State shares the longest border" << endl;
        cout << "with a foreign country?" << endl;
        cout << "1. Texas" << endl;
        cout << "2. Montana" << endl;
        cout << "3. Washington" << endl;
        cout << "4. Alaska" << endl;
        cin >> answer;

        if(answer == 4)
        {
            cout << "Correct, you have defeated the Wildlings" << endl;
            cout << "And can now explore the area" << endl;
        }
        else
        {
            cout << "Incorrect, you must now suffer the consequences" << endl;
            ouch = damage.rollDie();
            cout << "You have sustained " << ouch << " damage" << endl;
            cout << "and must restart the quiz or leave the area" << endl;
            healthDamage = ouch-ouch-ouch;
            answer = incorrect;
            break;
        }

        //if user got quiz correct
        //variables to be used
        Roll health(10,1);
        int upgrade;
        //set health upgrade
        upgrade = health.rollDie();
        cout << "Congratulations, you have defeated the Wildlings." << endl;
        cout << "For beating them you will receive " << upgrade << " health points.\n" << endl;
        healthDamage = upgrade;

        //allow user to get area item if they want
        cout << "'Wow, I didn't know they were such intellectuals. Looks" << endl;
        cout << "like there is something on the ground over there." << endl;
        cout << "It can't be... They must have taken the radio parts" << endl;
        cout << "Those could be really helpful." << endl;
        cout << "But I'm not too sure, the might be worthless\n" << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Pick up radio parts" << endl;
        cout << "2. Main Menu"  << endl;
        cin >> option;

        //if they want area item
        if(option == 1)
        {
            std::string bags;
            bags = s->getItem();
            bagItem = bags;
            break;
        }
        else
        {
            break;
        }
    }
    while(answer != incorrect);
}

std::string WWRM::addItem()
{
    return bagItem;
}

int WWRM::getHealthDamage()
{
    return healthDamage;
}


