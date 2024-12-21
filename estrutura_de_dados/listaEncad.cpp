#include <iostream>
#include "listaEncad.h"
#include "no.h"
#include <fstream>
 #include <string>

using namespace std;


listaEncad::listaEncad(){
   this->cabeca = NULL;
   this->cauda = NULL;
   this->tamanho = 0;

}

listaEncad::~listaEncad(){           
   for(No* c = cabeca; c != NULL; c = c->getProx()){
	        No* temp = cabeca;
            cabeca = cabeca->getProx();           // rever a lógica
            delete temp;
   }

}

  // Adiciona um valor no início da lista
    void listaEncad::insereInicio(int valor) {
        No* novoNo = new No(valor);
        novoNo->setProx(cabeca);
        cabeca = novoNo;
        tamanho++;
    }

    // Exibe os elementos da lista
    void listaEncad::exibeLista() {
        std::cout << " \nImprimindo toda a lista \n";
        
		 if(ehVazia()){
        std::cout<< "A lista está vazia \n";
    }else{
	   
	    No* atual = cabeca;
        while (atual != nullptr) {
            std::cout << " -> " << atual->getValor();
            atual = atual->getProx();
        }
	}
    }


bool listaEncad::ehVazia(){
 
    if (cabeca == nullptr) {
        return true;
    } else {
        return false;
    }


}

void listaEncad::insereFinal(int valor)
	{
		No* novoNo = new No(valor);

		if(ehVazia())
		{
			cabeca = novoNo;
			cauda = novoNo;
		}
		else
		{
			cauda->setProx(novoNo);
			cauda = novoNo;
		}
	}

int listaEncad::getTamanho()
	{
		
		return tamanho;
	}

