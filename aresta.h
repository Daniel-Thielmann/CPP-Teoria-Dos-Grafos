#ifndef ARESTA_H
#define ARESTA_H

class Aresta { // Classe que representa uma aresta
public:
    int id;          // ID do vértice destino
    int peso;        // Peso da aresta
    bool acessada;   // Indicador de se a aresta foi acessada

    Aresta(int id, int peso = 0) // Construtor
        : id(id), peso(peso), acessada(false) {} // Inicializa os atributos
};

#endif // ARESTA_H
