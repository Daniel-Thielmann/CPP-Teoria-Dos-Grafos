#include "listaV.h"

ListaV::ListaV() : raiz(nullptr) {} // Construtor

ListaV::~ListaV() { // Destrutor
    while (raiz) {
        NoV* aux = raiz;
        raiz = raiz->proximo;
        delete aux->v;
        delete aux;
    }
}

void ListaV::inserirVertice(Vertice* vertice) { // Insere um vértice na lista
    NoV* novo = new NoV(vertice);
    novo->proximo = raiz;
    raiz = novo;
}

Vertice* ListaV::encontraVertice(int id) const { // Encontra um vértice na lista
    NoV* atual = raiz;
    while (atual) {
        if (atual->v->id == id) {
            return atual->v;
        }
        atual = atual->proximo;
    }
    return nullptr; // Retorna nullptr se o vértice não for encontrado.
}

NoV* ListaV::getRaiz() const { // Retorna a raiz da lista
    return raiz;
}

int ListaV::tamanho() const { // Retorna o tamanho da lista
    int count = 0;
    NoV* atual = raiz;
    while (atual) {
        count++;
        atual = atual->proximo;
    }
    return count;
}