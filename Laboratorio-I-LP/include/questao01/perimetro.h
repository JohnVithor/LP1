/**
* @file		perimetro.h
* @brief	Definição das funções para o calculo do perímetro das figuras geométricas suportadas
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/

#ifndef PERIMETRO_H
#define PERIMETRO_H

/**
* @brief Função que calcula o perímetro de um triângulo equilátero
* @param[in] base Valor da base do triângulo equilátero
* @param[in] altura Valor da altura do triângulo equilátero
* @return perímetro do triângulo equilátero
*/
double triangulo_equi_perimetro(double lado);

/**
* @brief Função que calcula o perímetro de um retângulo
* @param[in] base Valor da base do retângulo
* @param[in] altura Valor da altura do retângulo
* @return perímetro do retângulo
*/
double retangulo_perimetro(double base, double altura);

/**
* @brief Função que calcula o perímetro de um quadrado
* @param[in] lado Valor do lado do quadrado
* @return perímetro do quadrado
*/
double quadrado_perimetro(double lado);

/**
* @brief Função que calcula o perímetro de um círculo
* @param[in] raio Valor do raio do círculo
* @return perímetro do círculo
*/
double circulo_perimetro(double raio);

#endif