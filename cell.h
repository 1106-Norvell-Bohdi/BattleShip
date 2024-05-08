//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef CELL_H
#define CELL_H
#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std; 

class Cell{
    
    string shape, column;
    int row;
    bool hit;
    bool occupied;

    public:
    Cell();
    Cell(string, string, int, bool, bool);
    Cell(const Cell&);

    string getShape();
    string getColumn();
    int getRow();
    bool getHit();
    bool getOccupied();

    void setShape(string);
    void setColumn(string);
    void setRow(int);
    void setHit(bool);
    void setOccupied(bool);
};
#endif