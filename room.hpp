/**********************************************
**Program Filename: room.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file retains the functions
**and variables of the abstract room class
**Input: none
**Output: none
**********************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

class Room
{
    protected:
        std::string areaName;
        std::string item;
        std::string danger;

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

    public:
        Room(std::string n, std::string i, std::string d);
        void setAreaName(std::string n);
        std::string getAreaName();
        void setItem(std::string i);
        std::string getItem();
        void setDanger(std::string d);
        std::string getDanger();
        virtual void menu()=0;
        virtual Room* moveArea()=0;
        virtual std::string addItem()=0;
        virtual int getHealthDamage()=0;
        Room *north;
        Room *south;
        Room *east;
        Room *west;





};
#endif
