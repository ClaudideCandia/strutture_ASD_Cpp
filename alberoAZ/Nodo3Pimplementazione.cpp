//
// Created by Utente on 23/01/2025.
//
#include <iostream>

#include "Nodo3p.h"

/*
void setFs(nodo* padre, nodo* figlio);
void setFd(nodo* padre, nodo* figlio);
void setPadre(nodo* figlio, nodo* padre);
void setEticheta(nodo* n, int etichetta);
nodo* getPadre(nodo* figlio);
nodo* getFs(nodo* padre);
nodo* getFd(nodo* padre);
int getEtichetta(nodo* n);
 */
//implementazione della struttura Nodo3P.h

nodo* creaNodo(const std::variant<int, std::string> &etichetta) {
 nodo* n = new nodo;
 n->etichetta = etichetta;
 n->Padre = nullptr;
 n->FiglioSin = nullptr;
 n->FiglioDes = nullptr;
 return n;
}


void setFs(nodo* padre, nodo* figlio) {
 if (padre != nullptr) {
  padre->FiglioSin = figlio;
 }else {throw std::invalid_argument("padre è nullo!");}
}
void setFd(nodo* padre, nodo* figlio) {
 if(padre != nullptr) {
  padre->FiglioDes = figlio;
 }else {throw std::invalid_argument("padre è nullo!");}
}
void setPadre(nodo* figlio, nodo* padre) {
 if (figlio != nullptr) {
  figlio->Padre = padre;
 }else {throw std::invalid_argument("figlio è nullo!");}
}
void setEticheta(nodo* n, std::variant<int,std::string>& etichetta) {
 if (n != nullptr) {
  n->etichetta = etichetta;
 }else {throw std::invalid_argument("il nodo passato è nullo!");}
}
nodo* getPadre(nodo* figlio) {
 if(figlio != nullptr) {
  return figlio->Padre;
 }else {throw std::invalid_argument("il nodo passato è nullo!");return nullptr;}
}

nodo* getFs(nodo* padre) {
 if(padre != nullptr) {
  return padre->FiglioSin;
 }else {throw std::invalid_argument("il nodo passato è nullo!");return nullptr;}
}

nodo* getFd(nodo* padre) {
 if(padre != nullptr) {
  return padre->FiglioDes;
 }else {throw std::invalid_argument("il nodo passato è nullo!");return nullptr;}
}

std::variant<int, std::string> getEtichetta(nodo* n) {
 if(n != nullptr) {
  return n->etichetta;
 } throw std::invalid_argument("il nodo passato è nullo!");return 0;}

void stampaEtichetta(const std::variant<int, std::string>& etichetta) {
 std::visit([](const auto& valore) {
     std::cout << valore << " ";
 }, etichetta);
}

// Funzione ricorsiva per la visita simmetrica
void visitaSimmetrica(nodo* radice) {
 if (radice == nullptr) {
  return; // Base case: il nodo è nullo, non fare nulla
 }

 // 1. Visita il sottoalbero sinistro
 visitaSimmetrica(getFs(radice));

 // 2. Stampa o processa il nodo corrente
 stampaEtichetta(getEtichetta(radice));

 // 3. Visita il sottoalbero destro
 visitaSimmetrica(getFd(radice));
}
// Funzione ricorsiva per la visita in preordine
void visitaInPreordine(nodo* radice) {
 if (radice == nullptr) {
  return;
 }
 stampaEtichetta(getEtichetta(radice)); // Nodo corrente
 visitaInPreordine(getFs(radice));         // Sottoalbero sinistro
 visitaInPreordine(getFd(radice));         // Sottoalbero destro
}

// Funzione ricorsiva per la visita in postordine
void visitaInPostordine(nodo* radice) {
 if (radice == nullptr) {
  return;
 }
 visitaInPostordine(getFs(radice));        // Sottoalbero sinistro
 visitaInPostordine(getFd(radice));        // Sottoalbero destro
 stampaEtichetta(getEtichetta(radice));; // Nodo corrente
}