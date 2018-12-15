/**
 * @file Excecoes.cpp
 * @brief      Declaração de algumas exceções
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      09/11/2017
 * @date       09/12/2017
 */

#ifndef EXCECOES_HPP
#define EXCECOES_HPP

#include <exception>
#include <string>

namespace PetFera
{

	class ErroLeituraCSVAnimal : public std::exception
	{
	public:
		const char* what()
		{
			return "Conteudo inválido no campo de tipo de uma animal. Campos Válidos: Domestico, Exotico e Nativo.";
		}
	};

	class ErroLeituraCSVFunc : public std::exception
	{
	public:
		const char* what()
		{
			return "Conteudo inválido no campo da função do funcionario. Campos Válidos: Veterinario e Tratador.";
		}
	};

	class ErroHeaderCSV: public std::exception
	{
	public:
		const char* what()
		{
			return "Conteudo inválido no header do arquivo.\n";
		}
	};
}

#endif