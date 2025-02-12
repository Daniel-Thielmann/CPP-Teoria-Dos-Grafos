#include "listaA.h"
#include "listaV.h"
#include <iostream>

using namespace std;

int main() {
    // Testando Lista de Vértices (ListaV)
    cout << "Testando Lista de Vértices:" << endl;

    ListaV listaVertices;
    listaVertices.inserirVertice(new Vertice(1, 10)); // Vértice 1 com peso 10
    listaVertices.inserirVertice(new Vertice(2, 20)); // Vértice 2 com peso 20
    listaVertices.inserirVertice(new Vertice(3, 30)); // Vértice 3 com peso 30

    // Impressão manual dos vértices
    NoV* noVertice = listaVertices.getRaiz();
    while (noVertice) {
        Vertice* vertice = noVertice->v;
        cout << "Vértice ID: " << vertice->id << ", Peso: " << vertice->peso << endl;
        noVertice = noVertice->proximo;
    }

    // Testando Lista de Arestas (ListaA)
    cout << "\nTestando Lista de Arestas:" << endl;

    ListaA listaArestas;
    listaArestas.insereAresta(2, 5); // Aresta de destino 2 com peso 5
    listaArestas.insereAresta(3, 7); // Aresta de destino 3 com peso 7
    listaArestas.insereAresta(1, 10); // Aresta de destino 1 com peso 10

    // Impressão manual das arestas
    NoA* noAresta = listaArestas.getRaiz();
    while (noAresta) {
        Aresta* aresta = noAresta->a;
        cout << "Aresta Destino: " << aresta->id << ", Peso: " << aresta->peso << endl;
        noAresta = noAresta->proximo;
    }

    return 0;
}
