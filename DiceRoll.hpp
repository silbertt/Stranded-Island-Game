/**********************************************
**Program Filename: DiceRoll.hpp
**Author:Teage Silbert
**Date:6/9/15
**Description:This file serves to randomize
**certain events
**Input: number of faces and dice
**Output: none
**********************************************/

#ifndef DICEROLL_H
#define DICEROLL_H

class Roll
{
    private:
        int faces;
        int dice;
        int rolls;

    public:
        Roll(int f, int d);
        void setFaces(int f);
        void setDice(int d);
        int rollDie();


};
#endif // DICEROLL_H
