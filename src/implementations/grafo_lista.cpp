#include "grafo_lista.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Construtor: carrega o grafo a partir de um arquivo
GrafoLista::GrafoLista(string nomeArquivo) { 
    
    this->direcionado = false; // Inicializa como não direcionado
    this->ponderadoVertices = false; // Inicializa como não ponderado
    this->ponderadoArestas = false; // Inicializa como não ponderado
   
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {  // Verifica se o arquivo foi aberto corretamente
        std::cerr << "Erro ao abrir o arquivo: " << nomeArquivo << std::endl;
        exit(1);
    }

    int numVertices;
    arquivo >> numVertices >> direcionado >> ponderadoVertices >> ponderadoArestas; // Lê o cabeçalho do arquivo

    // Adiciona os vértices
    for (int i = 0; i < numVertices; ++i) {       
        int peso = ponderadoVertices ? 0 : 1;     // Peso padrão é 1
        if (ponderadoVertices) {  // Se os vértices forem ponderados, leia o peso
            arquivo >> peso;
        }
        adicionaVertice(i + 1, peso); // Adiciona vértice com ID 1, 2, 3, ...
    }

    // Adiciona as arestas
    int origem, destino, peso;
    while (arquivo >> origem >> destino) {
        peso = ponderadoArestas ? 0 : 1; // Peso padrão é 1
        if (ponderadoArestas) { // Se as arestas forem ponderadas, leia o peso
            arquivo >> peso;
        }
        adicionaAresta(origem, destino, peso); // Adiciona a aresta ao grafo
    }

    arquivo.close();
}

// Destrutor: limpa a memória alocada
GrafoLista::~GrafoLista() {
    // A lista de vértices possui um destrutor que libera os recursos
}

// Adiciona um vértice ao grafo
void GrafoLista::adicionaVertice(int id, int peso) {
    Vertice* novoVertice = new Vertice(id, peso);
    vertices.inserirVertice(novoVertice);
}


void GrafoLista::adicionaAresta(int origem, int destino, int peso) { // Adiciona uma aresta ao grafo
    // Localiza os vértices de origem e destino
    Vertice* vOrigem = vertices.encontraVertice(origem);
    Vertice* vDestino = vertices.encontraVertice(destino);

    // Verifica se os vértices existem
    if (!vOrigem || !vDestino) {
        std::cerr << "Erro: vértice de origem ou destino não encontrado." << std::endl;
        return;
    }

    // Prevenção de laços
    if (origem == destino) {
        std::cerr << "Erro: laços não são permitidos." << std::endl;
        exit(1);
    }

    // Prevenção de multiarestas
    NoA* noAresta = vOrigem->arestas.getRaiz();
    while (noAresta) {
        if (noAresta->a->id == destino) {
            std::cerr << "Erro: multiaresta detectada entre " << origem << " e " << destino << "." << std::endl;
            exit(1);
        }
        noAresta = noAresta->proximo;
    }

    // Insere a aresta no grafo
    vOrigem->arestas.insereAresta(destino, peso);

    // Se o grafo não for direcionado, adiciona a aresta reversa
    if (!direcionado) {
        vDestino->arestas.insereAresta(origem, peso);
    }
}



// Imprime o grafo no formato de lista de adjacência
void GrafoLista::imprimeGrafo() const {
    NoV* noVertice = vertices.getRaiz();  // Acessa a raiz da lista de vértices
    while (noVertice) {  // Enquanto houver vértices na lista
        Vertice* vertice = noVertice->v;  // Pega o vértice atual
        cout << "Vértice " << vertice->id << " (Peso: " << vertice->peso << "): ";

        // Verifica se o vértice tem arestas
        if (vertice->arestas.getRaiz() == nullptr) {
            cout << "(sem arestas)" << endl;  // Caso o vértice não tenha arestas
        } else {
            // Itera sobre as arestas do vértice
            NoA* noAresta = vertice->arestas.getRaiz();
            while (noAresta) {
                cout << "-> " << noAresta->a->id << " (Peso: " << noAresta->a->peso << ") ";
                noAresta = noAresta->proximo;  // Move para a próxima aresta
            }
            cout << endl;
        }

        noVertice = noVertice->proximo;  // Move para o próximo vértice
    }
}



// Verifica se as arestas são ponderadas
bool GrafoLista::arestasPonderadas() const {
    return ponderadoArestas;
}


