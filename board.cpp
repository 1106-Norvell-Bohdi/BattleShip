//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "board.h"

Board::Board(){
    
}
Board::Board(cell, int){

}
Board::Board(const Board& rhs){

}

cell Board::getBoardArray(){
    return board;
}
int Board::getMaxSize(){
    return maxSize;
}
void Board::setBoardArray(cell array){
    board = array;
}
void Board::setMaxSize(int m){
    maxSize = m;
}
   
void Board::setBoard(){

}