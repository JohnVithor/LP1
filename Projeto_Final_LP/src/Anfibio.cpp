/**
 * @file Anfibio.hpp
 * @brief      Implementação da classe Anfibio do namespace PetFera, seus
 *             atributos e métodos
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       07/12/2017
 */

#include "Anfibio.hpp"

using namespace PetFera;

int Anfibio::get_total_mudas( void )
{
	return m_total_mudas;
}

std::string Anfibio::get_ultima_muda( void )
{
	return m_ultima_muda;
}

void Anfibio::set_total_mudas( int new_total )
{
	m_total_mudas = new_total;
}
void Anfibio::set_ultima_muda( std::string new_muda )
{
	m_ultima_muda = new_muda;
}

std::ostream& Anfibio::printAnimal( std::ostream & _os )
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
	_os << "Mudas:\t\t"  		<< this->get_total_mudas() << std::endl;
	_os << "Ultima Muda:\t"  		<< this->get_ultima_muda() << std::endl;
	_os << std::endl;

	return _os;
}