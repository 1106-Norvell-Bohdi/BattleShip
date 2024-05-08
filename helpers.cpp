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

int letterToNum(string letter){
    if(letter == "A" || letter == "a"){
        return 0;
    }
    if(letter == "B" || letter == "b"){
        return 1;
    }
    if(letter == "C" || letter == "c"){
        return 2;
    }
    if(letter == "D" || letter == "d"){
        return 3;
    }
    if(letter == "E" || letter == "e"){
        return 4;
    }
    if(letter == "F" || letter == "f"){
        return 5;
    }
    if(letter == "G" || letter == "g"){
        return 6;
    }
    if(letter == "H" || letter == "h"){
        return 7;
    }
    if(letter == "I" || letter == "i"){
        return 8;
    }
    return 9;
}

Board setAllCells(Board b){
    string row = "A";
    int column = 1;
    for(int i = 0; i < MAXSIZE; i++){
        for (int j = 0; j <MAXSIZE; j++){
            b.getBoardArray()[j][i].setColumn(column);
            b.getBoardArray()[j][i].setRow(row);
            column++;
        }
        row = 1;
        row = nextLetter(row);
    }
    return b;
}

void displayBoards(Board attack, Board defend){

    string letter = "A";
    cout<<"++++ ATTACK BOARD ++++"<<endl;
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<endl;
    for(int i = 0; i < MAXSIZE; i++){
        cout<<letter<<" ";
        letter = nextLetter(letter);
        for (int j = 0; j <MAXSIZE; j++){
            cout<<attack.getBoardArray()[j][i].getShape()<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<"---- Defend Board ----"<<endl;
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<endl;
    letter = "A";
        for(int i = 0; i < MAXSIZE; i++){
        cout<<letter<<" ";
        letter = nextLetter(letter);
        for (int j = 0; j <MAXSIZE; j++){
            cout<<attack.getBoardArray()[j][i].getShape()<<" ";
        }
        cout<<endl;
    }

}

int randomTurn(){
    srand(time(NULL));
    return rand() % 2;  
}

Board placeShips(Board b, Ship s){
    string row, choice;
    int col;
    
    cout<<"The "<<s.getName()<<" is "<<s.getLength()<<" spaces long. Please enter row and column number: "<<endl;
    cout<<"Row: ";
    cin>>row;
    cout<<"Column: ";
    cin>>col;
    //s.setFirstSpace(b.getBoardArray()[letterToNum(row)][col]);
    cout<<"Would you like to place this ship vertically or horizontally (H/V)? ";
    cin>>choice;
    
    if(choice == "H" || choice == "h"){
        s.setLastSpace(b.getBoardArray()[letterToNum(row)][col + s.getLength() - 1]);
        for(int i = 0; i < s.getLength(); i++){
            b.getBoardArray()[letterToNum(row)][col].setShape("b");
            cout<<b.getBoardArray()[letterToNum(row)][col].getShape();
            col++;
        }
            cout<<endl<<s.getFirstSpace().getColumn();
            cout<<s.getFirstSpace().getRow()<<endl;            
            
            cout<<s.getLastSpace().getColumn();
            cout<<s.getLastSpace().getRow();
    }
    
    return b;
}