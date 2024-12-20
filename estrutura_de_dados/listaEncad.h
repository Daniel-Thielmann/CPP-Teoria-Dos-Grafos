#ifndef LISTAENCAD_H
#define LISTAENCAD_H

#include <iostream>
#include "no.h"


class listaEncad{
    private:
    No* elemento; // Ponteiro para o primeiro nó da lista
    
    public:
    // Construtor
    listaEncad();
     

    // Destrutor
    ~listaEncad();

    // Inserir no início da lista
    void insereElemento(int info);
    
    bool removeElemento(int info);

    void exibirLista();
    bool estaVazia(); 

};

#endif