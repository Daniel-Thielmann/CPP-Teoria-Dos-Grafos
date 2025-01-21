# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Diretórios
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
IMPL_DIR = $(SRC_DIR)/implementations
TEST_DIR = $(SRC_DIR)/tests

# Arquivos de origem e objetos
SRC = $(CORE_DIR)/Grafo.cpp \
      $(IMPL_DIR)/grafo_lista.cpp \
      $(IMPL_DIR)/grafo_matriz.cpp \
      $(IMPL_DIR)/ListaV.cpp \
      $(IMPL_DIR)/ListaA.cpp \
      $(IMPL_DIR)/eh_bipartido.cpp \
      $(IMPL_DIR)/get_grau.cpp \
      $(IMPL_DIR)/n_conexo.cpp

TEST_SRC = $(TEST_DIR)/teste_eh_bipartido.cpp \
           $(TEST_DIR)/teste_get_grau.cpp \
           $(TEST_DIR)/teste_n_conexo.cpp

MAIN_APP = $(SRC_DIR)/main.cpp
MAIN_TEST = $(TEST_DIR)/teste_todos_daniel.cpp

# Binário final
BIN_DIR = bin
BIN_APP = $(BIN_DIR)/programa.exe
BIN_TEST = $(BIN_DIR)/teste_todos_daniel.exe

# Regras
all: $(BIN_APP) $(BIN_TEST)

# Regra para o programa principal
$(BIN_APP): $(SRC) $(MAIN_APP)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra para os testes
$(BIN_TEST): $(SRC) $(MAIN_TEST) $(TEST_SRC)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Limpeza
clean:
	rm -rf obj $(BIN_DIR)
