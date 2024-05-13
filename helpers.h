//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef HELPERS_H
#define HELPERS_H
#include "ai.h"

string nextLetter(string);
int letterToNumber(string);
Board* setAllCells(Board*);
void displayBoards(Board*, Board*);
int randomTurn();
Board* placeShips(Board*, Ship*);
Board* placeShipsAi(Board* b, Ship* ship1, Ship* ship2, Ship* ship3, Ship* ship4, Ship* ship5);
Board* placeAllShips(Board*, Board*, Ship*, Ship*, Ship*, Ship*, Ship*);
void checkForHit(Board*, Board*);
bool checkIfGuessed(Board*, int, int);
bool checkForWin(int);
void makeMove(Board*, Board*);
bool canPlaceShip(Board* b, Ship* s, int r, int c, bool o);

#endif