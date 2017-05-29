/**********************************************
**Program Filename: room.cpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file retains the functions
**and variables of the abstract room class
**Input: none
**Output: none (this is abstract)
**********************************************/

#include <iostream>
#include <string>

#include "room.hpp"


//constructor setting name, item, and danger
Room::Room(std::string n, std::string i, std::string d)
{
    setAreaName(n);
    setItem(i);
    setDanger(d);
}

void Room::setAreaName(std::string n)
{
    areaName = n;
}

void Room::setItem(std::string i)
{
    item = i;
}

void Room::setDanger(std::string d)
{
    danger = d;
}

std::string Room::getAreaName()
{
    return areaName;
}

std::string Room::getItem()
{
    return item;
}

std::string Room::getDanger()
{
    return danger;
}



