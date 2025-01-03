#ifndef N_CONEXO_H
#define N_CONEXO_H

#include "../core/Grafo.h"

class GrafoConexo : public Grafo {
public:
    GrafoConexo(int numVertices);
    int nConexo(); // Declaração correta
};

#endif // N_CONEXO_H
