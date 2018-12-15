/**
* @file		calcula.h
* @brief	Definição das funções que requisitam ao úsuario a entrada dos dados
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		14/08/2017
* @sa		
*/

#ifndef CALCULAR_H
#define CALCULAR_H

/**
* @brief Função que lê uma entrada e verifica se ela é um número maior que 1
* @return Uma entrada válida
*/
double pedir_entrada_valida();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre o triângulo equilátero
*/
void calcular_triangulo_equi();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre o retângulo
*/
void calcular_retangulo();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre o quadrado
*/
void calcular_quadrado();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre o círculo
*/
void calcular_circulo();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre a piramide quadrangular
*/
void calcular_piramide_quadrangular();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre o cubo
*/
void calcular_cubo();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre o paralelepipedo
*/
void calcular_paralelepipedo();

/**
* @brief Função que mostra quais informações o usuário deve digitar sobre a esfera
*/
void calcular_esfera();

#endif