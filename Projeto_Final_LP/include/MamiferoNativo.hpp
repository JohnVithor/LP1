/**
 * @file MamiferoNativo.hpp
 * @brief      Declaração da classe MamiferoNativo do
 *             namespace PetFera, seus atributos e métodos.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef MAMIFERO_NATIVO_HPP
#define MAMIFERO_NATIVO_HPP

#include "Mamifero.hpp"
#include "Silvestre.hpp"
#include <sstream>
#include <vector>

using namespace PetFera;

namespace PetFera
{

	/**
	 * @brief      Classe de Mamifero Nativo.
	 */
	class MamiferoNativo : public Mamifero , public Nativo
	{
	public:

		/**
		 * @brief      Construtor da classe MamiferoNativo.
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
		 * @param[in]  _uf_origem    - Variável do tipo string, que corresponde
		 *                           ao Estado de origem do animal.
		 * @param[in]  _autorizacao  - Variável do tipo string, que corresponde
		 *                           a autorização fornecida pelo ibama para a
		 *                           comercialização do animal.
		 */
		MamiferoNativo( int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo,
				std::string _cor_pelo, std::string _ibama, std::string _uf_origem, std::string _autorizacao )
			: Mamifero( _id, _classe, _tipo, _nome, _cientifico, _sexo, _tamanho, _dieta, _veterinario, _tratador
						, _batismo, _cor_pelo )
			, Nativo( _ibama, _uf_origem, _autorizacao )
			{	/*	Vazio	*/	}

		/**
		 * @brief      Destrutor da classe MamiferoNativo.
		 */
		~MamiferoNativo(){};

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