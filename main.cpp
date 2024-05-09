//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "helpers.h"

int main(){
    string choice;
        
    User player; 
    User AI;
    Cell firstSpace;
    Cell lastSpace;
    
    Board player_atk, player_def, AI_atk, AI_def;
    player_atk = setAllCells(player_atk); 
    player_def = setAllCells(player_def); 
    AI_atk = setAllCells(AI_atk); 
    AI_def = setAllCells(AI_def);
    
    Ship carrier("Carrier", "C", 5, false, firstSpace, lastSpace);
    Ship battleship("Battleship", "B", 4, false, firstSpace, lastSpace);
    Ship destroyer("Destroyer", "D", 3, false, firstSpace, lastSpace);
    Ship submarine("Submarine", "S", 3, false, firstSpace, lastSpace);
    Ship patrol_boat("Patrol Boat", "P", 2, false, firstSpace, lastSpace);
    
    system("clear");
    
    cout<<"Welcome to Battle Ship"<<endl;
    cout<<"======================"<<endl;
    cout<<"Would you like to play? (Y/N): ";
    cin>>choice;
        
    if(choice == "n" || choice == "N"){
        return 0;
    }
    
    system("clear");
    player_def = placeShips(player_def, patrol_boat);
    displayBoards(player_atk, player_def);
    player_def = placeShips(player_def, submarine);
    displayBoards(player_atk, player_def);
    player_def = placeShips(player_def, destroyer);
    displayBoards(player_atk, player_def);
    player_def = placeShips(player_def, battleship);
    displayBoards(player_atk, player_def);
    player_def = placeShips(player_def, carrier);
    displayBoards(player_atk, player_def);

    
    if(randomTurn() == 0){
        player.setTurn(true);
    }
    else{
        AI.setTurn(true);
    }

}