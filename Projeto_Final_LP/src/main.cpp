/**
 * @file Main.cpp
 * @brief      Arquivo que contém o programa principal
 * @details    
 *
 * @author     Gleydvan Macedo
 * @author     João Vítor Venceslau Coelho
 * @since      03/12/2017
 * @date       09/12/2017
 */

#include <iostream>
#include <exception>

#include "Animal.hpp"
#include "Ave.hpp"
#include "Anfibio.hpp"
#include "Mamifero.hpp"
#include "Reptil.hpp"
#include "Funcionario.hpp"
#include "Silvestre.hpp"
#include "Pet_Fera_Cadastro.hpp"
#include "Excecoes.hpp"

int main(int argc, char const *argv[])
{
	int opcao;
	int _id;
	std::string funcao_funcionario;
	std::string familia_animal;
	std::string tipo_animal;
	Pet_Fera_Cadastro pet_cadastro;

	std::ifstream dados_funcionarios;
	dados_funcionarios.open ("data/dados_funcionarios.csv");

	if(dados_funcionarios.bad())
	{
		std::cerr << "O arquivo com informações dos funcionarios não pode ser aberto" << std::endl;
		std::cerr << "Abortando execução do programa" << std::endl;
		return 1;
	}
	try
	{
		pet_cadastro.importar_dados_funcionarios( dados_funcionarios );	
	}
	catch ( ErroHeaderCSV &ex )
	{
		std::cerr << ex.what();
		std::cout << "Programa não conseguiu carregar dados dos funcionarios" << std::endl
		<< "Cancelando execução do programa para preservar dados não lidos." << std::endl;
		std::exit(1);
	}
	catch ( ErroLeituraCSVFunc &ex )
	{
		std::cerr << ex.what();
		std::cout << "Programa não conseguiu carregar os dados de um dos funcionarios." << std::endl
		<< " Programa irá continuar com apenas os funcionarios carregados, atenção funcionarios"
		<< " não lidos serão apagados.";
	}
	catch (...)
	{
		std::cerr << "Erro não esperado detectado. Cancelando programa para preservar os dados." << std::endl;
		std::exit(2);
	}

	dados_funcionarios.close();


	std::ifstream dados_animais;
	dados_animais.open ("data/dados_animais.csv");

	if(dados_animais.bad())
	{
		std::cerr << "O arquivo com informações dos animais não pode ser aberto" << std::endl;
		std::cerr << "Abortando execução do programa" << std::endl;
		return 1;
	}
	try
	{
		pet_cadastro.importar_dados_animais( dados_animais );
	}
	catch ( ErroHeaderCSV &ex )
	{
		std::cerr << ex.what();
		std::cout << "Programa não conseguiu carregar dados dos animais" << std::endl
		<< "Cancelando execução do programa para preservar dados não lidos." << std::endl;
		std::exit(1);
	}
	catch ( ErroLeituraCSVAnimal &ex )
	{
		std::cerr << ex.what();
		std::cout << "Programa não conseguiu carregar os dados de um dos animais." << std::endl
		<< " Programa irá continuar com apenas os animais carregados, atenção animais"
		<< " não lidos serão apagados.";
	}
	catch (...)
	{
		std::cerr << "Erro não esperado detectado. Cancelando programa para preservar os dados." << std::endl;
		std::exit(2);
	}
	dados_animais.close();

	do
	{
		std::cout << "Por favor digite uma das opcoes abaixo:" << std::endl
					<< "1 - Cadastrar animal a ser comercializado" << std::endl
					<< "2 - Cadastrar Funcionario" << std::endl
					<< "3 - Remover animal do banco de dados" << std::endl
					<< "4 - Alterar dados cadastrais de um animal" << std::endl
					<< "5 - Consultar dados de animais" << std::endl
					<< "6 - Consultar dados de animais sob responsabilidade de um Veterinario ou Tratador" << std::endl
					<< "7 - Remover Funcionario do banco de dados" << std::endl
					<< "8 - Alterar dados cadastrais de um Funcionario" << std::endl
					<< "9 - Consultar dados de um Funcionario" << std::endl
					<< "10 - Quantidade de Funcionarios cadastrados" << std::endl
					<< "11 - Quantidade de Animais cadastrados" << std::endl
					<< "0 - Sair" << std::endl;
		std::cin >> opcao;

		if( opcao < 0 or opcao > 11 )
			std::cout << "\nOpcao digitada invalida! Por favor digite uma opcao valida." << std::endl << std::endl;
		else
			switch ( opcao )
			{

				case 1:

					std::cout << "Digite a classe do animal que deseja cadastrar (Amphibia, Mammalia, Reptilia ou Aves):" << std::endl;
					std::cin >> familia_animal;
					std::cout << "Digite o tipo do animal que deseja cadastrar (Domestico, Exotico ou Nativo):" << std::endl;
					std::cin >> tipo_animal;

					if( familia_animal.compare( "Amphibia" ) == 0 )
						pet_cadastro.cadastrar_anfibio( familia_animal, tipo_animal );
					else if( familia_animal.compare( "Mammalia" ) == 0 )
						pet_cadastro.cadastrar_mamifero( familia_animal, tipo_animal );
					else if( familia_animal.compare( "Reptilia" ) == 0 )
						pet_cadastro.cadastrar_reptil( familia_animal, tipo_animal );
					else if( familia_animal.compare( "Aves" ) == 0 )
						pet_cadastro.cadastrar_ave( familia_animal, tipo_animal );
							
				break;

				case 2:

					std::cout << "Digite a funcao do Funcionario que deseja cadastrar (Veterinario ou Tratador):" << std::endl;
					std::cin >> funcao_funcionario;

					pet_cadastro.cadastrar_funcionario( funcao_funcionario );


				break;

				case 3:
					
					std::cout << "Digite o ID do animal a ser removido:" << std::endl;
					std::cin >> _id;

					pet_cadastro.remover_animal( _id );					
					

				break;

				case 4:
					
					std::cout << "Digite o ID do animal que deseja alterar os dados:" << std::endl;
					std::cin >> _id;

					pet_cadastro.alterar_dados_animais( _id );
						

				break;

				case 5:

					std::cout << "Digite o ID do animal que deseja consultar:" << std::endl;
					std::cin >> _id;

					pet_cadastro.consultar_animais( _id );
					
					
				break;

				case 6:

					std::cout << "Digite o ID do funcionario:" << std::endl;
					std::cin >> _id;
			
					pet_cadastro.consultar_animais_funcionario( _id );
					
				break;

				case 7:

					std::cout << "Digite o ID do funcionario a ser removido:" << std::endl;
					std::cin >> _id;

					pet_cadastro.remover_funcionario( _id );
					
				break;

				case 8:
					std::cout << "Digite o ID do funcionario que deseja alterar os dados:" << std::endl;
					std::cin >> _id;

					pet_cadastro.alterar_dados_funcionarios( _id );
						

				break;

				case 9:

					std::cout << "Digite o ID do funcionario que deseja consultar:" << std::endl;
					std::cin >> _id;
				
					pet_cadastro.consultar_funcionarios( _id );

				break;

				case 10:

					std::cout << "\nNumero de funcionarios cadastrados: " << pet_cadastro.quantidade_funcionarios_cadastrados() << std::endl << std::endl;

				break;

				case 11:

					std::cout << "\nNumero de Animais cadastrados: " << pet_cadastro.quantidade_animais_cadastrados() << std::endl << std::endl;

				break;

				default:
				break;

			}

	} while ( opcao != 0 );


	std::ofstream dados_animais_exportar;
	dados_animais_exportar.open ("data/dados_animais.csv");
	pet_cadastro.exportar_dados_animais( dados_animais_exportar );
	dados_animais_exportar.close();

	std::ofstream dados_funcionarios_exportar;
	dados_funcionarios_exportar.open ("data/dados_funcionarios.csv");
	pet_cadastro.exportar_dados_funcionarios( dados_funcionarios_exportar );
	dados_funcionarios_exportar.close();

	std::cout << "Obrigado por utilizar nossos servicos!" << std::endl;

	return 0;
	
}