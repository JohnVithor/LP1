/**
* @file		jogador.h
* @brief	Definição da classe Jogador, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		09/09/2017
*/

#ifndef JOGADOR_H
#define JOGADOR_H

#include "dado.h"
/**
* @brief Classe Jogador
*/
class Jogador {
	private:
		int identificador;
		int pontos;
		bool ativo;
		bool sortudo;

	public:
		static int numero_jogadores;
		static int numero_jogadores_ativos;
		static int numero_jogadores_excluidos;

		static int max_pontos_partida;

		/**
		* @brief Construtor da classe Jogador. Inicia o identificador, se está ativo ,os pontos e a vitorias.
		*/
		Jogador();
	
		/**
		* @brief Destrutor da classe Jogador.
		*/
		~Jogador();
	
		/**
		* @brief Função que retorna o valor do identificador
		* @return Valor do identificador
		*/
		int get_id();

		/**
		* @brief Função que retorna o estado de ativo
		* @return Valor de ativo
		*/
		bool is_ativo();

		/**
		* @brief Função que altera o estado de ativo para true
		* @return Valor de ativo
		*/
		bool set_ativo();

		/**
		* @brief Função que altera o estado de ativo para false
		* @return Valor de ativo
		*/
		bool not_ativo();

		/**
		* @brief Função que altera o estado de sortudo para true
		* @return Valor de sortudo
		*/
		bool is_sortudo();

		/**
		* @brief Função que retorna os pontos do jogador
		* @return Quantidade de pontos
		*/
		int get_pontos();

		/**
		* @brief 
		* @return Valor atual dos pontos.
		*/
		int jogar_dados();
};
#endif