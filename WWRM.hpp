/**********************************************
**Program Filename: WWRM.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'unknown'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef WWRM_HPP
#define WWRM_HPP

#include "room.hpp"

class WWRM:public Room
{
    protected:

        Room* newLoc;

        struct Area
        {
            friend class WWRM;
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
        WWRM():Room("Unknown", "radio parts", "Wildlings"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();



};
#endif // WWRM_HPP
