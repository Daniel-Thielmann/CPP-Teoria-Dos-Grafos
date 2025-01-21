# Trabalho 1 - Teoria dos Grafos

Este repositório contém a implementação do **Trabalho 1** para a disciplina **Teoria dos Grafos** (DCC059) da **Universidade Federal de Juiz de Fora (UFJF)**. O objetivo é implementar uma classe abstrata para grafos em C++, com diferentes estruturas de armazenamento para vértices e arestas, atendendo aos requisitos definidos pelo professor Gabriel Souza.

---

## **Descrição do Projeto**

### **1. Estruturas de Representação**

O projeto implementa duas representações de grafos:

- **grafo_matriz**: Utiliza uma **matriz de adjacência** para representar as arestas, sendo estática e, no caso de grafos não direcionados, armazenada como uma matriz triangular.
- **grafo_lista**: Utiliza **listas encadeadas** para armazenar os vértices e arestas dinamicamente.

### **2. Funcionalidades Implementadas**

A classe abstrata `grafo` fornece as seguintes funcionalidades que são herdadas pelas classes filhas:

- `eh_bipartido()`: Verifica se o grafo é bipartido.
- `n_conexo()`: Retorna o número de componentes conexas.
- `get_grau()`: Retorna o grau do grafo.
- `get_ordem()`: Retorna a ordem do grafo.
- `eh_direcionado()`: Verifica se o grafo é direcionado.
- `vertice_ponderado()`: Verifica se os vértices têm pesos.
- `aresta_ponderada()`: Verifica se as arestas têm pesos.
- `eh_completo()`: Verifica se o grafo é completo.
- `eh_arvore()`: Verifica se o grafo é uma árvore.
- `possui_articulacao()`: Verifica se existe algum vértice de articulação.
- `possui_ponte()`: Verifica se existe alguma aresta ponte.
- `carrega_grafo(arquivo)`: Carrega um grafo a partir de um arquivo `.txt`.
- `novo_grafo(arquivo_descricao)`: Gera um grafo aleatório com base nas configurações fornecidas em um arquivo de descrição.

---

## **Requisitos**

- **Linguagem**: C++
- **Paradigma**: Programação Orientada a Objetos (POO), utilizando conceitos de herança e encapsulamento.
- **Compilação e Execução**:

  - Os comandos devem ser executados via terminal, conforme os seguintes casos:

  1. Compilar o Programa Principal localizado em /src/main.cpp: mingw32-make
     1.1 Execute o programa: .\bin\programa.exe

  2. Compilar e Executar os Testes localizados em /tests: mingw32-make test
     2.1 Execute todos os testes: .\bin\teste_todos.exe

  3. Limpar os arquivos gerados:
     mingw32-make clean

---
