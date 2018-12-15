/**
 * @file Pet_Fera_Exportar.hpp
 * @brief      Declaração e Implementação de funções auxilares para o Pet_Fera
 *             que permite filtrar e exportar os dados dos animais
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      06/12/2017
 * @date       09/12/2017
 */

#ifndef PETFERA_AUX_HPP
#define PETFERA_AUX_HPP

#include <string>
#include <fstream>
#include <vector>

/**
 * @brief      Verifica se a string termina com o substring indicada
 *
 * @param[in]  str      A string a ser testada
 * @param[in]  termino  A substring utilizada
 *
 * @return     true se de fato a string termina com a substring
 */
bool termina_com(const std::string &str, const std::string &termino)
{
	return str.size() >= termino.size() and str.compare(str.size() - termino.size(), termino.size(), termino) == 0;
}

/**
 * @brief      Função que serve para separar uma string.
 *
 * @param[in]  alvo         - Variável do tipo string, que corresponde a string
 *                          alvo da separação.
 * @param[in]  delimitador  - Variável do tipo char, que corresponde a um
 *                          delimitador para a separação.
 *
 * @return     Um vector de strings.
 */
std::vector< std::string > separar ( const std::string& alvo, const char &delimitador )
{
	size_t start = alvo.find_first_not_of(delimitador);
	size_t end = start;

	std::vector< std::string > campos;

	while ( start != std::string::npos )
	{
		end = alvo.find(delimitador, start);

		campos.push_back(alvo.substr(start, end-start));
		
		start = alvo.find_first_not_of(delimitador, end);
	}
	return campos;
}

/**
 * @brief      Função para filtrar as familias/classes dos animais
 *
 * @param      alvo    - Variável do tipo vector de strings, que corresponde ao
 *                     vector contendo as strings alvo da filtragem.
 * @param[in]  filtro  - Variável do tipo string, que corresponde ao nome da
 *                     classe a ser filtrada.
 *
 * @return     Um vector de strings.
 */
std::vector< std::string > filtrar_classe( std::vector< std::string > &alvo, const std::string filtro )
{
	std::string linha;
	std::vector< std::string > retorno;
	if ( filtro == "" )
	{
		for ( std::vector< std::string >::iterator i = alvo.begin(); i != alvo.end(); ++i)
		{
			retorno.push_back(*i);
		}
	}
	else
	{
		for ( std::vector< std::string >::iterator i = alvo.begin(); i != alvo.end(); ++i)
		{
			std::vector< std::string > campos = separar( *i, ';' );
			if ( campos[1] == filtro )
			{
				retorno.push_back(*i);
			}
		}		
	}
	return retorno;
}

/**
 * @brief      Função para filtrar os dados dos funcionarios.
 *
 * @param      alvo    - Variável do tipo vector de strings, que corresponde ao
 *                     vector contendo as strings alvo da filtragem.
 * @param[in]  filtro  - Variável do tipo string, que corresponde ao nome do
 *                     dado a ser filtrada.
 * @param[in]  campo   - Variável do tipo size_t, que corresponde a posição do
 *                     dado a ser filtrado.
 *
 * @return     Um vector de strings.
 */
std::vector< std::string > filtrar_func( std::vector< std::string > &alvo, const std::string filtro, size_t campo )
{
	std::string linha;
	std::vector< std::string > retorno;
	if ( filtro == "" )
	{
		for ( std::vector< std::string >::iterator i = alvo.begin(); i != alvo.end(); ++i)
		{
			retorno.push_back(*i);
		}
	}
	else
	{
		for ( std::vector< std::string >::iterator i = alvo.begin(); i != alvo.end(); ++i)
		{
			std::vector< std::string > campos = separar( *i, ';' );
			if ( campos[campo] == filtro )
			{
				retorno.push_back(*i);
			}
		}		
	}
	return retorno;
}

#endif