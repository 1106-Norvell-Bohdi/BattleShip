//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "helpers.h"

int main(){
    string choice;

    Cell* firstSpace = new Cell;
    Cell* lastSpace = new Cell;

    Board* player_atk = new Board;
    Board* player_def = new Board; 
    Board* AI_atk = new Board; 
    Board* AI_def = new Board;
    player_atk = setAllCells(player_atk); 
    player_def = setAllCells(player_def); 
    AI_atk = setAllCells(AI_atk); 
    AI_def = setAllCells(AI_def);
    
    Player* player = new Player; 
    Player* AI = new Player;

    Ship* carrier = new Ship("Carrier", "C", 5, false, firstSpace, lastSpace);
    Ship* battleship = new Ship("Battleship", "B", 4, false, firstSpace, lastSpace);
    Ship* destroyer = new Ship("Destroyer", "D", 3, false, firstSpace, lastSpace);
    Ship* submarine = new Ship("Submarine", "S", 3, false, firstSpace, lastSpace);
    Ship* patrol_boat = new Ship("Patrol Boat", "P", 2, false, firstSpace, lastSpace);

    Ship* carrierAi = new Ship("Carrier", "C", 5, false, firstSpace, lastSpace);
    Ship* battleshipAi = new Ship("Battleship", "B", 4, false, firstSpace, lastSpace);
    Ship* destroyerAi = new Ship("Destroyer", "D", 3, false, firstSpace, lastSpace);
    Ship* submarineAi = new Ship("Submarine", "S", 3, false, firstSpace, lastSpace);
    Ship* patrol_boatAi = new Ship("Patrol Boat", "P", 2, false, firstSpace, lastSpace);
    
    system("clear");
    
    cout<<"Welcome to Battle Ship"<<endl;
    cout<<"======================"<<endl;
    cout<<"Would you like to play? (Y/N): ";
    cin>>choice;
        
    if(choice == "n" || choice == "N"){
        return 0;
    }
    //player_def = placeAllShips(player_atk, player_def, carrier, battleship, destroyer, submarine, patrol_boat);
    displayBoards(player_atk, player_def);
    cout<<endl;
    
    AI_def = placeShipsAi(AI_def, carrierAi, battleshipAi, destroyerAi, submarineAi, patrol_boatAi);
    displayBoards(AI_atk, AI_def);

    if(randomTurn() == 0){
        player->setTurn(true);
    }
    else AI->setTurn(true);
    do{
        if(player->getIsTurn() == true){
            makeMove(player_atk, AI_def);
            player->setTurn(false);
            AI->setTurn(true);
            system("clear");
            displayBoards(player_atk, player_def);
        }
        else{
            player->setTurn(true);
            AI->setTurn(false);
            system("clear");
            displayBoards(player_atk, player_def);
        }
    }while(checkForWin(AI->getNumHits()) == false || checkForWin(AI->getNumHits() == false));

}