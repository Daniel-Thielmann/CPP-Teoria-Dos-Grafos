# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Diretórios
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
IMPL_DIR = $(SRC_DIR)/implementations

# Arquivos
SRC = $(CORE_DIR)/Grafo.cpp \
      $(IMPL_DIR)/grafo_lista.cpp \
      $(IMPL_DIR)/grafo_matriz.cpp
MAIN = $(SRC_DIR)/main.cpp

# Binário
BIN = programa.exe

# Regra padrão
all: $(BIN)

$(BIN): $(SRC) $(MAIN)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(BIN)
