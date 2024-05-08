//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "cell.h"

Cell::Cell(){
    shape = '*';
    column = 'C';
    row = 0;
    hit = false;
    occupied = false;
}

Cell::Cell(string s, string c, int r, bool h, bool o){
    shape = s;
    column = c;
    row = r;
    hit = h;
    occupied = o;
}
Cell::Cell(const Cell& rhs){
    shape = rhs.shape;
    column = rhs.column;
    row = rhs.row;
    hit = rhs.hit;
    occupied = rhs.occupied;
}

string Cell::getShape(){
    return shape;
}
string Cell::getColumn(){
    return column;
}
int Cell::getRow(){
    return row;
}
bool Cell::getHit(){
    return hit;
}
bool Cell::getOccupied(){
    return occupied;
}

void Cell::setShape(string s){
    shape = s;
}
void Cell::setColumn(string c){
    column = c;
}
void Cell::setRow(int r){
    row = r;
}
void Cell::setHit(bool h){
    hit = h;
}
void Cell::setOccupied(bool o){
    occupied = o;
}
