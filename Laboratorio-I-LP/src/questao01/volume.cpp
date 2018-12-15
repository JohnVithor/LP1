/**
* @file		volume.cpp
* @brief	Implementação das funções que calculam o volume das figuras geométricas suportadas
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		13/08/2017
* @sa		
*/


//#include <cmath>
#include "volume.h"

#define PI 3.1415

double piramide_quadrangular_volume(double base_largura, double altura){
	return (base_largura * base_largura * altura) / 3;
}

double cubo_volume(double aresta){
	//return pow(aresta,3);
	return aresta * aresta * aresta;
}

double paralelepipedo_volume(double aresta_1, double aresta_2, double aresta_3){
	return aresta_1 * aresta_2 * aresta_3;
}

double esfera_volume(double raio){
	//return (4 * PI * pow(raio,3)) / 3;
	return (4 * PI * (raio * raio * raio)) / 3;
}
