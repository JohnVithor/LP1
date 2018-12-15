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
CFLAGS = -Wall -pedantic -ansi -std=c++11

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Define os alvos geometrica, anterior e questao03 como dependencias.
# Ao final da compilacao, remove os arquivos objeto.

all: dir Corrida_sapos

debug: CFLAGS += -g -O0 -pg
debug: corrida_sapos

# Alvo (target) para a construcao do executavel geometrica
# Define os arquivos sapo.o e main.o como dependencias
Corrida_sapos: $(OBJ_DIR)/sapo.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel corrida_sapos criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto sapo.o
# Define os arquivos sapo.cpp e sapo.h como dependencias.
$(OBJ_DIR)/sapo.o: $(SRC_DIR)/sapo.cpp $(INC_DIR)/sapo.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<

# Alvo (target) para a construcao do objeto main.o
# Define o arquivo main.cpp como dependencia.
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação
dir:
	mkdir -p bin build doc
	
# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*

# FIM do Makefile
