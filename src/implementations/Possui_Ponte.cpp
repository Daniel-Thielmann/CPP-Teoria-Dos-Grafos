#include "Possui_ponte.h"
#include <cstring> // Para memset, a função memset é utilizada para preencher um bloco de memória com um valor específico

// Construtor para inicializar as estruturas de dados
PossuiPonte::PossuiPonte() : tempo(0), temPonte(false) {
    memset(adj, 0, sizeof(adj));                    // Inicializa a matriz de adjacência com zeros.
    memset(visited, false, sizeof(visited));        // Marca todos os vértices como não visitados
    memset(disc, -1, sizeof(disc));                 // Inicializa o array de tempos de descoberta com -1.
    memset(low, -1, sizeof(low));                   // Inicializa o array de tempos mínimos com -1
}

// Função para adicionar uma aresta ao grafo
void PossuiPonte::adicionarAresta(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Função auxiliar de busca em profundidade (DFS)
void PossuiPonte::dfs(int u, int parent, int n) {
    visited[u] = true;
    disc[u] = low[u] = ++tempo; // Inicializa tempo de descoberta e low

    for (int v = 0; v < n; ++v) {
        if (adj[u][v] == 0) continue; // Ignora se não houver aresta

        if (!visited[v]) {
            dfs(v, u, n); // Explora aresta (u, v)

            low[u] = std::min(low[u], low[v]); // Atualiza low[u]

            if (low[v] > disc[u]) {
                temPonte = true; // Detecta ponte
            }
        } else if (v != parent) {
            low[u] = std::min(low[u], disc[v]); // Atualiza low[u] para aresta de retorno
        }
    }
}

// Função principal para verificar se há pelo menos uma ponte
bool PossuiPonte::verificarPonte(int n) {
    // Inicializa variáveis e chama DFS para cada componente conectado
    memset(visited, false, sizeof(visited));
    memset(disc, -1, sizeof(disc));
    memset(low, -1, sizeof(low));
    tempo = 0;
    temPonte = false;

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, -1, n);
        }
    }

    return temPonte;
}
