//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef AI_H
#define AI_H
#include "player.h"

class Ai: protected User{
    int numWins = 0;
    int numHits = 0;

    public:

    Ai();
    Ai(int, int);
    Ai(const Player&);

    int getNumWins();
    int getNumHits();
    void setNumWins(int);
    void setNumHits(int);

};
#endif