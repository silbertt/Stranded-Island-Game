/**********************************************
**Program Filename: cliff.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'cliff'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef CLIFF_HPP
#define CLIFF_HPP

#include "room.hpp"

class Cliff:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class Cliff;
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
        Cliff():Room("Cliff", "batteries", "'dark cloud'"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();

};
#endif // CLIFF_HPP
