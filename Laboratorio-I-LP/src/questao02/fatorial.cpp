/**
* @file		fatorial.cpp
* @brief	Implementação da função que calcula o fatorial de um número
* @details	
*
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/


#include "fatorial.h"

long long int fatorial(int n){
	/* Calcula recursivamente o fatorial de n */
	if (n == 0 || n == 1){
		return 1;
	}
	return n*fatorial(n-1);
}