/**
* @file		sapo.h
* @brief	Definição da classe Sapo, seus atributos e metodos.
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	17/08/2017
* @date		22/08/2017
*/

#ifndef SAPO_H
#define SAPO_H

class Sapo {
	private:
		int identificador;
		int dist_percorrida;
		int pulos;

		// Apos essa parte ter sido colocada aqui eu obtive erros na hora de organizar o vetor de sapos.
		std::random_device rd;
		std::mt19937 gen;
		std::uniform_int_distribution<int> linear_i;

	public:
		/**
		* @brief Construtor da classe Sapo. Inicia o identificador, a dist_percorrida e a quantidade de pulos
		*/
		Sapo();
	
		/**
		* @brief Destrutor da classe Sapo
		*/
		~Sapo();
	
		static int dist_da_corrida;
		static int get_dist_corr();
	
		/**
		* @brief Função que atribui um valor para o identificador
		* @param[in] id Valor a ser atribuido
		* @return Valor do identificador
		*/
		int set_id(int id);
	
		/**
		* @brief Função retorna valor do identificador
		* @return Valor do identificador
		*/
		int get_id();
	
		/**
		* @brief Função que retorna a distancia percorrida pelo sapo
		* @return Valor da dist_percorrida
		*/
		int get_dist_per();
		/**
		* @brief Função retorna a quantidade de pulos dados pelo sapo
		* @return Valor de pulos
		*/
		int get_pulos();

		/**
		* @brief Função que atribui um valor para a distancia percorrida pelo sapo
		* @param[in] id Valor a ser atribuido
		* @return Valor da dist_percorrida
		*/
		int set_dist_per(int qnt);
		/**
		* @brief Função que atribui um valor a quantidade de pulos dados pelo sapo
		* @param[in] id Valor a ser atribuido
		* @return Valor de pulos
		*/
		int set_pulos(int qnt);

		/**
		* @brief Função incrementa a distancia percorrida pelo sapo em um valor aleatorio entre 1 e 19, e incrementa os pulos em 1
		* @return Valor da dist_percorrida
		*/
		int pular();
};

#endif
