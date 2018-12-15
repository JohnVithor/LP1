/**
* @file		primalidade.cpp
* @brief	Implementação das funções relacionadas à primalidade
* @details	Implemantação das funções que testam se um número tem algum divisor ímpar
*			e que calculam qual o maior numero primo anterior a um determinado número
*
* @author	João Vítor Venceslau Coelho
* @since	10/08/2017
* @date		12/08/2017
* @sa		
*/

#include <math.h>

#include "primalidade.h"

/*
int eh_primo(const int n){
	if (n%2 == 0){
		return 0;
	}
	for (int i = 3; i < sqrt(n); i = i+2){
		if (n%i == 0){
			return 0;
		}
	}
	return 1;
}
*/

int eh_primo(long long int n, int i){
	if (i >= sqrt(n)){
	 	return 1;
	} 
	if (n % i == 0){
		return 0;
	} 
	return eh_primo(n,i+2);
}


long long int maior_primo_anterior(long long int valor){
	if (valor <= 2){
		return 0;
	}

	if ((valor-1)%2 != 0){ // Comparação apenas para eh_primo() na versão recursiva
		if (eh_primo(valor-1,3)){
			return valor-1;}
	}
	return maior_primo_anterior(valor-1);
}