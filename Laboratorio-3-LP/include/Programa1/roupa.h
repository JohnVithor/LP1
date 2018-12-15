/**
* @file		roupa.h
* @brief	Definição da classe Roupa, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho / Teobaldo
* @since	10/10/2017
* @date		23/10/2017	
*/

#ifndef _ROUPA_H_
#define _ROUPA_H_

#include "produto.h"

/**
* @brief Classe Roupa
*/
class Roupa : public Produto
{
public:

	/**
	* @brief Construtor padrão
	*/
	Roupa();

/**
* @brief Construtor da classe Roupa a partir dos dados da Roupa
* @param _codigo String que contém o código de barras da Roupa
* @param _descricao String que contém a descrição da Roupa
* @param _preco Double com o preço da Roupa
* @param _marca String que contém a marca da Roupa
* @param _sexo String que contém o sexo (gênero ao qual se destina) da Roupa.('M' ou 'F')
* @param _tamanho String que contém o tamanho da Roupa.  (Alguns exemplos são: 'p', 'P', 'M', 'G', 'GG', 'XL')
*/
	Roupa (std::string _codigo, std::string _descricao, double _preco, 
		std::string _marca, std::string _sexo, std::string _tamanho);

	/**
	* @brief Destrutor padrão
	*/
	~Roupa();

private:

	std::string m_marca;

	std::string m_sexo;

	std::string m_tamanho;

public:

	/**
	* @brief Informa a marca da roupa
	* @return A marca da roupa
	*/
	std::string getMarca();

	/**
	* @brief Informa o sexo ao qual é destinada a roupa
	* @return O sexo a o qual é destinada a roupa
	*/
	std::string getSexo();

	/**
	* @brief Informa o tamanho da roupa
	* @return O tamanho da roupa
	*/
	std::string getTamanho();

	/**
	* @brief Altera a marca da roupa
	* @param[in] _marca Nova marca da roupa
	*/
	void setMarca(std::string _marca);

	/**
	* @brief Altera o sexo ao qual é destinada a roupa
	* @param[in] _sexo Novo sexo ao qual é destinada a roupa
	*/
	void setSexo(std::string _sexo);

	/**
	* @brief Altera o tamanho da roupa
	* @param[in] _tamanho Nova tamanho da roupa
	*/
	void setTamanho(std::string _tamanho);

private:

	/**
	* @brief Adiciona ao ostream as informações da roupa
	* @param[in] o ostream alvo
	* @return ostream resultante
	*/
	std::ostream& print(std::ostream &o) const;
};

#endif