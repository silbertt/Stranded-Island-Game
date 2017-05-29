/**********************************************
**Program Filename: beach.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'beach'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef BEACH_HPP
#define BEACH_HPP

#include "room.hpp"

class Beach:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class Beach;
            Room *north;
            Room *south;
            Room *east;
            Room *west;
            Area(Room *n, Room *s, Room *e, Room *w)
            {
                north = n;
                south = s;
                east = e;
                west = w;
            }
        };
        int movement;
        int menuOpt;
        Area *currentLoc;
        std::string bagItem;
        int healthDamage;

    public:
        Beach():Room("Beach", "Spear", "Fish"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();



};
#endif // BEACH_HPP
