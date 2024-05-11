//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef HELPERS_H
#define HELPERS_H
#include "user.h"

string nextLetter(string);
int letterToNumber(string);
Board* setAllCells(Board*);
void displayBoards(Board*, Board*);
int randomTurn();
Board* placeShips(Board, Ship);
Board* placeShipsAi(Board, Ship);
Board* placeAllShips(Board*, Board*, Ship*, Ship*, Ship*, Ship*, Ship*);
void checkForHit(Board*, Board*);

template <class T>
void takeTurn(T*);

#endif