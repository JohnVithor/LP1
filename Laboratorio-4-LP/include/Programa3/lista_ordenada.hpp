/**
* @file		lista_ordenada.hpp
* @brief	Definição da classe jv::lista_ordenada, seus atributos e métodos
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	28/10/2017
* @date		28/10/2017	
*/

#ifndef	LISTA_ORDENADA_H
#define LISTA_ORDENADA_H

#include <memory>
#include <initializer_list>
#include "lista.hpp"

namespace jv
{
	/**
	* @brief Um tipo simplificado de lista ordenada duplamente encadeada com sentinelas
	* @tparam T Tipo do valor que será utilizado para o template da lista ordenada
	*/
	template < class T >
	class lista_ordenada : public lista< T > 
	{
		public:
			typedef T value_type;
			typedef std::size_t size_type;
			typedef const value_type& const_reference;
			typedef std::shared_ptr< node< value_type > > node_pointer;
			using iterator = MyIterator< value_type >;

		public:
			//								===========================
			//								===== SPECIAL MEMBERS =====

			/**
			* @brief Construtor vazio da lista ordenada.
			*/
			lista_ordenada ();

			/**
			* @brief Construtor da lista ordenada, com um valor inicial de capacidade
			* @param[in] count Quantidade de elementos a serem criados
			* @param[in] value Valor dos elementos a serem criados
			*/
			explicit lista_ordenada ( size_type count, value_type value = value_type() );

			/**
			* @brief Construtor da lista ordenada, com base em um intervalo 
			* @param[in] first Inicio do intervalor
			* @param[in] last Fim do intervalo
			*/
			template < typename InputItr >
			lista_ordenada ( InputItr first, InputItr last);

			/**
			* @brief Construtor cópia da lista ordenada
			* @param[in] other lista ordenada a ser copiada
			*/
			lista_ordenada ( const lista_ordenada & other );

			/**
			* @brief Construtor da lista ordenada a partir de uma lista inicializadora
			* @param[in] ilist Lista a ser utilizada
			*/
			lista_ordenada ( std::initializer_list< value_type > ilist );

			/**
			* @brief Destrutor da lista ordenada
			*/
			~lista_ordenada() = default;

			//								=====================
			//								===== Modifiers =====

			/**
			* @brief Insere o elemento indicado na posição indicada pelo iterador
			* @param[in] value Elemento a ser inserido
			* @return Iterador que indica a posição do elemento inserido
			*/
			iterator insert( const_reference value );

			/**
			* @brief Insere todos os elementos indicados do intervalo indicado na lista
			* @param[in] first Inicio do intevalo indicado
			* @param[in] last Fim do intevalo indicado
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			template < typename InputItr >
			iterator insert( InputItr first, InputItr last);

			/**
			* @brief Insere todos da lista inicializadora indicada na lista
			* @param[in] ilist Lista inicializadora
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			iterator insert( std::initializer_list< value_type > ilist );

			/**
			* @brief Adiciona o elemento indicado ao inicio da lista
			* @param[in] valor a ser adicionado
			*/
			void push_front ( const_reference value ) = delete;

			/**
			* @brief Adiciona o elemento indicado ao fim da lista
			* @param[in] valor a ser adicionado
			*/
			void push_back (const_reference value ) = delete;
	};
}

#include "lista_ordenada.inl"

#endif