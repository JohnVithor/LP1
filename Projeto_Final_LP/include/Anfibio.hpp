/**
 * @file Anfibio.hpp
 * @brief      Declaração da classe Anfibio do namespace PetFera, seus atributos
 *             e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef ANFIBIO_HPP
#define ANFIBIO_HPP

#include "Animal.hpp"

using namespace PetFera;

namespace PetFera
{
	/**
	 * @brief      Classe de anfibio.
	 */
	class Anfibio : public Animal
	{
	protected:
		int 		m_total_mudas;
		std::string m_ultima_muda;

	public:

		/**
		 * @brief      Método get do atributo m_total_mudas.
		 *
		 * @return     O total de mudas.
		 */
		int get_total_mudas( void );
		
		/**
		 * @brief      Método get do atributo m_ultima_muda.
		 *
		 * @return     A data da ultima muda.
		 */
		std::string get_ultima_muda( void );

		/**
		 * @brief      Método set do atributo m_total_mudas.
		 *
		 * @param[in]  new_total  - Variável do tipo int, que corresponde ao
		 *                        novo total de mudas.
		 */
		void set_total_mudas( int new_total );
		
		/**
		 * @brief      Método set do atributo m_ultima_muda.
		 *
		 * @param[in]  new_muda  - Variável do tipo string, que corresponde a
		 *                       data da ultima muda.
		 */
		void set_ultima_muda( std::string new_muda );

		/**
		 * @brief      Construtor da classe Anfibio.
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
		 * @param[in]  _sexo         - Variável do tipo char, que corresponde ao
		 *                           sexo do animal.
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
		 * @param[in]  _total_mudas  - Variável do tipo int, que corresponde ao
		 *                           total de mudas do animal.
		 * @param[in]  _ultima_muda  - Variável do tipo string, que corresponde
		 *                           a data da ultima muda do animal.
		 */
		Anfibio( int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				int _total_mudas = 0, std::string _ultima_muda = "0" ) 
			: Animal( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador, _batismo )
			, m_total_mudas( _total_mudas ), m_ultima_muda( _ultima_muda )
		{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da Classe Anfibio.
		 */
		virtual ~Anfibio(){};

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
		 *             um Anfibio.
		 */
//		void printAnimal(void);

	};
}

#endif