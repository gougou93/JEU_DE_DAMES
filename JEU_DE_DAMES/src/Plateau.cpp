#include "Plateau.h"
#include "Case.h"
Plateau::Plateau()
{

}

bool Plateau::test(){

}

void Plateau::init(){
  //  gride[4][1].pion.color="bleu";
   int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if((i==0||i==2)&&(j==1||j==3||j==5||j==7||j==9)){
                gride[i][j].pion.color="jaune";
            }else if((i==1||i==3)&&(j==0||j==2||j==4||j==6||j==8)){
                gride[i][j].pion.color="jaune";
            }else if((i==9||i==7)&&(j==1||j==3||j==5||j==7||j==9)){
                gride[i][j].pion.color="bleu";
            }else if((i==8||i==6)&&(j==0||j==2||j==4||j==6||j==8)){
                gride[i][j].pion.color="bleu";
            }

        }
    }
}

void Plateau::afficherPlateau(){
    int i,j;
    for(i=0;i<10;i++){
            cout << "|";
        for(j=0;j<10;j++){
            gride[i][j].afficher();
            if(j!=9){
                cout << "|";
            }
        }
        cout << "|" << i << endl;
    }
    cout << " 0 1 2 3 4 5 6 7 8 9" << endl;
}

void Plateau::choisirJ(){
        cout << "C'est a Jaune de jouer !" << endl;
        do{
        cout << "Choisi un pion a deplacer : Ligne :";
        cin >> caseSelectedY ;
        }while(caseSelectedY!=0&&caseSelectedY!=1&&caseSelectedY!=2&&caseSelectedY!=3&&caseSelectedY!=4&&caseSelectedY!=5&&caseSelectedY!=6&&caseSelectedY!=7&&caseSelectedY!=8&&caseSelectedY!=9);
        do{
        cout << "                            Colonne :";
        cin >> caseSelectedX ;
        }while(caseSelectedX!=0&&caseSelectedX!=1&&caseSelectedX!=2&&caseSelectedX!=3&&caseSelectedX!=4&&caseSelectedX!=5&&caseSelectedX!=6&&caseSelectedX!=7&&caseSelectedX!=8&&caseSelectedX!=9);
        if(gride[caseSelectedY][caseSelectedX].pion.color =="jaune"){
            gride[caseSelectedY][caseSelectedX].pion.color="blanc";
            cout << "Ok !" << endl;
        }else if(gride[caseSelectedY][caseSelectedX].pion.color!="jaune"){
            cout << "Mauvais pion, choisis un pion jaune" << endl;
            choisirJ();
        }
}

