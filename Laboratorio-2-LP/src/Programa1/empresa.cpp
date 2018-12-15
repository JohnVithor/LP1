/**
* @file		empresa.cpp
* @brief	
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		09/08/2017
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "empresa.h"
#include "funcionario.h"
#include "datas.h"
#include "../ler_entradas.h"

Empresa::Empresa(){

}
Empresa::Empresa(std::string nome_, int cnpj_, Datas data_cadastro_, const std::vector<Funcionario*> &list_){
	nome = nome_;
	cnpj = cnpj_;
	lista_funcionarios = list_;
	data_cadastro = data_cadastro_;

	endereco = "Não Informado";
	atv_comercial = "Não Informado";
	nome_dono = "Não Informado";

	++(++numero_empresas);
}

Empresa::~Empresa(){
	--numero_empresas;
}

std::string Empresa::get_nome(){
	return nome;
}

std::string Empresa::get_endereco(){
	return endereco;
}

std::string Empresa::get_atv_comercial(){
	return atv_comercial;
}

std::string Empresa::get_nome_dono(){
	return nome_dono;
}

int Empresa::get_cnpj(){
	return cnpj;
}

Datas& Empresa::get_data_cadastro(){
	return data_cadastro;
}


void Empresa::atualiza_dados(){
	std::string endereco_;
	std::string atv_comercial_;
	std::string nome_dono_;

	std::cout << std::endl << ">>> Digite os seguintes dados sobre a empresa: " << std::endl
	<< "Endereço: ";
	std::getline(std::cin, endereco_);

	std::cout << std::endl << "Atividade realizada: ";
	std::getline(std::cin, atv_comercial_);

	std::cout << std::endl << "Nome do dono: ";
	std::getline(std::cin, nome_dono_);

	endereco = endereco_;
	atv_comercial = atv_comercial_;
	nome_dono = nome_dono_;

	return;
}

bool Empresa::adicionar_funcionario(){
	std::string nome;
	float salario;
	Datas data;

	std::cout << std::endl << ">>> Digite os dados do funcionario:" << std::endl
	<< "Nome: ";
	std::getline(std::cin, nome);

	std::cout << std::endl << "Salario: ";
	salario = get_int();

	std::cout << std::endl << "Data: ";
	data.set_data();

	Funcionario *func = new Funcionario(nome,salario,data);

	for (std::vector<Funcionario*>::iterator it = lista_funcionarios.begin(); it != lista_funcionarios.end(); ++it)
	{
		if ( **it == *func){
			std::cout << std::endl << ">>> Funcionario já existe. Cancelando operação..." << std::endl;;
			return false;
		}
	}
	lista_funcionarios.push_back(func);

	return true;
}

bool Empresa::atualizar_funcionario() {
	std::cout << "Qual dos seguintes funcionarios gostaria de atualizar?" << std::endl;
	for (std::vector<Funcionario*>::iterator i = lista_funcionarios.begin(); i != lista_funcionarios.end(); ++i)
	{
		std::cout << (**i) << std::endl;
	}
	std::string nome;
	std::cout << "Nome: ";
	std::getline(std::cin, nome);

	for (std::vector<Funcionario*>::iterator it = lista_funcionarios.begin(); it != lista_funcionarios.end(); ++it)
	{
		if ( **it == nome){
			Datas data_nascimento;
			std::string endereco;
			std::string cargo;
			std::string dept;

			std::cout << std::endl << ">>> Digite as seguintes informações sobre o funcionario:" << std::endl
			<< "Endereço: ";
			std::getline(std::cin, endereco);
			(**it).set_endereco(endereco);

			std::cout << std::endl << "Cargo: ";
			std::getline(std::cin, cargo);
			(**it).set_cargo(cargo);

			std::cout << std::endl << "Departamento: ";
			std::getline(std::cin, dept);
			(**it).set_dept(dept);

			std::cout << std::endl << "Data de Nascimento: ";
			data_nascimento.set_data();
			(**it).set_nascimento(data_nascimento);

			return true;
		}
	}
	std::cout << " Funcionario não encontrado. Cancelando operação..." << std::endl;
	return false;
}

int Empresa::get_numero_funcionarios() {
	return lista_funcionarios.size();
}

void Empresa::alterar_salario(float per_cento){
	for (std::vector<Funcionario*>::iterator i = lista_funcionarios.begin(); i != lista_funcionarios.end(); ++i)
	{
		(**i).change_salario(per_cento);
	}
}

int Empresa::listar_func_exp(){
	int qtd = 0;
	Datas meses3(0,3,0);
	Datas data_alvo;
	std::cout << std::endl << ">>> Digite a data alvo para o teste de funcionario em experiencia: " << std::endl;
	data_alvo.set_data();
	for (std::vector<Funcionario*>::iterator i = lista_funcionarios.begin(); i != lista_funcionarios.end(); ++i)
	{
		std::cout << (**i).get_data_admissao();
		if ( ( (**i).get_data_admissao() - data_alvo ) < meses3)
		{
			std::cout << (**i) << std::endl;
			++qtd;
		}
	}
	return qtd;

}

bool Empresa::demitir_funcionario(std::string nome){
	for (std::vector<Funcionario*>::iterator it = lista_funcionarios.begin(); it != lista_funcionarios.end(); ++it)
	{
		if ( (**it).get_nome() == nome){
			lista_funcionarios.erase(it);
			delete &(**it);
			return true;
		}
	}
	return false;
}

std::ostream& operator<< (std::ostream &o, Empresa &empresa){
	for (std::vector<Funcionario*>::iterator i = empresa.lista_funcionarios.begin(); i != empresa.lista_funcionarios.end(); ++i)
	{
		o << (**i) << std::endl;
	}
	return o;
}

bool Empresa::operator==(const Empresa &empr) const{
	if (this->nome == empr.nome){
		return true;
	} else {
		return false;
	}
}