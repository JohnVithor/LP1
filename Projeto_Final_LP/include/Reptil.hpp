/**
 * @file Reptil.hpp
 * @brief      Declaração da classe Reptil do namespace PetFera, seus atributos
 *             e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef REPTIL_HPP
#define REPTIL_HPP

#include "Animal.hpp"

using namespace PetFera;

namespace PetFera
{
	/**
	 * @brief      Classe de Reptil.
	 */
	class Reptil : public Animal
	{
	protected:
		bool 		m_venenoso;
		std::string m_tipo_veneno;

	public:

		/**
		 * @brief      Método que determina se o animal tem veneno.
		 *
		 * @return     True se for venenoso, ou False caso contrário.
		 */
		bool is_venenoso( void );

		/**
		 * @brief      Método get do atributo m_tipo_veneno.
		 *
		 * @return     m_tipo_veneno.
		 */
		std::string get_tipo_veneno( void );

		/**
		 * @brief      Construtor da classe Reptil.
		 *
		 * @param[in]  _id           - Variável do tipo int, que corresponde ao
		 *                           ID do animal.
		 * @param[in]  _classe       - Variável do tipo string, que corresponde
		 *                           a familia que o animal pertence.
		 * @param[in]  _tipo         - Variável do tipo string, que corresponde
		 *                           ao tipo do animal.
		 * @param[in]  _nome         - Variável do tipo string, que corresponde
		 *                           ao nome do animal.
		 * @param[in]  _cientifico   - Variável do tipo string, que corresponde
		 *                           ao nome cientifico do animal.
		 * @param[in]  _sexo         - Variável do tipo char, que corresponde
		 *                           ao sexo do animal.
		 * @param[in]  _tamanho      - Variável do tipo float, que corresponde
		 *                           ao tamanho do animal.
		 * @param[in]  _dieta        - Variável do tipo string, que corresponde
		 *                           a dieta do animal.
		 * @param[in]  _veterinario  - Variável do tipo apontador para
		 *                           funcionario, que corresponde ao veterinario
		 *                           que cuida do animal.
		 * @param[in]  _tratador     - Variável do tipo apontador para
		 *                           funcionario, que corresponde ao tratador
		 *                           que cuida do animal.
		 * @param[in]  _batismo      - Variável do tipo string, que corresponde
		 *                           ao nome de batismo do animal.
		 * @param[in]  _venenoso     - Variável do tipo bool, que diz se o
		 *                           animal é venenoso ou não.
		 * @param[in]  _tipo_veneno  - Variável do tipo string, que corresponde
		 *                           ao tipo de veneno do animal.
		 */
		Reptil( int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				bool _venenoso = false, std::string _tipo_veneno = "")
			: Animal( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, _batismo )
			, m_venenoso( _venenoso ), m_tipo_veneno( _tipo_veneno )
		{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da classe Reptil.
		 */
		virtual ~Reptil(){};
		
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
		 *             um Reptil.
		 */
//		void printAnimal(void);

	};
}

#endif