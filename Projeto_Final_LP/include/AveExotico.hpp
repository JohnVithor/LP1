/**
 * @file AveExotico.hpp
 * @brief      Declaração da classe AveExotico do
 *             namespace PetFera, seus atributos e métodos.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef AVE_EXOTICO_HPP
#define AVE_EXOTICO_HPP

#include "Ave.hpp"
#include "Silvestre.hpp"
#include <sstream>
#include <vector>

using namespace PetFera;

namespace PetFera
{
	/**
	 * @brief      Classe de ave exotico.
	 */
	class AveExotico : public Ave , public Exotico
	{
	public:

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
		 * @param[in]  _ibama         - Variável do tipo string, que corresponde
		 *                            ao id do ibama associado ao animal.
		 * @param[in]  _pais_origem   - Variável do tipo string, que corresponde
		 *                            ao pais de origem do animal.
		 */
		AveExotico(int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				float _tamanho_bico, float _envergadura, std::string _ibama, std::string _pais_origem )
			: Ave( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador,
					_batismo, _tamanho_bico, _envergadura )
			, Exotico( _ibama, _pais_origem )
			{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da classe AveExotico.
		 */
		~AveExotico(){};

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