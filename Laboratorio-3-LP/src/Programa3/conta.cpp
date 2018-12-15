/**
* @file		conta.cpp
* @brief	Implementação dos métodos da classe Conta
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		24/10/2017	
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "conta.h"
#include "movimentacao.h"

Conta::Conta ()
		: m_agencia(0)
		, m_numero(0)
		, m_saldo(0)
		, m_conjunto_movimentacoes()
		{ /*Vazio*/ }

Conta::Conta ( Identificador tipo, unsigned int agencia, unsigned int numero, double saldo )
		: m_tipo_conta(tipo)
		, m_agencia(agencia)
		, m_numero(numero)
		, m_saldo(saldo)
		, m_conjunto_movimentacoes()
		{ /*Vazio*/ }


Identificador Conta::get_tipo ()
{
	return m_tipo_conta;
}

unsigned int Conta::get_agencia ()
{
	return m_agencia;
}

unsigned int Conta::get_numero ()
{
	return m_numero;
}

unsigned int Conta::get_saldo ()
{
	return m_saldo;
}

Status Conta::get_status ()
{
	std::cerr << "Este tipo de conta não possui status." << std::endl;
	return nao_possui;
}


unsigned int Conta::get_limite ()
{
	std::cerr << "Este tipo de conta não possui limite." << std::endl;
	return 0;
}


bool Conta::set_status ( Status status )
{
	std::cerr << "Este tipo de conta não possui status." << std::endl;
	return false;
}

std::ostream& operator<< ( std::ostream &o, Conta &conta )
{
	return conta.print(o);
}

bool Conta::operator== ( Conta &outra )
{
	return ( m_agencia == outra.m_agencia and m_numero == outra.m_numero );
}