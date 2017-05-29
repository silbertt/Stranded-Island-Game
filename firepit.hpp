/**********************************************
**Program Filename: firepit.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'firepit'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef FIREPIT_HPP
#define FIREPIT_HPP

#include "room.hpp"


class Firepit:public Room
{
    private:

        struct Area
        {
            friend class Firepit;
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
        Area *currentLoc;
        int menuOpt;
        std::string bagItem;
        int healthDamage;


    public:
        Firepit():Room("Fire Pit", "Rock", "Leftover Meat"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();
};

#endif // FIREPIT_HPP

