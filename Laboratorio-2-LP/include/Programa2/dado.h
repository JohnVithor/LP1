/**
* @file		dado.h
* @brief	Definição da classe Dado, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		02/08/2017	
*/

#ifndef DADO_H
#define DADO_H

#include <random>
#include <iostream>
/**
* @brief Classe Dado
*/
class Dado {
	private:
		int valor;
		std::random_device rd;
		std::default_random_engine gen;
		std::uniform_int_distribution<> dis;

	public:
		/**
		* @brief Construtor da classe Dado. Inicia o valor do dado
		*/
		Dado();

		/**
		* @brief Destrutor da classe Dado.
		*/
		~Dado();
		
		/**
		* @brief Função que sorteia um novo valor para o dado
		* @return Valor do dado
		*/
		int jogar();
		
		/**
		* @brief Função que retorna o valor atual do dado
		* @return Valor do dado
		*/
		int getvalor();
		
		/**
		* @brief Sobrecarga do operador +
		* @param[in] dado a ser somado
		* @return soma obtida
		*/
		Dado& operator+ (Dado &dado);

		/**
		* @brief Sobrecarga do operador <<
		*/
		friend std::ostream& operator<< (std::ostream &o, Dado &dado);
};

#endif