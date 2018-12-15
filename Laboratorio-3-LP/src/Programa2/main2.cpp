/**
* @file		main2.cpp
* @brief	Interface que seleciona a operação que será realizada
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		20/10/2017	
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <limits>

#include "conta.h"
#include "movimentacao.h"
#include "agencia_bancaria.h"
#include "../ler_entradas.h"

/**
* @brief	Funcao principal
* @details	Mostra as opções de operações que o programa realiza
* @param	argc Numero de argumentos fornecidos via linha de comando
* @param	argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char const *argv[])
{
	Agencia_Bancaria agencia_bancaria_teobaldo;

	char escolhido = '-';
	while(escolhido != '0'){
				std::cout << std::endl << "--- | Saudações, bem vindo(a) à Agencia Bancária! | ---" << std::endl
				<< "	Selecione uma opção:" << std::endl
				<< ">>> (1) Criar conta" << std::endl
				<< ">>> (2) Alterar status" << std::endl
				<< ">>> (3) Remover conta" << std::endl
				<< ">>> (4) Realizar um saque" << std::endl
				<< ">>> (5) Realizar um depósito" << std::endl
				<< ">>> (6) Realizar uma transferencia" << std::endl
				<< ">>> (7) Emitir o saldo" << std::endl
				<< ">>> (8) Emitir o extrato" << std::endl
				<< ">>> (0) Sair" << std::endl
				<< std::endl <<"Digite a sua opcao: ";
		char escolhido = get_one_char();
		switch(escolhido){
			case '1':
				agencia_bancaria_teobaldo.criar_conta();
				break;
			case '2':
				agencia_bancaria_teobaldo.alterar_status();
				break;
			case '3':
				agencia_bancaria_teobaldo.remover_conta();
				break;
			case '4':
				agencia_bancaria_teobaldo.saque();
				break;
			case '5':
				agencia_bancaria_teobaldo.deposito();
				break;
			case '6':
				agencia_bancaria_teobaldo.transferencia();
				break;
			case '7':
				agencia_bancaria_teobaldo.emitir_saldo();
				break;
			case '8':
				agencia_bancaria_teobaldo.emitir_extrato();
				break;
			case '0':
				std::cout << std::endl << "Obrigado pela preferência. Volte Sempre!!!" << std::endl;
				return 0;
			default:
				std::cin.clear();
				std::cin.ignore(200,'\n');
				std::cout << std::endl << "Entrada inválida, por favor digite uma entrada válida." << std::endl;
		}
	}
	return 0;
}