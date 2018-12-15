/**
* @file		funcionario.cpp
* @brief	
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		09/09/2017
*/

#include <string>
#include <iostream>
#include <iterator>

#include "datas.h"
#include "funcionario.h"
#include "../ler_entradas.h"

Funcionario::Funcionario(){
	nome = " ";
	salario = 0;
	Datas adm(0,0,0);
	data_admissao = adm;

	Datas nasc(0,0,0);
	Datas data_nascimento = nasc;
	std::string endereco = "Não Informado";
	std::string cargo = "Não Informado";
	std::string dept = "Não Informado";

	++numero_funcionarios;
}

Funcionario::Funcionario(std::string nome_, float salario_, Datas data_admissao_){
	nome = nome_;
	salario = salario_;
	data_admissao = data_admissao_;

	Datas nasc(0,0,0);
	Datas data_nascimento = nasc;
	std::string endereco = "Não Informado";
	std::string cargo = "Não Informado";
	std::string dept = "Não Informado";

	++numero_funcionarios;
}

Funcionario::~Funcionario(){
	--numero_funcionarios;
}

std::string Funcionario::get_nome(){
	return nome;
}

std::string Funcionario::set_endereco( std::string endereco_){
	endereco = endereco_;
	return endereco;
}

std::string Funcionario::set_cargo( std::string cargo_){
	cargo = cargo_;
	return cargo;
}

std::string Funcionario::set_dept( std::string dept_){
	dept = dept_;
	return dept;
}

Datas Funcionario::set_nascimento( Datas nascimento_){
	data_nascimento = nascimento_;
	return data_nascimento;
}

float Funcionario::change_salario(float per_cento){
	salario += salario*(per_cento/100);
	return salario;
}

Datas& Funcionario::get_data_admissao(){
	return data_admissao;	
}

std::ostream& operator<< (std::ostream &o, Funcionario &funcionario){
	o << "> Nome: " << funcionario.nome << std::endl
	  << "> Salário: " << funcionario.salario << std::endl
	  << "> Data de admissão: " << funcionario.data_admissao << std::endl
	  << "> Data de nascimento: " << funcionario.data_nascimento << std::endl
	  << "> Endereço: " << funcionario.endereco << std::endl
	  << "> Cargo: " << funcionario.cargo << std::endl
	  << "> Departamento: " << funcionario.dept;
	return o;
}

bool Funcionario::operator==(const Funcionario &func) const {
	if (this->nome == func.nome){
		return true;
	} else {
		return false;
	}
}

bool Funcionario::operator==(const std::string &nome) const {
	if (this->nome == nome){
		return true;
	} else {
		return false;
	}
}