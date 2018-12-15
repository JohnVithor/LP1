/**
* @file		ler_entradas.cpp
* @brief	Implementação das funções get_one_char e get_int
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/08/2017
* @date		31/08/2017
*/
#include <iostream>
#include <sstream>
#include <string>

#include "ler_entradas.h"

char get_one_char(){
	char escolhido;
	std::string line;
	while (std::getline(std::cin, line)) // Repete a leitura de toda a linha
	{ 
		if (line.length() == 1) // Verifica se na linha lida só há um caractere
		{
			escolhido = line[0];
			// Atribui à variavel 'escolhido' o primeiro (e unico) caractere da linha lida.
			break; // Sai da repetição
		} else{
			std::cout << "[ERRO] Entrada inválida, por favor digite uma entrada válida." << std::endl;
			std::cout << "Digite um caractere: ";
		}
	}
	return escolhido;
}

int get_int(){
	std::string line;
	int numero = 0;

	// o trecho de codigo abaixo foi editado e não é de minha autoria. Créditos: Silvio Costa Sampaio
	while (std::getline(std::cin, line)) // repete a leitura de toda a linha
	{ 
		std::stringstream ss(line); // cria um stringstream com o conteudo da linha
		if ((ss >> numero) and ss.eof())
		{
			// Tenta extrair um 'inteiro' do stringstream
			// Se extraiu com sucesso e não restou nada mais...
			break; // Sai da repetição
		}
		std::cout << "[ERRO] Entrada inválida, por favor digite uma entrada válida." << std::endl;
		std::cout << "Digite um valor inteiro: ";
	}
	// fim do trecho
	return numero;
}