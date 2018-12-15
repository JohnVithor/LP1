/**
* @file		poupanca.cpp
* @brief	Implementação dos métodos da classe Poupanca
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		20/10/2017	
*/

#include <iostream>

#include "poupanca.h"

Poupanca::Poupanca(): Conta( poupanca, 0, 0, 0 ) { /*Vazio*/ }

Poupanca::Poupanca( unsigned int agencia, unsigned int numero, double saldo ):
			Conta ( poupanca, agencia ,numero ,saldo ) { /*Vazio*/ }

bool Poupanca::set_saldo ( std::shared_ptr< Movimentacao > movimentacao )
{
	if ( (*movimentacao).get_tipo() == credito )
	{
		m_saldo += (*movimentacao).get_valor();
	}
	else
	{
		if ( ( m_saldo - (*movimentacao).get_valor() ) < 0 )
		{
			return false;
		}
		m_saldo -= (*movimentacao).get_valor();
	}

	m_conjunto_movimentacoes.push_back( movimentacao );

	return true;
}

std::ostream& Poupanca::print (std::ostream &o) const
{
	o << " == Conta Poupança == " << std::endl;
	if (m_conjunto_movimentacoes.empty())
	{
		o << "Esta conta não possui histórico de movimetações" << std::endl;
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