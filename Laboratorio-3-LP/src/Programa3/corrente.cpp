/**
* @file		corrente.cpp
* @brief	Implementação dos métodos da classe Corrente
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		24/10/2017	
*/

#include <iostream>
#include <vector>
#include "corrente.h"

Corrente::Corrente()
			:Conta( corrente, 0, 0, 0 )
			,m_status(nao_especial)
			,m_limite(0)
			{ /*Vazio*/ }

Corrente::Corrente( unsigned int agencia, unsigned int numero, double saldo, Status status )
			:Conta ( corrente, agencia, numero, saldo )
			,m_status(status)
			,m_limite((-1.2)*m_saldo)
			{ /*Vazio*/ }

Status Corrente::get_status()
{
	return m_status;
}

unsigned int Corrente::get_limite()
{
	return - m_limite;
}

bool Corrente::set_status ( Status status )
{
	if ( m_status == status )
	{
		return false;
	}
	else
	{
		m_status = status;
	}
	return true;
}

bool Corrente::set_saldo ( std::shared_ptr< Movimentacao > movimentacao )
{
	if ( (*movimentacao).get_tipo() == credito )
	{
		m_saldo += (*movimentacao).get_valor();
	}
	else
	{
		if ( m_status == especial )
		{
			if ( ( m_saldo - (*movimentacao).get_valor() ) < m_limite )
			{
				return false;
			}
		}
		else
		{
			if ( ( m_saldo - (*movimentacao).get_valor() ) < 0 )
			{
				return false;
			}
		}
		
		m_saldo -= (*movimentacao).get_valor();
	}

	m_limite = (-1.2)*m_saldo;
	m_conjunto_movimentacoes.push_back( movimentacao );

	return true;
}

std::ostream& Corrente::print (std::ostream &o) const
{
	o << " == Conta Corrente == " << std::endl;
	if (m_conjunto_movimentacoes.empty())
	{
		o << "Esta conta não possui histórico de movimentações" << std::endl;
	}
	else
	{
		for (auto i = m_conjunto_movimentacoes.begin(); i != m_conjunto_movimentacoes.end(); ++i)
		{
			o << (**i) << std::endl << std::endl;
		}
		o << "Fim do histórico de movimentações." << std::endl;
	}

	return o;
}