void Plateau::choisirB(){
        cout << "C'est a Bleu de jouer !" << endl;
        do{
        cout << "Choisi un pion a deplacer : Ligne :";
        cin >> caseSelectedY ;
        }while(caseSelectedY!=0&&caseSelectedY!=1&&caseSelectedY!=2&&caseSelectedY!=3&&caseSelectedY!=4&&caseSelectedY!=5&&caseSelectedY!=6&&caseSelectedY!=7&&caseSelectedY!=8&&caseSelectedY!=9);
        do{
        cout << "                            Colonne :";
        cin >> caseSelectedX ;
        }while(caseSelectedX!=0&&caseSelectedX!=1&&caseSelectedX!=2&&caseSelectedX!=3&&caseSelectedX!=4&&caseSelectedX!=5&&caseSelectedX!=6&&caseSelectedX!=7&&caseSelectedX!=8&&caseSelectedX!=9);
        if(gride[caseSelectedY][caseSelectedX].pion.color=="bleu"){
            gride[caseSelectedY][caseSelectedX].pion.color="blanc";
            cout << "Ok !" << endl;
        }else if(gride[caseSelectedY][caseSelectedX].pion.color!="bleu"){
            cout << "Mauvais pion, choisis un pion bleu" << endl;
            choisirB();
        }
}
void Plateau::placerJ(){
    int caseArriveX;
    int caseArriveY;
    do{
        cout << "Choisissez ou vous voulez aller : Ligne :";
        cin >> caseArriveY;
        cout << endl << "                                  Colonne :";
        cin >> caseArriveX;
        if(!(caseArriveY==caseSelectedY+1&&caseArriveX==(caseSelectedX+1||caseSelectedX-1)) && (caseArriveY!=caseSelectedY+2 && caseArriveX!=(caseSelectedX+2||caseSelectedX-2)) && gride[caseArriveY][caseArriveX].pion.color!=""){
            cout << "Deplacement non autorise !" << endl;
        }
    }while(!(caseArriveY==caseSelectedY+1&&caseArriveX==(caseSelectedX+1||caseSelectedX-1)) && (caseArriveY!=caseSelectedY+2&&caseArriveX!=(caseSelectedX+2||caseSelectedX-2))&& gride[caseArriveY][caseArriveX].pion.color!="");
    cout << "caseSelectedY : " << caseSelectedY << endl;
    cout << "caseSelectedX : " << caseSelectedX << endl;
    // Si le joueur se déplace de 1 et que la case est vide alors le pion se deplace dans la case vide
    if((gride[caseSelectedY+1][caseSelectedX+1||caseSelectedX-1].pion.color=="")&&caseArriveX==(caseSelectedX+1||caseSelectedX-1)&&caseArriveY==caseSelectedY+1){
        gride[caseSelectedY][caseSelectedX].pion.color="";
        gride[caseArriveY][caseArriveX].pion.color="jaune";
    // Si il se déplace pas de 1 c'est forcement 2 donc si il y a une pion ennemi dans la case entre les deux il le mange
    }else if((gride[caseSelectedY+1][caseSelectedX+1||caseSelectedX-1].pion.color=="bleu")&&gride[caseArriveY][caseArriveX].pion.color==""){
        gride[caseSelectedY+1][caseSelectedX+1||caseSelectedX-1].pion.color="";
        gride[caseArriveY][caseArriveX].pion.color="jaune";
        gride[caseSelectedY][caseSelectedX].pion.color="";
    }else{
        cout << "Il n'y a rien a manger ! recommencez " << endl;
        placerJ();
    }
}
void Plateau::placerB(){
    int caseArriveX;
    int caseArriveY;
    do{
        cout << "Choisissez ou vous voulez aller : Ligne :";
        cin >> caseArriveY;
        cout << endl << "                                  Colonne :";
        cin >> caseArriveX;
        if(!(caseArriveY==caseSelectedY-1&&caseArriveX==(caseSelectedX+1||caseSelectedX-1)) && (caseArriveY!=caseSelectedY-2 && caseArriveX!=(caseSelectedX+2||caseSelectedX-2)) && gride[caseArriveY][caseArriveX].pion.color!=""){
            cout << "Deplacement non autorise !" << endl;
        }
    }while(!(caseArriveY==caseSelectedY-1&&caseArriveX==(caseSelectedX+1||caseSelectedX-1)) && (caseArriveY!=caseSelectedY-2&&caseArriveX!=(caseSelectedX+2||caseSelectedX-2))&& gride[caseArriveY][caseArriveX].pion.color!="");
    // Si le joueur se déplace de 1 et que la case est vide alors le pion se deplace dans la case vide
     cout << "caseSelectedY : " << caseSelectedY << endl;
    cout << "caseSelectedX : " << caseSelectedX << endl;
    if((gride[caseSelectedY-1][caseSelectedX+1||caseSelectedX-1].pion.color=="")&&caseArriveX==(caseSelectedX+1||caseSelectedX-1)&&caseArriveY==caseSelectedY-1){
        gride[caseSelectedY][caseSelectedX].pion.color="";
        gride[caseArriveY][caseArriveX].pion.color="bleu";
    // Si il se déplace pas de 1 c'est forcement 2 donc si il y a une pion ennemi dans la case entre les deux il le mange
    }else if((gride[caseSelectedY+1][caseSelectedX+1||caseSelectedX-1].pion.color=="jaune")&&gride[caseArriveY][caseArriveX].pion.color==""){
        gride[caseSelectedY-1][caseSelectedX+1||caseSelectedX-1].pion.color="";
        gride[caseArriveY][caseArriveX].pion.color="bleu";
        gride[caseSelectedY][caseSelectedX].pion.color="";
    }else{
        cout << "Il n'y a rien a manger ! recommencez " << endl;
        placerB();
    }
}

