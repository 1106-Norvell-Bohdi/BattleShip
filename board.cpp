//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "board.h"

Board::Board(){
    board = new Cell *[MAXSIZE];
    for(int i = 0; i < MAXSIZE; i++){
        board[i] = new Cell [MAXSIZE]; 
    }
}
Board::Board(Cell** b){
    board = new Cell *[MAXSIZE];
    for(int i = 0; i < MAXSIZE; i++){
        board[i] = new Cell [MAXSIZE];
    }
    for(int i = 0; i < MAXSIZE; i++){
        for(int j = 0; j < MAXSIZE; j++){
            board[i][j] = b[i][j];
        }
    }

}
Board::Board(const Board& rhs){
    board = new Cell *[MAXSIZE];
    for(int i = 0; i < MAXSIZE; i++){
        board[i] = new Cell [MAXSIZE];
    }
    for(int i = 0; i < MAXSIZE; i++){
        for(int j = 0; j < MAXSIZE; j++){
            board[i][j] = rhs.board[i][j];
        }
    }
}

Cell** Board::getBoardArray(){
    return board;
}
void Board::setBoardArray(Cell** array){
    board = array;
}