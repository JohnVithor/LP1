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
CFLAGS = -Wall -pedantic -ansi -std=c++1z 

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Define os alvos geometrica, anterior e questao03 como dependencias.
# Ao final da compilacao, remove os arquivos objeto.

all: dir Programa1 Programa2 Programa3

debug: CFLAGS += -g -O0 -pg
debug: dir Programa1 Programa2 Programa3

Programa1: $(OBJ_DIR)/Programa1/produto.o $(OBJ_DIR)/Programa1/roupa.o $(OBJ_DIR)/Programa1/bebida.o $(OBJ_DIR)/Programa1/fruta.o $(OBJ_DIR)/Programa1/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa1 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/Programa1/produto.o: $(SRC_DIR)/Programa1/produto.cpp $(INC_DIR)/Programa1/produto.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<

$(OBJ_DIR)/Programa1/roupa.o: $(SRC_DIR)/Programa1/roupa.cpp $(INC_DIR)/Programa1/roupa.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<
	
$(OBJ_DIR)/Programa1/bebida.o: $(SRC_DIR)/Programa1/bebida.cpp $(INC_DIR)/Programa1/bebida.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<

$(OBJ_DIR)/Programa1/fruta.o: $(SRC_DIR)/Programa1/fruta.cpp $(INC_DIR)/Programa1/fruta.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<

$(OBJ_DIR)/Programa1/main1.o: $(SRC_DIR)/Programa1/main1.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1/ -o $@ $<


Programa2: $(OBJ_DIR)/Programa2/agencia_bancaria.o $(OBJ_DIR)/Programa2/conta.o $(OBJ_DIR)/Programa2/movimentacao.o $(OBJ_DIR)/ler_entradas.o $(OBJ_DIR)/Programa2/main2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa2 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/Programa2/agencia_bancaria.o: $(SRC_DIR)/Programa2/agencia_bancaria.cpp $(INC_DIR)/Programa2/agencia_bancaria.h 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<

$(OBJ_DIR)/Programa2/conta.o: $(SRC_DIR)/Programa2/conta.cpp $(INC_DIR)/Programa2/conta.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<
	
$(OBJ_DIR)/Programa2/movimentacao.o: $(SRC_DIR)/Programa2/movimentacao.cpp $(INC_DIR)/Programa2/movimentacao.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<

$(OBJ_DIR)/Programa2/main2.o: $(SRC_DIR)/Programa2/main2.cpp 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<


Programa3: $(OBJ_DIR)/Programa3/agencia_bancaria.o $(OBJ_DIR)/Programa3/conta.o $(OBJ_DIR)/Programa3/movimentacao.o $(OBJ_DIR)/Programa3/corrente.o $(OBJ_DIR)/Programa3/poupanca.o $(OBJ_DIR)/ler_entradas.o $(OBJ_DIR)/Programa3/main3.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa3 criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/Programa3/agencia_bancaria.o: $(SRC_DIR)/Programa3/agencia_bancaria.cpp $(INC_DIR)/Programa3/agencia_bancaria.h 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<

$(OBJ_DIR)/Programa3/conta.o: $(SRC_DIR)/Programa3/conta.cpp $(INC_DIR)/Programa3/conta.h 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<

$(OBJ_DIR)/Programa3/poupanca.o: $(SRC_DIR)/Programa3/poupanca.cpp $(INC_DIR)/Programa3/poupanca.h 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<

$(OBJ_DIR)/Programa3/corrente.o: $(SRC_DIR)/Programa3/corrente.cpp $(INC_DIR)/Programa3/corrente.h 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<
	
$(OBJ_DIR)/Programa3/movimentacao.o: $(SRC_DIR)/Programa3/movimentacao.cpp $(INC_DIR)/Programa3/movimentacao.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<

$(OBJ_DIR)/Programa3/main3.o: $(SRC_DIR)/Programa3/main3.cpp 
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa3/ -o $@ $<


$(OBJ_DIR)/ler_entradas.o: $(SRC_DIR)/ler_entradas.cpp $(INC_DIR)/ler_entradas.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2/ -o $@ $<

# Alvo (target) para a geração automatica de documentacao usando o Doxygen.
# Sempre remove a documentacao anterior (caso exista) e gera uma nova.
doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

# Alvo (target) para a criação dos diretórios dos binários e dos objetos
# Usado antes de iniciar a compilação

valgrind_1:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa1

valgrind_2:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa2

valgrind_3:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/Programa3

dir:
	mkdir -p bin build/Programa1 build/Programa2 build/Programa3 doc
	
# Alvo (target) usado para limpar os arquivos temporarios (objeto)
# gerados durante a compilacao, assim como os arquivos binarios/executaveis.

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*

# FIM do Makefile
