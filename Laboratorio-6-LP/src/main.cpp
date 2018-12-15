/**
 * @file main.cpp
 * @brief      Programa que calcula área, perímetro e volume de algumas figuras
 *             geométricas planas e espaciais
 * @details    
 *
 * @author     João Vítor Venceslau Coelho
 * @since      19/11/2017
 * @date       21/11/2017 
 */

#include <iostream>
#include <sstream>

#include "gerenciador.hpp"

/**
 * @brief      Funcão Principal
 * @details    Apresenta as opções de figuras geometricas suportadas pelo
 *             programa e solicita ao usuário uma resposta, após a resposta ser
 *             recebida executa a devida função para o calculo da área e
 *             perimetro ou volume da figura escolhida
 *
 * @param[in]  argc  Numero de argumentos fornecidos via linha de comando
 * @param      argv  Argumentos fornecidos via linha de comando
 *
 * @return     0
 */
int main(int argc, char const *argv[])
{
	int escolhido = -1;
	while( escolhido != 0 )
	{
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

		std::string line;
		std::getline( std::cin, line );
		std::stringstream ss( line );
		ss >> escolhido;
		
		Gerenciador figura;

		switch( escolhido )
		{
			case 1:
				figura.calcular_triangulo_equi();
				break;
			case 2:
				figura.calcular_retangulo();
				break;
			case 3:
				figura.calcular_quadrado();
				break;
			case 4:
				figura.calcular_circulo();
				break;
			case 5:
				figura.calcular_piramide_quadrangular();
				break;
			case 6:
				figura.calcular_cubo();
				break;
			case 7:
				figura.calcular_paralelepipedo();
				break;
			case 8:
				figura.calcular_esfera();
				break;
			case 0:
				std::cout << "Obrigado por usar a Calculadora de Geometria Plana e Espacial" << std::endl;
				break;
			default:
				std::cout << "Entrada inválida, por favor digite uma entrada válida" << std::endl;
		}
	}
	return 0;
}