/**
* @file		ler_entradas.h
* @brief	Definição de funções de leitura simples
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/08/2017
* @date		20/010/2017
*/

#ifndef LER_ENTRADAS_H
#define LER_ENTRADAS_H

/**
* @brief Função tenta ler um unico char a partir da entrada padrão
* @return Valor do lido
*/
char get_one_char();

/**
* @brief Função tenta ler um unico inteiro a partir da entrada padrão
* @return Valor do lido
*/
int get_int();

/**
* @brief Função tenta ler um unico inteiro não sinalizado a partir da entrada padrão
* @return Valor do lido
*/
int get_uint();

/**
* @brief Função tenta ler um unico double a partir da entrada padrão
* @return Valor do lido
*/
int get_double();

#endif