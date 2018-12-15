/**
 * @file gerenciador.cpp
 * @brief      Implementação dos métodos da classe Gerenciador
 *
 * @author     João Vítor Venceslau Coelho
 * @since      19/11/2017
 * @date       21/11/2017
 */

#include "gerenciador.hpp"

double Gerenciador::pedir_entrada_valida()
{
	std::string line;
	double numero = 0;

	// O trecho de codigo abaixo foi editado e não é de minha autoria. Créditos: Silvio Costa Sampaio
	while ( std::getline( std::cin, line ) ) // repete a leitura de toda a linha
	{ 
		std::stringstream ss( line ); // cria um stringstream com o conteudo da linha
		if ( ( ss >> numero ) and ss.eof() )
		{
			// Tenta extrair um 'double' do stringstream
			// Se extraiu com sucesso e não restou nada mais...
			break; // Sai da repetição
		}
		std::cout << "[ERRO] Entrada inválida, por favor digite uma entrada válida." << std::endl;
		std::cout << "Digite um double: ";
	}
	// Fim do trecho
	return numero;
}

void Gerenciador::calcular_triangulo_equi()
{
	std::cout << "Digite o tamanho da base do triangulo equilatero: ";

	geometria::triangulo_equi figura( pedir_entrada_valida() );

	std::cout << ">>> Area do triangulo equilatero: " << figura.area() << std::endl;
	std::cout << ">>> Perimetro do triangulo equilatero: " << figura.perimetro() << std::endl << std::endl;
}

void Gerenciador::calcular_retangulo()
{
	std::cout << "Digite o tamanho da base do retangulo: ";
	double base = pedir_entrada_valida();
	std::cout << "Digite o tamanho da altura do retangulo: ";
	double altura = pedir_entrada_valida();

	geometria::retangulo figura( base, altura );

	std::cout << ">>> Area do retangulo: " << figura.area() << std::endl;
	std::cout << ">>> Perimetro do retangulo: " << figura.perimetro() << std::endl << std::endl;
}

void Gerenciador::calcular_quadrado()
{
	std::cout << "Digite o tamanho do lado do quadrado: ";

	geometria::quadrado figura ( pedir_entrada_valida() );

	std::cout << ">>> Area do quadrado: " << figura.area() << std::endl;
	std::cout << ">>> Perimetro do quadrado: " << figura.perimetro() << std::endl << std::endl;
}

void Gerenciador::calcular_circulo()
{
	std::cout << "Digite o tamanho do raio do circulo: ";

	geometria::circulo figura ( pedir_entrada_valida() );

	std::cout << ">>> Area do circulo: " << figura.area() << std::endl;
	std::cout << ">>> Perimetro do circulo: " << figura.perimetro() << std::endl << std::endl;
}


void Gerenciador::calcular_piramide_quadrangular()
{
	std::cout << "Digite o tamanho da largura da base da piramide com base quadrangular: ";
	double base_largura = pedir_entrada_valida();

	std::cout << "Digite o tamanho da altura da piramide com base quadrangular: ";
	double altura = pedir_entrada_valida();

	geometria::piramide figura ( base_largura, altura );

	std::cout << ">>> Area da piramide com base quadrangular: " << figura.area() << std::endl;
	std::cout << ">>> Volume da piramide com base quadrangular: " << figura.volume() << std::endl << std::endl;
}

void Gerenciador::calcular_cubo()
{
	std::cout << "Digite o tamanho da aresta do cubo: ";

	geometria::cubo figura ( pedir_entrada_valida() );

	std::cout << ">>> Area do cubo: " << figura.area() << std::endl;
	std::cout << ">>> Volume do cubo: " << figura.volume() << std::endl << std::endl;
}

void Gerenciador::calcular_paralelepipedo()
{
	std::cout << "Digite o tamanho da primeira aresta do paralelepipedo: ";
	double aresta_1 = pedir_entrada_valida();

	std::cout << "Digite o tamanho da segunda aresta do paralelepipedo: ";
	double aresta_2 = pedir_entrada_valida();

	std::cout << "Digite o tamanho da terceira aresta do paralelepipedo: ";
	double aresta_3 = pedir_entrada_valida();
	
	geometria::paralelepipedo figura( aresta_1, aresta_2, aresta_3 );

	std::cout << ">>> Area do paralelepipedo: " << figura.area() << std::endl;
	std::cout << ">>> Volume do paralelepipedo: " << figura.volume() << std::endl << std::endl;
}

void Gerenciador::calcular_esfera()
{
	std::cout << "Digite o raio da esfera: ";

	geometria::esfera figura( pedir_entrada_valida() );

	std::cout << ">>> Area do esfera: " << figura.area() << std::endl;
	std::cout << ">>> Volume do esfera: " << figura.volume() << std::endl << std::endl;
}