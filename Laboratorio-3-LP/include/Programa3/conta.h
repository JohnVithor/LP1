/**
* @file		conta.h
* @brief	Definição da classe conta, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		23/10/2017
*/

#ifndef CONTA_H
#define CONTA_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>

#include "movimentacao.h"

/**
* @brief Enum que indica o status da conta se ela possuir
*/
enum Status
{
	nao_especial = 0,
	especial = 1,
	nao_possui = 2
};

/**
* @brief Enum que indica o tipo da conta
*/
enum Identificador
{
	corrente = 0,
	poupanca = 1
};

/**
* @brief Classe Conta
*/
class Conta
{
	protected:

		Identificador m_tipo_conta;

		unsigned int m_agencia;

		unsigned int m_numero;

		double m_saldo;

		std::vector< std::shared_ptr< Movimentacao > > m_conjunto_movimentacoes;

		/**
		* @brief Imprime as informações da conta no ostream indicado
		* @param o o stream de saída que receberá os dados das movimentações já realizadas na conta
		* @return Stream de saída com os dados já formatados
		*/
		virtual std::ostream& print ( std::ostream &o ) const = 0;

	public:

		/**
		* @brief Construtor vazio da classe Conta.
		*/
		Conta ();
		
		/**
		* @brief Construtor paramatrizado
		* @param[in] tipo Tipo da conta
		* @param[in] agencia Numero da agencia
		* @param[in] numero Numero da conta
		* @param[in] saldo Valor contido na conta
		*/
		Conta ( Identificador tipo, unsigned int agencia, unsigned int numero, double saldo );

		/**
		* @brief Destrutor da classe Conta
		*/
		virtual ~Conta () = default;

		/**
		* @brief Informa o tipo da conta
		* @return O tipo da conta
		*/
		Identificador get_tipo ();

		/**
		* @brief Informa o numero da agencia da conta
		* @return O numero da agencia da conta
		*/
		unsigned int get_agencia ();

		/**
		* @brief Informa o numero da conta
		* @return O numero da conta
		*/
		unsigned int get_numero ();

		/**
		* @brief Informa o saldo da conta
		* @return O saldo da conta
		*/
		unsigned int get_saldo ();

		/**
		* @brief Informa o status da conta, se ela possuir esse campo.
		* @return O status da conta corrente, se ela possuir esse campo.
		*/
		virtual Status get_status ();

		/**
		* @brief Informa o limite da conta, se ela possuir esse campo. 
		* @return O limite da conta, se ela possuir esse campo.
		*/
		virtual unsigned int get_limite ();

		/**
		* @brief Altera o status da conta, se ela possuir esse campo.
		* @param[in] status Novo status da conta, se ela possuir esse campo.
		* @return true se o status foi alterado, false se esse já era o status anterior
		*/
		virtual bool set_status ( Status status );


		/**
		* @brief Altera o saldo da conta
		* @param[in] movimentacao Movimentação com as informações sobre a alteração realizada no saldo
		* @return true se foi possivel realizar a alteração, false caso contrario
		*/
		virtual bool set_saldo ( std::shared_ptr< Movimentacao> movimentacao ) = 0;

		/**
		* @brief Sobrecarga do operador << para a conta
		* @param o o stream de saída que receberá os dados das movimentações já realizadas na conta
		* @param conta Conta cujas movimentações serão impressas
		* @return Stream de saída com os dados já formatados
		*/
		friend std::ostream& operator<< ( std::ostream &o, Conta &conta );

		/**
		* @brief Informa se duas contas possuem a mesma identificação, numero da agencia e da conta
		* @param p conta_ a ser comparada
		* @return true se as contas possuirem a mesma identificação
		*/
		bool operator== ( Conta &outra);
};

#endif