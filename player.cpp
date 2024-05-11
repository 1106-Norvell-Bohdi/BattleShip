//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "player.h"

Player::Player():User(){
    numWins = 0;
    numHits = 0;
}
Player::Player(int wins, int hits, int boats, int col, char row, bool turn, Board att, Board def):User(boats, col, row, turn, att, def){
    numWins = wins;
    numHits = hits;
}
Player::Player(const Player& rhs):User(rhs){
    numWins = rhs.numWins;
    numHits = rhs.numHits;
}

int Player::getNumWins(){
    return numWins;
}

int Player::getNumHits(){
    return numHits;
}

void Player::setNumWins(int w){
    numWins = w;
}

void Player::setNumHits(int h){
    numHits = h;
}

void Player::makeMove(Board* atk){
    string attackRow;
    int attackCol;
    cout << "Enter the Row (A-J) of the attack coordinate: ";
    cin >> attackRow;
    cout << endl;
    cout << "Enter the Column (A-J) of the attack coordinate: ";
    cin >> attackCol;


}
