/**
* @file		sapo.cpp
* @brief	
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	17/08/2017
* @date		22/08/2017
*/

#include <random>

#include "sapo.h"

Sapo::Sapo():rd(),gen(rd()),linear_i(1,19){ // A maquina randomica foi inicializada aqui

	identificador = -1;
	dist_percorrida = 0;
	pulos = 0;
}

Sapo::~Sapo(){

}

int Sapo::set_id(int id){
	identificador = id;
	return identificador;
}

int Sapo::get_id(){
	return identificador;
}

int Sapo::get_dist_per(){
	return dist_percorrida;
}

int Sapo::get_pulos(){
	return pulos;
}

int Sapo::set_dist_per(int qnt){
	dist_percorrida = qnt;
	return dist_percorrida;
}
int Sapo::set_pulos(int qnt){
	pulos = qnt;
	return pulos;
}

int Sapo::pular(){
	// Antes a maquina randomica era criada e destruida a cada pulo
	/*
	std::random_device rd;
	std::mt19937 gen(rd);
	std::uniform_int_distribution<int> dis(1,19);
	*/
	dist_percorrida += std::round(linear_i(gen));
	++pulos;

	return dist_percorrida;
}
