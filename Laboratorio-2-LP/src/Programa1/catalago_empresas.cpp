/**
* @file		catalago_empresas.cpp
* @brief	
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	01/09/2017
* @date		09/09/2017	
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "funcionario.h"
#include "empresa.h"
#include "catalago_empresas.h"
#include "../ler_entradas.h"

Catalago_empresas::Catalago_empresas(){
	lista_empresas = {};
}

Catalago_empresas::~Catalago_empresas(){

}

Empresa Catalago_empresas::criar_empresa(){

	std::string nome;
	float cnpj;
	Datas cadastro;
	std::vector<Funcionario*> lista_func;

	std::cout << std::endl << ">>> Por favor informe o nome da empresa a ser criada: ";
	std::getline(std::cin, nome);

	std::cout << std::endl << ">>> Por favor informe o cnpj da empresa a ser criada: ";
	cnpj = get_int();

	std::cout << std::endl << ">>> Por favor informe a data de cadastro da empresa a ser criada:" << std::endl;
	cadastro.set_data();
	
	Empresa *nova_empresa = new Empresa(nome,cnpj,cadastro);
	status_empresa status = nao_criada;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( **it == *nova_empresa){
			std::cout << std::endl << ">>> Empresa já existe. Cancelando operação..." << std::endl;
			status = criada;
		}
	}
	if (status == nao_criada)
	{
		lista_empresas.push_back(nova_empresa);
		std::cout << std::endl << ">>> Empresa Criada com sucesso." << std::endl;
	}
	return *nova_empresa;
}

bool Catalago_empresas::atualiza_empresa(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return false;
	}
	std::cout << std::endl << ">>> Qual empresa gostaria atualizar? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << "> Nome: " << (**it).get_nome() << std::endl
				  << "> Endereço: " << (**it).get_endereco() << std::endl
				  << "> Atv. Comercial: " << (**it).get_atv_comercial() << std::endl
				  << "> Nome do Dono: " << (**it).get_nome_dono() << std::endl
				  << "> CNPJ: " << (**it).get_cnpj() << std::endl
				  << "> Data de cadastro: " << (**it).get_data_cadastro() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);
	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			std::cout << "Empresa encontrada." << std::endl;

			(**it).atualiza_dados();
			std::cout << "Empresa atualizada." << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

void Catalago_empresas::add_funcionario(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return;
	}
	std::cout << std::endl << ">>> Em qual empresa gostaria de adicionar um funcionario? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);

	status_empresa status = nao_criada;
	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			status = criada;
			if ((**it).adicionar_funcionario())
			{
				status = func_criado;
			} 
		}
	}

	if (status == nao_criada)
	{
		std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	} else if (status == func_criado)
	{
		std::cout << std::endl << ">>> Funcionario adicionado com sucesso." << std::endl;
	} else {
		std::cout << std::endl << ">>> Funcionario já existe." << std::endl;
	}
	return;
}

bool Catalago_empresas::atualiza_funcionario(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return false;
	}
	std::cout << std::endl << ">>> Em qual empresa gostaria de adicionar um funcionario? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{	
		if ( (**it).get_nome() == nome){
			std::cout << "Empresa encontrada." << std::endl;
			if ((**it).get_numero_funcionarios() == 0)
			{
				std::cout << "Esta empresa não possui nenhum funcionario cadastrado. Cancelando operação..." << std::endl;
				return false;
			}
			(**it).atualizar_funcionario();
			std::cout << "Funcionario atualizado." << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}
bool Catalago_empresas::list_funcionarios(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return false;
	}
	std::cout << std::endl << ">>> Em qual empresa gostaria de listar os funcionario? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			std::cout << std::endl << ">>> Os funcionarios da empresa " << nome << " sao: "<< std::endl;
			std::cout << (**it);
			return true;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

bool Catalago_empresas::set_salarios(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return false;
	}
	std::cout << std::endl << ">>> Em qual empresa gostaria de alterar os salarios? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			std::cout << std::endl << ">>> Digite em quantos por cento o salario será alterado: ";
			float per_cento;
			per_cento = get_int();
			(**it).alterar_salario(per_cento);
			return true;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

int Catalago_empresas::listar_func_exp(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return 0;
	}
	std::cout << std::endl << ">>> Em qual empresa gostaria de listar os funcionario? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);

	int funcionarios_listados = 0;
	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			funcionarios_listados += (**it).listar_func_exp();
			return funcionarios_listados;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return 0;
}

float Catalago_empresas::media_func_empr(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return 0;
	} else {
		float media = Funcionario::numero_funcionarios / Empresa::numero_empresas;
		std::cout << ">>> A media de funcionarios por empresa é de: " << media << std::endl;
		return media;
	}

}

bool Catalago_empresas::apagar_empresa(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return false;
	}
	std::cout << std::endl << ">>> Qual empresa gostaria apagar? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome;
	std::getline(std::cin, nome);

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			lista_empresas.erase(it);
			delete &(**it);
			--Empresa::numero_empresas;
			std::cout << std::endl << ">>> Empresa apagada..." << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

bool Catalago_empresas::demitir_funcionario(){
	if (Empresa::numero_empresas == 0)
	{
		std::cout << ">>> Não temos nenhuma empresa cadastrada..." << std::endl;
		return false;
	}
	std::cout << std::endl << ">>> A qual empresa pertence o funcionario que gostaria de apagar? " << std::endl
			  << ">>> Empresas possiveis:" << std::endl << std::endl;

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		std::cout << (**it).get_nome() << std::endl;
	}
	std::cout << std::endl << ">>> Digite o nome da empresa: ";
	std::string nome_emp;
	std::getline(std::cin, nome_emp);

	for (std::vector<Empresa*>::iterator it = lista_empresas.begin(); it != lista_empresas.end(); ++it)
	{
		if ( (**it).get_nome() == nome_emp){
			std::cout << std::endl << ">>> Os funcionarios da empresa " << nome_emp << " sao: "<< std::endl;
			std::cout << **it;

			std::cout << std::endl << ">>> Digite o nome do funcionario a ser demitido: ";
			std::string nome_func;
			std::getline(std::cin, nome_func);

			(**it).demitir_funcionario(nome_func);
			std::cout << std::endl << ">>> O funcionario " << nome_func << " foi demitido sem maiores complicações." << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Empresa não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

