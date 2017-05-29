/**********************************************
**Program Filename: LostIsland.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the main file
**for the 'Lost Island' game
**Input: menu options
**Output: location, health, game status
**********************************************/

#include <iostream>
#include <string>
#include <ctime>

#include "character.hpp"
#include "room.hpp"
#include "beach.hpp"
#include "firepit.hpp"
#include "brush.hpp"
#include "smallpond.hpp"
#include "wreckage.hpp"
#include "jungle.hpp"
#include "WWRM.hpp"
#include "waterfall.hpp"
#include "cave.hpp"
#include "cliff.hpp"
#include "DiceRoll.hpp"

#include "character.cpp"
#include "room.cpp"
#include "beach.cpp"
#include "firepit.cpp"
#include "brush.cpp"
#include "smallpond.cpp"
#include "wreckage.cpp"
#include "jungle.cpp"
#include "WWRM.cpp"
#include "waterfall.cpp"
#include "cave.cpp"
#include "cliff.cpp"
#include "DiceRoll.cpp"

using std::cout;
using std::cin;
using std::endl;

int main()
{
    //for output purposes
    int dashes = 65;
    std::string dash;
    dash.assign(dashes, '*');
    //for rolldice function
    srand(time(NULL));

    //display game info
    cout << dash << endl;
    cout << "You've just crash landed on a remote island." << endl;
    cout << "It looks like there may have been people here" << endl;
    cout << "at some point but it may have been some time." << endl;
    cout << "but it might be a good idea to explore a little bit to" << endl;
    cout << "see what you can find.\n" << endl;
    cout << "You currently have 25 health points and moving from" << endl;
    cout << "area to area will decrease it by 1 due to fatigue." << endl;
    cout << "However there are also opportunities to add to your health" << endl;
    cout << "but beware that there can be a risk to trying certain things" << endl;
    cout << "as well and are wild creatures that are known to be" << endl;
    cout << "unpredictable\n" << endl;
    cout << "To be rescued you must explore the island, collect items and then use them" << endl;
    cout << "to notify the search teams" << endl;
    cout << "(you are only able to carry up to 3 items)\n" << endl;
    cout << "Please press enter to continue" << endl;
    cout << dash << endl;
    cin.get();

    cout << "You have three options of where to begin your Journey" << endl;

    //create pointer to room and starting pointer
    Room *island;
    Room *start = new Beach;
    Roll dice(10, 1);
    //create character pointer
    Character *survivor = new Character(25, start);
    //give initial option on where to start game
    island = start->moveArea();
    //set the characters location on the island
    survivor->setLocation(island);
    //for user input in game menu
    int play;

    do
    {
        //if game is won by starting a fire on the cliff
        if(island->getAreaName() == "Cliff" && (!survivor->itemIdUsed("fire starter")) && (!survivor->itemIdUsed("flint"))
           && (!survivor->itemIdUsed("Brush")))
        {
            cout << dash << endl;
            cout << "\nCongratulations you made it to the cliff with the Fire Starter," << endl;
            cout << "Flint, and Brush! your signal fire was easily visible to rescuers" << endl;
            cout << "from this location and you are now safe" << endl;
            cout << "          ****GAME OVER****\n" << endl;
            cout << dash << endl;
            break;
        }
        //if game is won by repairing the radio
        if((!survivor->itemIdUsed("Radio Manual")) && (!survivor->itemIdUsed("broken radio")) && (!survivor->itemIdUsed("batteries")))
        {
            cout << dash << endl;
            cout << "Congratulations! You were able to get all the items to fix the radio" << endl;
            cout << "and call for help! You have been rescued!" << endl;
            cout << "           ****GAME OVER****" << endl;
            cout << dash << endl;
            break;
        }

        //if health is low inform user
        if(survivor->getHealth() <= 5)
        {
            cout << "WARNING YOUR HEALTH IS AT:" << survivor->getHealth() << endl;
        }

        //to determine random attacks from the wildlings
        if(dice.rollDie() == 1)
        {
            cout << dash << endl;
            cout << "             WILDLING ATTACK" << endl;
            //if the character has either a spear or rock in their bag
            if(!survivor->itemIdUsed("Spear") || (!survivor->itemIdUsed("Rock")))
            {
                int ouch;
                ouch = dice.rollDie()/2;
                cout << "Due to you having a Spear or Rock you only sustained " << ouch << " damage points" << endl;
                cout << "Without the spear or Rock you would have sustained " << ouch*2 << " damage points" << endl;
                survivor->setHealth(survivor->getHealth() - 4);
                cout << dash << endl;
            }
            //if they don't have a spear or rock in their bag
            else
            {   int pain;
                pain = dice.rollDie();
                cout << "The Wildlings took " << pain << " damage points before you could fend them off" << endl;
                survivor->setHealth(survivor->getHealth() - pain);
                cout << dash << endl;
            }
        }
        //If survivor dies
        if(survivor->getHealth() <= 0)
        {
            cout << dash << endl;
            cout << "Unfortunately your health has diminished and you were unable" << endl;
            cout << "to be rescued.   ****GAME OVER***" << endl;
            cout << dash << endl;
            break;
        }

        //main game menu
        cout << dash << endl;
        cout << "               ---------CHARACTER INFORMATION---------" << endl;
        cout << "Current Island Location: " << survivor->getLocation() << endl;
        //if user health is below 0 reset to 0 to avoid negative numbers
        if(survivor->getHealth() <= 0)
        {
            survivor->setHealth(0);
        }
        cout << "Current Health: " << survivor->getHealth() << endl;
        cout << dash << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Search the area" << endl;
        cout << "2. Move to a different part of the island" << endl;
        cout << "3. Check items in bag" << endl;
        cout << "4. Remove an item from the bag" << endl;
        cout << "5. Quit Game" << endl;
        cout << "6. CHEAT GUIDE" << endl;
        cin >> play;

        //if user would like to search the area they're in
        if(play == 1)
        {
            //go to the area menu
            island->menu();
            //if user chooses to add item from the area to bag
            if(!island->addItem().empty())
            {
                //check to see if they have the item
                if(survivor->itemIdUsed(island->addItem()))
                {
                    //if they don't have the item, add it to the bag
                    survivor->addItem(island->addItem());
                }
                else
                {
                    cout << "It looks like that item is already in your bag" << endl;
                }

            }
            //to set damage or health sustained
            if(island->getHealthDamage() != 0)
            {
                survivor->setHealth(survivor->getHealth() +island->getHealthDamage());
            }
        }
        //if the user would like to move areas
        if(play == 2)
        {
            //call island move area function and set new room to island
            island = island->moveArea();
            //output new area name
            cout << island->getAreaName() << endl;
            //set location of survivor
            survivor->setLocation(island);
            //decrease health by 1 for movement
            survivor->areaMove();
        }
        //show items in the users bag
        if(play == 3)
        {
            survivor->viewItems();
        }

        //remove an item from the users bag
        if(play == 4)
        {
            std::string removal;
            cout << "What item would you like to remove from your bag?" << endl;
            cout << "(Please use the same punctuation is display when" << endl;
            cout << "viewing items in the bag)" << endl;
            cin.ignore();
            getline(cin, removal);
            survivor->removeItem(removal);
        }

        //for TA so they know how to beat the game
        if(play == 6)
        {
            cout << "There are two ways to win this game:" << endl;
            cout << "collect the fire starter(location waterfall)" << endl;
            cout << "flint(location cave), and brush(location Brush)" << endl;
            cout << "and be located at the cliff" << endl;
            cout << "Or collect the broken radio (location wreckage)" << endl;
            cout << "the radio manual(location small pond), and the batteries" << endl;
            cout << "(location cliff), 'radio parts' are not necessary" << endl;
            cout << "for the second scenario your location doesn't matter" << endl;
            cout << "QUIZ ANSWERS:" << endl;
            cout << "Everest is the tallest" << endl;
            cout << "Cincinnati Reds play at home" << endl;
            cout << "Yellowstone is potentially dangerous" << endl;
            cout << "Alaska has the longest border" << endl;
            cout << "combination is 295 for code, it is stated at beach" << endl;
            cout << "and used at the cave" << endl;
         }
    }
    while(play != 5);

    return 0;
}
