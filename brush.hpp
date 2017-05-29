/**********************************************
**Program Filename: brush.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves as the 'brush'
**area for the game
**Input: user input for choosing new area,
**and what to do in the area
**Output: user menus for area
**********************************************/

#ifndef BRUSH_HPP
#define BRUSH_HPP

#include "room.hpp"


class Brush:public Room
{
    private:

        struct Area
        {
            friend class Brush;
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
        Brush():Room("Brush", "Brush", "snakes"){};
        Room* moveArea();
        void menu();
        std::string addItem();
        int getHealthDamage();

};

#endif // BRUSH_HPP
