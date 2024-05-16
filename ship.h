//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef SHIP_H
#define SHIP_H
#include "cell.h"

class Ship{
    string name, shape;
    int length, hits;
    bool isSunk, orientation;
    Cell* firstSpace; 
    Cell* lastSpace;

    public:

    Ship();
    Ship(string, string, int, int, bool, Cell*, Cell*, bool);
    Ship(const Ship&);

    string getShape();
    string getName();
    int getLength();
    int getHits();
    bool getIsSunk();
    bool getOrientation();
    Cell* getFirstSpace();
    Cell* getLastSpace();

    void setShape(string);
    void setName(string);
    void setLength(int);
    void setHits(int);
    void setIsSunk(bool);
    void setOrientation(bool);
    void setFirstSpace(Cell*);
    void setLastSpace(Cell*);

    friend ostream& operator <<(ostream&, Ship*);
};
#endif
