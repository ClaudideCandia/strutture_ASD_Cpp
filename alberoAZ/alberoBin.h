//
// Created by Utente on 23/01/2025.
//

#ifndef ALBEROBIN_H
#define ALBEROBIN_H
#include "Nodo3p.h"



class alberoBin {

    public:
    alberoBin();
    ~alberoBin();
    bool alberoVuoto();
    void aggiungiSin(nodo* padre, nodo*figlio);
    void aggiungiDes(nodo* padre, nodo*figlio);
    nodo* getRadice();
    void setFiglioSinRadice(nodo* n);
    void setFiglioDesRadice(nodo* n);
    bool isFoglia(nodo* n);
    int visitaLivelloK(nodo* radice, int k);
    private:
    nodo* radice;

};



#endif //ALBEROBIN_H
