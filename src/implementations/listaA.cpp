#include "listaA.h"
#include <cstdlib>
#include <stdexcept>

ListaA::ListaA() : raiz(nullptr) {} // Construtor da lista de arestas

ListaA::~ListaA() { // Destrutor da lista de arestas
    while (raiz) { 
        NoA* aux = raiz; 
        raiz = raiz->proximo;
        delete aux->a;
        delete aux;
    }
}


 bool ListaA::existeAresta(int idDestino) const { // Adicionado 'const'
    NoA* atual = raiz;
    while (atual != nullptr) {
        if (atual->a->id == idDestino) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

void ListaA::insereAresta(int destino, int peso) {
    if (existeAresta(destino)) {
        throw std::invalid_argument("Aresta já existe!");
    }
    Aresta* novaAresta = new Aresta(destino, peso);
    NoA* novoNo = new NoA(novaAresta);
    novoNo->proximo = raiz;
    raiz = novoNo;
}


int ListaA::tamanho() const { // Método para retornar o tamanho da lista
    int count = 0;
    NoA* atual = raiz;
    while (atual) {
        count++;
        atual = atual->proximo;
    }
    return count;
}

void ListaA::removeAresta(int id) {
    NoA* atual = raiz;
    NoA* anterior = nullptr;

    while (atual) {
        if (atual->a->id == id) {
            if (anterior) {
                anterior->proximo = atual->proximo;
            } else {
                raiz = atual->proximo;
            }
            delete atual->a;
            delete atual;
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
}

NoA* ListaA::getRaiz() const {
    return raiz; // Retorna a raiz da lista
}