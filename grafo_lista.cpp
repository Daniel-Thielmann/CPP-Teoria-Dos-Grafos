#include <iostream>
#include "grafo_lista.h"
#include <string>
#include <fstream>

GrafoLista::GrafoLista(string path){
  
  ifstream arquivo;
  arquivo.open(path);
  cout << "Lendo arquivo " << arquivo << endl;
   
   if(arquivo.is_open()){
	   string linha;
	   while(getline(arquivo, linha)){
		   cout << linha << endl;
	   }
   }
   else{
	   cout << "Erro ao abrir o arquivo" << endl;
   }
  
 arquivo >> m_numVertices; //variavel que vai receber o numero de vertices do arquivo

listaEncad listaVertices = new listaEncad(m_numVertices); //cria uma lista de vertices

  if(m_numVertices > 0){ //se o numero de vertices for maior que 0
 m_listaAdjacencia = new listaEncad[m_numVertices](); //cria um vetor de listas de adjacencia

m_numArestas = 0; //inicializa o numero de arestas

  }
 

}


GrafoLista::~GrafoLista(){



}

GrafoLista::adicionarVertice(){


}

