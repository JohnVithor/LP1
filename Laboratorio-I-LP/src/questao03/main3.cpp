/**
* @file		main3.cpp
* @brief	Programa para treinar o uso do depurador GDB
* @details	
*
*
* @author	???
* @since	???
* @date		10/08/2017
* @sa		
*/

#include <iostream>


/**
* @brief Função que realiza a soma de dois números cujos valores são previamente incrementados em 1.
* @param[in] a Primeiro número
* @param[in] b Segundo número
* @return Soma de (a + 1) + (b + 1)
*/
int funcX (int a, int b)
{
	++a;
	b++;
	int result = a + b;
	return result;
}

/**
* @brief Função que realiza a soma de dois números cujo valor do primeiro é previamente multiplicado em 5
* @param[in] a Ponteiro para o primeiro número
* @param[in] b Segundo número
* @return Soma de 5*(*a) + b
*/
int funcY (int* a, int b)
{
	int* y = new int;

	(*y) = (*a);
	(*y) *= 5;
	int result = (*y) + b;
	return result;
}

/**
* @brief 				Função que realiza a soma de dois números após algumas manipulações e atribui o resultado a um terceiro numero
* @details 				Valor de a é previamente imcrementado em 1, e depois somado com o valor de 2*b,
* 						para o resultado ser adicionado ao valor já armazendo no endereço apontado por result
* @param[in] a 			Primeiro número
* @param[in] b 			Segundo número
* @param[out] result	Ponteiro para o número de saida
*/
void funcZ (int a, int b, int* result)
{
	a++;
	(*result) += a + 2*b;
}

/**
* @brief	Funcao principal
* @details	Chama as funções funcX(), funcY() e funcZ() utilizando arg1, arg2 e resultado como parâmetros
* @param	argc Numero de argumentos fornecidos via linha de comando
* @param	argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char* argv[])
	{
	int arg1 = 11;
	int arg2 = 23;
	funcX (arg1,arg2);
	funcY (&arg1,arg2);
	int resultado = 0;
	funcZ (arg1,arg2,&resultado);

	return 0;
}