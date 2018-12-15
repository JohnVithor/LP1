/**
* @file		print_elements.cpp
* @brief	Testes da função print_elements()
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/10/2017
* @date		31/10/2017	
*/

#include <set>
using std::set;

#include <list>
using std::list;

#include "print_elements.hpp"

int main(int argc, char const *argv[])
{
	set<int> numeros;
	numeros.insert(3);
	numeros.insert(1);
	numeros.insert(4);
	numeros.insert(1);
	numeros.insert(2);
	numeros.insert(5);
	print_elements(numeros, "Set: ");
	print_elements(numeros, "CSV Set: ", ';');

	list<char> caracteres = { 'a' , 'e' , 'i' , 'o' , 'u' };
	print_elements(caracteres, "List: ");
	print_elements(caracteres, "?? List: ", '-');
	return 0;
}