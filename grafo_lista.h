#ifndef GRAFO_TESTE_H
#define GRAFO_TESTE_H

#include <iostream>
#include <string>
#include "listaEncad.h"

using namespace std;

class grafoLista{

private:
     
     listaEncad* listaAdjacencia;
     int valorVertice,nVertice,nAresta;
     string nomeArq;


public:

    void adicionaAresta(listaEncad listaAdjacencia[],int origem, int destino);

    void imprimeListaAdjancecia(listaEncad *listaAdjacencia, int nVertice);

    grafoLista(string nomeArq);
    ~grafoLista();

    int getNAresta();
    int getNVertice();

    listaEncad* getListaAdjacencia();
};


#endif