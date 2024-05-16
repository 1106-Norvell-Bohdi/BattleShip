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
    Ai* AI = new Ai;

    Ship* carrier = new Ship("Carrier", "C", 5, 0, false, firstSpace, lastSpace, false);
    Ship* battleship = new Ship("Battleship", "B", 4, 0, false, firstSpace, lastSpace, false);
    Ship* destroyer = new Ship("Destroyer", "D", 3, 0, false, firstSpace, lastSpace, false);
    Ship* submarine = new Ship("Submarine", "S", 3, 0, false, firstSpace, lastSpace, false);
    Ship* patrol_boat = new Ship("Patrol Boat", "P", 2, 0, false, firstSpace, lastSpace, false);

    Ship* carrierAi = new Ship("Carrier", "C", 5, 0, false, firstSpace, lastSpace, false);
    Ship* battleshipAi = new Ship("Battleship", "B", 4, 0, false, firstSpace, lastSpace, false);
    Ship* destroyerAi = new Ship("Destroyer", "D", 3, 0, false, firstSpace, lastSpace, false);
    Ship* submarineAi = new Ship("Submarine", "S", 3, 0, false, firstSpace, lastSpace, false);
    Ship* patrol_boatAi = new Ship("Patrol Boat", "P", 2, 0, false, firstSpace, lastSpace, false);

    Ship** shipsP = new Ship*[5];
    shipsP[0] = carrier;
    shipsP[1] = battleship;
    shipsP[2] = destroyer;
    shipsP[3] = submarine;
    shipsP[4] = patrol_boat;

    Ship** shipsAi = new Ship*[5];
    shipsAi[0] = carrierAi;
    shipsAi[1] = battleshipAi;
    shipsAi[2] = destroyerAi;
    shipsAi[3] = submarineAi;
    shipsAi[4] = patrol_boatAi;
    
    system("clear");
    
    cout << carrier;
    cout<<"Welcome to Battle Ship"<<endl;
    cout<<"======================"<<endl;
    cout<<"Would you like to play? (Y/N): ";
    cin>>choice;
        
    if(choice == "n" || choice == "N"){
        return 0;
    }
    player_def = placeShipsAi(player_def, shipsP);
    //player_def = placeAllShips(player_atk, player_def, carrier, battleship, destroyer, submarine, patrol_boat);
    displayBoards(player_atk, player_def);
    cout<<endl;
    
    AI_def = placeShipsAi(AI_def, shipsAi);
    displayBoards(AI_atk, AI_def);

    if(randomTurn() == 0){
        player->setTurn(true);
    }
    else AI->setTurn(true);
    
    do{
        if(player->getIsTurn() == true){
            makeMove(player_atk, AI_def, player, shipsP);
            player->setTurn(false);
            AI->setTurn(true);
            displayBoards(player_atk, player_def);
            checkForWinPlayer(player->getNumHits());
        }
        else{
            makeMoveAi(AI_atk, player_def, AI, shipsAi);
            AI->setTurn(false);
            player->setTurn(true);
            displayBoards(AI_atk, AI_def);
            checkForWinAi(AI->getNumHits());
        }
    }while(AI->getNumHits() < 17 && player->getNumHits() < 17);
    
    delete [] shipsP;
    delete [] shipsAi;

}