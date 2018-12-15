/**
* @file		jogador.cpp
* @brief	Implementação dos métodos da classe Jogador
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	29/08/2017
* @date		29/08/2017
*/

#include "jogador.h"
#include "dado.h"

Jogador::Jogador(){
	identificador = numero_jogadores + 1000;
	pontos = 0;
	ativo = true;
	sortudo = false;

	++numero_jogadores;
	++numero_jogadores_ativos;
}

Jogador::~Jogador(){
	--numero_jogadores;
}

int Jogador::get_id(){
	return identificador;
}

bool Jogador::is_ativo(){
	return ativo;
}

bool Jogador::set_ativo(){
	ativo = true;
	++numero_jogadores_ativos;
	return ativo;
}

bool Jogador::not_ativo(){
	ativo = false;
	--numero_jogadores_ativos;
	return ativo;
}

bool Jogador::is_sortudo(){
	return sortudo;
}

int Jogador::jogar_dados(){
	Dado d1;
	Dado d2;
	int pontos_rodada = d1.jogar() + d2.jogar();
	pontos += pontos_rodada;
	if (pontos == max_pontos_partida){
		sortudo = true;
	} else if (pontos > max_pontos_partida){
		++numero_jogadores_excluidos;
	}
	return pontos_rodada;
}

int Jogador::get_pontos(){
	return pontos;
}
