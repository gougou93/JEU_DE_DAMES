#ifndef GAME_H
#define GAME_H
#include "stdlib.h"
#include "Plateau.h"
#include "iostream"
using namespace std;
class Game
{
    public:
        Game();
        string player;
        void changeCurrentPlayer();
        void deplacer();
        void checkTheGame();
    protected:

    private:
};

#endif // GAME_H
