/**
* @file		main3.cpp
* @brief	Testes dos metodos da classe jv::lista e jv::lista_ordenada
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	22/10/2017
* @date		28/10/2017	
*/

#include <iostream>
#include <cassert> // assert
#include <initializer_list>
#include <vector>

#include "lista.hpp"
#include "lista_ordenada.hpp"

int main(int argc, char const *argv[])
{

	std::cout << "\t\t===== Iniciando Testes =====" << std::endl;
{
	std::cout << ">>> swap()" << std::endl;	

	jv::lista<double> trocar1 = {6, 7, 8.2, 9, 10};
	jv::lista<double> trocar2 = {1, 2.1, 3, 4, 5,6,6};

	std::cout << "Antes do swap: " << std::endl;	
	std::cout << "trocar1 :" << trocar1 << std::endl;
	std::cout << "trocar2 :" << trocar2 << std::endl;

	std::swap(trocar1,trocar2);

	std::cout << "Após o swap: "  << std::endl;	
	std::cout << "trocar1 :" << trocar1 << std::endl;
	std::cout << "trocar2 :" << trocar2 << std::endl << std::endl;	
}

	std::cout << ">>> Construtores vazios" << std::endl;

{
	jv::lista< int > list_int;

	std::cout << ">>> size()" << std::endl;
	assert( list_int.size() == 0 );
	
	std::cout << ">>> empty()" << std::endl;
	assert( list_int.empty() == true );
}

	std::cout << ">>> Construtor com capacidade inicial" << std::endl;

{	
	jv::lista< char > list_c(20);

	std::cout << ">>> size()" << std::endl;
	assert( list_c.size() == 20 );
}

	std::cout << ">>> Construtor por lista inicializadora" << std::endl;

{
	jv::lista< std::string > list_string {"Testando", "Lista", "Inicializadora"};

	std::cout << ">>> size()" << std::endl;
	assert( list_string.size() == 3 );
	
	std::cout << ">>> empty()" << std::endl;
	assert( list_string.empty() == false );

	std::cout << ">>> front()" << std::endl;
	assert (list_string.front() == "Testando");

	std::cout << ">>> at()" << std::endl;
	assert (list_string.at(1) == "Lista");

	std::cout << ">>> back()" << std::endl;
	assert (list_string.back() == "Inicializadora");

	std::cout << ">>> Construtor cópia" << std::endl;

	jv::lista< std::string > list_string_copy(list_string);

	std::cout << ">>> Operador igualdade ( == )" << std::endl;
	assert (list_string_copy == list_string);

	std::cout << ">>> Push_back()" << std::endl;

	list_string.push_back("Original");
	assert (list_string.back() == "Original");

	std::cout << ">>> Push_front" << std::endl;

	list_string_copy.push_front("Cópia");
	assert (list_string_copy.front() == "Cópia");

	std::cout << ">>> Operador diferença ( != )" << std::endl;
	assert (list_string_copy != list_string);
}
	std::cout << ">>> Construtor por intervalo" << std::endl;

{	
	std::cout << ">>> cbegin() e cend()" << std::endl;
	jv::lista< int > list_int {20, 30};
	jv::lista< int > interval_int(list_int.cbegin(), list_int.cend());

	assert (interval_int.at(0) == 20);
	assert (interval_int.at(1) == 30);

	std::cout << std::endl << ">>> Testes acima realizados com sucesso. Iniciando parte II" << std::endl << std::endl;

	std::cout << ">>> insert() - Parte I" << std::endl;
	std::cout << "Antes do insert: \t" << interval_int << std::endl;

	interval_int.insert( interval_int.begin(), 10);

	std::cout << "Após o insert: \t\t" << interval_int << std::endl;

	std::cout << ">>> insert() - Parte II" << std::endl;
	std::cout << "Antes do insert: \t" << interval_int << std::endl;

	interval_int.insert( 1, { 11 , 12 , 13 });

	std::cout << "Após o insert: \t\t" << interval_int << std::endl;
	
	std::cout << ">>> insert() - Parte III" << std::endl;
	std::cout << "Antes do insert: \t" << interval_int << std::endl;

	interval_int.insert( interval_int.begin()+3, interval_int.begin(), interval_int.end());

	std::cout << "Após o insert: \t\t" << interval_int << std::endl;

	std::cout << ">>> Operador de atribuição ( = )" << std::endl;
	
	std::cout << "Antes da atribuição:" << std::endl;
	std::cout << "list_int: \t\t" << list_int << std::endl;
	std::cout << "interval_int: \t\t" << interval_int << std::endl;
	
	list_int = interval_int;

	assert (list_int.at(3) == interval_int.at(3));
	assert (list_int.front() == interval_int.front());

	std::cout << "Após a atribuição:" << std::endl;
	std::cout << "list_int: \t\t" << list_int << std::endl;
	std::cout << "interval_int: \t\t" << interval_int << std::endl;
}

{

	jv::lista< char > list_char(27,'+');
	assert (list_char.size() == 27);
	std::cout << ">>> assign()" << std::endl;

	std::cout << "Antes do assign: \t" << list_char << std::endl;
	list_char.assign({'t','e','s','t','a','n','d','o','!'});
	std::cout << "Após o assign: \t\t" << list_char << std::endl;

	std::cout << ">>> erase()" << std::endl;

	std::cout << "Antes do erase: \t" << list_char << std::endl;
	list_char.erase(list_char.begin(), list_char.begin()+15);
	std::cout << "Após o erase: \t\t" << list_char << std::endl;

	std::cout << ">>> erase()" << std::endl;

	std::cout << "Antes do erase: \t" << list_char << std::endl;
	list_char.erase(list_char.begin()+2);
	std::cout << "Após o erase: \t\t" << list_char << std::endl;
}

{
	jv::lista<char> l_assign = {'a','b','c','d'};
	std::cout << ">>> assign()" << std::endl;

	std::cout << "Antes do assign: \t" << l_assign << std::endl;
	l_assign.assign('?');
	std::cout << "Após o assign: \t\t" << l_assign << std::endl;

	std::cout << ">>> clear()" << std::endl;
	std::cout << "Antes do clear: \t" << l_assign << std::endl;
	l_assign.clear();
	assert (l_assign.size() == 0);
	std::cout << "Após o clear: \t\t" << l_assign << std::endl;
}


{
	std::cout << std::endl << "Iniciando testes do Insert para a lista ordenada" << std::endl << std::endl;

	jv::lista_ordenada< int > list_ord = { 20, 65, 1, 48, 91, 4, -16, 78, 45, 45, -31, 7 };
	std::cout << "Lista ordenada inicial: \t" << list_ord << std::endl;
	list_ord.insert(100);
	std::cout << "Insert único (100): \t\t" << list_ord << std::endl;
	list_ord.insert(-100);
	std::cout << "Insert único (-100): \t\t" << list_ord << std::endl;
	std::initializer_list< int >ilist = { 3, 4, 49, 42, 12, -94, -62 };

	std::cout << "ilist a ser inserida: \t\t[ ";
	for (auto i = ilist.begin(); i != ilist.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "]" << std::endl;
	list_ord.insert( ilist );

	std::cout << "Insert com lista inicializadora:" << list_ord << std::endl;

	std::cout << "intervalo a ser inserido: \t[ ";
	for (auto i = list_ord.begin()+1; i != list_ord.begin()+4; ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << "]" << std::endl;
	
	list_ord.insert( list_ord.begin()+1, list_ord.begin()+4 );
	std::cout << "Insert com intervalo: \t\t" << list_ord << std::endl;

}

	return 0;
}