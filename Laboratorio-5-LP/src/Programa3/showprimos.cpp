/**
* @file		showprimos.cpp
* @brief	Verifica quais dos números no intervalo 1-N informado são primos e os imprime
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/10/2017
* @date		01/11/2017	
*/

#include <iostream>		// std::cout std::cerr std::endl
#include <algorithm>	// std::find_if
#include <numeric>		// std::iota
#include <vector>		// std::vector
#include <sstream>		// std::istringstream

#include "showprimos.hpp" // verifica_primo

int main(int argc, char const *argv[])
{
	if ( argc != 2 )
	{
		std::cerr << "O Programa necessita de um único argumento." << std::endl
		<< "Esse argumento deve informar o limite superior da quantidade de números que serão analisados." << std::endl;
		return 1;
	}

	std::istringstream iss( argv[1] );
	long int size;
	iss >> size;
	if ( iss.fail() or !iss.eof() )
	{
		std::cerr << "Não foi possível utilizar o argumento informado." << std::endl;
		return 1;
	}

	std::vector< long int > container (size);
	std::iota( container.begin(), container.end(), 1 );

	auto it = std::find_if( container.begin(), container.end(), verifica_primo() );

	std::cout << "Números primos [1-" << size << "]: ";
	while ( it != container.end() )
	{
		std::cout << *it << " ";
		it = std::find_if( it+1, container.end(), verifica_primo() );		
	}
	std::cout << std::endl;
	
	return 0;
}