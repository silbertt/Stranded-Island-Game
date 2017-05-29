/**********************************************
**Program Filename: jungle.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'jungle'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef JUNGLE_HPP
#define JUNGLE_HPP

#include "room.hpp"

class Jungle:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class Jungle;
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
        int counter;

    public:
        Jungle():Room("Jungle", "wood", "howler monkeys"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();


};
#endif
