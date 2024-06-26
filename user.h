//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef USER_H
#define USER_H
#include "board.h"


class User{
    int numBoats, columnGuess;
    char rowGuess;
    bool isTurn;
    Board* attackBoard;
    Board* defendBoard;

    public:
    User();
    User(int, int, char, bool, Board*, Board*);
    User(const User&);

    int getNumBoats();
    int getColumnGuess();
    char getRowGuess();
    bool getIsTurn();

    Board* getAttackBoard();
    Board* getDefendBoard();

    void setNumBoats(int);
    void setColumnGuess(int);
    void setRowGuess(char);
    void setTurn(bool);
    void setAttackBoard(Board*);
    void setDefendBoard(Board*);

    friend ostream& operator <<(ostream&, User*);
    
};
#endif
