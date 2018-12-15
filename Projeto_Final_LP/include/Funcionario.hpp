/**
 * @file Funcionario.hpp
 * @brief      Declaração das classe Funcionario e suas subclasses
 *             Veterinario e Tratador, seus atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include <iostream>
#include <memory>
#include <string>

namespace PetFera
{
	/**
	 * @brief      Classe de Funcionario.
	 */
	class Funcionario
	{
	protected:
		int 		m_id;
		std::string m_funcao;
		std::string m_nome;
		std::string m_CPF;
		short 		m_idade;
		std::string	m_tipo_sangue;		// A / B / AB / O
		char 		m_fator_RH;			// + / -
		std::string m_especialidade;

	public:

		/**
		 * @brief      Construtor da classe Funcionario.
		 *
		 * @param[in]  _id             - Variável do tipo int, que corresponde
		 *                             ao ID do funcionario.
		 * @param[in]  _funcao         - Variável do tipo string, que
		 *                             corresponde a funcao que o funcionario
		 *                             exerce.
		 * @param[in]  _nome           - Variável do tipo string, que
		 *                             corresponde ao nome do funcionario.
		 * @param[in]  _CPF            - Variável do tipo string, que
		 *                             corresponde ao CPF do funcionario.
		 * @param[in]  _idade          - Variável do tipo short, que corresponde
		 *                             a idade do funcionario.
		 * @param[in]  _tipo_sangue    - Variável do tipo string, que
		 *                             corresponde ao tipo sanguineo do
		 *                             funcionario.
		 * @param[in]  _fator_RH       - Variável do tipo char, que corresponde
		 *                             ao fator RH do tipo sanguineo do
		 *                             funcionario.
		 * @param[in]  _especialidade  - Variável do tipo string, que
		 *                             corresponde a especialidade do
		 *                             funcionario.
		 */
		Funcionario( int _id, std::string _funcao, std::string _nome, std::string _CPF, short _idade,
					 std::string _tipo_sangue, char _fator_RH, std::string _especialidade )
			: m_id 				(_id)
			, m_funcao 			(_funcao)
			, m_nome 			(_nome) 
			, m_CPF 			(_CPF)
			, m_idade 			(_idade)
			, m_tipo_sangue 	(_tipo_sangue)
			, m_fator_RH 		(_fator_RH)
			, m_especialidade 	(_especialidade)
		{ /* Vazio */ }

		/**
		 * @brief      Destrutor da classe Funcionario.
		 */
		virtual ~Funcionario(){};
		
		/**
		 * @brief      Método get do atributo m_id.
		 *
		 * @return     m_id.
		 */
		int get_id ( void );
		
		/**
		 * @brief      Método get do atributo m_nome.
		 *
		 * @return     m_nome.
		 */
		std::string get_nome ( void );
		
		/**
		 * @brief      Método get do atributo m_funcao.
		 *
		 * @return     m_funcao.
		 */
		std::string get_funcao ( void );
		
		/**
		 * @brief      Método get do atributo m_CPF.
		 *
		 * @return     m_CPF.
		 */
		std::string get_CPF ( void );
		
		/**
		 * @brief      Método get do atributo m_idade.
		 *
		 * @return     m_idade.
		 */
		short get_idade ( void );
		
		/**
		 * @brief      Método get do atributo m_tipo_sangue.
		 *
		 * @return     m_tipo_sangue.
		 */
		std::string get_t_sangue ( void );
		
		/**
		 * @brief      Método get do atributo m_fator_RH.
		 *
		 * @return     m_fator_RH.
		 */
		char get_RH ( void );
		
		/**
		 * @brief      Método get do atributo m_especialidade.
		 *
		 * @return     m_especialidade.
		 */
		std::string get_espec ( void );

		/**
		 * @brief      Método set do atributo m_idade.
		 *
		 * @param[in]  _idade  - Variável do tipo short, que correponde a nova
		 *                     idade do funcionário.
		 */
		void set_idade ( short _idade );

		/**
		 * @brief      Método print auxiliar.
		 *
		 * @param      _os   - Variável do tipo ostream, que corresponde a saída
		 *                   padrão.
		 *
		 * @return     O ostream já formatado com os devidos dados.
		 */
		std::ostream& printFuncionario( std::ostream & _os );

		/**
		 * @brief      Sobrecarga do operador <<.
		 *
		 * @param      _os    o ostream alvo.
		 * @param      _func  O Funcionário alvo
		 *
		 * @return     O ostream já formatado com os devidos dados.
		 */
		inline friend std::ostream & operator << ( std::ostream & _os , Funcionario & _func ) 
		{
			_func.printFuncionario( _os );
			return _os;
		}
	};

	/**
	 * @brief      Classe de veterinario.
	 */
	class Veterinario : public Funcionario
	{
	public:

		/**
		 * @brief      Construtor da classe Veterinario.
		 *
		 * @param[in]  _id             - Variável do tipo int, que corresponde
		 *                             ao ID do veterinário.
		 * @param[in]  _funcao         - Variável do tipo string, que
		 *                             corresponde a funcao que o veterinário
		 *                             exerce.
		 * @param[in]  _nome           - Variável do tipo string, que
		 *                             corresponde ao nome do veterinário.
		 * @param[in]  _CPF            - Variável do tipo string, que
		 *                             corresponde ao CPF do veterinário.
		 * @param[in]  _idade          - Variável do tipo short, que corresponde
		 *                             a idade do veterinário.
		 * @param[in]  _tipo_sangue    - Variável do tipo string, que
		 *                             corresponde ao tipo sanguineo do
		 *                             veterinário.
		 * @param[in]  _fator_RH       - Variável do tipo char, que corresponde
		 *                             ao fator RH do tipo sanguineo do
		 *                             veterinário.
		 * @param[in]  _especialidade  - Variável do tipo string, que
		 *                             corresponde a especialidade do
		 *                             veterinário.
		 */
		Veterinario( int _id, std::string _funcao, std::string _nome, std::string _CPF, short _idade,
					 std::string _tipo_sangue, char _fator_RH, std::string _especialidade )
			: Funcionario( _id, _funcao, _nome, _CPF, _idade, _tipo_sangue, _fator_RH, _especialidade )
		{ /* Vazio */ }

		/**
		 * @brief      Destrutor da classe Veterinario.
		 */
		~Veterinario(){};
		
	};

	/**
	 * @brief      Classe de tratador.
	 */
	class Tratador : public Funcionario
	{
	public:

		/**
		 * @brief      Construtor da classe Tratador.
		 *
		 * @param[in]  _id             - Variável do tipo int, que corresponde
		 *                             ao ID do tratador.
		 * @param[in]  _funcao         - Variável do tipo string, que
		 *                             corresponde a funcao que o tratador
		 *                             exerce.
		 * @param[in]  _nome           - Variável do tipo string, que
		 *                             corresponde ao nome do tratador.
		 * @param[in]  _CPF            - Variável do tipo string, que
		 *                             corresponde ao CPF do tratador.
		 * @param[in]  _idade          - Variável do tipo short, que corresponde
		 *                             a idade do tratador.
		 * @param[in]  _tipo_sangue    - Variável do tipo string, que
		 *                             corresponde ao tipo sanguineo do
		 *                             tratador.
		 * @param[in]  _fator_RH       - Variável do tipo char, que corresponde
		 *                             ao fator RH do tipo sanguineo do
		 *                             tratador.
		 * @param[in]  _especialidade  - Variável do tipo string, que
		 *                             corresponde a especialidade do
		 *                             tratador.
		 */
		Tratador( int _id, std::string _funcao, std::string _nome, std::string _CPF, short _idade,
					 std::string _tipo_sangue, char _fator_RH, std::string _especialidade )
			: Funcionario( _id, _funcao, _nome, _CPF, _idade, _tipo_sangue, _fator_RH, _especialidade )
		{ /* Vazio */ }
			
		/**
		 * @brief      Destrutor da classe Tratador.
		 */
		~Tratador(){};
		
	};
}

#endif
