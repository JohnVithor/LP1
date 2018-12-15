/**
* @file		perimetro.cpp
* @brief	Implementação das funções que calculam o perímetro das figuras geométricas suportadas
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/


#include "perimetro.h"

#define PI 3.1415

double triangulo_equi_perimetro(double lado){
	return 3 * lado;
}

double retangulo_perimetro(double base, double altura){
	return 2 * (base + altura);
}

double quadrado_perimetro(double lado){
	return 4 * lado;
}

double circulo_perimetro(double raio){
	return 2 * PI * raio;
}