#include "grafo_lista.h"
#include <fstream>
#include <stdexcept>
#include <stdexcept>
#include <iostream>
#include "listaA.h"
#include "listaV.h"

GrafoLista::GrafoLista(const std::string& arquivo)
    : Grafo(0, false, false, false) {
    std::ifstream file(arquivo);
    if (!file.is_open()) {
        throw std::runtime_error("Erro ao abrir o arquivo: " + arquivo);
    }

    // Lê os vértices e arestas
    file >> numVertices >> direcionado >> ponderadoVertices >> ponderadosArestas;

    for (int i = 0; i < numVertices; ++i) {
        int peso = ponderadoVertices ? 0 : 1;
        if (ponderadoVertices) {
            file >> peso;
        }
        Vertice* vertice = new Vertice(i + 1, peso);
        vertices.inserirVertice(vertice);
    }

    int origem, destino, peso;
    while (file >> origem >> destino) {
        peso = ponderadosArestas ? 0 : 1;
        if (ponderadosArestas) {
            file >> peso;
        }
        adicionarAresta(origem, destino, peso);
    }

    std::cout << "Numero de vertices: " << numVertices << std::endl;

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
        throw std::invalid_argument("Erro: vertice inexistente.");
    }

    if (origem == destino) {
        throw std::invalid_argument("Erro: lacos nao permitidos.");
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
        throw std::invalid_argument("Erro: vertice inexistente.");
    }

    vOrigem->arestas.removeAresta(destino);

    if (!direcionado) {
        vDestino->arestas.removeAresta(origem);
    }
}

// Imprime o grafo
void GrafoLista::imprimeGrafo() const {
    std::cout << "Lista de Adjacencia:\n";
    NoV* noVertice = vertices.getRaiz();
    if (!noVertice) {
        std::cout << "Lista de vertices vazia.\n";
        return;
    }

    while (noVertice) {
        Vertice* vertice = noVertice->v;
        std::cout << "Vertice " << vertice->id << " (Peso: " << vertice->peso << "): ";

        NoA* noAresta = vertice->arestas.getRaiz();
        if (!noAresta) {
            std::cout << "Sem arestas.";
        }

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
        throw std::invalid_argument("Indice fora do intervalo valido.");
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

    // Percorre as arestas reversas (caso seja um grafo direcionado)
    NoV* noVertice = vertices.getRaiz();
    while (noVertice) {
        NoA* arestaReversa = noVertice->v->arestas.getRaiz();
        while (arestaReversa) {
            if (arestaReversa->a->id == vertice->id && !visitado[noVertice->v->id - 1]) {
                dfsConexao(noVertice->v, visitado);
            }
            arestaReversa = arestaReversa->proximo;
        }
        noVertice = noVertice->proximo;
    }
}

bool GrafoLista::vertice_ponderado() const{     // Verifica se os vertices do grafo tem peso
    return ponderadoVertices;   // Retorna o valor armazenado ao carregar o grafo
}

int* GrafoLista::getArestas(int id) const {
    Vertice* vertice = vertices.encontraVertice(id);
    NoA* noAresta = vertice->arestas.getRaiz();
    if (!noAresta) {
        return null;
    }
    // Contar quantas arestas existem para alocar espaço
    int count = 0;
    NoA* temp = noAresta;
    while (temp) {
        count++;
        temp = temp->proximo;
    }
    // Criar um array dinâmico para armazenar os ids dos vértices adjacentes
    int* adjacentes = new int[count];
    // Preencher o array com os ids dos vértices conectados
    temp = noAresta; // Resetar ponteiro para o início da lista
    for (int i = 0; i < count; i++) {
        adjacentes[i] = temp->a->id;
        temp = temp->proximo;
    }
    return adjacentes;
}
}
