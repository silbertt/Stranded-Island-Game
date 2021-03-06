/**********************************************
**Program Filename: smallpond.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'small pond'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef SMALLPOND_HPP
#define SMALLPOND_HPP

#include "room.hpp"

class SmallPond:public Room
{
    private:

        struct Area
        {
            friend class SmallPond;
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
        SmallPond():Room("Small Pond", "Radio Manual", "Fresh Water"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();
};

#endif // SMALLPOND_HPP
