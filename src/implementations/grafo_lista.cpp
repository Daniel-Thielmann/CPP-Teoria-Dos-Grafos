#include "grafo_lista.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

GrafoLista::GrafoLista(const std::string& arquivo)
    : Grafo(0, false, false, false) {
    for (int i = 0; i < numVertices; ++i) {
        // Código do loop aqui
    }
}


GrafoLista::~GrafoLista() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] grafo[i];
    }
    delete[] grafo;
}

// Adiciona uma aresta
void GrafoLista::adicionarAresta(int origem, int destino, int peso) {
    Vertice* vOrigem = vertices.encontraVertice(origem);
    Vertice* vDestino = vertices.encontraVertice(destino);

    if (!vOrigem || !vDestino) {
        throw std::invalid_argument("Erro: vértice inexistente.");
    }

    if (origem == destino) {
        throw std::invalid_argument("Erro: laços não permitidos.");
    }

    vOrigem->arestas.insereAresta(destino, peso);

    if (!direcionado) {
        vDestino->arestas.insereAresta(origem, peso);
    }
}

// Remove uma aresta
void GrafoLista::removerAresta(int origem, int destino) {
    Vertice* vOrigem = vertices.encontraVertice(origem);
    Vertice* vDestino = vertices.encontraVertice(destino);

    if (!vOrigem || !vDestino) {
        throw std::invalid_argument("Erro: vértice inexistente.");
    }

    vOrigem->arestas.removeAresta(destino);

    if (!direcionado) {
        vDestino->arestas.removeAresta(origem);
    }
}

// Imprime o grafo
void GrafoLista::imprimeGrafo() const {
    std::cout << "Lista de Adjacência:\n";
    NoV* noVertice = vertices.getRaiz();
    while (noVertice) {
        Vertice* vertice = noVertice->v;
        std::cout << "Vértice " << vertice->id << " (Peso: " << vertice->peso << "): ";

        NoA* noAresta = vertice->arestas.getRaiz();
        while (noAresta) {
            std::cout << "-> " << noAresta->a->id << " (Peso: " << noAresta->a->peso << ") ";
            noAresta = noAresta->proximo;
        }
        std::cout << std::endl;
        noVertice = noVertice->proximo;
    }
}

// Verifica se o grafo é completo
bool GrafoLista::ehCompleto() const {
    int numVertices = vertices.tamanho();
    NoV* noVertice = vertices.getRaiz();
    while (noVertice) {
        if (noVertice->v->arestas.tamanho() != numVertices - 1) {
            return false;
        }
        noVertice = noVertice->proximo;
    }
    return true;
}

// Verifica se o grafo é conexo
bool GrafoLista::ehConexo() const {
    int numVertices = vertices.tamanho();
    if (numVertices == 0) return true;

    bool* visitado = new bool[numVertices]();
    dfsConexao(vertices.encontraVertice(1), visitado);

    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            delete[] visitado;
            return false;
        }
    }
    delete[] visitado;
    return true;
}

// Verifica se o grafo tem ciclos
bool GrafoLista::temCiclo() const {
    // Implementação da lógica para detecção de ciclos
    return false;
}

// Obtém o grau de um vértice
int GrafoLista::getGrau(int vertice) const {
    if (vertice < 0 || vertice >= numVertices) {
        throw invalid_argument("Índice fora do intervalo válido.");
    }
    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (grafo[vertice][i] != 0) {
            grau++;
        }
    }
    return grau;
}

bool GrafoLista::existeAresta(int origem, int destino) const {
    if (origem < 0 || origem >= numVertices || destino < 0 || destino >= numVertices) {
        return false;
    }
    return grafo[origem][destino] != 0;
}

bool GrafoLista::ehArvore() const {
    return ehConexo() && !temCiclo();
}

void GrafoLista::dfsConexao(Vertice* vertice, bool* visitado) const {
    int id = vertice->id - 1;
    visitado[id] = true;

    NoA* noAresta = vertice->arestas.getRaiz();
    while (noAresta) {
        Vertice* vizinho = vertices.encontraVertice(noAresta->a->id);
        if (!visitado[vizinho->id - 1]) {
            dfsConexao(vizinho, visitado);
        }
        noAresta = noAresta->proximo;
    }
}
