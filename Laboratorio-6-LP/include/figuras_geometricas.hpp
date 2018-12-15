/**
 * @file figuras_geometricas.hpp
 * @brief      Declaração da classes fig_geometricas e suas subclasses
 * @details    
 *
 * @author     João Vítor Venceslau Coelho
 * @since      16/11/2017
 * @date       21/11/2017
 */

#ifndef FIGURAS_GEOMETRICAS_H
#define FIGURAS_GEOMETRICAS_H

#include <cmath>

namespace geometria
{
	/**
	 * @brief      Classe para Figuras Geométricas
	 */
	class fig_geometrica
	{
	public:

		/**
		 * @brief      Construtor Padrão da classe fig_geometrica
		 */
		fig_geometrica() { /* Vazio */ };

		/**
		 * @brief      Método que calcula a área da Figura Geométricas
		 *
		 * @return     Double que representa a área da Figura Geométricas
		 */
		virtual double area() = 0;
	};

	/**
	 * @brief      Classe para Figuras Geometricas Planas
	 */
	class fig_geometrica_plana :  public fig_geometrica
	{
	public:

		/**
		 * @brief      Construtor Padrão da classe fig_geometrica_plana
		 */
		fig_geometrica_plana() { /* Vazio */ };

		/**
		 * @brief      Método que calcula o perímetro da Figura Geométricas Plana
		 *
		 * @return     Double que representa o perímetro da Figura Geométricas Plana
		 */
		virtual double perimetro() = 0;
	};

	/**
	 * @brief      Classe para Figuras Geometricas Espaciais
	 */
	class fig_geometrica_espacial :  public fig_geometrica
	{
	public:

		/**
		 * @brief      Construtor Padrão da classe fig_geometrica_espacial
		 */
		fig_geometrica_espacial() { /* Vazio */ };

		/**
		 * @brief      Método que calcula o volume da Figura Geométricas Espacial
		 *
		 * @return     Double que representa o volume da Figura Geométricas Espacial
		 */
		virtual double volume() = 0;
	};

	///////////////////////////////////////////////////////
	//////////===Figuras Geométricas Planas===/////////////
	///////////////////////////////////////////////////////

	/**
	 * @brief       Classe que representa um Triângulo Equilátero
	 */
	class triangulo_equi : public fig_geometrica_plana
	{

	private:

		double m_lados;

	public:

		/**
		 * @brief      Construtor Padrão da classe triangulo_equi
		 *
		 * @param[in]  lados  A medida dos três lados do triângulo equilátero
		 */
		triangulo_equi( double lados = 0 ) : m_lados( lados ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida dos três lados do triângulo equilátero
		 *
		 * @return     Double que representamedida dos três lados do triângulo equilátero
		 */
		double get_lados();
		
		/**
		 * @brief      Altera a medida dos três lados do triângulo equilátero
		 *
		 * @param[in]  lados  Nova medida dos três lados do triângulo equilátero
		 */
		void set_lados( double lados );

		/**
		 * @brief      Método que calcula a área do Triângulo Equilátero
		 *
		 * @return     Double que representa a área do Triângulo Equilátero
		 */
		double area();

		/**
		 * @brief      Método que calcula o perímetro do Triângulo Equilátero
		 *
		 * @return     Double que representa o perímetro do Triângulo Equilátero
		 */
		double perimetro();
	};

	/**
	 * @brief       Classe que representa um Retângulo
	 */
	class retangulo : public fig_geometrica_plana
	{
	protected:

		double m_base;

		double m_altura;

	public:

		/**
		 * @brief      Construtor Padrão da classe retangulo
		 *
		 * @param[in]  base    A medida da base do Retângulo
		 * @param[in]  altura  A medida da altura do Retângulo
		 */
		retangulo( double base = 0, double altura = 0 ) : m_base( base ), m_altura( altura ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida da base do Retângulo
		 *
		 * @return     Double que representa a medida da base do Retângulo
		 */
		double get_base();
		
		/**
		 * @brief      Altera a medida da base do Retângulo
		 *
		 * @param[in]  base  Nova medida da base do Retângulo
		 */
		void set_base( double base );

		/**
		 * @brief      Retorna a medida da altura do Retângulo
		 *
		 * @return     Double que representa a medida da altura do Retângulo
		 */
		double get_altura();
		
		/**
		 * @brief      Altera a medida da altura do Retângulo
		 *
		 * @param[in]  altura  Nova medida da altura do Retângulo
		 */
		void set_altura( double altura );

		/**
		 * @brief      Método que calcula a área do Retângulo
		 *
		 * @return     Double que representa a área do Retângulo
		 */
		double area();

		/**
		 * @brief      Método que calcula o perímetro do Retângulo
		 *
		 * @return     Double que representa o perímetro do Retângulo
		 */
		double perimetro();
	};

