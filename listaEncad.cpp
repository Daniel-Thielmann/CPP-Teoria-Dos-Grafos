#include <iostream>
#include "listaEncad.h"
#include "no.h"
#include <fstream>
 #include <string>

using namespace std;

//Construtor da lista encadeada
listaEncad::listaEncad() {
    this->cabecaNo = nullptr;
    this->cauda = nullptr;
    this->tamanho = 0;
}

//Desconstrutor da lista encadeada
listaEncad::~listaEncad() {           
    while (cabecaNo != nullptr) {
        No* temp = cabecaNo;
        cabecaNo = cabecaNo->getProx();
        delete temp;
    }
    cauda = nullptr;
    tamanho = 0;
}



  // Adiciona um valor no início da lista
    void listaEncad::insereInicio(int valor) {
        No* novoNo = new No(valor);
        novoNo->setProx(cabecaNo);
        cabecaNo = novoNo;
        tamanho++;
    }



void listaEncad::setCabeca(No* cabecaNo){
    this->cabecaNo = cabecaNo;
}

/*
void listaEncad::exibeLista() {
    if (ehVazia()) {
        return; // Não faz nada se a lista estiver vazia
    }
    
    No* atual = cabecaNo;
    bool primeiraAresta = true; // Usada para controlar quando adicionar a seta
    
    while (atual != nullptr) {
        if (!primeiraAresta) {
            std::cout << " -> "; // Adiciona a seta entre os vértices
        }
        
        std::cout << atual->getValor(); // Imprime o valor da aresta
        
        primeiraAresta = false; // Depois de imprimir a primeira aresta, permite adicionar a seta
        atual = atual->getProx(); // Avança para o próximo nó
    }
}

*/



bool listaEncad::ehVazia(){
 
    if (cabecaNo == nullptr) {
        return true;
    } else {
        return false;
    }


}



void listaEncad::insereFinal(int valor) {
    No* novo = new No(valor);
    novo->setProx(nullptr);
    
    if (ehVazia()) {
        cabecaNo = novo;
    } else {
        No* atual = cabecaNo;
        while (atual->getProx() != nullptr) {
            atual = atual->getProx();
        }
        atual->setProx(novo);
    }
}





int listaEncad::getTamanho() {
    return tamanho;
}


No* listaEncad::getCabecaNo() {
    return cabecaNo;
}

//talvez desnecessárias
void listaEncad::insereUnico(int valor) {
    if (!existe(valor)) {
        insereFinal(valor);
    }
}

bool listaEncad::existe(int valor) {
    No *atual = cabecaNo;
    while (atual != nullptr) {
        if (atual->getValor() == valor) {
            return true;
        }
        atual = atual->getProx(); //ver se vai funfa
    }
    return false;
}

void listaEncad::exibirLista() {
    No *atual = cabecaNo;
    while (atual != nullptr) {
        cout << atual->getValor() + 1; // Adiciona 1 para base-1
        if (atual->getProx() != nullptr) {
            cout << " -> ";
        }
        atual = atual->getProx();
    }
}

