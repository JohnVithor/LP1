/**
 * @file gerenciador.hpp
 * @brief      Declaração da classe Gerenciador, seus métodos que requisitam ao
 *             úsuario a entrada dos dados para calcular a área e o
 *             perímetro/volume da figura geométrica
  *
 * @author     João Vítor Venceslau Coelho
 * @since      19/11/2017
 * @date       21/11/2017
 */

#ifndef GERENCIADOR_H
#define GERENCIADOR_H

#include <iostream>
#include <sstream>
#include "figuras_geometricas.hpp"

/**
 * @brief      Classe para um Gerenciador, gerenciando quais dados devem ser
 *             informadas para o cálculo da área e perimetro/volume da figura
 *             determinada pelo método
 */
class Gerenciador
{
public:

	/**
	 * @brief      Construtor padrão
	 */
	Gerenciador() {/* Vazio */}

	/**
	 * @brief      Destrutor padrão
	 */
	~Gerenciador() {/* Vazio */}


	/**
	 * @brief      Função que lê uma entrada do std::cin e verifica se ela é um
	 *             número maior que 0
	 *
	 * @return     Double válido para alguma medida das figuras geométricas
	 */
	double pedir_entrada_valida();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre o triângulo equilátero
	 *
	 * @return     Sem retorno
	 */
	void calcular_triangulo_equi();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre o retângulo
	 *             
	 * @return     Sem retorno
	 */
	void calcular_retangulo();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre o quadrado
	 *             
	 * @return     Sem retorno
	 */
	void calcular_quadrado();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre o círculo
	 *             
	 * @return     Sem retorno
	 */
	void calcular_circulo();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre a piramide quadrangular
	 *             
	 * @return     Sem retorno
	 */
	void calcular_piramide_quadrangular();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre o cubo
	 *             
	 * @return     Sem retorno
	 */
	void calcular_cubo();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre o paralelepipedo
	 *             
	 * @return     Sem retorno
	 */
	void calcular_paralelepipedo();

	/**
	 * @brief      Função que mostra quais informações o usuário deve digitar
	 *             sobre a esfera
	 *             
	 * @return     Sem retorno
	 */
	void calcular_esfera();
};

#endif