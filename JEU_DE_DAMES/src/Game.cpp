#include "Game.h"
#include "iostream"
#include "stdlib.h"
#include "Plateau.h"

using namespace std;
Game::Game()
{
    string player;
}

// Game::public Plateau;

void Game::changeCurrentPlayer(){
    if(player=="J"){
        player = "B";
    }else{
        player = "J";
    }
}




