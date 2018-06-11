#include "Case.h"
#include "Pion.h"
#include "Plateau.h"
#include <windows.h>
using namespace std;
Case::Case()
{
    //ctor
}

void Case::afficher()
{
    if(pion.color=="bleu"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        cout << "O";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }else if(pion.color=="jaune"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "O";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    }else if(pion.color==""){
        cout << " ";
    }else if(pion.color=="blanc"){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout << "O";
    }
}


