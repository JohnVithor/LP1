/**
* @file		print_elements.hpp
* @brief	Declaração e implementação da função print_elements()
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/10/2017
* @date		01/11/2017	
*/

#include <iostream>		// std::cout

/**
* @brief Imprime os elementos de um container, aceita um label para a impressão 
e tambem qual separador será utilizado
* @param[in] collection Container cujos elementos serão impressos
* @param[in] label String que será utilizada antes da impressão dos elementos
* @param[in] separator Caractere que irá separar um elemento do outro durante a impressão 
*/
template< typename TContainer >
void print_elements ( const TContainer& collection, const char* label = "", const char separator = ' ' )
{
	std::cout << label;

	for ( auto i = collection.begin(); i != collection.end(); ++i)
	{
		std::cout << *i << separator;
	}

	std::cout << std::endl;
}