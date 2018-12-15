/**
* @file		avaliador_expressao.cpp
* @brief	Implementação das funções necessarias para avaliar uma expressão na notação polonesa inversa
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	22/10/2017
* @date		28/10/2017
*/

#include <iostream>	
#include <stdexcept>
#include <sstream>
#include <cassert>
#include <cmath>

#include "avaliador_expressao.hpp"
#include "../stack.hpp"

using value_type = long int;

value_type str_to_int( std::string& alvo )
{
	std::istringstream iss( alvo );

	value_type value;
	
	iss >> value;

	if ( iss.fail() )
		throw std::runtime_error( "str_to_int(): Ocorreu um erro durante a conversão, inteiro não foi reconhecido." );

	return value;
}

void separar ( std::string& alvo, std::vector< std::string > &resultado, const char &delimitador )
{
	size_t start = alvo.find_first_not_of(delimitador);
	size_t end = start;

	while (start != std::string::npos)
	{
		end = alvo.find(delimitador, start);

		resultado.push_back(alvo.substr(start, end-start));
		
		start = alvo.find_first_not_of(delimitador, end);
	}
}

value_type operar ( value_type &valor_1, value_type &valor_2, char operador )
{
	value_type resultado = 0;
	switch ( operador )
	{
		case '^' : 
			resultado = static_cast< value_type >( pow( valor_1, valor_2 ) );
			break;

		case '*' : 
			resultado =  valor_1 * valor_2;
			break;

		case '/' : 
			if ( valor_2 == 0 ) throw std::runtime_error( "Divisão por zero" );

			resultado = valor_1/valor_2;
			break;

		case '%' : 
			if ( valor_2 == 0 ) throw std::runtime_error( "Divisão por zero" );

			resultado = valor_1%valor_2;
			break;

		case '+' : 
			resultado = valor_1 + valor_2;
			break;

		case '-' : 
			resultado =  valor_1 - valor_2;
			break;
	}

	return resultado;
}

bool eh_operador( char c )
{
	return std::string("+-%^/*").find( c ) != std::string::npos;
}

bool eh_numero ( std::string& alvo )
{
	for (unsigned int i = 0; i < alvo.size(); ++i)
	{
		if ( ( !isdigit(alvo[i]) and alvo[i] != '-' ) or alvo == "-" )
		{
			return false;
		}
	}
	return true;
}

value_type resolver_expressao ( std::string& expressao )
{
	std::vector < std::string > exp_separada;
	separar(expressao, exp_separada, ' ');

	jv::stack< value_type > resultados( expressao.size() );

	for (unsigned int i = 0; i < exp_separada.size(); ++i)
	{
		std::string atual = exp_separada[i];
		if ( eh_numero( atual ) == true )
		{
			resultados.push( str_to_int( atual ) );
		}
		else if ( eh_operador( atual[0] ) )
		{
			auto op2 = resultados.top();
			resultados.pop();
			
			auto op1 = resultados.top();
			resultados.pop();

			value_type result = operar( op1, op2, atual[0] );
		
			resultados.push(result);
		}
	}
	if (resultados.empty())
	{
		std::cerr << "Não foi realizada operação nenhuma com a expressão indicada." << std::endl;
		return 0;
	}
	return resultados.top();
}