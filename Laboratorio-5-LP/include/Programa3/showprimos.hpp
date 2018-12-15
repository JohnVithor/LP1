/**
* @file		showprimos.hpp
* @brief	Declaração e implementação do Functor verifica_primo
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/10/2017
* @date		03/11/2017	
*/

#ifndef SHOW_PRIMOS_H
#define SHOW_PRIMOS_H

/**
* @brief Functor para verificar se um numero é primo 
* @details Como eu deveria realmente utilizar esse Functor?
* Apenas uma função normal não já seria o suficiente?
*/
class verifica_primo
{
public:
	verifica_primo() = default;

	~verifica_primo() = default;

	/**
	* @brief Testa se um número é ou não primo
	* @param[in] numero Número a ser testado
	* @return true se o número for primo, false caso contrário
	*/
	bool operator() ( long int numero ) const
	{
		// Elimino a possíbilidade de testar o '1' e números negativos.
		// Verifico se o número é um par diferente de 2.
		if ( (numero < 2 or numero % 2 == 0) and numero != 2 )
		{
			return false;
		}

		// Inicio os testes sobre o numéro, verificando se ele é divisivel por algum
		// numero natural impar menor ou igual que a metade de 'numero', se nenhum divisor for encontrado
		// o numero testado de fato é primo.
		for ( long int i = 3; i <= (int long) numero/2; i+=2 )
		{
			if ( numero % i == 0 )
			{
				return false;
			}
		}

		return true;
	}
};

#endif