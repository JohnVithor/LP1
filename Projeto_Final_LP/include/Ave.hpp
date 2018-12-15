/**
 * @file Ave.hpp
 * @brief      Declaração da classe Ave do namespace PetFera, seus atributos
 *             e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef AVE_HPP
#define AVE_HPP

#include "Animal.hpp"

using namespace PetFera;

namespace PetFera
{
	/**
	 * @brief      Classe de ave.
	 */
	class Ave : public Animal
	{
	protected:
		float m_tamanho_bico;
		float m_envergadura;

	public:

		/**
		 * @brief      Método get do atributo m_tamanho_bico.
		 *
		 * @return     m_tamanho_bico.
		 */
		float get_tamanho_bico( void );

		/**
		 * @brief      Método get do atributo m_envergadura.
		 *
		 * @return     m_envergadura.
		 */
		float get_envergadura( void );

		/**
		 * @brief      Método set do atributo m_tamanho_bico.
		 *
		 * @param[in]  new_tamanho_bico  - Variável do tipo float, que
		 *                               corresponde ao novo tamanho do bico.
		 */
		void set_tamanho_bico( float new_tamanho_bico );

		/**
		 * @brief      Método set do atributo m_envergadura.
		 *
		 * @param[in]  new_envergadura  - Variável do tipo float, que
		 *                              corresponde a nova envergadura.
		 */
		void set_envergadura( float new_envergadura );

		/**
		 * @brief      Construtor da classe AveExotico.
		 *
		 * @param[in]  _id            - Variável do tipo int, que corresponde ao
		 *                            ID do animal.
		 * @param[in]  _classe        - Variável do tipo string, que corresponde
		 *                            a familia que o animal pertence.
		 * @param[in]  _tipo          - Variável do tipo string, que corresponde
		 *                            ao tipo do animal.
		 * @param[in]  _nome          - Variável do tipo string, que corresponde
		 *                            ao nome do animal.
		 * @param[in]  _cientifico    - Variável do tipo string, que corresponde
		 *                            ao nome cientifico do animal.
		 * @param[in]  _sexo          - Variável do tipo char, que corresponde
		 *                            ao sexo do animal.
		 * @param[in]  _tamanho       - Variável do tipo float, que corresponde
		 *                            ao tamanho do animal.
		 * @param[in]  _dieta         - Variável do tipo string, que corresponde
		 *                            a dieta do animal.
		 * @param[in]  _veterinario   - Variável do tipo apontador para
		 *                            funcionario, que corresponde ao
		 *                            veterinario que cuida do animal.
		 * @param[in]  _tratador      - Variável do tipo apontador para
		 *                            funcionario, que corresponde ao tratador
		 *                            que cuida do animal.
		 * @param[in]  _batismo       - Variável do tipo string, que corresponde
		 *                            ao nome de batismo do animal.
		 * @param[in]  _tamanho_bico  - Variável do tipo float, que corresponde
		 *                            ao tamanho do bico do animal.
		 * @param[in]  _envergadura   - Variável do tipo float, que corresponde
		 *                            a envergadura do animal.
		 */
		Ave( int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				float _tamanho_bico, float _envergadura ) 
			: Animal( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, _batismo )
			, m_tamanho_bico( _tamanho_bico ), m_envergadura( _envergadura )
		{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da classe Ave..
		 */
		virtual ~Ave(){};
		
		/**
		 * @brief      Método print auxiliar.
		 *
		 * @param      _os   - Variável do tipo ostream, que corresponde a saída
		 *                   padrão.
		 *
		 * @return     O ostream já formatado com os devidos dados.
		 */
		virtual std::ostream& printAnimal( std::ostream & _os );

		/**
		 * @brief      Método printAnimal, que serve para imprimir os dados de
		 *             uma Ave.
		 */
//		void printAnimal(void);
	};
}

#endif