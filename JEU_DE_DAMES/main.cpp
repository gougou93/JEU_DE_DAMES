#include <iostream>
#include "Game.h"
#include "stdio.h"
#include "stdlib.h"
#include "string"
using namespace std;

int main()
{
    Game partie;
    partie.player="J";
    int i =0;
    Plateau p;
    p.init();
    p.afficherPlateau();
    do{
    if(partie.player == "J"){
        char choix;
        do{
            p.choisirJ();
            p.afficherPlateau();
            do{
            cout << "Etes vous sur ? (o/n)";
            cin >> choix;
            }while(choix!='o'&&choix!='n');
            if(choix=='n'){
                p.gride[p.caseSelectedY][p.caseSelectedX].pion.color="jaune";
                p.afficherPlateau();
            }
        }while(choix!='o');
        p.placerJ();
    }else if(partie.player == "B"){
        char choix;
            do{
                p.choisirB();
                p.afficherPlateau();
                do{
                    cout << "Etes vous sur ? (o/n)";
                    cin >> choix;
                }while(choix!='o'&&choix!='n');
                if(choix=='n'){
                    p.gride[p.caseSelectedY][p.caseSelectedX].pion.color="jaune";
                    p.afficherPlateau();
                }
            }while(choix!='o');
            p.placerB();
    }

    p.afficherPlateau();
    partie.changeCurrentPlayer();
    }while(i!=1);


    return 0;
}
