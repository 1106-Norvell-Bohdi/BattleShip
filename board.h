//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef BOARD_H
#define BOARD_H
#include "ship.h"
#define MAXSIZE 10

class Board{
   Cell board[][MAXSIZE];

   public:
   Board();
   Board(Cell, int);
   Board(const Board&);

   Cell getBoardArray();
   int getMaxSize();
   
   void setBoardArray(Cell[][MAXSIZE]);
   void setMaxSize(int);
   void setBoard(); 
};
#endif