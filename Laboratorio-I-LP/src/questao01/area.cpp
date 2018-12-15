/**
* @file		area.cpp
* @brief	Implementação das funções que calculam a área das figuras geométricas suportadas
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		13/08/2017
* @sa		
*/

#include <cmath>
#include "area.h"

#define PI 3.1415

double triangulo_equi_area(double base){
	//return (base * ((base / 2) * sqrt(3))) / 2;
	return ((base * base) * sqrt(3)) / 4;
}

double retangulo_area(double base, double altura){
	return base * altura;
}

double quadrado_area(double lado){
	//return pow(lado,2);
	return lado * lado;
}

double circulo_area(double raio){
	//return PI * pow(raio,2);
	return PI * raio * raio;
}

double piramide_quadrangular_area(double base_largura, double altura){
	/*
	double area_base = base_largura * base_largura;
	double altura_triangulo_face = (sqrt(pow((base_largura/2),2) + pow((altura),2))); // pitágoras
	double area_face = (altura_triangulo_face * base_largura) / 2;
	return area_base +  4 * area_face;
	*/
	return (base_largura * base_largura) + 2 * ((sqrt(pow((base_largura/2),2) + pow((altura),2))) * base_largura);
}

double cubo_area(double aresta){
	return 6 * (aresta * aresta);
}

double paralelepipedo_area(double aresta_1, double aresta_2, double aresta_3){
	return (2 * aresta_1 * aresta_2) + (2 * aresta_1 * aresta_3) + (2 * aresta_2 * aresta_3);
}

double esfera_area(double raio){
	//return 4 * PI * pow(raio,2);
	return 4 * PI * raio * raio;
}