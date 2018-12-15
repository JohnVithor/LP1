/**
 * @file Pet_Fera_Exportar.cpp
 * @brief      Implementação de um programa auxiliar para o Pet_Fera que
 *             permite filtrar e exportar os dados dos animais
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      03/12/2017
 * @date       07/12/2017
 */

#include <getopt.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Pet_Fera_Exportar.hpp"

int main(int argc, char **argv )
{
	int c_flag = 0, v_flag = 0, t_flag = 0;
	int c;
	std::string classe, veterinario, tratador;
	std::string arquivo_saida;
	char temp[] = {'c',':','v',':','t',':'};
	opterr = 0;
	while ( (c = getopt (argc, argv, temp )) != -1 )
	{
		switch(c)
		{
			case 'c':
				c_flag = 1;
				classe = optarg;
				break;
			case 'v':
				v_flag = 1;
				veterinario = optarg;
				break;
			case 't':
				v_flag = 1;
				tratador = optarg;
				break;
			case '?':
				if (optopt == 'c' or optopt == 'v' or optopt == 't')
				{
					std::cerr << "Erro: '-" << char(optopt) << "' necessita de um argumento.\n";
					return 1;
				} else if (isprint(optopt))
				{
					std::cerr << "Erro: '-" << char(optopt) << "' inválido.\n";
					return 1;
				} else {
					std::cerr << "Erro: '\\x" << optopt << "' caractere inválido\n" ;
					return 1;
				}	
			default:
				std::cerr << "Erro desconhecido. Programa abortado.\n" ;
				return 1;
		}
	}

	if (optind < argc)
	{
		arquivo_saida = argv[optind];
	}

	if ( argc < 2 or (not termina_com(arquivo_saida,".csv") ) )
	{
		std::cout << "\t--Modo de usar--" << std::endl
				  << "Opcional:		'-c' <Classe> - Indica a classe de animais a serem exportados." << std::endl
				  << "				Opções de Classe: Amphibia, Reptilia, Aves e Mammalia." << std::endl
				  << "Opcional:		'-v' <Veterinario> - indica que apenas animais sob a responsabilidade do veterinário informado devem ser exportados." << std::endl
				  << "              Indicar qual o id do Veterinario" << std::endl // Seria melhor poder usar o código dele...
				  << "Opcional:		'-t' <Tratador> - indica que apenas animais tratados pelo tratador informado devem ser exportados" << std::endl
				  << "              Indicar qual o id do Tratador" << std::endl // Seria melhor poder usar o código dele...
				  << "Obrigatório:	<Arquivo de Saida> - indica o nome do arquivo de saída, ou seja, do arquivo onde serão guardados os dados a serem exportados" << std::endl
				  << "              Deve incluir a extensão .csv" << std::endl; // Facilita a diferenciar dos outros campos caso alguma entrada muito estranha seja colocada...
		return 1;
	}

	std::ifstream dados_animais;
	dados_animais.open ("data/dados_animais.csv");

	if(dados_animais.bad())
	{
		std::cerr << "O arquivo com informações dos animais não pode ser aberto" << std::endl;
		std::cerr << "Abortando execução do programa" << std::endl;
		return 1;
	}

	std::ifstream dados_funcionarios;
	dados_funcionarios.open ("data/dados_funcionarios.csv");

	if(dados_funcionarios.bad())
	{
		std::cerr << "O arquivo com informações dos funcionarios não pode ser aberto" << std::endl;
		std::cerr << "Abortando execução do programa" << std::endl;
		return 1;
	}

	std::ofstream filtrado( arquivo_saida.c_str(), std::ofstream::trunc );

	if(filtrado.bad())
	{
		std::cerr << "O arquivo de saida informado não pode ser aberto" << std::endl;
		std::cerr << "Abortando execução do programa" << std::endl;
		return 1;
	}

	std::string linha;
	std::vector< std::string > filtrando;
	while(std::getline(dados_animais, linha))
	{
		filtrando.push_back(linha);
	}

	if ( c_flag )
	{
		filtrando = filtrar_classe(filtrando, classe );
	}

	if ( v_flag )
	{
		filtrando = filtrar_func(filtrando, veterinario, 8 );
	}

	if ( t_flag )
	{
		filtrando = filtrar_func(filtrando, tratador, 9 );
	}

	filtrado << "ID;Classe;Tipo;Nome;Nome Cientifico;Sexo;Tamanho;Dieta;Veterinario;Tratador;Batismo;Tamanho do Bico;Envergadura;Total Mudas;Ultima Muda;Cor do Pelo;Venenoso;Tipo Veneno;Ibama;UF / Pais;Autorizacao" << std::endl;
	for (std::vector< std::string >::iterator i = filtrando.begin(); i != filtrando.end(); ++i)
	{
		filtrado << *i << std::endl;
	}

	std::cout << "Dados Filtrados com sucesso" << std::endl;
	
	dados_animais.close();
	dados_funcionarios.close();
	filtrado.close();

	return 0;
}