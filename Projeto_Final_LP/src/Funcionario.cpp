/**
 * @file Funcionario.cpp
 * @brief      Implementação das classe Funcionario e suas subclasses
 *             Veterinario e Tratador, seus atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       02/12/2017
 */

#include "Funcionario.hpp"

using namespace PetFera;

int Funcionario::get_id ( void )
{
	return m_id;
}

std::string Funcionario::get_nome ( void )
{
	return m_nome;
}

std::string Funcionario::get_funcao ( void )
{
	return m_funcao;
}

std::string Funcionario::get_CPF ( void )
{
	return m_CPF;
}

short Funcionario::get_idade ( void )
{
	return m_idade;
}

std::string Funcionario::get_t_sangue ( void )
{
	return m_tipo_sangue;
}

char Funcionario::get_RH ( void )
{
	return m_fator_RH;
}

std::string Funcionario::get_espec ( void )
{
	return m_especialidade;
}

void Funcionario::set_idade ( short _idade )
{
	m_idade = _idade;
}

std::ostream& Funcionario::printFuncionario( std::ostream & _os )
{
	_os << std::endl;
	_os << ">>>>> Ficha do Funcionario <<<<<" << std::endl;
	_os << "ID:\t\t" << m_id << std::endl;
	_os << "Funcao:\t" << m_funcao << std::endl;
	_os << "Nome:\t\t" << m_nome << std::endl;
	_os << "CPF:\t" << m_CPF << std::endl;
	_os << "Idade:\t\t" << m_idade << std::endl;
	_os << "Tipo Sanguineo:\t\t" << m_tipo_sangue << std::endl;
	_os << "Fator RH:\t\t" << m_fator_RH << std::endl;
	_os << "Especialidade:\t" << m_especialidade << std::endl;
	_os << std::endl;

	return _os;

}