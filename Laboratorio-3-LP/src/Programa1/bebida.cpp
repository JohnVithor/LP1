/**
* @file		bebida.cpp
* @brief	Implementação da Classe Bebida
* @details	
*
* @author	João Vítor Venceslau Coelho / Teobaldo
* @since	10/10/2017
* @date		23/10/2017
*/

#include <iomanip>
#include "bebida.h"

Bebida::Bebida() {}

Bebida::Bebida (std::string _codigo, std::string _descricao, double _preco, 
				unsigned short _alcool):
	Produto(_codigo, _descricao, _preco), m_alcool(_alcool) {}

Bebida::~Bebida() {}

unsigned short
Bebida::getAlcool() {
	return m_alcool;
}

void 
Bebida::setAlcool(unsigned short _alcool) {
	m_alcool = _alcool;
}

std::ostream& 
Bebida::print(std::ostream &o) const {
	o << std::setfill (' ') << std::setw (10) << m_cod_barras << " | " 
		<< std::setfill ('.') << std::setw (20) << m_descricao << " | " 
		<< std::setfill (' ') << std::setw (5) << m_preco << " | "
		<< std::setfill (' ') << std::setw (3) << m_alcool << "%";
	return o;
}