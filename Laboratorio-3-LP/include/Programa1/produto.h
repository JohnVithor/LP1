/**
* @file		produto.h
* @brief	Definição da classe Produto, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	10/10/2017
* @date		23/10/2017	
*/

#ifndef _PRODUTO_H_
#define _PRODUTO_H_

#include <iostream>
#include <string>

/**
* @brief Classe Produto
*/
class Produto
{
public:

	/**
	* @brief Construtor padrão
	*/
	Produto();

	/**
	* @brief Construtor paramatrizado
	* @param[in] _codigo Codigo de barras do produto
	* @param[in] _descricao Descrição do produto
	* @param[in] _preco Preço do produto
	*/
	Produto(std::string _codigo, std::string _descricao, double _preco);

	/**
	* @brief Destrutor padrão
	*/
	virtual ~Produto();
	/*
		A utilização do virtual no destrutor tem como objetivo permitir, que ao acessar uma fruta, roupa ou bebida como um produto, 
		quando o destrutor do objeto for chamado, primeiro será chamado o destrutor da classe derivada, para então poder 
		chamar o destrutor da classe base.
	*/

protected:

	std::string m_cod_barras;

	std::string m_descricao;

	double m_preco;
	
public:

	/**
	* @brief Informa o codigo de barras do produto
	* @return O codigo de barras do produto
	*/
	std::string getCodBarras();

	/**
	* @brief Informa a descrição do produto
	* @return A descrição do produto
	*/
	std::string getDescricao();

	/**
	* @brief Informa o preço do produto
	* @return O preço do produto
	*/
	double getPreco();

	/**
	* @brief Altera o codigo de barras do produto
	* @param[in] _codigo Novo codigo de barras do produto
	*/
	void setCodBarras(std::string _codigo);

	/**
	* @brief Altera a descrição do produto
	* @param[in] _descricao Nova descrição do produto
	*/
	void setDescricao(std::string _descricao);
	
	/**
	* @brief Altera o preço do produto
	* @param[in] _preco Novo preço do produto
	*/
	void setPreco(double _preco);

	/**
	* @brief Sobrecarga do operador << para Produto
	* @param o o stream de saída que receberá os dados do Produto
	* @param p Produto cujas informações serão impressas
	* @return Stream de saída com os dados já formatados
	*/
	friend std::ostream& operator<< (std::ostream &o, Produto const &p);

	/**
	* @brief Calcula a soma de um double com o preço de um Produto
	* @param val Valor a ser somado
	* @param p Produto cujo preço será somado
	* @return Double com o preço resultante da soma
	*/
	friend double operator+ (double const val , Produto const &p);

	/**
	* @brief Calcula a subtração de um double com o preço de um Produto
	* @param val Valor a ser subtraido
	* @param p Produto cujo preço será subtraido
	* @return Double com o preço resultante da subtração
	*/
	friend double operator- (double const val , Produto const &p);

	/**
	* @brief Calcula a soma dos preços de dois Produtos
	* @param p Produto cujo preço será somado
	* @return Double com o preço resultante da soma
	*/
	double operator+ ( Produto const &p) const;

	/**
	* @brief Calcula a subtração dos preços de dois Produtos
	* @param p Produto cujo preço será subtraido
	* @return Double com o preço resultante da subtração
	*/
	double operator- ( Produto const &p) const;

	/**
	* @brief Calcula a soma do preço de um produto com um valor 
	* @param val Valor a ser somado
	* @return Double com o preço resultante da soma
	*/
	double operator+ ( double const val) const;

	/**
	* @brief Calcula a subtração do preço de um produto com um valor 
	* @param val Valor a ser subtraido
	* @return Double com o preço resultante da subtração
	*/
	double operator- ( double const val) const;

	/**
	* @brief Informa se dois produtos possuem o mesmo código de barras ou não
	* @param p Produto a ser comparado
	* @return true se os produtos possuem o mesmo código, false caso contrário.
	*/
	bool operator== ( Produto const &p) const;

private:

	/**
	* @brief Sobrecarga do operador <<
	* @param[in] o Ostream alvo
	* @param[in] t Produto que terá as informações reveladas
	* @return Ostream com as informações do produto
	*/
	virtual std::ostream& print(std::ostream&) const = 0;
};
 
#endif
