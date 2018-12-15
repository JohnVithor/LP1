# Makefile baseado no exemplo dado pelo Professor Silvio Costa Sampaio

# $@ nome do alvo (target)
# $^ lista com os nomes de todos os pre-requisitos sem duplicatas
# $< nome do primeiro pre-requisito

# Variaveis para os subdiretorios
LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc

RM = rm -rf
CC = g++
CFLAGS = -Wall -pedantic -std=c++1y -ansi -I$(INC_DIR)
AR = ar
LIBFLAGS = -lJoao_vitor

.PHONY: all clean distclean doxy

linux: dir $(BIN_DIR)/geometrica_estatico $(BIN_DIR)/geometrica_dinamico

windows: dir $(BIN_DIR)/geometrica_estatico.exe $(BIN_DIR)/geometrica_dinamico.exe

debug: CFLAGS += -g -O0 -pg

# LINUX

$(BIN_DIR)/geometrica_estatico: $(LIB_DIR)/libJoao_vitor.a $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp -L$(LIB_DIR) $(LIBFLAGS) -o $@
	@echo "+++ [Binario criado em $@] +++"

$(BIN_DIR)/geometrica_dinamico: $(LIB_DIR)/libJoao_vitor.so $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp -L$(LIB_DIR) $(LIBFLAGS) -o $@
	@echo "+++ [Binario criado em $@] +++"

$(LIB_DIR)/libJoao_vitor.a: $(INC_DIR)/figuras_geometricas.hpp $(SRC_DIR)/figuras_geometricas_planas.cpp $(SRC_DIR)/figuras_geometricas_espaciais.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/figuras_geometricas_planas.cpp -o $(OBJ_DIR)/figuras_geometricas_planas.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/figuras_geometricas_espaciais.cpp -o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	$(AR) -cru $@ $(OBJ_DIR)/figuras_geometricas_planas.o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	@echo "+++ [Biblioteca estatica criada em $@] +++"

$(LIB_DIR)/libJoao_vitor.so: $(INC_DIR)/figuras_geometricas.hpp $(SRC_DIR)/figuras_geometricas_planas.cpp $(SRC_DIR)/figuras_geometricas_espaciais.cpp 
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/figuras_geometricas_planas.cpp -o $(OBJ_DIR)/figuras_geometricas_planas.o
	$(CC) $(CFLAGS) -fPIC -c $(SRC_DIR)/figuras_geometricas_espaciais.cpp -o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	$(CC) -shared -fPIC -o $@ $(OBJ_DIR)/figuras_geometricas_planas.o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	@echo "+++ [Biblioteca dinamica criada em $@] +++"

# WINDOWS

$(BIN_DIR)/geometrica_estatico.exe: $(LIB_DIR)/libJoao_vitor.lib $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp $(LIB_DIR)/libJoao_vitor.lib -o $@
	@echo "+++ [Executável criado em $@] +++"

$(BIN_DIR)/geometrica_dinamico.exe: $(LIB_DIR)/libJoao_vitor.dll $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp
	$(CC) $(CFLAGS) $(SRC_DIR)/main.cpp $(INC_DIR)/gerenciador.hpp $(SRC_DIR)/gerenciador.cpp $(LIB_DIR)/libJoao_vitor.dll -o $@
	@echo "+++ [Executável criado em $@] +++"

$(LIB_DIR)/libJoao_vitor.lib: $(INC_DIR)/figuras_geometricas.hpp $(SRC_DIR)/figuras_geometricas_planas.cpp $(SRC_DIR)/figuras_geometricas_espaciais.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/figuras_geometricas_planas.cpp -o $(OBJ_DIR)/figuras_geometricas_planas.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/figuras_geometricas_espaciais.cpp -o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	$(AR) cru $@ $(OBJ_DIR)/figuras_geometricas_planas.o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	@echo "+++ [Biblioteca estatica criada em $@] +++"

$(LIB_DIR)/libJoao_vitor.dll: $(INC_DIR)/figuras_geometricas.hpp $(SRC_DIR)/figuras_geometricas_planas.cpp $(SRC_DIR)/figuras_geometricas_espaciais.cpp 
	$(CC) $(CFLAGS) -c $(SRC_DIR)/figuras_geometricas_planas.cpp -o $(OBJ_DIR)/figuras_geometricas_planas.o
	$(CC) $(CFLAGS) -c $(SRC_DIR)/figuras_geometricas_espaciais.cpp -o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	$(CC) -shared -o $@ $(OBJ_DIR)/figuras_geometricas_planas.o $(OBJ_DIR)/figuras_geometricas_espaciais.o
	@echo "+++ [Biblioteca dinamica criada em $@] +++"

doxy:
	$(RM) $(DOC_DIR)/*
	doxygen Doxyfile

dir:
	mkdir -p bin build doc src include lib 
	
# Copiando o .so para as três possiveis localizações padrões para shared libraries
install: $(LIB_DIR)/libJoao_vitor.so
	sudo mkdir -p /usr/local/lib
	sudo mkdir -p /usr/local/include
	sudo mkdir -p /usr/local/src

	sudo cp $(LIB_DIR)/libJoao_vitor.so /lib/
	sudo cp $(LIB_DIR)/libJoao_vitor.so /usr/lib/
	sudo cp $(LIB_DIR)/libJoao_vitor.so /usr/local/lib/

	sudo cp $(INC_DIR)/figuras_geometricas.hpp /usr/local/include/
	sudo cp $(SRC_DIR)/figuras_geometricas_planas.cpp /usr/local/src/
	sudo cp $(SRC_DIR)/figuras_geometricas_espaciais.cpp /usr/local/src/

# Removendo o .so das três possiveis localizações padrões para shared libraries
uninstall: $(LIB_DIR)/libJoao_vitor.so
	
	sudo rm -f /lib/libJoao_vitor.so
	sudo rm -f /usr/lib/libJoao_vitor.so
	sudo rm -f /usr/local/lib/libJoao_vitor.so

	sudo rm -f /usr/local/include/figuras_geometricas.hpp
	sudo rm -f /usr/local/src/figuras_geometricas_planas.cpp
	sudo rm -f /usr/local/src/figuras_geometricas_espaciais.cpp

valgrind_estatico:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/geometrica_estatico

valgrind_dinamico:
	valgrind -v --leak-check=full --show-reachable=yes ./bin/geometrica_dinamico

clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*
	$(RM) $(DOC_DIR)/*
	$(RM) $(LIB_DIR)/*

# FIM do Makefile
