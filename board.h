//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef BOARD_H
#define BOARD_H
#include "ship.h"

class Board{
   Cell board[][];
   int maxSize;

   public:
   Board();
   Board(cell, int);
   Board(const board&);

   cell getBoardArray();
   int getMaxSize();
   
   void setBoardArray(cell[][]);
   void setMaxSize(int);
   void setBoard(); 
};
#endif