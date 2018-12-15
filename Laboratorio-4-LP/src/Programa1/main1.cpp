/**
* @file		main1.cpp
* @brief	Verifica se as strings do arquivo lida são ou não palindromos, tambem analissa strings digitadas pelo terminal
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	22/10/2017
* @date		28/10/2017
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "palindromo.hpp"

int main(int argc, char const *argv[])
{
	std::vector< std::string > lista_strings;
	
	std::ifstream arquivo_palindromos;
	arquivo_palindromos.open ("Arquivos_dat/Palindromos.dat");
	if(arquivo_palindromos.bad())
	{
		std::cerr << "O arquivo não foi aberto" << std::endl;
		std::exit(1);
	}

	std::string linha;
	while (std::getline(arquivo_palindromos,linha))
	{
		lista_strings.push_back( linha );
	}

	std::cout << "Alguns exemplos de palavras e frases palindromas, no final temos uma pequena curiosidade..." << std::endl;
	for (auto i = lista_strings.begin(); i != lista_strings.end(); ++i)
	{
		if (verifica_palindromo(*i))
		{
			std::cout << "É palindromo:\t\t " << *i << std::endl;
		}
		else
		{
			std::cout << "NÃO é palindromo:\t " << *i << std::endl;
		}
	}

	std::cout << std::endl <<">> Exite alguma palavra ou frase que gostaria de testar?"
	<< " Se sim digite-a, se não, digite a letra 'n' ou a letra 'q" << std::endl;
	std::getline(std::cin,linha);
	
	while ( linha != "n" and linha != "q" )
	{
		if ( verifica_palindromo( linha ) )
		{
			std::cout << "É palindromo:\t\t " << linha << std::endl;
		}
		else
		{
			std::cout << "NÃO é palindromo:\t " << linha << std::endl;
		}

		std::cout << std::endl <<">> Exite alguma palavra ou frase que gostaria de testar?"
		<< " Se sim digite-a, se não, digite a letra 'n' ou a letra 'q" << std::endl;
		std::getline(std::cin,linha);
	}
	return 0;
}
