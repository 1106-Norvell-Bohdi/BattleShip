//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#ifndef AI_H
#define AI_H
#include "player.h"

class Ai: public User{
    int numWins = 0;
    int numHits = 0;

    public:

    Ai();
    Ai(int, int, int, int, char, bool, Board*, Board*);
    Ai(const Ai&);

    int getNumWins();
    int getNumHits();
    void setNumWins(int);
    void setNumHits(int);

    friend ostream& operator <<(ostream&, Ai*);
};
#endif