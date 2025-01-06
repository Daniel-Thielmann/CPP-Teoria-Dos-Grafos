#include "Carrega_arquivo.h"

// Construtor: Inicializa o grafo com o número especificado de vértices
Grafo::Grafo(int vertices) {
    num_vertices = vertices;
    adjacencias = new Aresta*[vertices]; // Aloca memória para as linhas da matriz
    for (int i = 0; i < vertices; ++i) {
        adjacencias[i] = new Aresta[vertices]; // Aloca memória para as colunas de cada linha
    }
}

// Adiciona uma aresta ao grafo, especificando origem, destino e peso
void Grafo::adicionar_aresta(int origem, int destino, int peso) {
    adjacencias[origem][destino].origem = origem;
    adjacencias[origem][destino].destino = destino;
    adjacencias[origem][destino].peso = peso;
}

// Exibe a representação do grafo no console
void Grafo::exibir_grafo() {
    for (int i = 0; i < num_vertices; ++i) {
        cout << "Vértice " << i << ": ";
        for (int j = 0; j < num_vertices; ++j) {
            if (adjacencias[i][j].peso != 0) {
                // Imprime a aresta se tiver peso diferente de zero (existe uma conexão)
                cout << "(" << adjacencias[i][j].destino << ", peso: " << adjacencias[i][j].peso << ") ";
            }
        }
        cout << endl;
    }
}

// Destrutor: Libera a memória alocada para a matriz de adjacências
Grafo::~Grafo() {
    for (int i = 0; i < num_vertices; ++i) {
        delete[] adjacencias[i]; // Libera cada linha
    }
    delete[] adjacencias; // Libera a matriz
}

// Carrega um grafo a partir de um arquivo
Grafo carrega_grafo(const string& nome_arquivo) {
    ifstream arquivo(nome_arquivo);
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        exit(1);
    }

    // Lê o número de vértices e arestas do arquivo
    int num_vertices, num_arestas;
    arquivo >> num_vertices >> num_arestas;

    // Cria um novo grafo com o número de vértices lido
    Grafo grafo(num_vertices);

    // Lê as informações das arestas do arquivo e adiciona ao grafo
    for (int i = 0; i < num_arestas; ++i) {
        int origem, destino, peso;
        arquivo >> origem >> destino >> peso;
        grafo.adicionar_aresta(origem, destino, peso);
    }

    arquivo.close();
    return grafo;
}
