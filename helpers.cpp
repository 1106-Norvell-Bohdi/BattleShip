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
            cout<<b->getBoardArray()[i][j].getShape()<<" ";
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
        if(letterToNum(choice) == 7){
            s->setOrientation(true); 
        }
        if(letterToNum(choice) == 10){
            s->setOrientation(false);    
        }
        cout<<"Please enter row and column: "<<endl;
        cout<<"Row (Letter): ";
        cin>>row;
        rowN = letterToNum(row);
        cout<<"Column (Number): ";
        cin>>col;

    if(canPlaceShip(b, s, rowN, col, s->getOrientation())){
    if(s->getOrientation()){
        s->setOrientation(true);
        s->setFirstSpace(&b->getBoardArray()[rowN][col-1]);
        s->setLastSpace(&b->getBoardArray()[rowN-1][col+s->getLength()-1]);
        for(int i = 0; i < s->getLength(); i++){
            b->getBoardArray()[rowN][col-1].setShape(s->getShape());
            b->getBoardArray()[rowN][col-1].setOccupied(true);
            col++;
        }
    }
    else{
        s->setOrientation(false);
        s->setFirstSpace(&b->getBoardArray()[rowN][col-1]);
        s->setLastSpace(&b->getBoardArray()[rowN+s->getLength()-1][col-1]);
        for(int i = 0; i < s->getLength(); i++){
            b->getBoardArray()[rowN][col-1].setShape(s->getShape());
            b->getBoardArray()[rowN][col-1].setOccupied(true);
            rowN++;
        }
    }
    }
    
    return b;
}

