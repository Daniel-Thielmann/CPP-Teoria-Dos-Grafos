#ifndef LISTAA_H
#define LISTAA_H

#include "aresta.h"
#include "noA.h"

class ListaA { // Classe que representa uma lista de arestas
private:
    NoA* raiz; // Raiz da lista

public:
    ListaA(); // Construtor
    ~ListaA(); // Destrutor

   bool existeAresta(int idDestino); // Verifica se existe uma aresta com o ID de destino
    void insereAresta(int destino, int peso); // Insere uma aresta na lista
    NoA* getRaiz() const; // Retorna a raiz da lista
    int tamanho() const; // Retorna o tamanho da lista


};

#endif // LISTAA_H
