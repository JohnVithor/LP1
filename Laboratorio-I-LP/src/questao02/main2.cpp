/**
* @file		main2.cpp
* @brief	Programa que calcula o maior número primo anterior ao fatorial de um número
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/

#include <iostream>
#include <sstream>

#include "primalidade.h"
#include "fatorial.h"

/**
* @brief	Funcao principal
* @details	Calcula o maior número primo anterior ao fatorial de um número
*			fornecido pelo usuário via linha de comando. O primeiro argumento 
*			refere-se ao número que terá o fatorial calculado
* @param	argc Numero de argumentos fornecidos via linha de comando
* @param	argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char const *argv[])
{
	if (argc != 2){
		std::cout << "É necessário passar apenas um numero de entrada como argumento." << std::endl;
		return 1;
	} else {
		std::istringstream entrada (argv[1]);
		int num_entrada;
		if (!(entrada >> num_entrada)){
    		std::cerr << "Entrada Inválida " << argv[1] << std::endl;
    		std::cout << "Reinicie o programa com uma entrada númerica." << std::endl;
    		return 1;
		}
		if (num_entrada <= 2){
			std::cout << "Não há primo menor que 2." << std::endl;
			return 1;
		}
		
		if (num_entrada >= 15){
			std::cout << "Maior valor de entrada possível é 14." << std::endl;
			return 1;
		}
		std::cout << "Maior numero primo anterior ao fatorial de " << num_entrada << 
		" ( "<< fatorial(num_entrada) << " ) eh " << maior_primo_anterior(fatorial(num_entrada)) << ".\n";
	}
	return 0;
}