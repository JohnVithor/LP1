/**
 * @file AnfibioExotico.hpp
 * @brief      Implementação dos métodos da classe AnfibioExotico do namespace
 *             PetFera.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       03/12/2017
 */

#include "AnfibioExotico.hpp"

using namespace PetFera;

std::ostream& AnfibioExotico::printAnimal( std::ostream & _os ){

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
	_os << "Ibama:\t\t"    	<< this->get_ibama() << std::endl;
	_os << "País Origem:\t"    << this->get_pais_origem() << std::endl;
	_os << std::endl;
	
	return _os;
}