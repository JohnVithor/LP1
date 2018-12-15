/**
 * @file Mamifero.hpp
 * @brief      Implementação da classe Mamifero do namespace PetFera, seus
 *             atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       07/12/2017
 */

#include "Mamifero.hpp"

#include <iostream>
using namespace PetFera;

std::string Mamifero::get_cor_pelo( void )
{
	return m_cor_pelo;
}
/*
std::string Mamifero::set_cor_pelo( std::string new_cor )
{
	m_cor_pelo = new_cor;
}
*/
std::ostream& Mamifero::printAnimal( std::ostream & _os )
{
	_os << std::endl;
	_os << ">>>>> Ficha do animal <<<<<" << std::endl;
	_os << "ID:\t\t"			<< this->get_id() << std::endl;
	_os << "Classe:\t\t"		<< this->get_classe() << std::endl;
	_os << "Nome:\t\t"			<< this->get_nome() << std::endl;
	_os << "Cientifico:\t"		<< this->get_cientifico() << std::endl;
	_os << "Batismo:\t"		<< this->get_batismo() << std::endl;
	_os << "Dieta:\t\t"		<< this->get_dieta() << std::endl;
	_os << "Sexo:\t\t"    		<< this->get_sexo() << std::endl;
	_os << "Veterinario:\t"  	<< (this->get_veterinario()!=nullptr?this->get_veterinario()->get_nome():"") << std::endl;
	_os << "Tratador:\t"  		<< (this->get_tratador()!=nullptr?this->get_tratador()->get_nome():"") << std::endl;
	_os << "Cor do pelo:\t"	<< this->get_cor_pelo() << std::endl;
	_os << std::endl;

	return _os;
}
