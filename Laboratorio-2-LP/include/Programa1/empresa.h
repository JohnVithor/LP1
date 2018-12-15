/**
* @file		empresa.h
* @brief	Definição da classe Empresa, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		09/09/2017
*/

#ifndef EMPRESA_H
#define EMPRESA_H

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include "datas.h"

#include "funcionario.h"

/**
* @brief Classe Empresa
*/
class Empresa
{
	private:
		std::string nome;
		std::string endereco;
		std::string atv_comercial;
		std::string nome_dono;

		int cnpj;
		std::vector<Funcionario*> lista_funcionarios;
		Datas data_cadastro;

	public:
		/**
		* @brief contador do numero de empresas criadas
		*/
		static int numero_empresas;

		/**
		* @brief Construtor da classe Empresa. Inicia o nome, o cnpj e a lista_funcionarios
		*/
		Empresa();
		
		/**
		* @brief Construtor da classe Empresa. Inicia o nome, o cnpj e a lista_funcionarios
		* @param[in] nome_ nome da empresa
		* @param[in] cnpj_ CNPJ da empresa
		* @param[in] list_ lista_funcionarios a ser atribuida (default: vector vazio)
		*/
		Empresa(std::string nome_, int cnpj_, Datas data_cadastro,
				const std::vector<Funcionario*> &list_ = std::vector<Funcionario*>());

		/**
		* @brief Destrutor da classe Sapo
		*/
		~Empresa();

		/**
		* @brief Função que retorna o nome da empresa
		* @return nome do empresa
		*/
		std::string get_nome();
		
		/**
		* @brief Função que retorna o endereco da empresa
		* @return endereco do empresa
		*/
		std::string get_endereco();

		/**
		* @brief Função que retorna a atividade comercial da empresa
		* @return atividade comercial da empresa
		*/
		std::string get_atv_comercial();

		/**
		* @brief Função que retorna o nome do dono da empresa
		* @return nome do dono da empresa
		*/
		std::string get_nome_dono();

		/**
		* @brief Função que retorna o cnpj da empresa
		* @return cnpj da empresa
		*/
		int get_cnpj();

		/**
		* @brief Função que retorna a data de cadastro da empresa
		* @return data de cadastro da empresa
		*/
		Datas& get_data_cadastro();

		/**
		* @brief Função que atualiza os dados da empresa
		*/
		void atualiza_dados();

		/**
		* @brief Função que adiciona um funcionario a empresa
		* @return true se o funcionario foi adicionado e false se ele ja existe
		*/
		bool adicionar_funcionario();
		
		/**
		* @brief Função que atualiza um funcionario da empresa
		* @return true se o funcionario foi alterado com sucesso e false se algo deu errado
		*/
		bool atualizar_funcionario();
		
		/**
		* @brief Função que retorna o numero de funcionarios da empresa
		* @return numero de funcionarios da empresa
		*/
		int get_numero_funcionarios();
		/**
		* @brief Função que altera o salario de todos os funcionarios da empresa
		* @param[in] per_cento porcentagem a ser alterada
		*/
		void alterar_salario(float per_cento);

		/**
		* @brief Função que lista os funcionarios da empresa que estao 
		* a menos de 90 dias na empresa de acordo com uma data
		*
		* @return a quantidade de usuarios em experiencia
		*/
		int listar_func_exp();
		
		/**
		* @brief Função que remove um funcionario da empresa
		* @return true se o funcionario foi removido e false se ele não foi encontrado
		*/
		bool demitir_funcionario(std::string nome);

		/**
		* @brief Sobrecarga do operador <<
		*/
		friend std::ostream& operator<< (std::ostream &o, Empresa &empresa);

		/**
		* @brief Sobrecarga do operador ==
		*/
		bool operator==(const Empresa &empr) const;
};

#endif