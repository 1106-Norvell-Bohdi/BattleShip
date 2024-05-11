//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef BOARD_H
#define BOARD_H
#include "ship.h"
#define MAXSIZE 10

class Board{
   Cell** board;

   public:
   Board();
   Board(Cell**);
   Board(const Board&);

   Cell** getBoardArray();
   void setBoardArray(Cell**);

 friend ostream& operator <<(ostream&, Board*);
};
#endif