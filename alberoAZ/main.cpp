//
// Created by Utente on 23/01/2025.
//
#include <iostream>
#include"Nodo3p.h"
#include"alberoBin.h"
int calcolaProfondita(nodo* radice) {
    if (radice == nullptr) {
        return 0;  // Se il nodo è nullo, la profondità è 0
    } else {
        // Calcola la profondità dei sottoalberi sinistro e destro
        int profonditaSinistra = calcolaProfondita(getFs(radice));
        int profonditaDestra = calcolaProfondita(getFd(radice));

        // La profondità dell'albero è il massimo tra i sottoalberi + 1 (per la radice)
        return std::max(profonditaSinistra, profonditaDestra) + 1;
    }
}
alberoBin insAuto() {
    //inizializzo oggetto albero.
    alberoBin bin;

    //creo e aggiungo i nodi che verranno inseriti nell'albero.
    nodo* primo = creaNodo(1);
    nodo* secondo = creaNodo(2);
    nodo* terzo = creaNodo(3);
    nodo* quarto = creaNodo(4);

    //primo figlio sinistro della root
    bin.setFiglioSinRadice(primo);
    setPadre(primo,bin.getRadice());

    //secondo figlio destro della root
    bin.setFiglioDesRadice(secondo);
    setPadre(secondo,bin.getRadice());

    //terzo figlio sinistro di primo
    bin.aggiungiSin(primo,terzo);

    //quarto figlio destro di primo
    bin.aggiungiDes(primo,quarto);
    return bin;
}
int main() {
    alberoBin bin = insAuto();

    visitaSimmetrica(bin.getRadice());
    std::cout<<std::endl;
    visitaInPostordine(bin.getRadice());
    std::cout<<std::endl;
    visitaInPreordine(bin.getRadice());
    std::cout<<std::endl;
    int p = calcolaProfondita(bin.getRadice());
    std::cout<<"profondita : "<<p<<std::endl;
}
