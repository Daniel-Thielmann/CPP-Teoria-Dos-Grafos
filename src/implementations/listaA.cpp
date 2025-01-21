#include "listaA.h"

#include <cstdlib>


ListaA::ListaA() : raiz(nullptr) {} // Construtor da lista de arestas

ListaA::~ListaA() { // Destrutor da lista de arestas
    while (raiz) { 
        NoA* aux = raiz; 
        raiz = raiz->proximo;
        delete aux->a;
        delete aux;
    }
}


 void ListaA::insereAresta(int destino, int peso) { // Método para inserir uma aresta
        Aresta* novaAresta = new Aresta(destino, peso);
        NoA* novoNo = new NoA(novaAresta);
        novoNo->proximo = raiz;
        raiz = novoNo;
    }

    // Método para verificar se existe uma aresta (com id)
    bool ListaA::existeAresta(int idDestino) {
        NoA* atual = raiz;
        while (atual != nullptr) {
            if (atual->a->id == idDestino) {
                return true;
            }
            atual = atual->proximo;
        }
        return false;
    }

   NoA* ListaA::getRaiz() const { // Método para retornar a raiz da lista
    return raiz; // Retorna a raiz da lista
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
