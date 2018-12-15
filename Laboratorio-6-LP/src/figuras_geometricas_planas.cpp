/**
 * @file figuras_geometricas_planas.cpp
 * @brief      Implementação dos métodos da classes derivadas da classe
 *             fig_geometrica_plana
 * @details    
 *
 * @author     João Vítor Venceslau Coelho
 * @since      16/11/2017
 * @date       21/11/2017
 */

#include "figuras_geometricas.hpp"

#define PI 3.1415

using namespace geometria;

///////////////////////////////////////////////
//////////// 		Getters

double triangulo_equi::get_lados()
{
	return m_lados;
}

double retangulo::get_base()
{
	return m_base;
}

double retangulo::get_altura()
{
	return m_altura;
}

double quadrado::get_lados()
{
	return m_lados;
}

double circulo::get_raio()
{
	return m_raio;
}

///////////////////////////////////////////////
//////////// 		Setters

void triangulo_equi::set_lados( double lados )
{
	m_lados = lados;
}

void retangulo::set_base( double base )
{
	m_base = base;
}

void retangulo::set_altura( double altura )
{
	m_altura = altura;
}

void quadrado::set_lados( double lados )
{
	m_lados = lados;
}

void circulo::set_raio( double raio )
{
	m_raio = raio;
}

///////////////////////////////////////////////
//////////// 		Área

double triangulo_equi::area()
{
	return ((m_lados * m_lados) * sqrt(3)) / 4;
}

double retangulo::area()
{
	return m_base * m_altura;
}

double quadrado::area()
{
	return m_lados * m_lados;
}

double circulo::area()
{
	return PI * m_raio * m_raio;
}

///////////////////////////////////////////////
//////////// 		Perimetro

double triangulo_equi::perimetro()
{
	return 3 * m_lados;
}

double retangulo::perimetro()
{
	return 2 * (m_base + m_altura);
}

double quadrado::perimetro()
{
	return 4 * m_lados;
}

double circulo::perimetro()
{
	return 2 * PI * m_raio;
}