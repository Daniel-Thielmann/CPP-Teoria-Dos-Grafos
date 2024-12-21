#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Classe Nó (para a lista encadeada)
class No {
public:
    int valor;   // Valor armazenado no nó
    No* prox;    // Ponteiro para o próximo nó

    // Construtor
    No(int valor) {
        this->valor = valor;
        this->prox = nullptr;
    }
};

// Classe Lista Encadeada
class listaEncad {
private:
    No* cabeca; // Ponteiro para o primeiro nó da lista
    int tamanho;

public:
    // Construtor
    listaEncad() {
        cabeca = nullptr;
        tamanho = 0;
    }

    // Destrutor
    ~listaEncad() {
        while (cabeca != nullptr) {
            No* temp = cabeca;
            cabeca = cabeca->prox;
            delete temp;
        }
    }

    // Adiciona um valor no início da lista
    void insereInicio(int valor) {
        No* novoNo = new No(valor);
        novoNo->prox = cabeca;
        cabeca = novoNo;
        tamanho++;
    }

    // Exibe os elementos da lista
    void exibeLista() {
        No* atual = cabeca;
        while (atual != nullptr) {
            std::cout << " -> " << atual->valor;
            atual = atual->prox;
        }
    }
};

// Classe Vértice
class Vertice {
public:
    int id;              // Identificador do vértice
    listaEncad arestas;  // Lista de arestas conectadas a este vértice
    Vertice* prox;       // Próximo vértice na lista encadeada de vértices

    // Construtor
    Vertice(int id) {
        this->id = id;
        this->prox = nullptr;
    }
};

// Classe GrafoLista
class GrafoLista {
private:
    Vertice* cabeca; // Ponteiro para a lista de vértices

    // Busca um vértice na lista de vértices
    Vertice* buscarVertice(int id) {
        Vertice* atual = cabeca;
        while (atual != nullptr) {
            if (atual->id == id) return atual;
            atual = atual->prox;
        }
        return nullptr;
    }

    // Adiciona um vértice ao grafo
    void adicionarVertice(int id) {
        if (buscarVertice(id) == nullptr) {
            Vertice* novoVertice = new Vertice(id);
            novoVertice->prox = cabeca;
            cabeca = novoVertice;
        }
    }

    // Adiciona uma aresta ao grafo
    void adicionarAresta(int origem, int destino) {
        Vertice* verticeOrigem = buscarVertice(origem);
        if (verticeOrigem != nullptr) {
            verticeOrigem->arestas.insereInicio(destino);
        }
    }

public:
    // Construtor que lê o arquivo e monta o grafo
    GrafoLista(const std::string& path) {
        cabeca = nullptr;
        std::ifstream arquivo("teste.txt");

        if (!arquivo.is_open()) {
            std::cerr << "Erro ao abrir o arquivo " << path << std::endl;
            return;
        }

        std::string linha;
        int numVertices;

        // Lendo o número de vértices (primeira linha)
        if (std::getline(arquivo, linha)) {
            numVertices = std::stoi(linha);
            for (int i = 1; i <= numVertices; i++) {
                adicionarVertice(i);
            }
        }

        // Lendo as arestas
        while (std::getline(arquivo, linha)) {
            std::istringstream iss(linha);
            int origem, destino;
            if (iss >> origem >> destino) {
                adicionarAresta(origem, destino);
            }
        }

        arquivo.close();
    }

    // Exibe o grafo
    void exibirGrafo() {
        Vertice* atual = cabeca;
        while (atual != nullptr) {
            std::cout << "Vértice " << atual->id << ":";
            atual->arestas.exibeLista();
            std::cout << std::endl;
            atual = atual->prox;
        }
    }

    // Destrutor
    ~GrafoLista() {
        while (cabeca != nullptr) {
            Vertice* temp = cabeca;
            cabeca = cabeca->prox;
            delete temp;
        }
    }
};

int main() {
    // Caminho do arquivo que contém as informações do grafo
    std::string path = "grafo.txt";

    // Criando o grafo a partir do arquivo
    GrafoLista grafo(path);

    // Exibindo o grafo
    std::cout << "Grafo carregado:\n";
    grafo.exibirGrafo();

    return 0;
}
