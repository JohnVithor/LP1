/**
 * @file AnfibioExotico.hpp
 * @brief      Declaração da classe AnfibioExotico do
 *             namespace PetFera, seus atributos e métodos.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef ANFIBIO_EXOTICO_HPP
#define ANFIBIO_EXOTICO_HPP

#include "Anfibio.hpp"
#include "Silvestre.hpp"
#include <sstream>
#include <vector>

using namespace PetFera;

namespace PetFera
{
	/**
	 * @brief      Classe de anfibio exotico.
	 */
	class AnfibioExotico : public Anfibio , public Exotico
	{
	public:

		/**
		 * @brief      Construtor da classe AnfibioExotico.
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
		 * @param[in]  _ibama        - Variável do tipo string, que corresponde
		 *                           ao id do ibama associado ao animal.
		 * @param[in]  _pais_origem  - Variável do tipo string, que corresponde
		 *                           ao pais de origem do animal.
		 */
		AnfibioExotico( int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				int _total_mudas, std::string _ultima_muda, std::string _ibama, std::string _pais_origem )
			: Anfibio( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador
						, _batismo, _total_mudas, _ultima_muda )
			, Exotico( _ibama, _pais_origem )
			{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da classe AnfibioExotico.
		 */
		~AnfibioExotico(){};

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