/**
 * @file MamiferoExotico.hpp
 * @brief      Declaração da classe MamiferoExotico do
 *             namespace PetFera, seus atributos e métodos.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef MAMIFERO_EXOTICO_HPP
#define MAMIFERO_EXOTICO_HPP

#include "Mamifero.hpp"
#include "Silvestre.hpp"
#include <sstream>
#include <vector>

using namespace PetFera;

namespace PetFera
{
	/**
	 * @brief      Class for mamifero exotico.
	 */
	class MamiferoExotico : public Mamifero , public Exotico
	{
	public:

		
		/**
		 * @brief      Construtor da classe MamiferoExotico.
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
		 * @param[in]  _cor_pelo     - Variável do tipo string, que corresponde
		 *                           a cor do pelo do animal.
		 * @param[in]  _ibama        - Variável do tipo string, que corresponde
		 *                           ao id do ibama associado ao animal.
		 * @param[in]  _pais_origem  - Variável do tipo string, que corresponde
		 *                           ao pais de origem do animal.
		 */
		MamiferoExotico( int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				std::string _cor_pelo, std::string _ibama, std::string _pais_origem )
			: Mamifero( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador
						, _batismo, _cor_pelo )
			, Exotico( _ibama, _pais_origem )
			{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da classe MamiferoExotico.
		 */
		~MamiferoExotico(){};

		/**
		 * @brief      Método print auxiliar.
		 *
		 * @param      _os   - Variável do tipo ostream, que corresponde a saída
		 *                   padrão.
		 *
		 * @return     O ostream já formatado com os devidos dados.
		 */
		virtual std::ostream& printAnimal( std::ostream & _os );
		
	};
}
#endif