/**
* @file		datas.h
* @brief	Definição da classe Datas, seus atributos e metodos.
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	02/09/2017
* @date		09/09/2017
*/

#ifndef DATAS_H
#define DATAS_H

/**
* @brief Classe Datas
*/
class Datas
{
	private:
		int dia;
		int mes;
		int ano;

	public:

		/**
		* @brief Construtor da classe Datas. Inicia o dia, o mes e o ano
		* @param[in] dia numero do dia
		* @param[in] mes numero do mes
		* @param[in] ano numero do ano
		*/
		Datas( int dia_ = 0, int mes_ = 0, int ano_ = 0);

		/**
		* @brief Destrutor da classe Datas
		*/
		~Datas();

		/**
		* @brief Função que lê valores e os astribui aos devidos atributos
		* @return data resultante
		*/
		Datas set_data();

		/**
		* @brief Sobrecarga do operador +
		* @param[in] data a ser somada
		* @return data resultante
		*/
		Datas& operator+ (Datas &data_);

		/**
		* @brief Sobrecarga do operador -
		* @param[in] data a ser subtraida
		* @return data resultante
		*/
		Datas& operator- (Datas &data_);

		/**
		* @brief Sobrecarga do operador >
		*/
		bool operator>(const Datas &data_) const;

		/**
		* @brief Sobrecarga do operador <
		*/
		bool operator<(const Datas &data_) const;

		/**
		* @brief Sobrecarga do operador ==
		*/
		bool operator==(const Datas &data_) const;

		/**
		* @brief Sobrecarga do operador =
		*/
		Datas& operator=(const Datas &data_);

		/**
		* @brief Sobrecarga do operador <<
		*/
		friend std::ostream& operator<< (std::ostream &o, Datas &data_);

};
#endif