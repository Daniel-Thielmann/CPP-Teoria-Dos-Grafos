#include <iostream>
#include <string>
#include <fstream>
#include "grafo_lista.h"

using namespace std;

grafoLista::grafoLista(string nome) {
    string linha;
    int verticea, verticeb;
    ifstream arquivo;

    // Abrindo o arquivo
    arquivo.open(nome);
    if (arquivo.is_open()) {
        // Lendo o número de vértices
        arquivo >> nVertice;
        cout << "Numero de vertices: " << nVertice << endl;
        arquivo.ignore(); // Ignora o restante da linha

        // Alocando memória para a lista de adjacência
        listaAdjacencia = new listaEncad[nVertice];

        int nAresta = 0;

        // Lendo as arestas do arquivo
        while (arquivo >> verticea >> verticeb) {
            adicionaAresta(listaAdjacencia, verticea -1, verticeb -1); // Ajuste para índices baseados em 0
            nAresta++;
        }

        cout << "Numero de arestas: " << nAresta << endl;

        // Imprimindo a lista de adjacência
        imprimeListaAdjancecia(listaAdjacencia, nVertice);
    } else {
        cout << "Erro ao abrir o arquivo" << endl;
        exit(1);
    }

    // Fechando o arquivo
    arquivo.close();
}

grafoLista::~grafoLista() {
    delete[] listaAdjacencia; // Liberando a memória alocada
}

void grafoLista::imprimeListaAdjancecia(listaEncad *listaAdjacencia, int nVertice) {
    cout << "Lista de Adjacencia" << endl;
    for (int i = 0; i < nVertice; i++) {
        cout << "Vertice " << i + 1 << ": ";
        listaAdjacencia[i].exibirLista(); // Exibindo a lista do vértice atual
        cout << endl;
    }
}
/*
void grafoLista::adicionaAresta(listaEncad listaAdjacencia[], int verticea, int verticeb) {
    listaAdjacencia[verticea].insereFinal(verticeb); // Adiciona a aresta na lista de adjacência
    listaAdjacencia[verticeb].insereFinal(verticea); // Adiciona a aresta inversa para grafo não-direcionado
}
*/
void grafoLista::adicionaAresta(listaEncad listaAdjacencia[], int verticea, int verticeb) {
    listaAdjacencia[verticea].insereUnico(verticeb); // Adiciona a aresta na lista de adjacência
    listaAdjacencia[verticeb].insereUnico(verticea); // Adiciona a aresta inversa para grafo não-direcionado
}

int grafoLista::getNAresta() {
    return nAresta;
}

int grafoLista::getNVertice() {
    return nVertice;
}

listaEncad* grafoLista::getListaAdjacencia() {
    return listaAdjacencia;
}
