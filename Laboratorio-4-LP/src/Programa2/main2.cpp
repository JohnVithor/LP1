/**
* @file		main2.cpp
* @brief	Resolve as expressoes do arquivo lido e de expressoes informadas pelo terminal
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

#include "avaliador_expressao.hpp"

int main(int argc, char const *argv[])
{
	std::vector< std::string > lista_expressoes;
	
	std::ifstream arquivo_expressoes;
	arquivo_expressoes.open ("Arquivos_dat/Expressoes.dat");
	if(arquivo_expressoes.bad())
	{
		std::cerr << "O arquivo não foi aberto" << std::endl;
		std::exit(1);
	}

	std::string linha;
	while (std::getline(arquivo_expressoes,linha))
	{
		lista_expressoes.push_back( linha );
	}

	for (auto j = lista_expressoes.begin(); j != lista_expressoes.end(); ++j)
	{
		std::cout << std::endl << "O resultado da expressão (" << *j 
		<< ") é de : " << resolver_expressao( *j ) << std::endl;
	}

	std::cout << std::endl <<">> Exite alguma expressão que gostaria de resolver?"
	<< " Se sim digite-a na notação polonesa inversa, se não, digite a letra 'n' ou a letra 'q" << std::endl;
	std::getline(std::cin,linha);
	
	while ( linha != "n" and linha != "q" )
	{
		std::cout << std::endl << "O resultado da expressão (" << linha 
		<< ") é de : " << resolver_expressao( linha ) << std::endl;

		std::cout << std::endl <<">> Exite alguma expressão que gostaria de resolver?"
		<< " Se sim digite-a na notação polonesa inversa, se não, digite a letra 'n' ou a letra 'q" << std::endl;
		std::getline(std::cin,linha);
	}

	return 0;
}
	