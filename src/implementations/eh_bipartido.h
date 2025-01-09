#ifndef EH_BIPARTIDO_H
#define EH_BIPARTIDO_H

#include "../core/Grafo.h"
#include <cstdlib> 

class GrafoBipartido : public Grafo {
public:
    GrafoBipartido(int numVertices);
    bool ehBipartido(); // Método para verificar se o grafo é bipartido
};

#endif // EH_BIPARTIDO_H
