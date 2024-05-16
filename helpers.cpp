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

string numToLetter(int n){
    string letter = "";
    if( n == 1){
        letter = "A";
        return letter;
    }
    if(n == 2){
        letter = "B";
        return letter;
    }
    if(n == 3){
        letter = "C";
        return letter;
    }
    if(n == 4){
        letter = "D";
        return letter;
    }
    if(n == 5){
        letter = "E";
        return letter;
    }
    if(n == 6){
        letter = "F";
        return letter;
    }
    if(n == 7){
        letter = "G";
        return letter;
    }
    if(n == 8){
        letter = "H";
        return letter;
    }
    if(n == 9){
        letter = "I";
        return letter;
    }
    if(n == 10){
        letter = "J";
        return letter;
    }
    return "ERROR";
}

int letterToNumber(string letter){
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
ostream& operator<<(ostream& out, Ship* ship){
    out << ship->getShape() << endl;
    return out;
}

ostream& operator<<(ostream& out, Cell* cell){
    out << cell->getShape() << endl;
    return out;
}

ostream& operator<<(ostream& out, User* user){
    out << user->getColumnGuess() << endl;
    out << user->getRowGuess() << endl;
    return out;
}

ostream& operator<<(ostream& out, Ai* ai){
    out << ai->getNumWins() << endl;
    return out;
}

ostream& operator<<(ostream& out, Player* player){
    out << player->getNumWins() << endl;
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
        if(letterToNumber(choice) == 7){
            s->setOrientation(true); 
        }
        if(letterToNumber(choice) == 10){
            s->setOrientation(false);    
        }
        cout<<"Please enter row and column: "<<endl;
        cout<<"Row (Letter): ";
        cin>>row;
        rowN = letterToNumber(row);
        cout<<"Column (Number): ";
        cin>>col;

    if(canPlaceShip(b, s, rowN, col, s->getOrientation())){
    if(s->getOrientation()){
        Cell* firstS = new Cell;
        Cell* lastS = new Cell;
        firstS->setRow(row);
        firstS->setColumn(col);
        lastS->setRow(row);
        lastS->setColumn(col+s->getLength()-1);
        s->setFirstSpace(firstS);
        s->setLastSpace(lastS);
        cout << "TEST" << endl;
        cout << s->getFirstSpace()->getRow() <<endl;
        cout << s->getFirstSpace()->getColumn() <<endl;
        for(int i = 0; i < s->getLength(); i++){
            b->getBoardArray()[rowN][col-1].setShape(s->getShape());
            b->getBoardArray()[rowN][col-1].setOccupied(true);
            col++;
        }
    }
    else{
        s->setOrientation(false);
        Cell* firstS = new Cell;
        Cell* lastS = new Cell;
        firstS->setRow(row);
        firstS->setColumn(col-1);
        lastS->setRow(numToLetter(rowN+s->getLength()-1));
        lastS->setColumn(col-1);
        s->setFirstSpace(firstS);
        s->setLastSpace(lastS);
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
                ship[j]->setOrientation(true);
                do{
                    maxStartCol = MAXSIZE - ship[j]->getLength();
                    row = rand() % MAXSIZE;
                    col = rand() % maxStartCol;
                }while(!canPlaceShip(b, ship[j], row, col, isHorizontal));
                Cell* firstS = new Cell;
                Cell* lastS = new Cell;
                firstS->setRow(numToLetter(row));
                firstS->setColumn(col);
                lastS->setRow(numToLetter(row));
                lastS->setColumn(col+ship[j]->getLength()-1);
                ship[j]->setFirstSpace(firstS);
                ship[j]->setLastSpace(lastS);
                for(int i = 0; i < ship[j]->getLength(); i++){
                    b->getBoardArray()[row][col+i].setShape(ship[j]->getShape());
                    b->getBoardArray()[row][col+i].setOccupied(true);
                }
            }
            else{
                ship[j]->setOrientation(false);
                do{
                    maxStartRow = MAXSIZE - ship[j]->getLength();
                    row = rand() % maxStartRow;
                    col = rand() % MAXSIZE;
                }while(!canPlaceShip(b, ship[j], row, col, isHorizontal));
                Cell* firstS = new Cell;
                Cell* lastS = new Cell;
                firstS->setRow(numToLetter(row));
                firstS->setColumn(col-1);
                lastS->setRow(numToLetter(row+ship[j]->getLength()-1));
                lastS->setColumn(col-1);
                ship[j]->setFirstSpace(firstS);
                ship[j]->setLastSpace(lastS);
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

bool checkForHit(Board* a, Board* d, int r, int c, Ship* ship, Player* player){
    if(d->getBoardArray()[r][c].getOccupied() == true){
        a->getBoardArray()[r][c].setShape("!");
        a->getBoardArray()[r][c].setHit(true);
        
        //d->getBoardArray()[r][c].setShape("!");
        d->getBoardArray()[r][c].setHit(true);
        if(d->getBoardArray()[r][c].getShape() == ship->getShape()){
            ship->setHits(ship->getHits()+1);
            player->setNumHits(player->getNumHits()+1);
        }
        
        cout<<"You Hit a Ship!!" << endl;
        return true;
    }
    else{
        a->getBoardArray()[r][c].setShape("M");
        a->getBoardArray()[r][c].setHit(false);
        
        //d->getBoardArray()[r][c].setShape("M");
        d->getBoardArray()[r][c].setHit(false);
        
        cout<<"You Missed!" << endl;
        return false;
    }
}
bool checkForHit(Board* a, Board* d, int r, int c, Ship* ship, Ai* AI){
    if(d->getBoardArray()[r][c].getOccupied() == true){
        a->getBoardArray()[r][c].setShape("!");
        a->getBoardArray()[r][c].setHit(true);
        
        //d->getBoardArray()[r][c].setShape("!");
        d->getBoardArray()[r][c].setHit(true);
        if(d->getBoardArray()[r][c].getShape() == ship->getShape()){
            ship->setHits(ship->getHits()+1);
            AI->setNumHits(AI->getNumHits()+1);
        }
        cout<<"AI Hit a Ship!!" << endl;
        return true;
    }
    else{
        a->getBoardArray()[r][c].setShape("M");
        a->getBoardArray()[r][c].setHit(false);
        
        d->getBoardArray()[r][c].setShape("M");
        d->getBoardArray()[r][c].setHit(false);
        
        cout<<"AI Missed!" << endl;
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

bool checkForWinPlayer(int n){
    if(n == 17){
        cout<<"Congratulations! You sunk all of your opponents Battleships! YOU WIN:)"<<endl;
        return true;
    }
    return false;
}

bool checkForWinAi(int n){
    if(n == 17){
        cout<<"Unfortunately AI sunk all of your  Battleships! YOU LOSE :("<<endl;
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
    int attackR, row;
    int attackC, col;
    bool turnUsed = false;
    do{
        cout << "Enter the Row (A-J) of the attack coordinate: ";
        cin >> r;
        cout << endl;
        cout << "Enter the Column (1-10) of the attack coordinate: ";
        cin >> attackC;
        attackR = letterToNumber(r);
        if(checkIfGuessed(atk_board, attackR, attackC-1) == false){
            for(int i=0; i < 5; i++){
            if(checkForHit(atk_board, def_board, attackR, attackC-1, ship[i], player)){
                // player->setNumHits(player->getNumHits()+1);
                //CHECKS TO SEE IF A SHIP IS SUNK< IF SO CHANGES SHAPE ON THE CORRESPONDING ATTACK BOARD
                if(!ship[i]->getIsSunk()){
                if(ship[i]->getHits() == ship[i]->getLength()){
                        // for(int j = 0; j < ship[i]->getLength(); j++){
                        //     row = letterToNumber(ship[i]->getFirstSpace()->getRow());
                        //     col = ship[i]->getFirstSpace()->getColumn()-1;
                        //     cout << row << col+j << endl;
                        //     if(ship[i]->getOrientation()){
                        //         atk_board->getBoardArray()[row][col+j].setShape("X");
                        //     } 
                        //     else{
                        //         atk_board->getBoardArray()[row+j][col].setShape("X");
                        //     }
                        // }
                        cout << "The " << ship[i]->getName() << " has been sunk!!" << endl;
                        ship[i]->setIsSunk(true);
                    }
                }
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
            for(int i=0; i < 5; i++){
            if(checkForHit(atk_board, def_board, attackR, attackC, ship[i], ai)){
                // ai->setNumHits(ai->getNumHits()+1);
                    //CHECKS TO SEE IF A SHIP IS SUNK< IF SO CHANGES SHAPE ON THE CORRESPONDING ATTACK BOARD
                    if(!ship[i]->getIsSunk()){
                    if(ship[i]->getHits() == ship[i]->getLength()){
//COULDN"T GET THE BOARD TO UPDATE WHEN A SHIP IS SUNK BUT THE GAME DISPLAYS WHEN A SHIP IS SUNK
                        // for(int j = 0; j < ship[i]->getLength(); j++){
                        //     int row = letterToNumber(ship[i]->getFirstSpace()->getRow());
                        //     int col = ship[i]->getFirstSpace()->getColumn();
                        //     cout << row << col+j << endl;
                        //     // if(ship[i]->getOrientation()){
                        //     //     atk_board->getBoardArray()[row][col+j].setShape("X");
                        //     // } 
                        //     // else{
                        //     //     atk_board->getBoardArray()[row+j][col].setShape("X");
                        //     // }
                        // }
                        cout << "The " << ship[i]->getName() << " has been sunk!!" << endl;
                        ship[i]->setIsSunk(true);
                    }
                    }
            }
            }
            turnUsed = true; 
        }
    }while(turnUsed == false);
}

// void checkIfSunk(Board* atk_board, Board* def_board, Ship* ship){
//     int row = letterToNumber(ship->getFirstSpace()->getRow());
//     int col = ship->getFirstSpace()->getColumn();
//     int length = ship->getLength();
//         if(ship->getHits() == length){
//             ship->setIsSunk(true);
//             for(int k = 0; k < length; k++){
//                 if(ship->getOrientation()){
//                     atk_board->getBoardArray()[row][col+k].setShape("X");
//                 } 
//                  else{
//                     atk_board->getBoardArray()[row+k][col].setShape("X");
//                 }
//             }
//             cout << " The " << ship->getName() << " has been sunk!" << endl;
//         }
// }