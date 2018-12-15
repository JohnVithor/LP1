/**
* @file		closest2mean.hpp
* @brief	Declaração e implementação da função closest2mean()
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/10/2017
* @date		31/10/2017	
*/

#include <numeric>		// std::accumulate
#include <complex>		// std::abs
#include <iterator>		// std::distance, std::advance

/**
* @brief Localiza em um intervalo '[fechado, aberto)', indicado por iteradores,
 o valor mais próximo da média dos elementos do intervalo
* @param[in] first Inicio do intervalo
* @param[in] last Fim do intervalo
* @return Iterador para o elemento mais próximo da média encontrado
*/
template<typename InputIterator>
InputIterator closest2mean ( InputIterator first, InputIterator last )
{
	double media = std::accumulate( first, last, 0 ) / std::distance( first, last );
	InputIterator aux = first;
	std::advance( first , 1 );

/*
	Comparo o valor absoluto da diferença de cada elemento com 
	a média encontrada, com a menor diferença encontrada até o momento, 
	( essa diferença informa a distância desse elemento até a média ). 
	Se a nova diferença for menor que a anterior, atualizo o iterador para
	o elemento encontrado ( que é o mais proximo da média até o momento )
*/
	while ( first != last )
	{
		if ( std::abs((*first - media)) < std::abs((*aux - media)) )
		{
			aux = first;
		}
		std::advance( first , 1 );
	}

	return aux;

}