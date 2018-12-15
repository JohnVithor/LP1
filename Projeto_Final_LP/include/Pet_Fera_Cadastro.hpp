/**
 * @file Pet_Fera_Cadastro.cpp
 * @brief      Declaração da classe Pet_Fera_Cadastro, seus atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       09/12/2017
 */

#ifndef PET_FERA_HPP
#define PET_FERA_HPP

#include <fstream>
#include <map>
#include <vector>
#include <tuple>
#include <iostream>

#include "Pet_Fera_Exportar.hpp"
#include "Animal.hpp"
#include "Ave.hpp"
#include "Anfibio.hpp"
#include "Mamifero.hpp"
#include "Reptil.hpp"
#include "AnfibioExotico.hpp"
#include "AnfibioNativo.hpp"
#include "MamiferoExotico.hpp"
#include "MamiferoNativo.hpp"
#include "ReptilExotico.hpp"
#include "ReptilNativo.hpp"
#include "AveExotico.hpp"
#include "AveNativo.hpp"
#include "Excecoes.hpp"

/**
 * @brief      Classe que simula parte do cadastro de um pet shop.
 */
class Pet_Fera_Cadastro
{
protected:
	std::map< int, Anfibio* > m_tabela_anfibio;
	std::map< int, Mamifero* > m_tabela_mamifero;
	std::map< int, Reptil* > m_tabela_reptil;
	std::map< int, Ave* > m_tabela_ave;
	std::map< int, Funcionario* > m_tabela_funcionario;

public:

	/**
	 * @brief      Construtor padrão da classe Pet_Fera_Cadastro.
	 */
	Pet_Fera_Cadastro() { /* Vazio */ };

	/**
	 * @brief      Destrutor padrão da classe Pet_Fera_Cadastro.
	 */
	~Pet_Fera_Cadastro();

	/**
	 * @brief      Método que ser para cadastrar um anfibio.
	 *
	 * @param[in]  _classe  - Variável do tipo string, que corresponde a classe
	 *                      do animal.
	 * @param[in]  _tipo    - Variável do tipo string, que corresponde ao tipo
	 *                      do animal.
	 */
	void cadastrar_anfibio( std::string _classe, std::string _tipo );

	/**
	 * @brief      Método que ser para cadastrar um mamifero.
	 *
	 * @param[in]  _classe  - Variável do tipo string, que corresponde a classe
	 *                      do animal.
	 * @param[in]  _tipo    - Variável do tipo string, que corresponde ao tipo
	 *                      do animal.
	 */
	void cadastrar_mamifero( std::string _classe, std::string _tipo );
	
	/**
	 * @brief      Método que ser para cadastrar um reptil.
	 *
	 * @param[in]  _classe  - Variável do tipo string, que corresponde a classe
	 *                      do animal.
	 * @param[in]  _tipo    - Variável do tipo string, que corresponde ao tipo
	 *                      do animal.
	 */
	void cadastrar_reptil( std::string _classe, std::string _tipo );
	
	/**
	 * @brief      Método que serve para cadastrar uma ave.
	 *
	 * @param[in]  _classe  - Variável do tipo string, que corresponde a classe
	 *                      do animal.
	 * @param[in]  _tipo    - Variável do tipo string, que corresponde ao tipo
	 *                      do animal.
	 */
	void cadastrar_ave( std::string _classe, std::string _tipo );

	/**
	 * @brief      Método que serve para cadastrar um funcionário.
	 *
	 * @param[in]  _funcao  - Variável do tipo string, que corresponde a função
	 *                      que o funcionário exerce.
	 */
	void cadastrar_funcionario( std::string _funcao );

	/**
	 * @brief      Método que serve para consultar os dados dos animais
	 *             cadastrados.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do animal.
	 */
	void consultar_animais( int _id );
	
	/**
	 * @brief      Método que serve para consultar os dados dos animais
	 *             cadastrados, com base em um funcionário especifico.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do funcionário.
	 */
	void consultar_animais_funcionario( int _id );
	
	/**
	 * @brief      Método que serve para consultar os dados funcionários.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do funcionário.
	 */
	void consultar_funcionarios( int _id );

	/**
	 * @brief      Método que serve para remover um funcionário cadastrado.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do funcionário.
	 */
	void remover_funcionario( int _id );

	/**
	 * @brief      Método que serve para remover um animal cadastrado.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do animal.
	 */
	void remover_animal( int _id );

	/**
	 * @brief      Método que serve para alterar os dados de um animal
	 *             cadastrado.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do animal.
	 */
	void alterar_dados_animais( int _id );
	
	/**
	 * @brief      Método que serve para alterar os dados de um funcionário
	 *             cadastrado.
	 *
	 * @param[in]  _id   - Variável do tipo int, que corresponde a identificação
	 *                   do funcionário.
	 */
	void alterar_dados_funcionarios( int _id );
	
	/**
	 * @brief      Método que serve para importar os dados dos animais de um
	 *             arquivo csv.
	 *
	 * @param      dados_animais  - Variável do tipo ifstream, que corresponde a
	 *                            entrada para se obter os dados.
	 */
	void importar_dados_animais( std::ifstream& dados_animais );
	
	/**
	 * @brief      Método que serve para importar os dados dos funcionário de um
	 *             arquivo csv.
	 *
	 * @param      dados_funcionarios  - Variável do tipo ifstream, que
	 *                                 corresponde a entrada para se obter os
	 *                                 dados.
	 */
	void importar_dados_funcionarios( std::ifstream& dados_funcionarios );

	/**
	 * @brief      Método para converter um valor generico T em uma string.
	 *
	 * @param[in]  target  - Variável generica do tipo T, que corresponde ao
	 *                     valor a ser convertido.
	 *
	 * @tparam     T       - Tipo abstrato de dado.
	 *
	 * @return     Uma string.
	 */
	template < typename T >
	std::string to_string( T target );

	/**
	 * @brief      Método que serve para exportar os dados dos animais para um
	 *             arquivo csv.
	 *
	 * @param      dados_animais  - Variável do tipo ifstream, que corresponde a
	 *                            entrada para se obter os dados.
	 */
	void exportar_dados_animais( std::ofstream& dados_animais );
	
	/**
	 * @brief      Método que serve para exportar os dados dos funcionário para
	 *             um arquivo csv.
	 *
	 * @param      dados_funcionarios  - Variável do tipo ifstream, que
	 *                                 corresponde a entrada para se obter os
	 *                                 dados.
	 */
	void exportar_dados_funcionarios( std::ofstream& dados_funcionarios );

	/**
	 * @brief      Método que serve para calcular a quantidade de animais
	 *             cadastrados.
	 *
	 * @return     Quantidade de animais cadastrados.
	 */
	unsigned int quantidade_animais_cadastrados( void );
	
	/**
	 * @brief      Método que serve para calcular a quantidade de funcionarios
	 *             cadastrados.
	 *
	 * @return     Quantidade de funcionarios cadastrados.
	 */
	unsigned int quantidade_funcionarios_cadastrados( void );

};

#endif