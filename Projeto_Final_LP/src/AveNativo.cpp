/**
 * @file AveNativo.hpp
 * @brief      Implementação dos métodos da classe AveNativo do namespace
 *             PetFera.
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      30/11/2017
 * @date       03/12/2017
 */

#include "AveNativo.hpp"

using namespace PetFera;

std::ostream& AveNativo::printAnimal( std::ostream & _os ){

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
	_os << "Ibama:\t\t"    	<< this->get_ibama() << std::endl;
	_os << "UF Origem:\t"    	<< this->get_uf_origem() << std::endl;
	_os << "Autorizacao:\t"    << this->get_autorizacao() << std::endl;
	_os << std::endl;
	
	return _os;
}