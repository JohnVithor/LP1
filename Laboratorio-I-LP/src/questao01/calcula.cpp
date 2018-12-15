/**
* @file		calcula.cpp
* @brief	Implementação das funções que requisitam ao usuário a entrada dos dados
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		14/08/2017
* @sa		
*/


#include <iostream>

#include "calcula.h"
#include "area.h"
#include "perimetro.h"
#include "volume.h"

double pedir_entrada_valida(){
	double entrada;
	std:: cin >> entrada;
	while(std::cin.fail() or entrada < 1){
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cout << "Por favor digite um valor numérico." << std::endl;
		std:: cin >> entrada;
	}
	return entrada;
}

void calcular_triangulo_equi(){
	std::cout << "Digite o tamanho da base do triangulo equilatero: ";
	double base;
	base = pedir_entrada_valida();

	std::cout << ">>> Area do triangulo equilatero: " << triangulo_equi_area(base) << std::endl;
	std::cout << ">>> Perimetro do triangulo equilatero: " << triangulo_equi_perimetro(base) << std::endl << std::endl;
}

void calcular_retangulo(){
	std::cout << "Digite o tamanho da base do retangulo: ";
	double base;
	base = pedir_entrada_valida();
	std::cout << "Digite o tamanho da altura do retangulo: ";
	double altura;
	altura = pedir_entrada_valida();

	std::cout << ">>> Area do retangulo: " << retangulo_area(base,altura) << std::endl;
	std::cout << ">>> Perimetro do retangulo: " << retangulo_perimetro(base,altura) << std::endl << std::endl;
}

void calcular_quadrado(){
	std::cout << "Digite o tamanho do lado do quadrado: ";
	double lado;
	lado = pedir_entrada_valida();

	std::cout << ">>> Area do quadrado: " << quadrado_area(lado) << std::endl;
	std::cout << ">>> Perimetro do quadrado: " << quadrado_perimetro(lado) << std::endl << std::endl;
}

void calcular_circulo(){
	std::cout << "Digite o tamanho do raio do circulo: ";
	double raio;
	raio = pedir_entrada_valida();

	std::cout << ">>> Area do circulo: " << circulo_area(raio) << std::endl;
	std::cout << ">>> Perimetro do circulo: " << circulo_perimetro(raio) << std::endl << std::endl;
}


void calcular_piramide_quadrangular(){
	std::cout << "Digite o tamanho da largura da base da piramide com base quadrangular: ";
	double base_largura;
	base_largura = pedir_entrada_valida();
	std::cout << "Digite o tamanho da altura da piramide com base quadrangular: ";
	double altura;
	altura = pedir_entrada_valida();

	std::cout << ">>> Area da piramide com base quadrangular: " << piramide_quadrangular_area(base_largura,altura) << std::endl;
	std::cout << ">>> Volume da piramide com base quadrangular: " << piramide_quadrangular_volume(base_largura,altura) << std::endl << std::endl;
}

void calcular_cubo(){
	std::cout << "Digite o tamanho da aresta do cubo: ";
	double aresta;
	aresta = pedir_entrada_valida();

	std::cout << ">>> Area do cubo: " << cubo_area(aresta) << std::endl;
	std::cout << ">>> Volume do cubo: " << cubo_volume(aresta) << std::endl << std::endl;
}

void calcular_paralelepipedo(){
	std::cout << "Digite o tamanho da primeira aresta do paralelepipedo: ";
	double aresta_1;
	aresta_1 = pedir_entrada_valida();
	std::cout << "Digite o tamanho da segunda aresta do paralelepipedo: ";
	double aresta_2;
	aresta_2 = pedir_entrada_valida();
	std::cout << "Digite o tamanho da terceira aresta do paralelepipedo: ";
	double aresta_3;
	aresta_3 = pedir_entrada_valida();

	std::cout << ">>> Area do paralelepipedo: " << paralelepipedo_area(aresta_1,aresta_2,aresta_3) << std::endl;
	std::cout << ">>> Volume do paralelepipedo: " << paralelepipedo_volume(aresta_1,aresta_2,aresta_3) << std::endl << std::endl;
}

void calcular_esfera(){
	std::cout << "Digite o raio da esfera: ";
	double raio;
	raio = pedir_entrada_valida();

	std::cout << ">>> Area do esfera: " << esfera_area(raio) << std::endl;
	std::cout << ">>> Volume do esfera: " << esfera_volume(raio) << std::endl << std::endl;
}