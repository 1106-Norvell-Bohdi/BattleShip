//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef SHIP_H
#define SHIP_H
#include "cell.h"

class Ship{
    string name, shape;
    int length;
    bool isSunk;
    Cell* firstSpace; 
    Cell* lastSpace;

    public:

    Ship();
    Ship(string, string, int, bool, Cell*, Cell*);
    Ship(const Ship&);

    string getShape();
    string getName();
    int getLength();
    bool getIsSunk();
    Cell* getFirstSpace();
    Cell* getLastSpace();

    void setShape(string);
    void setName(string);
    void setLength(int);
    void setIsSunk(bool);
    void setFirstSpace(Cell*);
    void setLastSpace(Cell*);

    void checkIfHit();
};
#endif
