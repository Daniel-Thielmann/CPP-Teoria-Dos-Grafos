#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include <iostream>
#include "no.h"

class listaEncad {
private:
    No* cabeca; // Ponteiro para o primeiro nó da lista
    No* cauda;
    int tamanho;

public:
    listaEncad();
    ~listaEncad();
    void insereInicio(int valor);
    void insereFinal(int valor);
    int getTamanho();
    void exibeLista();
    bool ehVazia();
};

#endif