bool GrafoLista::temCiclo() const { // Verifica se o grafo direcionado contém ciclos
    int numVertices = vertices.tamanho();
    bool* visitado = new bool[numVertices]();
    bool* pilhaRecursao = new bool[numVertices](); // Para rastrear a pilha de recursão

    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            // Verifica ciclos a partir de cada vértice não visitado
            Vertice* vertice = vertices.encontraVertice(i + 1);
            if (verificaCicloUtil(vertice, visitado, pilhaRecursao)) {
                delete[] visitado;
                delete[] pilhaRecursao;
                return true; // Ciclo encontrado
            }
        }
    }

    delete[] visitado;
    delete[] pilhaRecursao;
    return false; // Nenhum ciclo encontrado
}

bool GrafoLista::verificaCicloUtil(Vertice* vertice, bool* visitado, bool* pilhaRecursao) const { // Verifica ciclos em grafos direcionados
    int id = vertice->id - 1; // Índice zero-based

    // Se o vértice não foi visitado, explora suas arestas
    if (!visitado[id]) {
        visitado[id] = true;
        pilhaRecursao[id] = true;

        NoA* noAresta = vertice->arestas.getRaiz();
        while (noAresta) {
            int destino = noAresta->a->id - 1;

            // Caso não visitado, faz a chamada recursiva
            if (!visitado[destino]) {
                Vertice* destinoVertice = vertices.encontraVertice(destino + 1);
                if (verificaCicloUtil(destinoVertice, visitado, pilhaRecursao)) {
                    return true;
                }
            } 
            // Se já está na pilha de recursão, encontrou um ciclo
            else if (pilhaRecursao[destino]) {
                return true;
            }

            noAresta = noAresta->proximo;
        }
    }

    pilhaRecursao[id] = false; // Remove da pilha de recursão
    return false;
}



bool GrafoLista::temCicloNaoDirecionado() const { // Verifica se o grafo contém ciclos
    int numVertices = vertices.tamanho();
    bool* visitado = new bool[numVertices]();

    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i] && verificaCicloNaoDirecionado(vertices.encontraVertice(i + 1), visitado, -1)) {
            delete[] visitado;
            return true;
        }
    }

    delete[] visitado;
    return false;
}

bool GrafoLista::verificaCicloNaoDirecionado(Vertice* vertice, bool* visitado, int pai) const { // Verifica ciclos em grafos não direcionados
    int id = vertice->id - 1;
    visitado[id] = true;

    NoA* noAresta = vertice->arestas.getRaiz();
    while (noAresta) {
        int destino = noAresta->a->id - 1;

        if (!visitado[destino]) {
            if (verificaCicloNaoDirecionado(vertices.encontraVertice(destino + 1), visitado, id)) {
                return true;
            }
        } else if (destino != pai) { // Se o destino já foi visitado e não é o pai, encontrou um ciclo
            return true;
        }

        noAresta = noAresta->proximo;
    }

    return false;
}

bool GrafoLista::ehDirecionado() const { // Verifica se o grafo é direcionado
    return direcionado; // Retorna o valor armazenado ao carregar o grafo
}

// Verifica se o grafo é completo (todos os vértices estão conectados)
bool GrafoLista::ehCompleto() const { 
    int numVertices = vertices.tamanho();
    NoV* noVertice = vertices.getRaiz(); // Pega a raiz da lista de vértices
    while (noVertice) {
        if (noVertice->v->arestas.tamanho() != numVertices - 1) { // Verifica se o vértice tem o número correto de arestas
            return false;
        }
        noVertice = noVertice->proximo; // Move para o próximo vértice
    }
    return true;
}

const ListaV& GrafoLista::getVertices() const { // Retorna uma referência constante para os vértices
    return vertices; // vertices deve ser uma instância de ListaV
}

// Verifica se o grafo é conexo
bool GrafoLista::ehConexo() const {
    int numVertices = vertices.tamanho();
    if (numVertices == 0) return true; // Grafo vazio é considerado conexo

    bool* visitado = new bool[numVertices]();
    dfsConexao(vertices.encontraVertice(1), visitado); // Executa DFS ignorando direções

    // Verifica se todos os vértices foram visitados
    for (int i = 0; i < numVertices; ++i) {
        if (!visitado[i]) {
            delete[] visitado;
            return false; // Algum vértice não foi alcançado; grafo não é conexo
        }
    }

    delete[] visitado;
    return true; // Todos os vértices foram visitados; grafo é conexo
}

// Modifica a DFS para ignorar direções (funciona para grafos direcionados e não direcionados)
void GrafoLista::dfsConexao(Vertice* vertice, bool* visitado) const {
    int id = vertice->id - 1; // Índice zero-based
    visitado[id] = true;

    // Percorre as arestas de saída
    NoA* noAresta = vertice->arestas.getRaiz();
    while (noAresta) {
        int destino = noAresta->a->id - 1; // Índice zero-based
        if (!visitado[destino]) {
            dfsConexao(vertices.encontraVertice(destino + 1), visitado);
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