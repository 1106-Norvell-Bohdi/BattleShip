//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "ship.h"

char shape;
string name;
int length;
bool isSunk;
    
cell firstSpace, lastSpace;

public:

Ship::Ship(){
    shape = 'S';
    name = "Ship";
    length = 3 // Total Ship Sizes: 2, 3. 3,4,5
    isSunk = false;
    firstSpace = new Cell;
    lastSpace = new Cell;
}
Ship::Ship(char s, string n, int l, bool is, cell fs, cell ls){
    shape = s;
    name = n
    length = l;
    isSunk = is;
    firstSpace = fs;
    lastSpace = ls;
}

Ship::Ship(const Ship& rhs){
    shape = rh.shape;
    name = rhs.name;
    length = rhs.length;
    isSunk = rhs.isSunk;
    firstSpace = rhs.firstSpace;
    lastSpace = rhs.lastSpace;
}

char Ship::getShape(){
    return shape;
}
string Ship::getName(){
    return name;
}
int Ship::getLength(){
    return length;
}
bool Ship::getIsSunk(){
    return isSunk;
}
cell Ship::getFirstSpace(){
    return firstSpace;
}
cell Ship::getLastSpace(){
    return lastSpace;
}

void Ship::setShape(char s){
    shape = s;
}
void Ship::setName(string n){
    name = n;
}
void Ship::setLength(int l){
    length = l;
}
void Ship::setIsSunk(bool is){
    isSunk = is;
}
void Ship::setFirstSpace(cell fs){
    firstSpace = fs;
}
void Ship::setLastSpace(cell ls){
    lastSpace = ls;
}

void Ship::checkIfHit(){
}