/**
* @file		palindromo.hpp
* @brief	Declaração das funções necessarias para avaliar se uma string é ou não um palindromo
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	28/10/2017
* @date		28/10/2017	
*/

#ifndef PALINDROMO_H
#define PALINDROMO_H

#include <iostream>
#include <string>

/**
* @brief Substitui os caracteres acentuados por seus correspondentes sem acento
* @param[in] alvo String que terá os acentos removidos
* @return String de entrada já sem acentuação
*/
std::string& remover_acentos ( std::string& alvo );

/**
* @brief Remove os espaços em branco e a pontuação de uma string
* @param[in] alvo String que terá os caracteres de pontuação e de espaços removidos
* @return String de entrada já sem pontuação e espaços
*/
std::string& remover_invalidos ( std::string& alvo );

/**
* @brief Verifica se uma string é um palindromo
* @param[in] alvo String que será verificada
* @return true se a string for um palindromo e false caso contrário
*/
bool verifica_palindromo ( std::string alvo );

#endif