	/**
	 * @brief      Classe que representa um Quadrado.
	 */
	class quadrado : public fig_geometrica_plana
	{
	protected:

		double m_lados;

	public:

		/**
		 * @brief      Construtor Padrão da classe quadrado
		 *
		 * @param[in]  lados  A medida dos quatro lados do Quadrado
		 */
		quadrado( double lados ) : m_lados( lados ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida dos quatro lados do Quadrado
		 *
		 * @return     Double que representa a medida dos quatro lados do Quadrado
		 */
		double get_lados();
		
		/**
		 * @brief      Altera a medida dos quatro lados do Quadrado
		 *
		 * @param[in]  lados  Nova medida dos quatro lados do Quadrado
		 */
		void set_lados( double lados );

		/**
		 * @brief      Método que calcula a área do Quadrado
		 *
		 * @return     Double que representa a área do Quadrado
		 */
		double area();

		/**
		 * @brief      Método que calcula o perímetro do Quadrado
		 *
		 * @return     Double que representa o perímetro do Quadrado
		 */
		double perimetro();
	};

	/**
	 * @brief      Classe que representa um Círculo.
	 */
	class circulo : public fig_geometrica_plana
	{
	protected:

		double m_raio;

	public:

		/**
		 * @brief      Construtor Padrão da classe circulo
		 *
		 * @param[in]  raio  A medida que representa o raio do Círculo
		 */
		circulo( double raio ) : m_raio( raio ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida que representa o raio do Círculo
		 *
		 * @return     Double que representa a medida do raio do Círculo
		 */
		double get_raio();
		
		/**
		 * @brief      Altera a medida que representa o raio do Círculo
		 *
		 * @param[in]  raio  Nova medida que representa o raio do Círculo
		 */
		void set_raio( double raio );

		/**
		 * @brief      Método que calcula a área do Círculo
		 *
		 * @return     Double que representa a área do Círculo
		 */
		double area();

		/**
		 * @brief      Método que calcula o perímetro do Círculo
		 *
		 * @return     Double que representa o perímetro do Círculo
		 */
		double perimetro();
	};


	///////////////////////////////////////////////////////
	/////////===Figuras Geométricas Espaciais===///////////
	///////////////////////////////////////////////////////

	/**
	 * @brief      Classe que representa uma Pirâmide.
	 */
	class piramide : public fig_geometrica_espacial
	{
	protected:

		double m_base;

		double m_altura;

	public:

		/**
		 * @brief      Construtor Padrão da classe piramide
		 *
		 * @param[in]  base    A medida que representa a base da Pirâmide
		 * @param[in]  altura  A medida que representa a altura da Pirâmide
		 */
		piramide( double base, double altura ) : m_base( base ), m_altura( altura ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida da base da Pirâmide
		 *
		 * @return     Double que representa a medida da base da Pirâmide
		 */
		double get_base();
		
		/**
		 * @brief      Altera a medida da base da Pirâmide
		 *
		 * @param[in]  base  Nova medida da base da Pirâmide
		 */
		void set_base( double base );

		/**
		 * @brief      Retorna a medida da altura da Pirâmide
		 *
		 * @return     Double que representa a medida da altura da Pirâmide
		 */
		double get_altura();
		
		/**
		 * @brief      Altera a medida da altura da Pirâmide
		 *
		 * @param[in]  altura  Nova medida da altura da Pirâmide
		 */
		void set_altura( double altura );

		/**
		 * @brief      Método que calcula a área da Pirâmide
		 *
		 * @return     Double que representa a área da Pirâmide
		 */
		double area();

		/**
		 * @brief      Método que calcula o volume da Pirâmide
		 *
		 * @return     Double que representa o volume da Pirâmide
		 */
		double volume();
	};

	/**
	 * @brief      Classe que representa um Cubo.
	 */
	class cubo : public fig_geometrica_espacial
	{
	protected:

		double m_arestas;

	public:

