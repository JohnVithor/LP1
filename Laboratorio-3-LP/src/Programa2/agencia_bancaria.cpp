/**
* @file		agencia_bancaria.cpp
* @brief	Implementãção dos métodos da classe Agencia_Bancaria
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	20/10/2017
* @date		23/10/2017	
*/

#include <vector>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>


#include "conta.h"
#include "movimentacao.h"
#include "agencia_bancaria.h"
#include "../ler_entradas.h"

Agencia_Bancaria::Agencia_Bancaria(){
	contas_registradas = {};
}

Agencia_Bancaria::~Agencia_Bancaria(){

}

bool Agencia_Bancaria::criar_conta(){

	unsigned int agencia;
	unsigned int numero;
	double saldo;
	Status status;

	std::cout << std::endl << ">>> Por favor informe a agencia da conta a ser criada: ";
	agencia = get_uint();

	std::cout << std::endl << ">>> Por favor informe o numero da conta a ser criada: ";
	numero = get_uint();
	
	std::cout << std::endl << ">>> Por favor informe o valor inicial do saldo da conta a ser criada: ";
	saldo = get_double();

	char tipo_status = '-';
	while (true)
	{
		if (tipo_status == 's')
		{
			status = especial;
			break;
		}
		else if (tipo_status == 'n')
		{
			status = nao_especial;
			break;
		}
		std::cout << std::endl << ">>> A conta a ser criada é especial ou não? ( s / n ): ";
		tipo_status = get_one_char();
	}

	std::shared_ptr< Conta > nova_conta = std::make_shared< Conta >( agencia, numero, saldo, status );

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( **it == *nova_conta){
			std::cout << std::endl << ">>> Conta já existe. Cancelando operação..." << std::endl;
			return false;
		}
	}

	contas_registradas.push_back(nova_conta);
	std::cout << std::endl << ">>> Conta criada com sucesso." << std::endl;

	return true;
}

bool Agencia_Bancaria::alterar_status(){
	std::cout << std::endl << ">>> Qual conta gostaria alterar o status? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}

	unsigned int agencia;
	unsigned int numero;
	std::cout << std::endl << ">>> Digite a agencia da conta: ";
	agencia = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta: ";
	numero = get_uint();

	char tipo_status = '-';
	Status status;
	while (true)
	{
		if (tipo_status == 's')
		{
			status = especial;
			break;
		}
		else if (tipo_status == 'n')
		{
			status = nao_especial;
			break;
		}
		std::cout << std::endl << ">>> A conta a ser criada é especial ou não? ( s / n ): ";
		tipo_status = get_one_char();
	}

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia and (**it).get_numero() == numero){
			(**it).set_status(status);
			std::cout << std::endl << ">>> Status Alterado. O status atual é ";
			if ( (**it).get_status() == 1 )
			{
				std::cout << "'Especial'" << std::endl;
			}
			else
			{
				std::cout << "'Não especial'" << std::endl;	
			}
			return true;
		}
	}
	std::cout << std::endl << ">>> Conta não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

bool Agencia_Bancaria::remover_conta(){
	std::cout << std::endl << ">>> Qual conta gostaria remover? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}

	unsigned int agencia;
	unsigned int numero;
	std::cout << std::endl << ">>> Digite a agencia da conta: ";
	agencia = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta: ";
	numero = get_uint();

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia and (**it).get_numero() == numero){
			contas_registradas.erase(it);
			std::cout << std::endl << ">>> Conta removida..." << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Conta não foi encontrada. Cancelando operação..." << std::endl;
	return false;
}

bool Agencia_Bancaria::saque(){
	std::cout << std::endl << ">>> De qual conta gostaria realizar o saque? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}
	unsigned int agencia;
	unsigned int numero;
	double valor;
	std::cout << std::endl << ">>> Digite a agencia da conta: ";
	agencia = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta: ";
	numero = get_uint();
	std::cout << std::endl << ">>> Digite o valor a ser sacado: ";
	valor = get_double();

	std::shared_ptr< Movimentacao > nova_movimentacao = std::make_shared< Movimentacao >( "Saque", valor, debito);

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia and (**it).get_numero() == numero){
			if( (**it).set_saldo(nova_movimentacao) )
			{
				std::cout << std::endl << ">>> Saque realizado com sucesso. Novo saldo da conta: " << 
				(**it).get_saldo() << std::endl;
				return true;
			}
			
		}
	}
	std::cout << std::endl << ">>> Não foi possivel realizar o saque. Esta conta não existe ou não possui saldo suficiente." << std::endl;

	return false;
}

