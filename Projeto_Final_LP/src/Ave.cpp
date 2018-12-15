/**
 * @file Ave.hpp
 * @brief      Implementação da classe Ave do namespace PetFera, seus
 *             atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       07/12/2017
 */

#include "Ave.hpp"

#include <iostream>
using namespace PetFera;

float Ave::get_tamanho_bico( void )
{
	return m_tamanho_bico;
}
float Ave::get_envergadura( void )
{
	return m_envergadura;
}

void Ave::set_tamanho_bico( float new_tamanho_bico )
{
	m_tamanho_bico = new_tamanho_bico;
}

void Ave::set_envergadura( float new_envergadura )
{
	m_envergadura = new_envergadura;
}

std::ostream& Ave::printAnimal( std::ostream & _os )
{
	_os << std::endl;
	_os << ">>>>> Ficha do animal <<<<<" << std::endl;
	_os << "ID:\t\t"     		<< this->get_id() << std::endl;
	_os << "Classe:\t\t"   	<< this->get_classe() << std::endl;
	_os << "Nome:\t\t"     	<< this->get_nome() << std::endl;
	_os << "Cientifico:\t"  	<< this->get_cientifico() << std::endl;
	_os << "Batismo:\t"    	<< this->get_batismo() << std::endl;
	_os << "Dieta:\t\t"    	<< this->get_dieta() << std::endl;
	_os << "Sexo:\t\t"    		<< this->get_sexo() << std::endl;
	_os << "Veterinario:\t"  	<< (this->get_veterinario()!=nullptr?this->get_veterinario()->get_nome():"") << std::endl;
	_os << "Tratador:\t"  		<< (this->get_tratador()!=nullptr?this->get_tratador()->get_nome():"") << std::endl;
	_os << "Bico:\t\t"  		<< this->get_tamanho_bico() << std::endl;
	_os << "Envergadura:\t"  	<< this->get_envergadura() << std::endl;
	_os << std::endl;

	return _os;
}