/**
* @file		funcionario.h
* @brief	Definição da classe Funcionario, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		09/09/2017
*/

#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
#include <iostream>
#include <iterator>
#include "datas.h"

/**
* @brief Classe Funcionario
*/
class Funcionario
{
	private:
		std::string nome;
		float salario;
		Datas data_admissao;
		
		Datas data_nascimento;
		std::string endereco;
		std::string cargo;
		std::string dept;
		

	public:
		/**
		* @brief contador do numero de funcionarios criados
		*/
		static int numero_funcionarios;

		/**
		* @brief Construtor da classe Funcionario. Inicia o nome, a salario e a data_admissao
		*/
		Funcionario();

		/**
		* @brief Construtor da classe Funcionario. Inicia o nome, a salario e a data_admissao
		* @param[in] nome nome do funcionario
		* @param[in] salario salario do funcionario
		* @param[in] data_admissao data de admissao do funcionario
		*/
		Funcionario(std::string nome, float salario, Datas data_admissao);
		
		/**
		* @brief Destrutor da classe Sapo
		*/
		~Funcionario();

		/**
		* @brief Função que retorna o nome do funcionario
		* @return nome do funcionario
		*/
		std::string get_nome();

		/**
		* @brief Função que altera o endereço
		* @param[in] endereco_ novo endereço 
		* @return endereço do funcionario
		*/
		std::string set_endereco( std::string endereco_);

		/**
		* @brief Função que altera o cargo
		* @param[in] cargo_ novo cargo
		* @return cargo do funcionario
		*/
		std::string set_cargo( std::string cargo_);

		/**
		* @brief Função que altera o departamento
		* @param[in] dept_ novo departamento
		* @return departamento do funcionario
		*/
		std::string set_dept( std::string dept_);

		/**
		* @brief Função que altera a data de nascimento do Funcionario
		* @param[in] nascimento_ nova data de nascimento
		* @return data de nascimento do funcionario
		*/
		Datas set_nascimento( Datas nascimento_);
		/**
		* @brief Função que altera o salario do funcionario
		* @param[in] per_cento por centagem a ser alterada no salario do funcionario
		* @return salario do funcionario
		*/
		float change_salario(float per_cento);

		/**
		* @brief Função que retorna a data de admissão do funcionario
		* @return data de admissão do funcionario
		*/
		Datas& get_data_admissao();

		/**
		* @brief Sobrecarga do operador <<
		*/
		friend std::ostream& operator<< (std::ostream &o, Funcionario &funcionario);

		/**
		* @brief Sobrecarga do operador ==
		*/
		bool operator==(const Funcionario &func) const;

		bool operator==(const std::string &nome) const;
};
#endif