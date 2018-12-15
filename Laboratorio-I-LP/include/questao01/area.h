/**
* @file		area.h
* @brief	Definição das funções para o calculo da área das figuras geométricas suportadas
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/

#ifndef AREA_H
#define AREA_H

/**
* @brief Função que calcula a área de um triângulo equilátero
* @param[in] base Valor da base do triângulo equilátero
* @return área do triângulo equilátero
*/
double triangulo_equi_area(double base);

/**
* @brief Função que calcula a área de um retângulo
* @param[in] base Valor da base do retângulo
* @param[in] altura Valor da altura do retângulo
* @return área do retângulo
*/
double retangulo_area(double base, double altura);

/**
* @brief Função que calcula a área de um quadrado
* @param[in] lado Valor do lado do quadrado
* @return área do quadrado
*/
double quadrado_area(double lado);

/**
* @brief Função que calcula a área de um círculo
* @param[in] raio Valor do raio do círculo
* @return área do círculo
*/
double circulo_area(double raio);

/**
* @brief Função que calcula a área de uma pirâmide
* @param[in] base_largura Valor da largura da base da pirâmide
* @param[in] altura Valor da altura da pirâmide
* @return área da pirâmide
*/
double piramide_quadrangular_area(double base_largura, double altura);

/**
* @brief Função que calcula a área de um cubo
* @param[in] aresta Valor da aresta do cubo
* @return área do círculo
*/
double cubo_area(double aresta);

/**
* @brief Função que calcula a área de um paralelepipedo
* @param[in] aresta_1 Valor da primeira aresta do paralelepipedo
* @param[in] aresta_2 Valor da segunda aresta do paralelepipedo
* @param[in] aresta_3 Valor da terceira aresta do paralelepipedo
* @return área do círculo
*/
double paralelepipedo_area(double aresta_1, double aresta_2, double aresta_3);

/**
* @brief Função que calcula a área de uma esfera
* @param[in] raio Valor do raio da esfera
* @return área do esfera
*/
double esfera_area(double raio);

#endif