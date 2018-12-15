/**
 * @file Silvestre.cpp
 * @brief      Implementação da classe AnimalSilvestre e suas subclasses
 *             Nativo e Exotico, seus atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       02/12/2017
 */

#include "Silvestre.hpp"

using namespace PetFera;

std::string AnimalSilvestre::get_ibama( void )
{
	return m_ibama;
}

std::string Nativo::get_uf_origem( void )
{
	return m_uf_origem;
}

std::string Nativo::get_autorizacao( void )
{
	return m_autorizacao;
}

std::string Exotico::get_pais_origem( void )
{
	return m_pais_origem;
}
