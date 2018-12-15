/**
* @file		volume.h
* @brief	Definição das funções para o calculo do volume das figuras geométricas suportadas
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		13/08/2017
* @sa		
*/

#ifndef VOLUME_H
#define VOLUME_H

/**
* @brief Função que calcula o volume de uma pirâmide
* @param[in] base_largura Valor da área da base da pirâmide
* @param[in] altura Valor da altura da pirâmide
* @return volume da pirâmide
*/
double piramide_quadrangular_volume(double base_largura, double altura);

/**
* @brief Função que calcula o volume de um cubo
* @param[in] aresta Valor da aresta do cubo
* @return volume do círculo
*/
double cubo_volume(double aresta);

/**
* @brief Função que calcula o volume de um paralelepipedo
* @param[in] aresta_1 Valor da primeira aresta do paralelepipedo
* @param[in] aresta_2 Valor da segunda aresta do paralelepipedo
* @param[in] aresta_3 Valor da terceira aresta do paralelepipedo
* @return volume do círculo
*/
double paralelepipedo_volume(double aresta_1, double aresta_2, double aresta_3);

/**
* @brief Função que calcula o volume de uma esfera
* @param[in] raio Valor do raio da esfera
* @return volume do esfera
*/
double esfera_volume(double raio);

#endif