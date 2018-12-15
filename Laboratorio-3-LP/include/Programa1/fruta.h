/**
* @file		fruta.h
* @brief	Definição da classe Fruta, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho / Teobaldo
* @since	10/10/2017
* @date		23/10/2017	
*/

#ifndef _FRUTA_H_
#define _FRUTA_H_

#include "produto.h"

/**
* @brief Classe Bebida
*/
class Fruta : public Produto
{
public:

	/**
	* @brief Construtor padrão
	*/
	Fruta();

	/**
	* @brief Construtor da classe Fruta a partir dos dados da Fruta
	* @param _codigo String que contém o código de barras da Fruta
	* @param _descricao String que contém a descrição da Fruta
	* @param _preco Double com o preço da Fruta
	* @param _data String que contém a data do lote da Fruta
	* @param _validade Quantidade de dias que informa a validade da Fruta
	*/
	Fruta(std::string _codigo, std::string _descricao, double _preco, 
			std::string _data, short _validade);

	/**
	* @brief Destrutor padrão
	*/
	~Fruta();

private:

	std::string m_data_lote;

	short m_validade;

public:

	/**
	* @brief Informa a data do lote da fruta
	* @return A data do lote da fruta
	*/
	std::string getDataLote();

	/**
	* @brief Informa a validade da fruta
	* @return A validade da fruta
	*/
	short getValidade();

	/**
	* @brief Altera a data do lote da fruta
	* @param[in] _data Nova data do lote
	*/
	void setDataLote(std::string _data);

	/**
	* @brief Altera a validade da fruta
	* @param[in] _validade Nova validade da fruta
	*/
	void setValidade(short _validade);

private:

	/**
	* @brief Adiciona ao ostream as informações da fruta
	* @param[in] o ostream alvo
	* @return ostream resultante
	*/
	std::ostream& print(std::ostream &o) const;
};

#endif