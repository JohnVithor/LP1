/**
* @file		avaliador_expressao.hpp
* @brief	Declaração das funções necessarias para avaliar uma expressão na notação polonesa inversa
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	22/10/2017
* @date		28/10/2017
*/

#ifndef AVALIADOR_EXPRESSAO_H
#define AVALIADOR_EXPRESSAO_H

#include <string>
#include <vector>

using value_type = long int;

/**
* @brief Converte o número contido na string para uma variável numerica
* @param[in] alvo String que contem o número
* @return O número extraido da string
*/
value_type str_to_int( std::string& alvo );

/**
* @brief Separa uma string com base no delimitador informado e guarda as partes separadas no vector informado
* @param[in] alvo String que será separada
* @param[in] resultado Vector que irá guardar as partes da string
* @param[in] delimitador char que indicará quando a string deve ser separada
*/
void separar ( std::string& alvo, std::vector< std::string > &resultado, const char &delimitador );

/**
* @brief Opera os dois valores informados com base na operação que o char indica
* @param[in] valor_1 Primeiro operando
* @param[in] valor_2 Segundo operando
* @param[in] operador Char que indica qual operação será realizada
* @return Resultado da operação dos dois valores 
*/
value_type operar ( value_type &valor_1, value_type &valor_2, char operador );

/**
* @brief Verifica se o char informado é uma operação suportada
* @param[in] c Char a ser analisado
* @return true se é um char válido, false caso contrário
*/
bool eh_operador( char c );

/**
* @brief Verifica se o char informado é um numero válido
* @param[in] c Char a ser analisado
* @return true se é um char válido, false caso contrário
*/
bool eh_numero ( std::string& alvo );

/**
* @brief A partir de uma string contendo uma expressão na notação polonesa inversa resolve as operações indicadas
* @param[in] expressao String contendo a expressão a ser resolvida
* @return Valor obtido após a expressão indicada ter sido resolvida
*/
value_type resolver_expressao ( std::string& expressao );

#endif