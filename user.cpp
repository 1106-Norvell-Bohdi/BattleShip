//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "user.h"

User::User(){
    numBoats = 5; 
    columnGuess = 0;
    rowGuess = 'O'
    isTurn = false;
    attackBoard;
    defendBoard;
}
User::User(int n, int c, char r, bool t, board a, board d){
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
    return row;
}
bool User::getIsTurn(){
    return isTurn;
}
board User::getAttackBoard(){
    return attackBoard;
}
board User::getDefendBoard(){
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
void User::setAttackBoard(board a){
    attackBoard = a;
}
void User::setDefendBoard(board d){
    defendBoard = d;
}