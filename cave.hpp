/**********************************************
**Program Filename: cave.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'cave'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/


#ifndef CAVE_HPP
#define CAVE_HPP

#include "room.hpp"

class Cave:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class Cave;
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
        Cave():Room("Cave", "flint", "hieroglyphics"){};
        Room* moveArea();
        void menu();
        int getHealthDamage();
        std::string addItem();

};
#endif // CAVE_HPP
