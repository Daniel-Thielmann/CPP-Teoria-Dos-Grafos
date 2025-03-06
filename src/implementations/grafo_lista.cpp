#include "grafo_lista.h"
#include "../core/Grafo.h"
#include <fstream>
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



/*GrafoLista::~GrafoLista() {
    for (int i = 0; i < numVertices; ++i) {
        delete[] grafo[i];
    }
    delete[] grafo;
}
*/


GrafoLista::~GrafoLista() {

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
}






void GrafoLista::deleta_no(int id) {
    std::cout << "Excluindo nó " << id << "...\n";
    

    for (NoV* noAtual = vertices.getRaiz(); noAtual != nullptr; noAtual = noAtual->proximo) {
        if (noAtual->v->id != id) {
            noAtual->v->arestas.removeAresta(id);
        }
    }

    NoV* atual = vertices.getRaiz();
    NoV* anterior = nullptr;
    
    while (atual != nullptr) {
        if (atual->v->id == id) {
        
            if (anterior == nullptr) {
                vertices.setRaiz(atual->proximo);
            } else {
              
                anterior->proximo = atual->proximo;
            }
     
            delete atual->v;
            delete atual;
            
          
            numVertices--;
            
            std::cout << "Vertice " << id << " deletado com sucesso!\n";
            return;  
        }
        anterior = atual;
        atual = atual->proximo;
    }
    
    
    throw std::invalid_argument("Erro: vertice inexistente.");
}




void GrafoLista::novo_no(int id, int peso) {
   
    NoV* atual = vertices.getRaiz();
    while (atual != nullptr) {
        if (atual->v->id == id) {
       
            throw std::invalid_argument("Erro: vértice já existe.");
        }
        atual = atual->proximo;
    }
    
    
    Vertice* novoVertice = new Vertice(id, peso);
    
    vertices.inserirVertice(novoVertice);
    
    numVertices++;

}



void GrafoLista::deleta_aresta(int id) {
    std::cout << "Excluindo primeira aresta do nó " << id << "...\n";
    
    // Encontra o vértice com o id informado.
    Vertice* v = vertices.encontraVertice(id);
    if (v == nullptr) {
        std::cout << "Nenhum vértice com id " << id << " encontrado.\n";
        return;
    }
    
    NoA* firstEdge = v->arestas.getRaiz();
    if (firstEdge == nullptr) {
        std::cout << "Nenhuma aresta para remover no nó " << id << ".\n";
        return;
    }
    
    int dest = firstEdge->a->id;
    
    v->arestas.removePrimeiraAresta();
    
    if (!direcionado) {
        Vertice* vDest = vertices.encontraVertice(dest);
        if (vDest != nullptr) {
            vDest->arestas.removeAresta(id);
        }
    }
}

void GrafoLista::nova_aresta(int origem, int destino, int peso, bool direcionado) {
  
    Vertice* vOrigem = vertices.encontraVertice(origem);
    Vertice* vDestino  = vertices.encontraVertice(destino);

    if (!vOrigem || !vDestino) {
        throw std::invalid_argument("Erro: vértice inexistente.");
    }

    // Evita laços
    if (origem == destino) {
        throw std::invalid_argument("Erro: laços não permitidos.");
    }

    
    vOrigem->arestas.insereAresta(destino, peso);

    // Se o grafo for não direcionado, insere a aresta inversa (de destino para origem).
    if (!direcionado) {
        vDestino->arestas.insereAresta(origem, peso);
    }
}


