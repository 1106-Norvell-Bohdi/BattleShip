//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef SHIP_H
#define SHIP_H
#include "cell.h"

class Ship{
    char shape;
    string name;
    int length;
    bool isSunk;
    cell firstSpace, lastSpace;

    public:

    Ship();
    Ship(char, string, int, bool, cell);
    Ship(const Ship&);

    char getShape();
    string getName();
    int getLength();
    bool getIsSunk();
    cell getFirstSpace();
    cell getLastSpace();

    void setShape(char);
    void setName(string);
    void setLength(int);
    void setIsSunk(bool);
    void setFirstSpace(cell);
    void setLastSpace(cell);

    void checkIfHit();
};
#endif
