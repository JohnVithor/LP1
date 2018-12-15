# Makefile baseado no exemplo dado pelo Professor Silvio Costa Sampaio

# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito

# Comandos do sistema operacional
RM = rm -rf

# Compilador
CC=g++

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

# Opcoes de compilacao  -I$(INC_DIR)
CFLAGS = -Wall -pedantic -ansi -std=c++1y 

.PHONY: all clean distclean doxy

all: dir Programa1 Programa2 Programa3

debug: CFLAGS += -g -O0 -pg
debug: dir Programa1 Programa2 Programa3

Programa1: $(OBJ_DIR)/palindromo.o $(OBJ_DIR)/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa1 criado em $(BIN_DIR)] +++"
	@echo "============="


$(OBJ_DIR)/palindromo.o: $(SRC_DIR)/Programa1/palindromo.cpp $(INC_DIR)/Programa1/palindromo.hpp #$(INC_DIR)/stack.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<

$(OBJ_DIR)/main1.o: $(SRC_DIR)/Programa1/main1.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<

Programa2: $(OBJ_DIR)/avaliador_expressao.o $(OBJ_DIR)/main2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa2 criado em $(BIN_DIR)] +++"
	@echo "============="


$(OBJ_DIR)/avaliador_expressao.o: $(SRC_DIR)/Programa2/avaliador_expressao.cpp $(INC_DIR)/Programa2/avaliador_expressao.hpp #$(INC_DIR)/stack.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<

$(OBJ_DIR)/main2.o: $(SRC_DIR)/Programa2/main2.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<

Programa3: $(OBJ_DIR)/main3.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa3 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/main3.o: $(SRC_DIR)/Programa3/main3.cpp $(INC_DIR)/Programa3/lista.hpp $(INC_DIR)/Programa3/lista.inl $(INC_DIR)/Programa3/MyIterator.inl $(INC_DIR)/Programa3/Node.inl $(INC_DIR)/Programa3/lista_ordenada.hpp $(INC_DIR)/Programa3/lista_ordenada.inl
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

dir:
	mkdir -p bin build doc
	
valgrind_1:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa1

valgrind_2:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa2

valgrind_3:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa3

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*

# FIM do Makefile
