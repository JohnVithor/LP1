/**
* @file		produto.cpp
* @brief	Implementação da Classe Produto
* @details	
*
* @author	João Vítor Venceslau Coelho / Teobaldo
* @since	10/10/2017
* @date		23/10/2017
*/

#include <iostream>
#include "produto.h"

Produto::Produto() {}

Produto::~Produto(){}

Produto::Produto(std::string _codigo, std::string _descricao, double _preco):
	m_cod_barras(_codigo), m_descricao(_descricao), m_preco(_preco) {}

std::string 
Produto::getCodBarras() {
	return m_cod_barras;
}

std::string 
Produto::getDescricao() {
	return m_descricao;
}

double 
Produto::getPreco() {
	return m_preco;
}

void 
Produto::setCodBarras(std::string _codigo) {
	m_cod_barras = _codigo;
}

void 
Produto::setDescricao(std::string _descricao) {
	m_descricao = _descricao;
}

void 
Produto::setPreco(double _preco) {
	m_preco = _preco;
}

std::ostream& operator<< (std::ostream &o, Produto const &p) {
/*
	O operador << da classe produto depende da implementação do método print(), como esse método é virtual puro,
	todas as classes derivadas devem implementar esse método, então ao acessar-mos um objeto das classes derivadas como um produto,
	e utilizar o operador << nesse objeto, será utilizado a versão implementada na classe produto, que, por sua vez,
	depende da implementação do método print(), que foi implementado nas classes derivadas, portanto ao utilizar o operador de <<
	numa das classes derivadas, ele irá funcionar normalmente, chamando o método << da pŕopria classe produto.
*/
	return p.print(o);
}


double
operator+ (double const val, Produto const &p)
{
	return (val + p.m_preco);
}


double 
operator- (double const val, Produto const &p)
{
	return (val - p.m_preco);
}

double
Produto::operator+ ( Produto const &p) const
{
	return (this->m_preco + p.m_preco);
}


double
Produto::operator+ ( double const val) const
{
	return (this->m_preco + val);
}

double
Produto::operator- ( Produto const &p) const
{
	return (this->m_preco - p.m_preco);
}

double
Produto::operator- ( double const val) const
{
	return (this->m_preco - val);
}


bool
Produto::operator== ( Produto const &p) const
{
	return (m_cod_barras == p.m_cod_barras);
}

