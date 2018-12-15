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

Conta::Conta()
		: m_agencia(0)
		, m_numero(0)
		, m_saldo(0)
		, m_status(nao_especial)
		, m_conjunto_movimentacoes()
{ /*Vazio*/ }

Conta::Conta ( unsigned int agencia, unsigned int numero, double saldo, Status status )
		: m_agencia(agencia)
		, m_numero(numero)
		, m_saldo(saldo)
		, m_status(status)
		, m_conjunto_movimentacoes()
{ /*Vazio*/ }

Conta::~Conta()
{ /*Vazio*/ }

unsigned int Conta::get_agencia()
{
	return m_agencia;
}

unsigned int Conta::get_numero()
{
	return m_numero;
}

unsigned int Conta::get_saldo()
{
	return m_saldo;
}

Status Conta::get_status()
{
	return m_status;
}

unsigned int Conta::get_limite()
{
	return - m_limite;
}

bool Conta::set_saldo ( std::shared_ptr< Movimentacao > movimentacao )
{
	if ((*movimentacao).get_tipo() == credito)
	{
		m_saldo += (*movimentacao).get_valor();
	}
	else
	{
		if (m_status == especial)
		{
			if ((m_saldo - (*movimentacao).get_valor()) < m_limite)
			{
				return false;
			}
		}
		else
		{
			if ((m_saldo - (*movimentacao).get_valor()) < 0)
			{
				return false;
			}
		}
		
		m_saldo -= (*movimentacao).get_valor();	
	}

	m_limite = (-1.2)*m_saldo;
	m_conjunto_movimentacoes.push_back(movimentacao);

	return true;
}

bool Conta::set_status ( Status status )
{
	if (m_status == status)
	{
		return false;
	}
	else
	{
		m_status = status;
	}
	return true;
}

std::ostream& operator<< (std::ostream &o, Conta &conta)
{
	for (auto i = conta.m_conjunto_movimentacoes.begin(); i != conta.m_conjunto_movimentacoes.end(); ++i)
	{
		o << (**i) << std::endl << std::endl;
	}
	return o;
}

bool Conta::operator== ( Conta &outra )
{
	return ( m_agencia == outra.m_agencia and m_numero == outra.m_numero );
}