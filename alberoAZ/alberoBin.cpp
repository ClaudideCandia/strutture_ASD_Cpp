//
// Created by Utente on 23/01/2025.
//

#include "alberoBin.h"
#include <iostream>
alberoBin::alberoBin() {
    radice = new nodo;
    std::cout << "Inserire etichetta radice" << std::endl;
    int e;
    std::cin >> e;
    radice->etichetta = e;
    radice->Padre = nullptr;
    radice->FiglioDes = nullptr;
    radice->FiglioSin = nullptr;
    std::cout << "Albero creato!" << std::endl;
}


bool alberoBin::alberoVuoto() {
    try {
        if(getFd(this->getRadice())==nullptr && getFs(this->getRadice())==nullptr) {
            return true;
        }return false;
    }catch (const std::invalid_argument e) {
        std::cout << "Errore gestito nella classe: " << e.what() << std::endl;
    }
}

void alberoBin::aggiungiSin(nodo *padre, nodo *figlio) {
    try {
        setFs(padre, figlio);
        setPadre(figlio,padre);
    }catch (const std::invalid_argument e) {
        std::cout << "Errore gestito nella classe: " << e.what() << std::endl;
    }
}
void alberoBin::aggiungiDes(nodo *padre, nodo *figlio) {
    try {
        setFd(padre,figlio);
        setPadre(figlio,padre);
    }catch (const std::invalid_argument e) {
        std::cout << "Errore gestito nella classe: " << e.what() << std::endl;
    }
}
alberoBin::~alberoBin(){}

nodo* alberoBin::getRadice() {
    return radice;
}
void alberoBin::setFiglioSinRadice(nodo *n) {
    try {
        setFs(getRadice(),n);
    }catch (const std::invalid_argument e) {
        std::cout << "Errore gestito nella classe: " << e.what() << std::endl;
    }
}
void alberoBin::setFiglioDesRadice(nodo *n) {
    try {
        setFd(getRadice(),n);
    }catch (const std::invalid_argument e) {
        std::cout << "Errore gestito nella classe: " << e.what() << std::endl;
    }
}






