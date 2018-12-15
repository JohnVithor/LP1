/**
* @file		closest2mean.cpp
* @brief	Teste da função closest2mean()
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	31/10/2017
* @date		31/10/2017	
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include "closest2mean.hpp"

int main(int argc, char const *argv[])
{
	{
		std::vector< int > v = { 1 , 2 , 3 , 30 , 40 , 50 };
		auto result = closest2mean( v.begin(), v.end());
		double media = std::accumulate( v.begin(), v.end(), 0 ) / v.size();
		std::cout << "A média dos elementos do vector v é: " << media << std::endl;
		std::cout << "O elemento mais próximo da média do vector v é: " << *result << std::endl;
		std::cout << "Sendo esse o "<< std::distance( v.begin(), result ) + 1 <<"º elemento do vector." << std::endl << std::endl;
	}

	{
		std::list< int > l = { 42 , 17 , 25 , 73 , 30 , 51 };
		auto result = closest2mean( l.begin(), l.end());
		double media = std::accumulate( l.begin(), l.end(), 0 ) / l.size();
		std::cout << "A média dos elementos da lista l é: " << media << std::endl;
		std::cout << "O elemento mais próximo da média do vector v é: " << *result << std::endl;
		std::cout << "Sendo esse o "<< std::distance( l.begin(), result ) + 1 <<"º elemento da list." << std::endl << std::endl;
	}

	{
		std::set< int > s = { 22 , 18 , 47 , 21 , 73 , 35 };
		auto result = closest2mean( s.begin(), s.end());
		double media = std::accumulate( s.begin(), s.end(), 0 ) / s.size();
		std::cout << "A média dos elementos do set s é: " << media << std::endl;
		std::cout << "O elemento mais próximo da média do set s é: " << *result << std::endl;
	}

	return 0;
}