		/**
		 * @brief      Construtor Padrão da classe cubo
		 *
		 * @param[in]  arestas  A medida que representa as arestas do Cubo
		 */
		cubo( double arestas ) : m_arestas( arestas ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida que representa as arestas do Cubo
		 *
		 * @return     Double que representa a medida das arestas do Cubo
		 */
		double get_arestas();
		
		/**
		 * @brief      Altera a medida que representa as arestas do Cubo
		 *
		 * @param[in]  arestas  Nova medida que representa as arestas do Cubo
		 */
		void set_arestas( double arestas );

		/**
		 * @brief      Método que calcula a área do Cubo
		 *
		 * @return     Double que representa a área do Cubo
		 */
		double area();

		/**
		 * @brief      Método que calcula o volume do Cubo
		 *
		 * @return     Double que representa o volume do Cubo
		 */
		double volume();
	};

	/**
	 * @brief      Classe que representa um Paralelepipedo.
	 */
	class paralelepipedo : public fig_geometrica_espacial
	{
	protected:

		double m_aresta_1;

		double m_aresta_2;

		double m_aresta_3;

	public:

		/**
		 * @brief      Construtor Padrão da classe paralelepipedo
		 *
		 * @param[in]  aresta_1  A medida que representa a aresta do comprimento do Paralelepipedo
		 * @param[in]  aresta_2  A medida que representa a aresta da altura do Paralelepipedo
		 * @param[in]  aresta_3  A medida que representa a aresta da largura do Paralelepipedo
		 */
		paralelepipedo( double aresta_1, double aresta_2, double aresta_3 )
			: m_aresta_1( aresta_1 ), m_aresta_2( aresta_2 ), m_aresta_3( aresta_3 ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida que representa a aresta 1 do Paralelepipedo
		 *
		 * @return     Double que representa a medida da aresta 1 do Paralelepipedo
		 */
		double get_aresta1();
		
		/**
		 * @brief      Altera a medida que representa a aresta 1 do Paralelepipedo
		 *
		 * @param[in]  aresta1  Nova medida que representa a aresta 1 do Paralelepipedo
		 */
		void set_aresta1( double aresta1 );

		/**
		 * @brief      Retorna a medida que representa a aresta 2 do Paralelepipedo
		 *
		 * @return     Double que representa a medida da aresta 2 do Paralelepipedo
		 */
		double get_aresta2();
		
		/**
		 * @brief      Altera a medida que representa a aresta 2 do Paralelepipedo
		 *
		 * @param[in]  aresta2  Nova medida que representa a aresta 2 do Paralelepipedo
		 */
		void set_aresta2( double aresta2 );

		/**
		 * @brief      Retorna a medida que representa a aresta 3 do Paralelepipedo
		 *
		 * @return     Double que representa a medida da aresta 3 do Paralelepipedo
		 */
		double get_aresta3();
		
		/**
		 * @brief      Altera a medida que representa a aresta 3 do Paralelepipedo
		 *
		 * @param[in]  aresta3  Nova medida que representa a aresta 3 do Paralelepipedo
		 */
		void set_aresta3( double aresta3 );

		/**
		 * @brief      Método que calcula a área do Paralelepipedo
		 *
		 * @return     Double que representa a área do Paralelepipedo
		 */
		double area();

		/**
		 * @brief      Método que calcula o volume do Paralelepipedo
		 *
		 * @return     Double que representa o volume do Paralelepipedo
		 */
		double volume();
	};

	/**
	 * @brief      Classe que representa uma Esfera.
	 */
	class esfera : public fig_geometrica_espacial
	{
	protected:

		double m_raio;

	public:

		/**
		 * @brief      Construtor Padrão da classe esfera
		 *
		 * @param[in]  raio  A medida que representa o raio da Esfera
		 */
		esfera( double raio ) : m_raio( raio ) { /* Vazio */ };

		/**
		 * @brief      Retorna a medida que representa o raio da Esfera
		 *
		 * @return     Double que representa a medida do raio da Esfera
		 */
		double get_raio();
		
		/**
		 * @brief      Altera a medida que representa o raio da Esfera
		 *
		 * @param[in]  lados  Nova medida que representa o raio da Esfera
		 */
		void set_raio( double lados );

		/**
		 * @brief      Método que calcula a área da Esfera
		 *
		 * @return     Double que representa a área da Esfera
		 */
		double area();

		/**
		 * @brief      Método que calcula o volume da Esfera
		 *
		 * @return     Double que representa o volume da Esfera
		 */
		double volume();
	};
}

#endif