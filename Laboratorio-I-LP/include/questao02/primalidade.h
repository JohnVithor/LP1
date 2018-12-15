/**
* @file		primalidade.h
* @brief	Definição das função relacionadas à primalidade
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/

#ifndef PRIMALIDADE_H
#define PRIMALIDADE_H

/**
* @brief Função que calcula se um número é primo
* @param[in] n Número a ser testado
* @return 1 se for primo e 0 se não for
*/
//int eh_primo(const int n);

/**
* @brief Função que calcula se um número é primo
* @param[in] n Número a ser testado
* @return 1 se for primo e 0 se não for
*/
int eh_primo(long long int n, int i); // Versão recursiva

/**
* @brief Função que calcula o maior número primo anterior a um número
* @param[in] n Número do limite superior
* @return o maior número primo encontrado
*/
long long int maior_primo_anterior(long long int valor);

#endif
