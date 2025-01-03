#ifndef EH_BIPARTIDO_H
#define EH_BIPARTIDO_H

#include "../core/Grafo.h"

class GrafoBipartido : public Grafo {
public:
    GrafoBipartido(int numVertices);
    bool ehBipartido(); // Declaração do método
};

#endif // EH_BIPARTIDO_H
