#include <iostream>
#include "grafo_lista.h"
#include "no.h"
#include "listaEncad.h"

using namespace std;

int main() {
    // Nome do arquivo que contém as informações do grafo
    string nome = "teste.txt";

    // Criando o grafo a partir do arquivo
    grafoLista grafo(nome);

    return 0;
}
