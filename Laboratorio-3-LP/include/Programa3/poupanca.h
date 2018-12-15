/**
* @file		poupanca.h
* @brief	Definição da classe poupanca, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		20/10/2017
*/

#ifndef POUPANCA_H
#define POUPANCA_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "conta.h"

/**
* @brief Classe Poupanca
*/
class Poupanca : public Conta
{
	private:

		/**
		* @brief Imprime as informações da conta poupanca no ostream indicado
		* @param o o stream de saída que receberá os dados das movimentações já realizadas na conta
		* @return Stream de saída com os dados já formatados
		*/
		std::ostream& print (std::ostream &o) const;

	public:

		/**
		* @brief Construtor da classe Poupanca.
		*/
		Poupanca ();

		/**
		* @brief Construtor paramatrizado
		* @param[in] agencia_ Numero da agencia
		* @param[in] numero_ Numero da conta
		* @param[in] saldo_ Valor contido na conta
		*/
		Poupanca ( unsigned int agencia, unsigned int numero, double saldo );

		/**
		* @brief Destrutor da classe Poupanca
		*/
		~Poupanca () = default;

		/**
		* @brief Altera o saldo da conta
		* @param[in] movimentacao Movimentação com as informações sobre a alteração realizada no saldo
		* @return true se foi possivel realizar a alteração, false caso contrario
		*/
		bool set_saldo ( std::shared_ptr< Movimentacao> movimentacao );
};

#endif