Board* placeShipsAi(Board* b, Ship** ship){
    bool isHorizontal;
    int maxStartCol, maxStartRow, row, col;

    srand(time(NULL));

     for(int j = 0; j < 5; j++){
            isHorizontal = rand() % 2 == 0;
            if(isHorizontal){
                do{
                    maxStartCol = MAXSIZE - ship[j]->getLength();
                    row = rand() % MAXSIZE;
                    col = rand() % maxStartCol;
                }while(!canPlaceShip(b, ship[j], row, col, isHorizontal));
                ship[j]->setFirstSpace(&b->getBoardArray()[row][col]);
                ship[j]->setLastSpace(&b->getBoardArray()[row][col+ship[j]->getLength()-1]);
                for(int i = 0; i < ship[j]->getLength(); i++){
                    b->getBoardArray()[row][col+i].setShape(ship[j]->getShape());
                    b->getBoardArray()[row][col+i].setOccupied(true);
                }
            }
            else{
                do{
                    maxStartRow = MAXSIZE - ship[j]->getLength();
                    row = rand() % maxStartRow;
                    col = rand() % MAXSIZE;
                }while(!canPlaceShip(b, ship[j], row, col, isHorizontal));
                ship[j]->setFirstSpace(&b->getBoardArray()[row][col]);
                ship[j]->setLastSpace(&b->getBoardArray()[row+ship[j]->getLength()-1][col]);
                for(int i = 0; i < ship[j]->getLength(); i++){
                    b->getBoardArray()[row+i][col].setShape(ship[j]->getShape());
                    b->getBoardArray()[row+i][col].setOccupied(true);
                }
            }
    }
    //get random selection for H/V
    //get random selection for Starting Row
    //get random selection for Starting Col
    //Check cells to make sure it can be placed with no overlap
    return b;
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

bool checkForHit(Board* a, Board* d, int r, int c){
    if(d->getBoardArray()[r][c].getOccupied() == true){
        a->getBoardArray()[r][c].setShape("!");
        a->getBoardArray()[r][c].setHit(true);
        
        //d->getBoardArray()[r][c].setShape("!");
        d->getBoardArray()[r][c].setHit(true);
        
        cout<<"Hit! At position "<<r<<c+1<<endl;
        return true;
    }
    else{
        a->getBoardArray()[r][c].setShape("M");
        a->getBoardArray()[r][c].setHit(false);
        
        //d->getBoardArray()[r][c].setShape("M");
        d->getBoardArray()[r][c].setHit(false);
        
        cout<<"Miss. At position "<<r<<c+1<<endl;
        return false;
    }
}

bool checkIfGuessed(Board* b, int r, int c){
    if(b->getBoardArray()[r][c].getShape() == "!" || b->getBoardArray()[r][c].getShape() == "M"){
        cout<<"Sorry that position has already been guessed!"<<endl;
        return true;
    }
    return false;
}

bool checkForWin(int n){
    if(n == 17){
        cout<<"Congratulations! You sunk all of your opponents Battleships!"<<endl;
        return true;
    }
    return false;
}
    
    

bool canPlaceShip(Board* b, Ship* s, int r, int c, bool orientation){
        if(orientation){
            if(c + s->getLength() >= MAXSIZE){
                return false;
            }
            for(int j = c; j < c+s->getLength(); j++){
                if(b->getBoardArray()[r][j].getOccupied()){
                    return false;
                }
            }
        }
        else{
            if(r+s->getLength() >= MAXSIZE){
                return false;
            }
            for(int k = r; k < r+s->getLength(); k++){
                if(b->getBoardArray()[k][c].getOccupied()){
                    return false;
                }
            }
        }
    return true;
}

void makeMove(Board* atk_board, Board* def_board, Player* player, Ship** ship){
    string r;
    int attackR;
    int attackC;
    bool turnUsed = false;
    do{
        cout << "Enter the Row (A-J) of the attack coordinate: ";
        cin >> r;
        cout << endl;
        cout << "Enter the Column (1-10) of the attack coordinate: ";
        cin >> attackC;
        attackR = letterToNum(r);
        if(checkIfGuessed(atk_board, attackR, attackC-1) == false){
            if(checkForHit(atk_board, def_board, attackR, attackC-1)){
                player->setNumHits(player->getNumHits()+1);
                for(int i=0; i < 5; i++){
                    //checkIfSunk(atk_board, def_board, ship[i]);
                }
            }
            turnUsed = true; 
        }
    }while(turnUsed == false);
}

void makeMoveAi(Board* atk_board, Board* def_board, Ai* ai, Ship** ship){
    int attackR;
    int attackC;
    bool turnUsed = false;
    srand(time(NULL));
    do{
        attackR = rand() % MAXSIZE;
        attackC = rand() % MAXSIZE;
        if(checkIfGuessed(atk_board, attackR, attackC-1) == false){
            if(checkForHit(atk_board, def_board, attackR, attackC)){
                ai->setNumHits(ai->getNumHits()+1);
                for(int i=0; i < 5; i++){
                    //checkIfSunk(atk_board, def_board, ship[i]);
                }
            }
            turnUsed = true; 
        }
    }while(turnUsed == false);
}

void checkIfSunk(Board* atk_board, Board* def_board, Ship* ship){
    int numHits = 0;
    int row = letterToNum(ship->getFirstSpace()->getRow());
    int col = ship->getFirstSpace()->getColumn();
    int length = ship->getLength();

    if (ship->getOrientation()) { // horizontal
        if (col + length > MAXSIZE) {
            return;
        }
    } else { // vertical
        if (row + length > MAXSIZE) {
            return;
        }
    }
            //horizontal
            for(int j = 0; j < length; j++){
                if(ship->getOrientation()){ 
                    if(def_board->getBoardArray()[row][col+j].getHit() && def_board->getBoardArray()[row][col+j].getOccupied()){
                        numHits++;
                    }
                }
                else{
                    if(def_board->getBoardArray()[row+j][col].getHit() && def_board->getBoardArray()[row+j][col].getOccupied()){
                        numHits++;
                    }
                }
            }
        if(numHits == length){
            for(int k = 0; k < length; k++){
                if(ship->getOrientation()){
                    atk_board->getBoardArray()[row][col+k].setShape("X");
                } 
                 else{
                    atk_board->getBoardArray()[row+k][col].setShape("X");
                }
            }
            ship->setIsSunk(true);
            cout << " The " << ship->getName() << " has been sunk!" << endl;
        }
}