/**
* @file		main1.cpp
* @brief	
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		09/09/2017
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <limits>

#include "Programa1/empresa.h"
#include "Programa1/funcionario.h"
#include "Programa1/catalago_empresas.h"
#include "ler_entradas.h"


int Funcionario::numero_funcionarios = 0;
int Empresa::numero_empresas = 0;

/**
* @brief	Funcao principal
* @details	Mostra as opções de operações que o prgrama realiza
* @param	argc Numero de argumentos fornecidos via linha de comando
* @param	argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char const *argv[])
{
	Catalago_empresas lista_empresas;

	int escolhido = -1;
	while(escolhido != 0){
				std::cout << std::endl << "--- | Saudações, qual é a sua escolha? | ---" << std::endl
				<< ">>> (1) Criar Empresa" << std::endl
				<< ">>> (2) Atualizar as Informações de uma Empresa" << std::endl
				<< ">>> (3) Adicionar Funcionario a uma empresa" << std::endl
				<< ">>> (4) Atualizar as Informações de um Funcionario" << std::endl
				<< ">>> (5) Listar os Dados dos Funcionarios" << std::endl
				<< ">>> (6) Alterar os salários dos funcionarios de uma empresa" << std::endl
				<< ">>> (7) Listar os Dados dos Funcionarios em Experiencia" << std::endl
				<< ">>> (8) Media de Funcionarios por Empresa" << std::endl
				<< ">>> (9) Apagar Empresa" << std::endl
				<< ">>> (10) Demitir Funcionario" << std::endl
				<< ">>> (0) Sair" << std::endl
				<< std::endl <<"Digite a sua opcao: ";
		int escolhido = get_int();
		switch(escolhido){
			case 1:
				lista_empresas.criar_empresa();
				break;
			case 2:
				lista_empresas.atualiza_empresa();
				break;
			case 3:
				lista_empresas.add_funcionario();
				break;
			case 4:
				lista_empresas.atualiza_funcionario();
				break;
			case 5:
				lista_empresas.list_funcionarios();
				break;
			case 6:
				lista_empresas.set_salarios();
				break;
			case 7:
				lista_empresas.listar_func_exp();
				break;
			case 8:
				lista_empresas.media_func_empr();
				break;
			case 9:
				lista_empresas.apagar_empresa();
				break;
			case 10:
				lista_empresas.demitir_funcionario();
				break;	
			case 0:
				std::cout << std::endl << "Volte Sempre" << std::endl;
				return 0;
			default:
				std::cin.clear();
				std::cin.ignore(200,'\n');
				std::cout << std::endl << "Entrada inválida, por favor digite uma entrada válida." << std::endl;
		}
	}
	return 0;
}