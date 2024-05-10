//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "ai.h"

Ai::Ai():User(){
    numWins = 0;
    numHits = 0;
}
Ai::Ai(int wins, int hits, int boats, int col, char row, bool turn, Board att, Board def):User(boats, col, row, turn, att, def){
    numWins = wins;
    numHits = hits;
}
Ai::Ai(const Ai& rhs):User(rhs){
    numWins = rhs.numWins;
    numHits = rhs.numHits;
}

int Ai::getNumWins(){
    return numWins;
}

int Ai::getNumHits(){
    return numHits;
}

void Ai::setNumWins(int w){
    numWins = w;
}

void Ai::setNumHits(int h){
    numHits = h;
}
