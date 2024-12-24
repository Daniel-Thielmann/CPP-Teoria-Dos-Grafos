#include <iostream>
#include "grafo_lista.h"
#include "include/funcoes/eh_conexo.h"
#include "include/funcoes/tem_ciclo.h"
#include "include/funcoes/eh_arvore.h"
#include "include/funcoes/eh_completo.h"

using namespace std;

int main() {
    // Nome do arquivo que contém as informações do grafo
    string nome = "teste.txt";

    // Criando o grafo a partir do arquivo
    grafoLista grafo(nome);

    cout << endl << endl;

   bool x = eConexo(grafo.getListaAdjacencia(), grafo.getNVertice());
   if(x == true){
       cout << "O grafo é conexo" << endl;
    }else{
        cout << "O grafo não é conexo" << endl;
    }

    bool y = temCiclo(grafo.getListaAdjacencia(), grafo.getNVertice());

    if(y == true){
        cout << "O grafo tem ciclo" << endl;
    }else{ 
        cout << "O grafo não tem ciclo" << endl;
    }


    bool z = eh_arvore(grafo.getListaAdjacencia(), grafo.getNVertice());
    if(z == true){
        cout << "O grafo é uma árvore" << endl;
    }else{ 
        cout << "O grafo não é uma árvore" << endl;
    }

    bool w = ehCompleto(grafo.getListaAdjacencia(), grafo.getNVertice());
    if(w == true){
        cout << "O grafo é completo" << endl;
        }else{
            cout << "O grafo não é completo" << endl;
        }

    return 0;
}
