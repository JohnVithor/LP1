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
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I. -I$(INC_DIR)

# Garante que os alvos desta lista nao sejam confundidos com arquivos de mesmo nome
.PHONY: all clean distclean doxy

# Define o alvo (target) para a compilacao completa.
# Define os alvos geometrica, anterior e questao03 como dependencias.
# Ao final da compilacao, remove os arquivos objeto.

all: dir Programa1 Programa2

debug: CFLAGS += -g -O0 -pg
debug: dir Programa1 Programa2

# Alvo (target) para a construcao do executavel Programa1
# Define os arquivos empresa.o, funcionario.o e main1.o como dependencias
Programa1: $(OBJ_DIR)/empresa.o $(OBJ_DIR)/funcionario.o $(OBJ_DIR)/catalago_empresas.o $(OBJ_DIR)/datas.o $(OBJ_DIR)/ler_entradas.o $(OBJ_DIR)/main1.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa1 criado em $(BIN_DIR)] +++"
	@echo "============="

# Alvo (target) para a construcao do objeto empresa.o
# Define os arquivos empresa.cpp, empresa.h como dependencias.
$(OBJ_DIR)/empresa.o: $(SRC_DIR)/Programa1/empresa.cpp $(INC_DIR)/Programa1/empresa.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1 -o $@ $<

# Alvo (target) para a construcao do objeto funcionario.o
# Define os arquivos funcionario.cpp, funcionario.h como dependencias.
$(OBJ_DIR)/funcionario.o: $(SRC_DIR)/Programa1/funcionario.cpp $(INC_DIR)/Programa1/funcionario.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1 -o $@ $<
	
# Alvo (target) para a construcao do objeto datas.o
# Define os arquivos datas.cpp, datas.h como dependencias.
$(OBJ_DIR)/datas.o: $(SRC_DIR)/Programa1/datas.cpp $(INC_DIR)/Programa1/datas.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1 -o $@ $<

# Alvo (target) para a construcao do objeto funcionario.o
# Define os arquivos funcionario.cpp, funcionario.h como dependencias.
$(OBJ_DIR)/catalago_empresas.o: $(SRC_DIR)/Programa1/catalago_empresas.cpp $(INC_DIR)/Programa1/catalago_empresas.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa1 -o $@ $<

# Alvo (target) para a construcao do objeto main1.o
# Define o arquivo main1.cpp como dependencias.
$(OBJ_DIR)/main1.o: $(SRC_DIR)/Programa1/main1.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<



# Alvo (target) para a construcao do executavel Programa2
# Define os arquivos dado.o, jogador.o e main2.o como dependencias.
Programa2: $(OBJ_DIR)/dado.o $(OBJ_DIR)/jogador.o $(OBJ_DIR)/ler_entradas.o $(OBJ_DIR)/main2.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel Programa2 criado em $(BIN_DIR)] +++"
	@echo "============="
	
# Alvo (target) para a construcao do objeto dado.o
# Define os arquivos dado.cpp e dado.h como dependencias.
$(OBJ_DIR)/dado.o: $(SRC_DIR)/Programa2/dado.cpp $(INC_DIR)/Programa2/dado.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2 -o $@ $<

# Alvo (target) para a construcao do objeto jogador.o
# Define os arquivos jogador.cpp e jogador.h como dependencias.
$(OBJ_DIR)/jogador.o: $(SRC_DIR)/Programa2/jogador.cpp $(INC_DIR)/Programa2/jogador.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/Programa2 -o $@ $<
	
# Alvo (target) para a construcao do objeto main2.o
# Define o arquivo main2.cpp como dependências.
$(OBJ_DIR)/main2.o: $(SRC_DIR)/Programa2/main2.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR) -o $@ $<
	


# Alvo (target) para a construcao do objeto ler_entradas.o
# Define os arquivos ler_entradas.cpp e ler_entradas.h como dependencias.
$(OBJ_DIR)/ler_entradas.o: $(SRC_DIR)/ler_entradas.cpp $(INC_DIR)/ler_entradas.h
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

# FIM do Makefile
