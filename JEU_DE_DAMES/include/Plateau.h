#ifndef PLATEAU_H
#define PLATEAU_H
#include "Case.h"

class Plateau
{
    public:
        Plateau();
        Case gride[10][10];
        int caseSelectedX;
        int caseSelectedY;
        void init();
        void afficherPlateau();
        void choisirJ();
        void choisirB();
        void placerJ();
        void placerB();
        bool test();
    protected:

    private:
};

#endif // PLATEAU_H
