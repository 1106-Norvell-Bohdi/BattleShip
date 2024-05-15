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
Board* placeShipsAi(Board*, Ship**);
Board* placeAllShips(Board*, Board*, Ship*, Ship*, Ship*, Ship*, Ship*);
bool checkForHit(Board*, Board*, int, int, Ship*);
bool checkIfGuessed(Board*, int, int);
bool checkForWin(int);
// void checkIfSunk(Board*, Board*, Ship*);
void makeMove(Board*, Board*, Player*, Ship**);
void makeMoveAi(Board*, Board*, Ai*, Ship**);
bool canPlaceShip(Board*, Ship*, int, int, bool);

#endif