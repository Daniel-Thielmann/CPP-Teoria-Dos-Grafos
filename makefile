# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Diretórios
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
IMPL_DIR = $(SRC_DIR)/implementations
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos de origem e objetos
SRC = $(CORE_DIR)/Grafo.cpp \
      $(IMPL_DIR)/grafo_lista.cpp \
      $(IMPL_DIR)/grafo_matriz.cpp \
      $(IMPL_DIR)/ListaV.cpp \
      $(IMPL_DIR)/ListaA.cpp
OBJ = $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
MAIN = $(SRC_DIR)/main.cpp
MAIN_OBJ = $(MAIN:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Binário final
BIN = $(BIN_DIR)/programa.exe

# Regra padrão
all: $(BIN)

# Regra para criar o executável
$(BIN): $(OBJ) $(MAIN_OBJ)
	mkdir -p $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Regra genérica para criar objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza de arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
