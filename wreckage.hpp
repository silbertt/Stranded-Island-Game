/**********************************************
**Program Filename: wreckage.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'wreckage'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef WRECKAGE_HPP
#define WRECKAGE_HPP

#include "room.hpp"

class Wreckage:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class Wreckage;
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
        Wreckage():Room("Wreckage", "broken radio", "sharp metal"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();


};
#endif // WRECKAGE_HPP
