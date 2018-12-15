/**
* @file		main1.cpp
* @brief	Leitura dos .dat e testes
* @details	
*
* @author	João Vítor Venceslau Coelho / Teobaldo
* @since	10/10/2017
* @date		23/10/2017
*/

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <sstream>
#include <string>

#include "produto.h"
#include "bebida.h"
#include "roupa.h"
#include "fruta.h"

using namespace std;

/**
* @brief Imprime os dados já formatados da Bebida
* @param lista Vector, com ponteiros inteligentes, a ser testado se o codigo de barras já está cadastrado
* @param cod_bar String contendo o código de barras do produto a ser testado
* @return true se o produto já está na lista, false caso contrário
*/
bool produto_ja_adicionado (std::vector<shared_ptr<Produto>> &lista, std::string &cod_bar)
{
		for (std::vector<shared_ptr<Produto>>::iterator it = lista.begin(); it != lista.end(); ++it)
		{
			if (cod_bar == (**it).getCodBarras())
			{
				return true;
			}		
		}
	return false;
}


int main(int argc, char const *argv[])
{
	std::vector<shared_ptr<Produto>> lista;
	
	std::ifstream Frutas;
	Frutas.open ("Produtos/Frutas.dat");
	if(Frutas.bad())
	{
		std::cerr << "O arquivo não foi aberto" << std::endl;
		std::exit(1);
	}

	std::ifstream Bebidas;
	Bebidas.open ("Produtos/Bebidas.dat");
	if(Bebidas.bad())
	{
		std::cerr << "O arquivo não foi aberto" << std::endl;
		std::exit(1);
	}

	std::ifstream Roupas;
	Roupas.open ("Produtos/Roupas.dat");
	if(Roupas.bad())
	{
		std::cerr << "O arquivo não foi aberto" << std::endl;
		std::exit(1);
	}

	std::string linha;
	while (std::getline(Frutas,linha))
	{
		// Campos de um produto Fruta
		std::string cod_bar;
		std::string nome;
		std::string preco;
		std::string lote;
		std::string validade;

		std::stringstream ss(linha);

		std::getline(ss,cod_bar, ';');
		std::getline(ss,nome, ';');
		std::getline(ss,preco, ';');
		std::getline(ss,lote, ';');
		std::getline(ss,validade, ';');

		if (!produto_ja_adicionado(lista,cod_bar))
		{
			lista.push_back(make_shared<Fruta>(cod_bar,nome,std::stod(preco),lote,std::stoi(validade)));
		}
	
	}

	while (std::getline(Bebidas,linha))
	{
		// Campos de um produto Bebida
		std::string cod_bar;
		std::string nome;
		std::string preco;
		std::string teor;

		std::stringstream ss(linha);

		std::getline(ss,cod_bar, ';');
		std::getline(ss,nome, ';');
		std::getline(ss,preco, ';');
		std::getline(ss,teor, ';');

		if (!produto_ja_adicionado(lista,cod_bar))
		{
			lista.push_back(make_shared<Bebida>(cod_bar,nome,std::stod(preco),std::stoi(teor)));
		}
	}

	while (std::getline(Roupas,linha))
	{
		// Campos de um produto Roupa
		std::string cod_bar;
		std::string nome;
		std::string preco;
		std::string marca;
		std::string sexo;
		std::string tamanho;
		
		std::stringstream ss(linha);

		std::getline(ss,cod_bar, ';');
		std::getline(ss,nome, ';');
		std::getline(ss,preco, ';');
		std::getline(ss,marca, ';');
		std::getline(ss,sexo, ';');
		std::getline(ss,tamanho, ';');

		if (!produto_ja_adicionado(lista,cod_bar))
		{
			lista.push_back(make_shared<Roupa>(cod_bar,nome,std::stod(preco),marca,sexo,tamanho));
		}
	}

	for (auto i = lista.begin(); i != lista.end(); ++i)
	{
		std::cout << (**i) << std::endl;
	}

	std::cout << "Qual o preço de 3 mangas? " << (*lista[0] + *lista[0] + *lista[0]) << std::endl;
	std::cout << "Qual o preço de 2 Vinhos Tintos menos o preço de Whisky? " << (*lista[11] + *lista[11] - *lista[13]) << std::endl;
	std::cout << "Codigo é igual? " << ( (*lista[3] == *lista[15]) ? "Sim" : "Não" ) << std::endl;
	std::cout << "Codigo é igual? " << ( (*lista[8] == *lista[9]) ? "Sim" : "Não" )<< std::endl;
	return 0;
}