bool Agencia_Bancaria::deposito(){
	std::cout << std::endl << ">>> De qual conta gostaria realizar o deposito? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}
	unsigned int agencia;
	unsigned int numero;
	double valor;
	std::cout << std::endl << ">>> Digite a agencia da conta: ";
	agencia = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta: ";
	numero = get_uint();
	std::cout << std::endl << ">>> Digite o valor a ser depositado: ";
	valor = get_double();

	std::shared_ptr< Movimentacao > nova_movimentacao = std::make_shared< Movimentacao >( "Deposito", valor, credito);

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia and (**it).get_numero() == numero){
			if( (**it).set_saldo(nova_movimentacao) )
			{
				std::cout << std::endl << ">>> Deposito realizado com sucesso. Novo saldo da conta: " << 
				(**it).get_saldo() << std::endl;
				return true;
			}
			
		}
	}
	std::cout << std::endl << ">>> Não foi possivel realizar o deposito. Esta conta não existe ou não possui limite suficiente." << std::endl;
	return false;
}

bool Agencia_Bancaria::transferencia(){
	std::cout << std::endl << ">>> Em quais contas será realizada a transferencia? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}

	unsigned int agencia1;
	unsigned int numero1;
	std::cout << std::endl << ">>> Digite a agencia da conta transferidora: ";
	agencia1 = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta transferidora: ";
	numero1 = get_uint();

	unsigned int agencia2;
	unsigned int numero2;
	std::cout << std::endl << ">>> Digite a agencia da conta a receber a transferencia: ";
	agencia2 = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta a receber a transferencia: ";
	numero2 = get_uint();

	double valor;
	std::cout << std::endl << ">>> Digite o valor a ser transferido: ";
	valor = get_double();

	std::string descricao1 = "Transferencia para a conta ";
	std::string descricao2 = "Transferencia da conta ";

	std::stringstream alvo1;
	alvo1 << agencia2 << numero2;
	std::stringstream alvo2;
	alvo2 << agencia1 << numero1;

	descricao1 = descricao1 + alvo1.str();
	descricao2 = descricao2 + alvo2.str();

	std::shared_ptr< Movimentacao > nova_movimentacao1 = std::make_shared< Movimentacao >( descricao1, valor, debito);
	std::shared_ptr< Movimentacao > nova_movimentacao2 = std::make_shared< Movimentacao >( descricao2, valor, credito);

	bool saque = false;
	bool deposito = false;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia1 and (**it).get_numero() == numero1 and ((**it).get_saldo() - valor) >= 0 )
		{
			(**it).set_saldo(nova_movimentacao1);
			saque = true;
		}

		if ( (**it).get_agencia() == agencia2 and (**it).get_numero() == numero2 and ((**it).get_saldo() + valor) < (**it).get_limite() )
		{
			(**it).set_saldo(nova_movimentacao2);
			deposito = true;
		}
	}

	if (saque and deposito)
	{
		std::cout << std::endl << ">>> Transferencia realizada com sucesso." << std::endl;
		return true;
	}

	std::cout << std::endl << ">>> Não foi possivel realizar a transferencia." << 
	" A conta transferidora não existe ou não possui saldo o suficiente e/ou a conta a receber a transferencia não existe ou não possui limite o suficiente" << std::endl;
	return false;
}

bool Agencia_Bancaria::emitir_saldo()
{
	std::cout << std::endl << ">>> De qual conta gostaria consultar o saldo? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}
	unsigned int agencia;
	unsigned int numero;
	std::cout << std::endl << ">>> Digite a agencia da conta: ";
	agencia = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta: ";
	numero = get_uint();

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia and (**it).get_numero() == numero)
		{
			std::cout << std::endl << ">>> O saldo dessa conta é: " << (**it).get_saldo() << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Conta não encontrada. Cancelando operação..." << std::endl;
	return false;
}

bool Agencia_Bancaria::emitir_extrato()
{
	std::cout << std::endl << ">>> De qual conta gostaria visualizar o extrato? " << std::endl
			  << ">>> Contas possiveis:" << std::endl;

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		std::cout << (**it).get_agencia() << " " << (**it).get_numero() << std::endl;
	}
	unsigned int agencia;
	unsigned int numero;
	std::cout << std::endl << ">>> Digite a agencia da conta: ";
	agencia = get_uint();
	std::cout << std::endl << ">>> Digite o numero da conta: ";
	numero = get_uint();

	for (auto it = contas_registradas.begin(); it != contas_registradas.end(); ++it)
	{
		if ( (**it).get_agencia() == agencia and (**it).get_numero() == numero)
		{

			std::cout << std::endl << "Histórico de transferências:" << std::endl << 
			(**it) << std::endl;
			return true;
		}
	}
	std::cout << std::endl << ">>> Conta não encontrada. Cancelando operação..." << std::endl;
	return false;
}