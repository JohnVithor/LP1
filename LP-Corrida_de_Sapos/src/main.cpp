/**
* @file		main.cpp
* @brief	Programa principal
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	17/08/2017
* @date		22/08/2017
*/

#include <iostream>
#include <random>

#include "sapo.h"

int Sapo::dist_da_corrida = 500; // 5 metros

int main(int argc, char const *argv[]){

	int corrida = Sapo::dist_da_corrida;

	Sapo sapos[3];
	for (int i = 0; i < 3; ++i){
		sapos[i].set_id(i+1000);
	}

	int atual = 0;
	while((sapos[0].get_dist_per() < corrida) or (sapos[1].get_dist_per() < corrida) 
		or (sapos[2].get_dist_per() < corrida)){
		if (atual == 3){
			atual = 0;
		}
		if (sapos[atual].get_dist_per() < corrida){ // Verifico se o sapo atual ja terminou a corrida
			sapos[atual].pular();					// Caso ele não tenha terminado, ele pula.
		}
		++atual;
	}
/*
	Para poder organizar o vetor de sapos tive que criar um auxiliar e utilizar set'ers e get'ers para
	conseguir trocar os valores, caso fosse feito desse modo abaixo dava erro:

	for (int i = 1; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			if (sapos[i].get_pulos() < sapos[j].get_pulos()){
				Sapo aux = sapos[i];
				sapos[i] = sapos[j];
				sapos[j] = aux;
			}
		}
	}
	Assim tive que criar set_dist_per(int qnt) e set_pulos(int qnt), mesmo não parecendo muito certo...
*/
	for (int i = 1; i < 3; ++i){
		for (int j = 0; j < 3; ++j){
			/*
			Não criei nenhum criterio de desempate, classifiquei apenas pela quantidade de pulos dados
			Caso dois sapos tenham a mesma quantidade de pulos eles "teriam chegado ao mesmo tempo"
			*/
			if (sapos[i].get_pulos() < sapos[j].get_pulos()){ 
				Sapo aux;

				aux.set_id(sapos[i].get_id());
				aux.set_dist_per(sapos[i].get_dist_per());
				aux.set_pulos(sapos[i].get_pulos());

				sapos[i].set_id(sapos[j].get_id());
				sapos[i].set_dist_per(sapos[j].get_dist_per());
				sapos[i].set_pulos(sapos[j].get_pulos());

				sapos[j].set_id(aux.get_id());
				sapos[j].set_dist_per(aux.get_dist_per());
				sapos[j].set_pulos(aux.get_pulos());
			}
		}
	}
	

	for (int i = 0; i < 3; ++i){
		std::cout << "Em " << i+1 << "º lugar temos o sapo " << sapos[i].get_id() << ":" << std::endl;
		std::cout << "Pulou " << sapos[i].get_pulos() << " vezes." << std::endl;
		std::cout << "Percorreu " << sapos[i].get_dist_per() << " centimetros." << std::endl;
		std::cout << std::endl;
	}

	return 0;
}