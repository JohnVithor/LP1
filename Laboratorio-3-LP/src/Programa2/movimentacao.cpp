/**
* @file		movimentacao.cpp
* @brief	Implementação dos métodos da classe Movimentacao
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		20/10/2017	
*/

#include <string>
#include <iostream>
#include <iterator>

#include "movimentacao.h"

Movimentacao::Movimentacao()
		: descricao(std::string())
		, valor(0)
		, tipo_movimentacao(credito)
{ /*Vazio*/ }

Movimentacao::Movimentacao( std::string descricao_, double valor_, Indic tipo_movimentacao_ )
		: descricao(descricao_)
		, valor(valor_)
		, tipo_movimentacao(tipo_movimentacao_)
{ /*Vazio*/ }

Movimentacao::~Movimentacao()
{ /*Vazio*/ }


std::string Movimentacao::get_descricao()
{
	return descricao;
}

double Movimentacao::get_valor()
{
	return valor;	
}

Indic Movimentacao::get_tipo()
{
	return tipo_movimentacao;
}

std::ostream& operator<< (std::ostream &o, Movimentacao &movimentacao)
{
	o << "> Descrição: " << movimentacao.descricao << std::endl
	  << "> Valor: " << movimentacao.valor << std::endl
	  << "> Tipo: " << ( (movimentacao.tipo_movimentacao == credito) ? "Crédito" : "Débito");
	return o;
}

