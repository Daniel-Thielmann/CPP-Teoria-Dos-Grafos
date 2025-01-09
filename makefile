# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -std=c++17 -g -I$(IMPL_DIR)

# Diretórios
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
IMPL_DIR = $(SRC_DIR)/implementations
TEST_DIR = tests
BIN_DIR = bin
OBJ_DIR = obj

# Arquivos do núcleo e implementações
SRC = $(CORE_DIR)/Grafo.cpp \
      $(IMPL_DIR)/eh_bipartido.cpp \
      $(IMPL_DIR)/get_grau.cpp \
      $(IMPL_DIR)/n_conexo.cpp

# Arquivo principal
MAIN = $(SRC_DIR)/main.cpp

# Arquivos de teste
TESTS = $(TEST_DIR)/teste_eh_bipartido.cpp \
        $(TEST_DIR)/teste_get_grau.cpp \
        $(TEST_DIR)/teste_n_conexo.cpp \
        $(TEST_DIR)/teste_todos.cpp

# Objetos
OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC) $(MAIN))
TEST_OBJ = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC) $(TESTS))

# Binaries
BIN_MAIN = $(BIN_DIR)/programa.exe
BIN_TEST = $(BIN_DIR)/teste_todos.exe

# Regra padrão
all: main test

# Regra para compilar o programa principal
main: $(OBJ)
	@echo "Objetos gerados para main:" $(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_MAIN)

# Regra para compilar os testes
test: $(TEST_OBJ)
	@echo "Objetos gerados para testes:" $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_TEST)

# Regra genérica para compilar arquivos .cpp em .o
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_MAIN) $(BIN_TEST)
