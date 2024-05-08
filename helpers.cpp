//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "helpers.h"

string nextLetter(string letter){
    if(letter == "A"){
        return letter = "B";
    }
    if(letter == "B"){
        return letter = "C";
    }
    if(letter == "C"){
        return letter = "D";
    }
    if(letter == "D"){
        return letter = "E";
    }
    if(letter == "E"){
        return letter = "F";
    }
    if(letter == "F"){
        return letter = "G";
    }
    if(letter == "G"){
        return letter = "H";
    }
    if(letter == "H"){
        return letter = "I";
    }
    if(letter == "I"){
        return letter = "J";
    }
    return letter = "error";
}

Board setAllCells(Board b){
    string column = "A";
    int row = 1;
    for(int i = 0; i < MAXSIZE; i++){
        for (int j = 0; j <MAXSIZE; j++){
            b.getBoardArray()[j][i].setColumn(column);
            b.getBoardArray()[j][i].setRow(row);
            row++;
        }
        row = 1;
        column = nextLetter(column);
    }
    return b;
}

void displayBoard(Board b){

    string letter = "A";
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<endl;
    for(int i = 0; i < MAXSIZE; i++){
        cout<<letter<<" ";
        letter = nextLetter(letter);
        for (int j = 0; j <MAXSIZE; j++){
            cout<<b.getBoardArray()[j][i].getShape()<<" ";
        }
        cout<<endl;
    }
}

int randomTurn(){
    srand(time(NULL));
    return rand() % 2;  
}