/**
 * @file figuras_geometricas_espaciais.cpp
 * @brief      Implementação dos métodos da classes derivadas da classe
 *             fig_geometrica_espacial
 * @details    
 *
 * @author     João Vítor Venceslau Coelho
 * @since      16/11/2017
 * @date       21/11/2017
 */

#include "figuras_geometricas.hpp"

using namespace geometria;

#define PI 3.1415

///////////////////////////////////////////////
//////////// 		Getters

double piramide::get_base()
{
	return m_base;
}

double piramide::get_altura()
{
	return m_altura;
}

double cubo::get_arestas()
{
	return m_arestas;
}

double paralelepipedo::get_aresta1()
{
	return m_aresta_1;
}

double paralelepipedo::get_aresta2()
{
	return m_aresta_2;
}

double paralelepipedo::get_aresta3()
{
	return m_aresta_3;
}

double esfera::get_raio()
{
	return m_raio;
}

///////////////////////////////////////////////
//////////// 		Setters

void piramide::set_base( double base )
{
	m_base = base;
}

void piramide::set_altura( double altura )
{
	m_altura = altura;
}

void cubo::set_arestas( double arestas )
{
	m_arestas = arestas;
}

void paralelepipedo::set_aresta1( double aresta1 )
{
	m_aresta_1 = aresta1;
}

void paralelepipedo::set_aresta2( double aresta2 )
{
	m_aresta_2 = aresta2;
}

void paralelepipedo::set_aresta3( double aresta3 )
{
	m_aresta_3 = aresta3;
}

void esfera::set_raio( double raio )
{
	m_raio = raio;
}

///////////////////////////////////////////////
//////////// 		Área

double piramide::area()
{
	return (m_base * m_base) + 2 * ((sqrt(pow((m_base/2),2) + pow((m_altura),2))) * m_base);
}

double cubo::area()
{
	return 6 * (m_arestas * m_arestas);
}

double paralelepipedo::area()
{
	return (2 * m_aresta_1 * m_aresta_2) + (2 * m_aresta_1 * m_aresta_3) + (2 * m_aresta_2 * m_aresta_3);
}

double esfera::area()
{
	return 4 * PI * m_raio * m_raio;
}

///////////////////////////////////////////////
//////////// 		Volume

double piramide::volume()
{
	return (m_base * m_base * m_altura) / 3;
}

double cubo::volume()
{
	return m_arestas * m_arestas * m_arestas;
}

double paralelepipedo::volume()
{
	return m_aresta_1 * m_aresta_2 * m_aresta_3;
}

double esfera::volume()
{
	return (4 * PI * (m_raio * m_raio * m_raio)) / 3;
}