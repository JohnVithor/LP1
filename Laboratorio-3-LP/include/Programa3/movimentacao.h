/**
* @file		movimentacao.h
* @brief	Definição da classe Movimentacao, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		23/10/2017	
*/

#ifndef MOVIMENTACAO_H
#define MOVIMENTACAO_H

#include <string>
#include <iostream>
#include <iterator>

#include "movimentacao.h"

/**
* @brief Enum que indica o tipo de movimentação
*/
enum Indic
{
	credito = 0,
	debito = 1
};

/**
* @brief Classe Movimentacao
*/
class Movimentacao
{
	private:
		
		std::string descricao;
		double valor;
		Indic tipo_movimentacao;

	public:

		/**
		* @brief Construtor da classe Movimentacao. Inicia a descricao, o valor e o tipo de movimentacao
		*/
		Movimentacao();

		/**
		* @brief Construtor paramatrizado
		* @param[in] descricao_ Descrição da movimentação
		* @param[in] valor_ Valor que foi movimentado
		* @param[in] tipo_movimentacao_ Tipo da movimentação
		*/
		Movimentacao( std::string descricao_, double valor_, Indic tipo_movimentacao_ );

		/**
		* @brief Destrutor da classe Movimentacao
		*/
		~Movimentacao();

		/**
		* @brief Informa a descrição da movimentação
		* @return A descrição da movimentação
		*/
		std::string get_descricao();

		/**
		* @brief Informa o valor da movimentação
		* @return O valor da movimentação
		*/
		double get_valor();

		/**
		* @brief Informa o tipo movimentação
		* @return O tipo da movimentação
		*/
		Indic get_tipo();

		/**
		* @brief Sobrecarga do operador << para a movimentação
		* @param o o stream de saída que receberá os dados da movimentação
		* @param movimentacao Movimentacao cujas informações serão impressas
		* @return Stream de saída com os dados já formatados
		*/
		friend std::ostream& operator<< (std::ostream &o, Movimentacao &movimentacao);

};
#endif