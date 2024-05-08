//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "cell.h"

Cell::Cell(){
    shape = '*';
    row = 'Z';
    column = 0;
    hit = false;
    occupied = false;
}

Cell::Cell(string s, string r, int c, bool h, bool o){
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
int Cell::getColumn(){
    return column;
}
string Cell::getRow(){
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
void Cell::setColumn(int c){
    column = c;
}
void Cell::setRow(string r){
    row = r;
}
void Cell::setHit(bool h){
    hit = h;
}
void Cell::setOccupied(bool o){
    occupied = o;
}
