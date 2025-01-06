#ifndef POSSUI_PONTE_H_INCLUDED
#define POSSUI_PONTE_H_INCLUDED

using namespace std;

const int MAX = 100; // Define o tamanho máximo do grafo

class PossuiPonte {
private:
    int tempo;             // Variável para rastrear o tempo de descoberta
    bool temPonte;         // Indica se há pelo menos uma ponte
    int adj[MAX][MAX];     // Matriz de adjacência representada como array estático
    bool visited[MAX];     // Array para verificar os nós visitados
    int disc[MAX];         // Array para armazenar o tempo de descoberta
    int low[MAX];          // Array para armazenar o menor tempo alcançável

    void dfs(int u, int parent, int n); // Função auxiliar de DFS

public:
    PossuiPonte();                       // Construtor para inicializar os dados
    void adicionarAresta(int u, int v);  // Adiciona aresta ao grafo
    bool verificarPonte(int n);          // Verifica se há pelo menos uma ponte
};


#endif // POSSUI_PONTE_H_INCLUDED
