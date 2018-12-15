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

# Opcoes de compilacao
CFLAGS = -Wall -pedantic -ansi -std=c++1y

.PHONY: all clean distclean doxy

all: dir Programa1 Programa2 Programa3

debug: CFLAGS += -g -O0 -pg
debug: dir Programa1 Programa2 Programa3

Programa1: $(OBJ_DIR)/closest2mean.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa1 criado em $(BIN_DIR)] +++"
	@echo "============="


$(OBJ_DIR)/closest2mean.o: $(SRC_DIR)/Programa1/closest2mean.cpp $(INC_DIR)/Programa1/closest2mean.hpp
	$(CC) -c $(CFLAGS) -lm -I$(INC_DIR)/Programa1/ -o $@ $<

Programa2: $(OBJ_DIR)/print_elements.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa2 criado em $(BIN_DIR)] +++"
	@echo "============="


$(OBJ_DIR)/print_elements.o: $(SRC_DIR)/Programa2/print_elements.cpp $(INC_DIR)/Programa2/print_elements.hpp
	$(CC) -c $(CFLAGS) -lm -I$(INC_DIR)/Programa2/ -o $@ $<

Programa3: $(OBJ_DIR)/showprimos.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa3 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/showprimos.o: $(SRC_DIR)/Programa3/showprimos.cpp $(INC_DIR)/Programa3/showprimos.hpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Lista/ -I$(INC_DIR)/Programa3/ -o $@ $<

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
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa3 50

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile
