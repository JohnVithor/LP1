/**
* @file		palindromo.cpp
* @brief	Implementação das funções necessarias para avaliar se uma string é ou não um palindromo
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	28/10/2017
* @date		28/10/2017	
*/
#include <iostream>
#include <string>
#include <vector>

#include "../stack.hpp"
#include "palindromo.hpp"

std::string& remover_acentos ( std::string& alvo )
{
	std::vector < std::string > com_acentos = { "Ä","Å","Á","Â","À","Ã","ä","á","â","à","ã","É","Ê","Ë","È",
	"é","ê","ë","è","Í","Î","Ï","Ì","í","î","ï","ì","Ö","Ó","Ô","Ò","Õ","ö","ó","ô","ò","õ","Ü","Ú","Û",
	"ü","ú","û","ù","Ç","ç" };
	std::vector < std::string > sem_acentos = { "A","A","A","A","A","A","a","a","a","a","a","E","E","E","E",
	"e","e","e","e","I","I","I","I","i","i","i","i","O","O","O","O","O","o","o","o","o","o","U","U","U",
	"u","u","u","u","C","c" };

	for (unsigned int i = 0; i < alvo.size(); ++i)
	{
		for (unsigned int j = 0; j < com_acentos.size(); ++j)
		{
			std::size_t found = alvo.find(com_acentos[j]);
			if ( found != std::string::npos )
			{
				alvo.replace( found, com_acentos[j].size(), sem_acentos[j] );
			}
		}
	}
	return alvo;
}

std::string& remover_invalidos ( std::string& alvo )
{
	for (auto i = alvo.begin(); i != alvo.end(); ++i)
	{
		if (std::ispunct(*i) or std::isspace(*i))
		{
			alvo.erase(i--);
		}
	}
	return alvo;
}

bool verifica_palindromo ( std::string alvo )
{
	remover_acentos(alvo);
	remover_invalidos(alvo);

	for (unsigned int i = 0; i < alvo.size(); ++i)
	{
		alvo.at(i) = std::toupper(alvo.at(i));
	}

	jv::stack < char > letras(alvo.size());
	
	for (unsigned int i = 0; i < alvo.size()/2; ++i)
	{
		letras.push(alvo[i]);
	}

	for (unsigned int i = alvo.size()/2 + alvo.size()%2; i < alvo.size(); ++i)
	{
		if ( !letras.empty() and letras.top() == alvo[i])
		{
			letras.pop();
		}
	}
	
	if (letras.empty())
	{
		return true;
	}

	return false;
}