/**
* @file		agencia_bancaria.h
* @brief	Definição da classe Agencia_Bancaria, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		23/10/2017
*/

#ifndef AGENCIA_BANCARIA_H
#define AGENCIA_BANCARIA_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <memory>

#include "conta.h"
#include "corrente.h"
#include "poupanca.h"
#include "../ler_entradas.h"
#include "movimentacao.h"

/**
* @brief Classe Agencia_Bancaria
*/
class Agencia_Bancaria
{
	private:
		std::vector< std::shared_ptr< Conta > > contas_registradas;

	public:
		/**
		* @brief Construtor da classe Agencia_Bancaria.
		*/
		Agencia_Bancaria ();

		/**
		* @brief Destrutor da classe Agencia_Bancaria
		*/
		~Agencia_Bancaria ();

		/**
		* @brief Cria uma nova conta
		* @return true se foi possivel criar a conta, false caso contrario
		*/
		bool criar_conta ();

		/**
		* @brief Altera o status de uma conta
		* @return true se foi possivel alterar o status da conta, false caso contrario
		*/
		bool alterar_status ();

		/**
		* @brief Remove uma conta
		* @return true se foi possivel remover a conta, false caso contrario
		*/
		bool remover_conta ();

		/**
		* @brief Realiza um saque numa conta
		* @return true se foi possivel realizar o saque na conta, false caso contrario
		*/
		bool saque ();

		/**
		* @brief Realiza um deposito numa conta
		* @return true se foi possivel realizar o deposito na conta, false caso contrario
		*/
		bool deposito ();

		/**
		* @brief Realiza uma transferencia de uma conta para outra
		* @return true se foi possivel realizar a transferencia, false caso contrario
		*/
		bool transferencia ();

		/**
		* @brief Emite o saldo de uma conta
		* @return true se foi possivel emitir o saldo da conta, false caso contrario
		*/
		bool emitir_saldo ();

		/**
		* @brief Emite o extrato de uma conta
		* @return true se foi possivel emitir o extrato da conta, false caso contrario
		*/
		bool emitir_extrato ();
};

#endif