//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "ship.h"

Ship::Ship(){
    shape = 'S';
    name = "Ship";
    length = 3; // Total Ship Sizes: 2, 3. 3,4,5
    hits = 0;
    isSunk = false;
    firstSpace = new Cell;
    lastSpace = new Cell;
    orientation = false;
}
Ship::Ship(string n, string s, int l, int h, bool is, Cell* fs, Cell* ls, bool o){
    shape = s;
    name = n;
    length = l;
    hits = h;
    isSunk = is;
    firstSpace = fs;
    lastSpace = ls;
    orientation = o;
}

Ship::Ship(const Ship& rhs){
    shape = rhs.shape;
    name = rhs.name;
    length = rhs.length;
    hits = rhs.hits;
    isSunk = rhs.isSunk;
    firstSpace = rhs.firstSpace;
    lastSpace = rhs.lastSpace;
    orientation = rhs.orientation;
}

string Ship::getShape(){
    return shape;
}
string Ship::getName(){
    return name;
}
int Ship::getLength(){
    return length;
}
int Ship::getHits(){
    return hits;
}
bool Ship::getIsSunk(){
    return isSunk;
}
bool Ship::getOrientation(){
    return orientation;
}
Cell* Ship::getFirstSpace(){
    return firstSpace;
}
Cell* Ship::getLastSpace(){
    return lastSpace;
}

void Ship::setShape(string s){
    shape = s;
}
void Ship::setName(string n){
    name = n;
}
void Ship::setLength(int l){
    length = l;
}
void Ship::setHits(int h){
    hits = h;
}
void Ship::setIsSunk(bool is){
    isSunk = is;
}
void Ship::setOrientation(bool o){
    orientation = o;
}
void Ship::setFirstSpace(Cell* fs){
    firstSpace = fs;
}
void Ship::setLastSpace(Cell* ls){
    lastSpace = ls;
}