RM = rm -rf

CC=g++

LIB_DIR=./lib
INC_DIR=./include
SRC_DIR=./src
OBJ_DIR=./build
BIN_DIR=./bin
DOC_DIR=./doc
TEST_DIR=./test

CFLAGS = -Wall -pedantic -ansi -std=c++11

all: dir TeobaldoQuest

debug: CFLAGS += -g -O0 -pg
debug: TeobaldoQuest

TeobaldoQuest: $(OBJ_DIR)/aluno.o $(OBJ_DIR)/turma.o $(OBJ_DIR)/main.o
	@echo "============="
	@echo "Ligando o alvo $@"
	@echo "============="
	$(CC) $(CFLAGS) -o $(BIN_DIR)/$@ $^
	@echo "+++ [Executavel TeobaldoQuest criado em $(BIN_DIR)] +++"
	@echo "============="

$(OBJ_DIR)/aluno.o: $(SRC_DIR)/aluno.cpp $(INC_DIR)/aluno.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<

$(OBJ_DIR)/turma.o: $(SRC_DIR)/turma.cpp $(INC_DIR)/turma.h
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<
	
$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(CFLAGS) -I$(INC_DIR)/ -o $@ $<	

dir:
	mkdir -p bin build
	
clean: dir
	$(RM) $(BIN_DIR)/*
	$(RM) $(OBJ_DIR)/*

