//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std; 

class Cell{
    protected:
    char shape, column;
    int row;
    bool hit;
    bool occupied;

    public:
    Cell();
    Cell(char, string, int, bool, bool);
    Cell(const Cell&);

    char getShape();
    char getColumn();
    int getRow();
    bool getHit();
    bool getOccupied();

    void setShape(char);
    void setColumn(char);
    void setRow(int);
    void setHit(bool);
    void setOccupied(bool);
};
#endif