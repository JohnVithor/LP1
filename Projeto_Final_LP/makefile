# Makefile baseado no exemplo dado pelo Professor Silvio Costa Sampaio

# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito

# Variaveis para os subdiretorios
LIB_DIR=lib
INC_DIR=include
SRC_DIR=src
OBJ_DIR=build
BIN_DIR=bin
DOC_DIR=doc

RM = rm -rf
CC = g++
CFLAGS = -Wall -pedantic -ansi -std=c++11 -I$(INC_DIR)
AR = ar
LIBFLAGS = -lPetFera

.PHONY: all clean distclean doxy

linux: dir $(BIN_DIR)/cadastrar $(BIN_DIR)/exportar 

debug: CFLAGS += -g -O0 -pg
debug: $(BIN_DIR)/teste

# LINUX

$(BIN_DIR)/cadastrar: $(LIB_DIR)/libPetFera.so $(SRC_DIR)/main.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp -L$(LIB_DIR) $(LIBFLAGS) -o $@
	@echo "+++ [Binario criado em $@] +++"

$(BIN_DIR)/exportar: $(SRC_DIR)/Pet_Fera_Exportar.cpp $(INC_DIR)/Pet_Fera_Exportar.hpp
	$(CC) $(CFLAGS) $(SRC_DIR)/Pet_Fera_Exportar.cpp -o $@
	@echo "+++ [Binario criado em $@] +++"

$(LIB_DIR)/libPetFera.so: $(OBJ_DIR)/Animal.o $(OBJ_DIR)/Anfibio.o $(OBJ_DIR)/Ave.o $(OBJ_DIR)/Mamifero.o $(OBJ_DIR)/Reptil.o $(OBJ_DIR)/Silvestre.o $(OBJ_DIR)/AnfibioExotico.o $(OBJ_DIR)/AnfibioNativo.o $(OBJ_DIR)/MamiferoExotico.o $(OBJ_DIR)/MamiferoNativo.o $(OBJ_DIR)/ReptilExotico.o $(OBJ_DIR)/ReptilNativo.o $(OBJ_DIR)/AveExotico.o $(OBJ_DIR)/AveNativo.o $(OBJ_DIR)/Funcionario.o $(OBJ_DIR)/Pet_Fera_Cadastro.o
	$(CC) -shared -fPIC -o $@ $^
	@echo "+++ [Biblioteca dinamica criada em $@] +++"

$(OBJ_DIR)/Animal.o: $(SRC_DIR)/Animal.cpp $(INC_DIR)/Animal.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Anfibio.o: $(SRC_DIR)/Anfibio.cpp $(INC_DIR)/Anfibio.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Ave.o: $(SRC_DIR)/Ave.cpp $(INC_DIR)/Ave.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Mamifero.o: $(SRC_DIR)/Mamifero.cpp $(INC_DIR)/Mamifero.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Reptil.o: $(SRC_DIR)/Reptil.cpp $(INC_DIR)/Reptil.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Silvestre.o: $(SRC_DIR)/Silvestre.cpp $(INC_DIR)/Silvestre.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/AnfibioExotico.o: $(SRC_DIR)/AnfibioExotico.cpp $(INC_DIR)/AnfibioExotico.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/AnfibioNativo.o: $(SRC_DIR)/AnfibioNativo.cpp $(INC_DIR)/AnfibioNativo.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/MamiferoExotico.o: $(SRC_DIR)/MamiferoExotico.cpp $(INC_DIR)/MamiferoExotico.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/MamiferoNativo.o: $(SRC_DIR)/MamiferoNativo.cpp $(INC_DIR)/MamiferoNativo.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/ReptilExotico.o: $(SRC_DIR)/ReptilExotico.cpp $(INC_DIR)/ReptilExotico.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/ReptilNativo.o: $(SRC_DIR)/ReptilNativo.cpp $(INC_DIR)/ReptilNativo.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/AveExotico.o: $(SRC_DIR)/AveExotico.cpp $(INC_DIR)/AveExotico.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/AveNativo.o: $(SRC_DIR)/AveNativo.cpp $(INC_DIR)/AveNativo.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Funcionario.o: $(SRC_DIR)/Funcionario.cpp $(INC_DIR)/Funcionario.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

$(OBJ_DIR)/Pet_Fera_Cadastro.o: $(SRC_DIR)/Pet_Fera_Cadastro.cpp $(INC_DIR)/Pet_Fera_Cadastro.hpp
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

dir:
	mkdir -p bin build doc src include lib 
	
# Copiando o .so para as três possiveis localizações padrões para shared libraries
install: $(LIB_DIR)/libPetFera.so
	sudo mkdir -p /usr/local/lib

	sudo cp $(LIB_DIR)/libPetFera.so /lib/
	sudo cp $(LIB_DIR)/libPetFera.so /usr/lib/
	sudo cp $(LIB_DIR)/libPetFera.so /usr/local/lib/

# Removendo o .so das três possiveis localizações padrões para shared libraries
uninstall:
	
	sudo rm -f /lib/libPetFera.so
	sudo rm -f /usr/lib/libPetFera.so
	sudo rm -f /usr/local/lib/libPetFera.so

valgrind_cadastrar:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/cadastrar

valgrind_exportar:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/exportar

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*
	$(RM) $(LIB_DIR)/*

# FIM do Makefile
