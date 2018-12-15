/**
* @file		catalago_empresas.h
* @brief	Definição da classe Catalago_empresas, seus atributos e metodos, alem de um pequeno enum
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	01/09/2017
* @date		09/09/2017	
*/

#ifndef CATALAGO_EMPRESAS_H
#define CATALAGO_EMPRESAS_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "funcionario.h"
#include "empresa.h"

/**
* @brief Enum dos possiveis status sobre uma empresa e sobre a situação de um funcionario
*/
enum status_empresa
{
	nao_criada = 0,
	criada = 1,
	func_criado = 2,	
};

/**
* @brief Classe Catalago_empresas
*/
class Catalago_empresas
{
	private:

		std::vector<Empresa*> lista_empresas;

	public:
		/**
		* @brief Construtor da classe Catalago_empresas. Inicia a lista_empresas
		*/
		Catalago_empresas();

		/**
		* @brief Destrutor da classe Catalago_empresas
		*/
		~Catalago_empresas();

		/**
		* @brief Função que cria uma empresa e a adiciona na lista_empresas
		* @return Empresa criada
		*/
		Empresa criar_empresa();

		/**
		* @brief Função que atualiza as informações de uma empresa da lista_empresas
		* @return True se a empresa foi atualizada, false se algum erro ocorreu
		*/
		bool atualiza_empresa();

		/**
		* @brief Função que adiciona um funcionario a uma empresa da lista_empresas
		*/
		void add_funcionario();
		
		/**
		* @brief Função que atualiza as informações de um funcionario de uma empresa da lista_empresas
		* @return True se o funcionario foi atualizado, false se algum erro ocorreu
		*/
		bool atualiza_funcionario();

		/**
		* @brief Função que lista os funcionarios de uma empresa
		* @return True se a empresa foi encontrada e False se não foi
		*/
		bool list_funcionarios();

		/**
		* @brief Função que altera todos os salarios dos funcionarios de uma empresa
		* @return True se a empresa foi encontrada e False se não foi
		*/
		bool set_salarios();

		/**
		* @brief Função que lista os funcionarios de uma empresa que estao 
		* a menos de 90 dias na empresa de acordo com uma data
		*
		* @return True se a empresa foi encontrada e False se não foi
		*/
		int listar_func_exp();

		/**
		* @brief Função mostra a media de funcionarios por empresa
		* @return Media obtida
		*/
		float media_func_empr();

		/**
		* @brief Função que apaga uma empresa e a remove da lista_empresas
		* @return True se a empresa foi encontrada e False se não foi
		*/
		bool apagar_empresa();

		/**
		* @brief Função que remove um funcionario de uma empresa
		* @return True se a empresa foi encontrada e False se não foi
		*/
		bool demitir_funcionario();
};

#endif