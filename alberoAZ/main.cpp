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
alberoBin insAuto1() {
    //inizializzo oggetto albero.
    alberoBin bin;

    //creo e aggiungo i nodi che verranno inseriti nell'albero.
    nodo* primo = creaNodo(1);
    nodo* secondo = creaNodo(2);
    nodo* terzo = creaNodo(3);
    nodo* quarto = creaNodo(4);
    nodo* quinto = creaNodo(5);

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

    //quinto figlio sinistro di secondo
    bin.aggiungiSin(secondo,quinto);
    return bin;
}
alberoBin insAuto2() {
    //inizializzo oggetto albero.
    alberoBin bin;

    //creo e aggiungo i nodi che verranno inseriti nell'albero.
    nodo* primo = creaNodo("a");
    nodo* secondo = creaNodo("b");
    nodo* terzo = creaNodo("c");
    nodo* quarto = creaNodo("d");
    nodo* quinto = creaNodo("e");

    //primo figlio sinistro della root
    bin.setFiglioSinRadice(primo);
    setPadre(primo,bin.getRadice());

    //secondo figlio sinistro di primo (foglia)
    bin.aggiungiSin(primo,secondo);

    //terzo figlio destro di primo
    bin.aggiungiDes(primo,terzo);

    //quarto figlio sinistro di terzo
    bin.aggiungiSin(terzo,quarto);

    //quinto figlio destro di terzo
    bin.aggiungiDes(terzo,quinto);
    return bin;
}
void test1() {
    alberoBin bin = insAuto1();

    visitaSimmetrica(bin.getRadice());
    std::cout<<std::endl;
    visitaInPostordine(bin.getRadice());
    std::cout<<std::endl;
    visitaInPreordine(bin.getRadice());
    std::cout<<std::endl;
    int p = calcolaProfondita(bin.getRadice());
    std::cout<<"profondita : "<<p<<std::endl;
    int foglie = bin.visitaLivelloK(bin.getRadice(),2);
    std::cout<<"foglie albero 1: "<<foglie<<std::endl;
}
void test2() {
    alberoBin bin2 = insAuto2();
    visitaSimmetrica(bin2.getRadice());
    std::cout<<std::endl;
    visitaInPostordine(bin2.getRadice());
    std::cout<<std::endl;
    visitaInPreordine(bin2.getRadice());
    std::cout<<std::endl;
    int b = calcolaProfondita(bin2.getRadice());
    std::cout<<"profondita : "<<b<<std::endl;


    int foglie2 = bin2.visitaLivelloK(bin2.getRadice(),2);
    std::cout<<"foglie albero 2: "<<foglie2<<std::endl;
}
int main() {
    test1();
    test2();
}
/*realizzare funzione che calcola numero foglie per un dato livello k
 */

