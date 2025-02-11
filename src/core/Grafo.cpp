#include "Grafo.h"
#include <iostream>

// Construtor
Grafo::Grafo(int numVertices, bool ponderadoVertices, bool ponderadosArestas, bool direcionado) {
    this->numVertices = numVertices;
    this->ponderadoVertices = ponderadoVertices;
	this->ponderadosArestas = ponderadosArestas;
	this->direcionado = direcionado;

    // Alocação dinâmica da matriz de adjacências
    adjacencias = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencias[i] = new int[numVertices]();
    }
}

Grafo::Grafo(int numVertices) {
    this->numVertices = numVertices;

    // Alocação dinâmica da matriz de adjacências
    adjacencias = new int*[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjacencias[i] = new int[numVertices]();
    }
}

// Destrutor
Grafo::~Grafo() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] adjacencias[i];
    }
    delete[] adjacencias;
}

// Adiciona uma aresta
void Grafo::adicionarAresta(int origem, int destino) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        adjacencias[origem][destino] = 1;
        adjacencias[destino][origem] = 1;
    }
}

// Remove uma aresta
void Grafo::removerAresta(int origem, int destino) {
    if (origem >= 0 && origem < numVertices && destino >= 0 && destino < numVertices) {
        adjacencias[origem][destino] = 0;
        adjacencias[destino][origem] = 0;
    }
}

// Imprime a matriz de adjacências
void Grafo::imprimirGrafo() {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencias[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Obtém o grau de um vértice
int Grafo::getGrau(int vertice) {
    if (vertice < 0 || vertice >= numVertices) return -1;

    int grau = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencias[vertice][i] != 0) { // Verifica se há aresta
            grau++;
        }
    }
    return grau;
}

// Retorna se as arestas tem direção
bool Grafo::ehDirecionado()
{
	return direcionado;
}

// Retorna se os vertices tem peso
bool Grafo::verticePonderado()
{
	return ponderadoVertices;
}

// Retorna se as arestas têm peso
bool Grafo::arestaPonderada()
{
	return ponderadosArestas;
}

// Retorna o número de elementos
int Grafo::get_ordem()
{
	return numVertices;
}

int Grafo::dfsMenorCaminho(int atual, int destino, bool visitado[], int distanciaAtual) 
{
    if (atual == destino) {
        return distanciaAtual; // Retorna a distância atual
    }

    visitado[atual] = true;
    int menorDistancia = -1; // Inicializa com -1
    for (int vizinho = 0; vizinho < numVertices; vizinho++) {
        if (adjacencias[atual][vizinho] > 0 && !visitado[vizinho]) {
            int distancia = dfsMenorCaminho(vizinho, destino, visitado, distanciaAtual + adjacencias[atual][vizinho]);
            // Se um caminho válido foi encontrado, atualiza a menorDistancia
            if (distancia != -1) {
                if (menorDistancia == -1 || distancia < menorDistancia) {
                    menorDistancia = distancia;
                }
            }
        }
    }

    visitado[atual] = false; 
    return menorDistancia; // Retorna a menor distância
}

// Função que retorna o maior menor caminho no grafo sem depender de uma função separada para menor caminho
int Grafo::maiorMenorCaminho(int *inicio, int *fim)
{
    int maiorCaminho = 0;
    
    for (int i = 0; i < numVertices; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            if (i != j) {
                bool visitado[numVertices];
                for (int k = 0; k < numVertices; k++) {
                    visitado[k] = false;
                }            
                int menorCaminho = dfsMenorCaminho(i, j, visitado, 0);
                if (menorCaminho > maiorCaminho) {
                    *inicio = i;
                    *fim = j;
                    maiorCaminho = menorCaminho;
                }
            }
        }
    }
    return maiorCaminho;
}