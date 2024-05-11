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
    if(letter == "J" || letter == "j"){
        return 9;
    }
    if(letter == "V" || letter == "v"){
        return 10;
    }
    return 99;
}

Board* setAllCells(Board* b){
    string row = "A";
    int column = 1;
    for(int i = 0; i < MAXSIZE; i++){
        for (int j = 0; j <MAXSIZE; j++){
            b->getBoardArray()[j][i].setColumn(column);
            b->getBoardArray()[j][i].setRow(row);
            column++;
        }
        row = 1;
        row = nextLetter(row);
    }
    return b;
}

ostream& operator<<(ostream& out, Board* b){
        string letter = "A";
        for(int i = 0; i < MAXSIZE; i++){
        out<<letter<<" ";
        letter = nextLetter(letter);
        for (int j = 0; j <MAXSIZE; j++){
            cout<<b->getBoardArray()[j][i].getShape()<<" ";
        }
        cout<<endl;
    }
    return out;
}

void displayBoards(Board* attack, Board* defend){

    string letter = "A";
    cout<<"++++ ATTACK BOARD ++++"<<endl;
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<endl;
    cout<<attack;

    cout<<endl<<"---- Defend Board ----"<<endl;
    cout<<"  1 2 3 4 5 6 7 8 9 10"<<endl;
    cout<<defend;

}

int randomTurn(){
    srand(time(NULL));
    return rand() % 2;  
}

Board* placeShips(Board* b, Ship* s){
    string row, choice;
    int col, rowN;

        cout << "The "<<s->getName()<<" is "<<s->getLength()<<" spaces long..." << endl;
        cout<<"Would you like to place this ship vertically or horizontally (H/V)? ";
        cin>>choice;
        cout<<"Please enter row and column: "<<endl;
        cout<<"Row (Letter): ";
        cin>>row;
        rowN = letterToNum(row);
        cout<<"Column (Number): ";
        cin>>col;
    
    if(letterToNum(choice) == 7){
        s->setFirstSpace(&b->getBoardArray()[col-1][rowN]);
        s->setLastSpace(&b->getBoardArray()[col+s->getLength()-1][rowN-1]);
        for(int i = 0; i < s->getLength(); i++){
            b->getBoardArray()[col-1][rowN].setShape(s->getShape());
            b->getBoardArray()[col-1][rowN].setOccupied(true);
            col++;
        }
    }
    if(letterToNum(choice) == 10){
        s->setFirstSpace(&b->getBoardArray()[col-1][rowN]);
        s->setLastSpace(&b->getBoardArray()[col-1][rowN+s->getLength()-1]);
        for(int i = 0; i < s->getLength(); i++){
            b->getBoardArray()[col-1][rowN].setShape(s->getShape());
            b->getBoardArray()[col-1][rowN].setOccupied(true);
            rowN++;
        }
    }
    
    return b;
}

Board* placeShipsAi(Board* b, Ship* ship){
    srand(time(NULL));
    bool isHorizontal = rand() % 2 == 0;
    if(isHorizontal){
        int maxStartCol = MAXSIZE - ship->getLength();
        int row = rand() % MAXSIZE;
        int col = rand() % (maxStartCol+1);
        ship->setFirstSpace(&b->getBoardArray()[col-1][row]);
        ship->setLastSpace(&b->getBoardArray()[col+ship->getLength() -1][row]);
        for(int i = 0; i < ship->getLength(); i++){
            b->getBoardArray()[col-1][row].setShape(ship->getShape());
            col++;
        }
    }
    else{
        int maxStartRow = MAXSIZE - ship->getLength();
        int row = rand() % (maxStartRow+1);
        int col = rand() % MAXSIZE;
        ship->setFirstSpace(&b->getBoardArray()[col-1][row]);
        ship->setLastSpace(&b->getBoardArray()[col-1][row+ship->getLength()-1]);
        for(int i = 0; i < ship->getLength(); i++){
            b->getBoardArray()[col-1][row].setShape(ship->getShape());
            row++;
        }
    }
    return b;
    //get random selection for H/V
    //get random selection for Starting Row
    //get random selection for Starting Col
    //Check cells to make sure it can be placed with no overlap
}

Board* placeAllShips(Board* A, Board* D, Ship* c, Ship* b, Ship* d, Ship* s, Ship* p){
    system("clear");
    displayBoards(A, D);
    D = placeShips(D, c);
    system("clear");
    displayBoards(A, D);
    D = placeShips(D, b);
    system("clear");
    displayBoards(A, D);
    D = placeShips(D, d);
    system("clear");
    displayBoards(A, D);
    D = placeShips(D, s);
    system("clear");
    displayBoards(A, D);
    D = placeShips(D, p);
    system("clear");
    displayBoards(A, D);
    return D;
}

void checkForHit(Board* a, Board* d, int r, int c){
    if(d->getBoardArray()[r][c].getOccupied() == true){
        a->getBoardArray()[r][c].setShape("!");
        a->getBoardArray()[r][c].setHit(true);
        
        d->getBoardArray()[r][c].setShape("!");
        d->getBoardArray()[r][c].setHit(true);
        
        cout<<"Hit! At position "<<r<<c<<endl; 
    }
    else{
        a->getBoardArray()[r][c].setShape("M");
        a->getBoardArray()[r][c].setHit(false);
        
        d->getBoardArray()[r][c].setShape("M");
        d->getBoardArray()[r][c].setHit(false);
        
        cout<<"Miss. At position "<<r<<c<<endl;
    }
}

bool checkIfGuessed(Board* b, int r, int c){
    if(b->getBoardArray()[r][c].getShape() == "!" || b->getBoardArray()[r][c].getShape() == "M"){
        cout<<"Sorry that position has already been guessed!"<<endl;
        return true;
    }
    else return false;
}

void checkForWin(int n){
    if(n == 17){
        cout<<"Congratulations! You sunk all of your opponents Battleships!"<<endl;
    }
}

/*template <class T>
void takeTurn(T p){

    //I was thinking here we could use the template for both the AI and the Player.
    //We just have to make sure that any text that is displayed is applicable to both player and AI
    //call check for Hit and display boards and check if guessed

}*/