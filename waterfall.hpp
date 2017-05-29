/**********************************************
**Program Filename: waterfall.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'waterfall'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef WATERFALL_HPP
#define WATERFALL_HPP

#include "room.hpp"

class Waterfall:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class Waterfall;
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
        Waterfall():Room("Waterfall", "fire starter", "piranha"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();

};
#endif // WATERFALL_HPP
