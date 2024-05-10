//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef PLAYERS_H
#define PLAYERS_H
#include "helpers.h"

class Player: protected User{
    int numWins = 0;
    int numHits = 0;

    public:

    Player();
    Player(int, int);
    Player(const Player&);

    int getNumWins();
    int getNumHits();
    void setNumWins(int);
    void setNumHits(int);

    void makeMove();
};
#endif
