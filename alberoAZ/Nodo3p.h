//
// Created by Utente on 23/01/2025.
//

#ifndef NODO3P_H
#define NODO3P_H
#include <variant>
#include<string>
//definizione struttura nodo a 3 puntatori 1 etichetta

struct NodoBin{
    NodoBin* FiglioSin = nullptr;
    NodoBin* FiglioDes = nullptr;
    NodoBin* Padre = nullptr;
    std::variant<int, std::string> etichetta;
};
//alias per la struttura
typedef struct NodoBin nodo;
nodo* creaNodo(const std::variant<int, std::string> &etichetta);
//prototipi funzioni accesso
void setFs(nodo* padre, nodo* figlio);
void setFd(nodo* padre, nodo* figlio);
void setPadre(nodo* figlio, nodo* padre);
void setEticheta(nodo* n,std::variant<int, std::string> &etichetta);

nodo* getPadre(nodo* figlio);
nodo* getFs(nodo* padre);
nodo* getFd(nodo* padre);
std::variant<int, std::string>getEtichetta(nodo* n);
void stampaEtichetta(const std::variant<int, std::string>& etichetta);
// Funzione ricorsiva per la visita simmetrica
void visitaSimmetrica(nodo* radice);
void visitaInPostordine(nodo* radice);
void visitaInPreordine(nodo* radice);

#endif //NODO3P_H
