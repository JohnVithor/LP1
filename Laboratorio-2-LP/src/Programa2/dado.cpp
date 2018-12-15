/**
* @file		dado.cpp
* @brief	Implementação dos métodos da classe Dado
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		29/08/2017
*/

#include <random>
#include <iostream>

#include "dado.h"

Dado::Dado():rd(),gen(rd()),dis(1,6){
	valor = std::round(dis(gen));
}

Dado::~Dado(){
}

int Dado::jogar(){
	valor = std::round(dis(gen));
	return valor;
}

int Dado::getvalor(){
	return valor;
}

Dado& Dado::operator+ (Dado &dado){
	valor = valor + dado.valor;
	return *this;
}

std::ostream& operator<< (std::ostream &o, Dado &dado) {
	o << dado.getvalor();
	return o;
}