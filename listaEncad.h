#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include <iostream>
#include "no.h"



class listaEncad {
private:
    No* cabecaNo; // Ponteiro para o primeiro nó da lista
    No* cauda;
    int tamanho;

public:
    listaEncad();
    ~listaEncad();
    void insereInicio(int valor);
    void insereFinal(int valor);
    int getTamanho();
 //   void exibeLista();
    bool ehVazia();
    void setCabeca(No* cabeca);
    No* getCabecaNo();


    void exibirLista();
    bool existe(int valor);
    void insereUnico(int valor);

};

#endif
