/**
* @file		main1.cpp
* @brief	Programa que calcula área, perímetro e volume de algumas figuras geométricas planas e espaciais
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/

#include <iostream>

#include "calcula.h"
#include "area.h"
#include "perimetro.h"
#include "volume.h"

/**
* @brief	Funcao principal
* @details	Apresenta as opções de figuras geometricas suportadas pelo programa
			e solicita ao usuário uma resposta, após a resposta ser recebida 
			executa a devida função para o calculo da área e perimetro ou volume
			da figura escolhida
* @param	argc Numero de argumentos fornecidos via linha de comando
* @param	argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char const *argv[])
{
	char escolhido = '-';
	while(escolhido != '0'){
		std::cout << "Calculadora de Geometria Plana e Espacial" << std::endl
				<< "(1) Triangulo equilatero" << std::endl
				<< "(2) Retangulo" << std::endl
				<< "(3) Quadrado" << std::endl
				<< "(4) Circulo" << std::endl
				<< "(5) Piramide com base quadrangular" << std::endl
				<< "(6) Cubo" << std::endl
				<< "(7) Paralelepipedo" << std::endl
				<< "(8) Esfera" << std::endl
				<< "(0) Sair" << std::endl
				<< "Digite a sua opcao: ";
		std::cin >> escolhido;
		switch(escolhido){
			case '1':
				calcular_triangulo_equi();
				break;
			case '2':
				calcular_retangulo();
				break;
			case '3':
				calcular_quadrado();
				break;
			case '4':
				calcular_circulo();
				break;
			case '5':
				calcular_piramide_quadrangular();
				break;
			case '6':
				calcular_cubo();
				break;
			case '7':
				calcular_paralelepipedo();
				break;
			case '8':
				calcular_esfera();
				break;
			case '0':
				std::cout << "Obrigado por usar a Calculadora de Geometria Plana e Espacial" << std::endl;
				break;
			default:
				std::cout << "Entrada inválida, por favor digite uma entrada válida" << std::endl;
		}
	}
	return 0;
}