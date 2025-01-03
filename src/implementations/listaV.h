#ifndef LISTAV_H
#define LISTAV_H

#include "vertice.h"
#include "noV.h"

class ListaV { // Classe que representa uma lista de vértices
private:
    NoV* raiz; // Raiz da lista

public:
    ListaV(); // Construtor
    ~ListaV(); // Destrutor
    void inserirVertice(Vertice* vertice); // Insere um vértice na lista
    Vertice* encontraVertice(int id) const; // Encontra um vértice na lista
    NoV* getRaiz() const; // Retorna a raiz da lista
    int tamanho() const; // Retorna o tamanho da lista
  


};

#endif // LISTAV_H
