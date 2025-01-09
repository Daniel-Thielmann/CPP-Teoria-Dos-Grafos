#ifndef N_CONEXO_H
#define N_CONEXO_H

#include "../core/Grafo.h"
#include <iostream>
#include <cstdlib> 

class GrafoConexo : public Grafo {
public:
    GrafoConexo(int numVertices);
    int nConexo(); // Método que calcula componentes conexas
};

#endif // N_CONEXO_H
