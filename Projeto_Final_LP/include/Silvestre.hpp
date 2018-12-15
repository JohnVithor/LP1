/**
 * @file Silvestre.cpp
 * @brief      Declaração da classe AnimalSilvestre e suas subclasses
 *             Nativo e Exotico, seus atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef SILVESTRE_HPP
#define SILVESTRE_HPP

#include <string>

namespace PetFera
{

	/**
	 * @brief      Classe para animal silvestre.
	 */
	class AnimalSilvestre
	{
	protected:
		std::string m_ibama;

	public:

		/**
		 * @brief      Método get do atributo m_ibama.
		 *
		 * @return     m_ibama.
		 */
		std::string get_ibama( void );

		/**
		 * @brief      Construtor do AnimalSilvestre
		 *
		 * @param[in]  _ibama  - Variável do tipo string, que corresponde ao
		 *                     novo valor de m_ibama.
		 */
		AnimalSilvestre( std::string _ibama ) : m_ibama( _ibama )
		{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor de AnimalSilvestre.
		 */
		virtual ~AnimalSilvestre(){};
		
	};

	/**
	 * @brief      Classe para nativo.
	 */
	class Nativo : public AnimalSilvestre
	{
	protected:
		std::string m_uf_origem;
		std::string m_autorizacao;

	public:

		/**
		 * @brief      Método get do atributo m_uf_origem.
		 *
		 * @return     m_uf_origem.
		 */
		std::string get_uf_origem( void );

		/**
		 * @brief      Método get do atributo m_autorizacao.
		 *
		 * @return     m_autorizacao.
		 */
		std::string get_autorizacao( void );

		/**
		 * @brief      Método set do atributo m_autorizacao.
		 *
		 * @param[in]  new_autorizacao  - Variável do tipo string, que
		 *                              corresponde ao novo valor de
		 *                              m_autorizacao.
		 */
		void set_autorizacao( std::string new_autorizacao );

		/**
		 * @brief      Construtor do Nativo.
		 *
		 * @param[in]  _ibama        - Variável do tipo string, que corresponde
		 *                           ao id de ibama.
		 * @param[in]  _uf_origem    - Variável do tipo string, que corresponde
		 *                           ao estado de origem.
		 * @param[in]  _autorizacao  - Variável do tipo string, que corresponde
		 *                           a autorização.
		 */
		Nativo( std::string _ibama, std::string _uf_origem, std::string _autorizacao )
			: AnimalSilvestre( _ibama )
			, m_uf_origem( _uf_origem )
			, m_autorizacao( _autorizacao )
			{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor do Nativo.
		 */
		virtual ~Nativo(){};
		
	};

	/**
	 * @brief      Classe para exotico.
	 */
	class Exotico : public AnimalSilvestre
	{
	protected:
		std::string m_pais_origem;

	public:

		/**
		 * @brief      Método get do atributo m_pais_origem.
		 *
		 * @return     m_pais_origem.
		 */
		std::string get_pais_origem( void );

		/**
		 * @brief      Construtor para o Exotico
		 *
		 * @param[in]  _ibama        - Variável do tipo string, que corresponde
		 *                           ao id de ibama.
		 * @param[in]  _pais_origem  - Variável do tipo string, que corresponde
		 *                           ao pais de origem do animal.
		 */
		Exotico( std::string _ibama, std::string _pais_origem )
			: AnimalSilvestre( _ibama )
			, m_pais_origem( _pais_origem )
			{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor do Exotico.
		 */
		virtual ~Exotico(){};
		
	};
}

#endif