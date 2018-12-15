/**
* @file     main2.cpp
* @brief    Gerencia o funcionamento da partida,.
* @details  
*
* @author   João Vítor Venceslau Coelho
* @since    29/08/2017
* @date     10/09/2017
*/

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

#include "Programa2/dado.h"
#include "Programa2/jogador.h"
#include "ler_entradas.h"

int Jogador::numero_jogadores = 0;
int Jogador::numero_jogadores_ativos = 0;
int Jogador::numero_jogadores_excluidos = 0;

int Jogador::max_pontos_partida = 51;

/**
* @brief    Funcao principal
* @details  
*
* @param    argc Numero de argumentos fornecidos via linha de comando
* @param    argv Argumentos fornecidos via linha de comando
*/
int main(int argc, char const *argv[])
{
	bool continuar = true;
	while(continuar)
	{
		std::cout << "Saudações, quantos jogadores teremos nessa partida?" << std::endl
				  << "(Digite '0' ou um numero negativo para não jogar): ";

		int qnt_jogadores = get_int();

		if (qnt_jogadores <= 0){
			return 0;
		}
	
		Jogador *jogadores = new Jogador[qnt_jogadores];

		for (int i = 0; i < qnt_jogadores; ++i)
		{
			// O jogador atual inicia sua e vez e joga os dados
			std::cout << std::endl << "Jogador " << jogadores[i].get_id() << " é a sua vez!" << std::endl;
			while(jogadores[i].is_ativo())
			{
				std::cout << "Você marcou " << jogadores[i].jogar_dados() << " pontos";

				// Caso ele tenha a sorte de marcar exatamente o numero maximo de pontos, encerramos o laço
				// pois ja temos um vencedor
				if (jogadores[i].is_sortudo())
				{
					std::cout << std::endl << "Sortudo! Conseguiu marcar exatamente " << Jogador::max_pontos_partida
					<< " pontos." << std::endl;
					break;
				// Caso contrario, informo a quantidade de pontos que ele possui no total
				} else
				{
					std::cout << " nessa rodada, "
					<< "obtendo um total de " << jogadores[i].get_pontos() << " pontos."<<std::endl;

					// Verifico se o jogador não ultrapassou o numero máximo de pontos
					if (jogadores[i].get_pontos() < Jogador::max_pontos_partida)
					{
						// Verifico se o jogador quer continuar jogando ou prefere parar com seus pontos atuais
						bool invalido = true;
						while(invalido)
						{
							std::cout << "Gostaria de continuar na partida ou prefere parar com os seus pontos atuais? "
							<< "(p = parar / c = continuar): ";

							char escolhido = get_one_char();

							switch(escolhido)
							{
								case 'c':
									invalido = false;
									break;
								case 'p':
									jogadores[i].not_ativo();
									invalido = false;
									break;
								default:
									std::cout << "[ERRO] Entrada inválida, por favor digite uma entrada válida."
									<< " (p = parar / c = continuar)" << std::endl;
							}
						}
						// Se o jogador ultrapassou o numero máximo de pontos, ele sai da partida
					} else {
						std::cout << std::endl << "Que azar! Infelizmente você ultrapassou " << Jogador::max_pontos_partida
						<< " pontos. E agora está fora da partida." << std::endl;
						jogadores[i].not_ativo();
					}
				}
			}
			// Se algum jogador marcou exatamente o numero necessario de pontos, o jogo acaba imediatamente
			if (jogadores[i].is_sortudo())
			{
				break;
			}
			// Se sobrou apenas um jogador que não ultrapassou os pontos máximos,a partida acaba
			if (Jogador::numero_jogadores_excluidos == Jogador::numero_jogadores - 1)
			{
				std::cout << "Temos apenas um jogador na partida, todos os outros foram eliminados..." << std::endl;
				break;
			}
		}

		// Como a partida terminou verifico como ele acabou
		std::cout << std::endl << "Fim da Partida!" << std::endl;
		// Se sobrou apenas um jogador que não ultrapassou os pontos máximos, ele é o vencedor
		if (Jogador::numero_jogadores_excluidos == Jogador::numero_jogadores - 1) 
		{
			for (int i = 0; i < qnt_jogadores; ++i)
				{
					if (jogadores[i].get_pontos() < Jogador::max_pontos_partida)
					{
						std::cout << "Parabéns Jogador " << jogadores[i].get_id()
						<< " você acaba de ganhar a partida" << std::endl;
						//break;
					}
				}
		} else {
			// Se todos decidiram parar de jogar, então fazemos a contagem dos pontos
			// Enquanto não for decido um vencedor válido
			bool invalido = true;
			// Auxiliar assume que o jogador com menos pontos é o primeiro.
			int auxiliar = 0;
			int vencedor_partida;
			while(invalido){
				// Antes do inicio do laço o vencedor temporario é o indicado pelo auxiliar
				vencedor_partida = auxiliar;
				for (int i = 0; i < qnt_jogadores; ++i)
				{
					// Caso o jogador atual tenha mais pontos que o atual vencedor e
					// menos pontos que o maximo permitido, ele é o novo vencedor
					if (jogadores[i].get_pontos() > jogadores[vencedor_partida].get_pontos()
					and jogadores[i].get_pontos() <= Jogador::max_pontos_partida)
					{
						vencedor_partida = i;
					}
				}
				// Verifico se o vencedor indicado possui uma quantidade válida de pontos
				if (jogadores[vencedor_partida].get_pontos() <= Jogador::max_pontos_partida)
				{	
					// caso sim, saio do while
					invalido = false;
				} else {
					// se não incremento o auxiliar e repito a busca pelo vencedor
					++auxiliar;
				}
			}

			// Informo a quantidade de pontos que cada jogador obteu durante a partida
			for (int i = 0; i < qnt_jogadores; ++i)
				{
					std::cout << "O jogador " << jogadores[i].get_id() << " terminou com "
					<< jogadores[i].get_pontos() << " pontos." << std::endl;
				}

			// Informo qual o jogador que ganhou a partida
			std::cout << "O vencedor da partida foi o jogador " << jogadores[vencedor_partida].get_id()
			<< " com " << jogadores[vencedor_partida].get_pontos() << " pontos." << std::endl;
		}

		// Apago os jogadores e zero as variaveis abaixo
		delete[] jogadores;
		Jogador::numero_jogadores = 0;
		Jogador::numero_jogadores_ativos = 0;
		Jogador::numero_jogadores_excluidos = 0;

		// Verifico se teremos outra partida
		bool invalido = true;
		while(invalido)
		{
			std::cout << "Gostariam de outra partida jogadores?"
			<< "(s ou y = sim / n = não): ";

			char escolhido = get_one_char();

			switch(escolhido)
			{
				case 's':
					invalido = false;
					break;
				case 'y':
					invalido = false;
					break;
				case 'n':
					continuar = false;
					invalido = false;
					break;
				default:
					std::cout << "Entrada inválida, por favor digite uma entrada válida" << std::endl;
			}
		}
	}

	return 0;
}