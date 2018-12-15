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

all: geometrica anterior questao03 

debug: CFLAGS += -g -O0 -pg
debug: geometrica anterior questao03

# Alvo (target) para a construcao do executavel geometrica
# Define os arquivos classe11.o, classe12.o e main1.o como dependencias
geometrica: $(OBJ_DIR)/area.o $(OBJ_DIR)/calcula.o $(OBJ_DIR)/perimetro.o $(OBJ_DIR)/volume.o $(OBJ_DIR)/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel geometrica criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto area.o
# Define os arquivos area.cpp e area.h como dependencias.
$(OBJ_DIR)/area.o: $(SRC_DIR)/questao01/area.cpp $(INC_DIR)/questao01/area.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

# Alvo (target) para a construcao do objeto calcula.o
# Define os arquivos calcula.cpp, calcula.h como dependencias.
$(OBJ_DIR)/calcula.o: $(SRC_DIR)/questao01/calcula.cpp $(INC_DIR)/questao01/calcula.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

# Alvo (target) para a construcao do objeto perimetro.o
# Define os arquivos perimetro.cpp, perimetro.h como dependencias.
$(OBJ_DIR)/perimetro.o: $(SRC_DIR)/questao01/perimetro.cpp $(INC_DIR)/questao01/perimetro.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao01 -o $@ $<

# Alvo (target) para a construcao do objeto volume.o
# Define os arquivos volume.cpp, volume.h como dependencias.
$(OBJ_DIR)/volume.o: $(SRC_DIR)/questao01/volume.cpp $(INC_DIR)/questao01/volume.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao01 -o $@ $<
	
# Alvo (target) para a construcao do objeto main1.o
# Define o arquivo main1.cpp como dependencias.
$(OBJ_DIR)/main1.o: $(SRC_DIR)/questao01/main1.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao01 -o $@ $<


# Alvo (target) para a construcao do executavel anterior
# Define os arquivos fatorial.o e main2.o como dependencias.
anterior: $(OBJ_DIR)/fatorial.o $(OBJ_DIR)/primalidade.o $(OBJ_DIR)/main2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel anterior criado em $(BIN_DIR)] +++"
	@echo "============="
	
# Alvo (target) para a construcao do objeto fatorial.o
# Define os arquivos fatorial.cpp e fatorial.h como dependencias.
$(OBJ_DIR)/fatorial.o: $(SRC_DIR)/questao02/fatorial.cpp $(INC_DIR)/questao02/fatorial.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao02 -o $@ $<

# Alvo (target) para a construcao do objeto primalidade.o
# Define os arquivos primalidade.cpp e primalidade.h como dependencias.
$(OBJ_DIR)/primalidade.o: $(SRC_DIR)/questao02/primalidade.cpp $(INC_DIR)/questao02/primalidade.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao02 -o $@ $<

# Alvo (target) para a construcao do objeto main2.o
# Define o arquivo main2.cpp como dependências.
$(OBJ_DIR)/main2.o: $(SRC_DIR)/questao02/main2.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/questao02 -o $@ $<
	
	
# Alvo (target) para a construcao do executavel questao03
# Define o arquivo main3.o como dependência.
questao03: $(OBJ_DIR)/main3.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel questao03 criado em $(BIN_DIR)] +++"
	@echo "============="
	
# Alvo (target) para a construcao do objeto main3.o
# Define o arquivo main3.cpp como dependências.
$(OBJ_DIR)/main3.o: $(SRC_DIR)/questao03/main3.cpp
	$(CC) -c $(CFLAGS) -o $@ $<


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

clean:
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*

# FIM do Makefile
