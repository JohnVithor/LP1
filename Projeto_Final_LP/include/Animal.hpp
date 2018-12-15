/**
 * @file Animal.hpp
 * @brief      Declaração da classe Animal do namespace PetFera, seus atributos
 *             e métodos.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Funcionario.hpp"

#include <memory>

#include <string>

typedef PetFera::Funcionario* F_pointer;

namespace PetFera
{
	/**
	 * @brief      Classe de Animal.
	 */
	class Animal
	{
	protected:

		int 		m_id;
		std::string m_classe;
		std::string m_tipo;
		std::string m_nome;
		std::string m_cientifico;
		char 		m_sexo;
		float 		m_tamanho;
		std::string m_dieta;
		F_pointer 	m_veterinario;
		F_pointer	m_tratador;
		std::string m_batismo;

	public:

		/**
		 * @brief      Construtor da classe Animal.
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
		 */
		Animal(	int _id, std::string _classe, std::string _tipo, std::string _nome, std::string _cientifico, char _sexo, 
				float _tamanho, std::string _dieta, F_pointer _veterinario, F_pointer _tratador, std::string _batismo )
			: m_id( _id )
			, m_classe( _classe )
			, m_tipo( _tipo )
			, m_nome( _nome )
			, m_cientifico( _cientifico )
			, m_sexo( _sexo )
			, m_tamanho( _tamanho )
			, m_dieta( _dieta )
			, m_veterinario( _veterinario )
			, m_tratador( _tratador )
			, m_batismo( _batismo )
		{ /* Vazio */ }

		/**
		 * @brief      Destrutor da Classe Animal.
		 */
		virtual ~Animal(){};

		/**
		 * @brief      Método get para o atributo m_id.
		 *
		 * @return     O id.
		 */
		int 		get_id( void );
		
		/**
		 * @brief      Método get para o atributo m_classe.
		 *
		 * @return     A classe.
		 */
		std::string get_classe( void );
		
		/**
		 * @brief      Método get para o atributo m_tipo.
		 *
		 * @return     O tipo.
		 */
		std::string get_tipo( void );
		
		/**
		 * @brief      Método get para o atributo m_nome.
		 *
		 * @return     O nome.
		 */
		std::string get_nome( void );
		
		/**
		 * @brief      Método get para o atributo m_cientifico.
		 *
		 * @return     O nome cientifico.
		 */
		std::string get_cientifico( void );
		
		/**
		 * @brief      Método get para o atributo m_sexo.
		 *
		 * @return     O sexo.
		 */
		char 		get_sexo( void );
		
		/**
		 * @brief      Método get para o atributo m_tamanho.
		 *
		 * @return     O tamanho.
		 */
		float 		get_tamanho( void );
		
		/**
		 * @brief      Método get para o atributo m_dieta.
		 *
		 * @return     A dieta.
		 */
		std::string get_dieta( void );
		
		/**
		 * @brief      Método get para o atributo m_veterinario.
		 *
		 * @return     O veterinario associado.
		 */
		F_pointer	get_veterinario( void );
		
		/**
		 * @brief      Método get para o atributo m_tratador.
		 *
		 * @return     O tratador associado.
		 */
		F_pointer 	get_tratador( void );
		
		/**
		 * @brief      Método get para o atributo m_batismo.
		 *
		 * @return     O nome de batismo.
		 */
		std::string get_batismo( void );

		/**
		 * @brief      Método para alterar o nome.
		 *
		 * @param[in]  new_nome  - Variável do tipo string, que corresponde ao
		 *                       novo nome.
		 */
		void set_nome( std::string new_nome );
		
		/**
		 * @brief      Método para alterar o tamanho.
		 *
		 * @param[in]  new_tamanho  - Variável do tipo string, que corresponde
		 *                          ao novo tamanho.
		 */
		void set_tamanho( float new_tamanho );
		
		/**
		 * @brief      Método para alterar a dieta.
		 *
		 * @param[in]  new_dieta  - Variável do tipo string, que corresponde a
		 *                        nova dieta.
		 */
		void set_dieta( std::string new_dieta );
		
		/**
		 * @brief      Método para alterar o veterinario.
		 *
		 * @param[in]  new_veterinario  - Variável do tipo string, que
		 *                              corresponde ao novo veterinario.
		 */
		void set_veterinario( F_pointer new_veterinario );
		
		/**
		 * @brief      Método para alterar o tratador.
		 *
		 * @param[in]  new_tratador  - Variável do tipo string, que corresponde
		 *                           ao novo tratador.
		 */
		void set_tratador( F_pointer new_tratador );

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
		 * @brief      Sobrecarga do operador <<.
		 *
		 * @param      _os      o ostream alvo.
		 * @param      _animal  O animal alvo
		 *
		 * @return     O ostream já formatado com os devidos dados.
		 */
		inline friend std::ostream & operator << ( std::ostream & _os , Animal & _animal ) 
		{
			_animal.printAnimal( _os );
			return _os;
		}

	};

}
#endif