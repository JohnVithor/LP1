/**
* @file		bebida.h
* @brief	Definição da classe Bebida, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho / Teobaldo
* @since	10/10/2017
* @date		23/10/2017	
*/

#ifndef _BEBIDA_H_
#define _BEBIDA_H_

#include "produto.h"

/**
* @brief Classe Bebida
*/
class Bebida : public Produto
{
public:

	/**
	* @brief Construtor padrão
	*/
	Bebida();

	/**
	* @brief Construtor da classe Bebida a partir dos dados da bebida
	* @param _codigo String que contém o código de barras da Bebida
	* @param _descricao String que contém a descrição da Bebida
	* @param _preco Double com o preço da Bebida
	* @param _alcool teor alcoolico da Bebida
	*/
	Bebida(std::string _codigo, std::string _descricao, double _preco, 
			unsigned short _alcool);

	/**
	* @brief Destrutor padrão
	*/
	~Bebida();

private:

	unsigned short m_alcool;

public:

	/**
	* @brief Informa a porcentagem de alcool da bebida 
	* @return Porcentagem de alcool da bebida
	*/
	unsigned short getAlcool();

	/**
	* @brief Altera a porcentagem de alcool da bebida 
	* @param[in] _alcool Nova porcentagem de alcool
	*/
	void setAlcool(unsigned short _alcool);

private:

	/**
	* @brief Adiciona ao ostream as informações da bebida
	* @param[in] o ostream alvo
	* @return ostream resultante
	*/
	std::ostream& print(std::ostream &o) const;
};

#endif