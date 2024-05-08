//Authors: Bohdi Norvell & Keegan Evans
//Project: PA4 - Battleship
//Due Date May 15th, 2024

#include "helpers.h"

int main(){
    string choice;
    Board player_atk, player_def, AI_atk, AI_def;
    User player; 
    User AI;
    system("clear");
    
    cout<<"Welcome to Battle Ship"<<endl;
    cout<<"======================"<<endl;
    cout<<"Would you like to play? (Y/N): ";
    cin>>choice;
        
    if(choice == "n" || choice == "N"){
        return 0;
    }
    
    system("clear");
    player_atk = setAllCells(player_atk); // These are just to show that it is working
    displayBoard(player_atk);// This is as well

    if(randomTurn() == 0){
        player.setTurn(true);
    }
    else{
        AI.setTurn(true);
    }

}