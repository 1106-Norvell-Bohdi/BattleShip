//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "user.h"

User::User(){
    numBoats = 5; 
    columnGuess = 0;
    rowGuess = 'O';
    isTurn = false;
    attackBoard = new Board;
    defendBoard = new Board;
}
User::User(int n, int c, char r, bool t, Board* a, Board* d){
    numBoats = n; 
    columnGuess = c;
    rowGuess = r;
    isTurn = t;
    attackBoard = a;
    defendBoard = d;
}
User::User(const User& rhs){
    numBoats = rhs.numBoats;
    columnGuess = rhs.columnGuess;
    rowGuess = rhs.rowGuess;
    isTurn = rhs.isTurn;
    attackBoard = rhs.attackBoard;
    defendBoard = rhs.defendBoard;
}

int User::getNumBoats(){
    return numBoats;
    }
int User::getColumnGuess(){
    return columnGuess;
}
char User::getRowGuess(){
    return rowGuess;
}
bool User::getIsTurn(){
    return isTurn;
}
Board* User::getAttackBoard(){
    return attackBoard;
}
Board* User::getDefendBoard(){
    return defendBoard;
}
void User::setNumBoats(int n){
    numBoats = n;
}
void User::setColumnGuess(int c){
    columnGuess = c;
}
void User::setRowGuess(char r){
    rowGuess = r;
}
void User::setTurn(bool t){
    isTurn = t;
}
void User::setAttackBoard(Board* a){
    attackBoard = a;
}
void User::setDefendBoard(Board* d){
    defendBoard = d;
}