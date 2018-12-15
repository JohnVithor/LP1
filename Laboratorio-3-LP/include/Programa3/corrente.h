/**
* @file		corrente.h
* @brief	Definição da classe corrente, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		24/10/2017
*/

#ifndef CORRENTE_H
#define CORRENTE_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "conta.h"

/**
* @brief Classe Corrente
*/
class Corrente : public Conta
{
	private:

		Status m_status;

		double m_limite;

		/**
		* @brief Imprime as informações da conta corrente no ostream indicado
		* @param o o stream de saída que receberá os dados das movimentações já realizadas na conta
		* @return Stream de saída com os dados já formatados
		*/
		std::ostream& print (std::ostream &o) const;

	public:

		/**
		* @brief Construtor da classe Corrente.
		*/
		Corrente ();
		
		/**
		* @brief Construtor paramatrizado
		* @param[in] agencia Numero da agencia
		* @param[in] numero Numero da conta corrente
		* @param[in] saldo Valor contido na conta corrente
		* @param[in] status Status da conta corrente ( Especial ou não )
		*/
		Corrente ( unsigned int agencia, unsigned int numero, double saldo, Status status );

		/**
		* @brief Destrutor da classe Corrente
		*/
		~Corrente () = default;

		/**
		* @brief Altera o saldo da conta
		* @param[in] movimentacao Movimentação com as informações sobre a alteração realizada no saldo
		* @return true se foi possivel realizar a alteração, false caso contrario
		*/
		bool set_saldo ( std::shared_ptr< Movimentacao> movimentacao );

		/**
		* @brief Informa o status da conta corrente
		* @return O status da conta corrente
		*/
		Status get_status ();

		/**
		* @brief Informa o limite da conta corrente
		* @return O limite da conta corrente
		*/
		unsigned int get_limite ();

		/**
		* @brief Altera o status da conta corrente
		* @param[in] status Novo status da conta corrente
		* @return true se o status foi alterado, false se esse já era o status anterior
		*/
		bool set_status ( Status status );
};

#endif