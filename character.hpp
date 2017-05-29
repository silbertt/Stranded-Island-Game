/**********************************************
**Program Filename: character.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves to hold data
**on the character in the game
**Input: items to add to their bag, health items,
**location
**Output: location and health
**********************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include <vector>
#include "room.hpp"

class Character
{
    private:
        int health;
        Room *location;
        std::vector<std::string> bag;

    public:
        Character(int h, Room *l);
        void setHealth(int h);
        int getHealth();
        void areaMove();
        void addItem(std::string s);
        void removeItem(std::string r);
        void viewItems();
        void setLocation(Room *l);
        std::string getLocation();
        bool itemIdUsed(std::string j);

};
#endif // CHARACTER_HPP
