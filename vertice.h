#ifndef VERTICE_H
#define VERTICE_H

#include "listaA.h"

class Vertice {
public:
    int id;
    int peso;
    bool acessado;
    ListaA arestas;

    Vertice(int id, int peso = 0)
        : id(id), peso(peso), acessado(false), arestas() {}
};

#endif // VERTICE_H
