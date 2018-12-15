/**
* @file		lista.hpp
* @brief	Definição das classes jv::node jv::MyIterator e jv::lista, seus atributos e métodos
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	25/10/2017
* @date		28/10/2017	
*/

#ifndef	LISTA_H
#define LISTA_H

#include <memory>
#include <initializer_list>

namespace jv
{
	template < class T> class node; // Declaracao antecipada da classe
	template < typename T> // Definicao antecipada do template para o operador de inserção
	std::ostream& operator<<( std::ostream&, node< T > const & );

	/**
	* @brief Um node, isto é, um ponto da lista, que contém o elemento armazenado e dois campos que 
	* indicam o elemento anterior e o proximo.
	* @tparam T Tipo do valor que será utilizado para o template do node
	*/
	template < class T >
	class node
	{
		public:
			typedef T value_type;
			typedef std::shared_ptr< value_type > pointer;
			typedef std::shared_ptr< const value_type > const_pointer;
			typedef std::shared_ptr< node< value_type > > node_pointer;
			typedef std::shared_ptr< const node< value_type > > const_node_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;

		private:
			value_type m_value;
			node_pointer m_previous;
			node_pointer m_next;

		public:
			/**
			* @brief Construtor vazio do node.
			*/
			node ();

			/**
			* @brief Construtor do node, inicializando o valor que ele guarda.
			* @param[in] value Valor que será armazenado pelo node
			*/
			node ( value_type value );
			
			/**
			* @brief Construtor do node, inicializando o valor que ele guarda e seus nodes vizinhos
			* @param[in] value Valor que será armazenado pelo node
			* @param[in] next_ptr Endereço do próximo node
			* @param[in] previous_ptr Endereço do node anterior
			*/
			node ( value_type value, node_pointer next_ptr, node_pointer previous_ptr );

			/**
			* @brief Construtor cópia do node
			* @param[in] alvo Node que será copiado
			*/
			node ( node< value_type > &alvo );

			/**
			* @brief Construtor vazio do node.
			*/
			~node ();
			
			/**
			* @brief Informa qual o valor armazenado pelo node
			* @return Referencia para o valor armazenado no node
			*/
			reference get_value ();

			/**
			* @brief Altera o valor armazenado pelo node
			* @param[in] value Novo valor armazenado pelo node
			*/
			void set_value ( value_type value);

			/**
			* @brief Informa qual o próximo node
			* @return Referencia para o shared_ptr que armazena o endereço do próximo node
			*/
			node_pointer& get_next ();

			/**
			* @brief Altera qual é o próximo node
			* @param[in] next_ptr Novo endereço do próximo node
			*/
			void set_next ( node_pointer next_ptr = nullptr);

			/**
			* @brief Informa qual o node anterior
			* @return Referencia para o shared_ptr que armazena o endereço do node anterior
			*/
			node_pointer& get_previous ();

			/**
			* @brief Altera qual é o node anterior
			* @param[in] next_ptr Novo endereço do node anterior
			*/
			void set_previous ( node_pointer previous_ptr = nullptr);

			/**
			* @brief Sobrecarga do operador =
			* @param[in] other node a ser atribuido
			* @return O node já modificado
			*/
			node& operator= ( const node& other );

			/**
			* @brief Sobrecarga do operador *
			* @return Referência para o conteúdo armazenado pelo node
			*/
			reference operator* ();

			/**
			* @brief Sobrecarga do operador != para comparar dois nodes
			* @param[in] other node a ser comparado
			* @return true se os nodes são diferentes, false caso contrário
			*/
			bool operator!= (const node& other) const;

			/**
			* @brief Sobrecarga do operador == para comparar dois nodes
			* @param[in] other node a ser comparado
			* @return true se os nodes são iguais, false caso contrário
			*/
			bool operator== (const node& other) const;

			/**
			* @brief Sobrecarga do operador <<
			* @param[in] o Ostream alvo
			* @param[in] n Node a ter o conteúdo impresso
			* @return Ostream contendo o valor do node indicado
			*/
			friend std::ostream& operator<< < value_type >( std::ostream &o, node< value_type > const &n);
	};

	/**
	* @brief Um tipo simplificado de iterador
	* @tparam T Tipo do valor que será utilizado para o template do iterador
	*/
	template < class T >
	class MyIterator
	{
		public:
			typedef T value_type;
			typedef std::size_t size_type;
			typedef std::ptrdiff_t difference_type;
			typedef MyIterator self_type;
			typedef std::shared_ptr< jv::node< value_type > > node_pointer;
			typedef std::shared_ptr< const jv::node< value_type > > const_node_pointer;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef std::bidirectional_iterator_tag iterator_category;

		private:
			node_pointer m_ptr;

		public:
			/**
			* @brief Construtor da classe MyIterator. Inicia o ponteiro interno a partir de outro shared_ptr
			* @param[in] ptr Ponteiro a ser atribuido
			*/
			MyIterator( node_pointer ptr = nullptr );

			/**
			* @brief Construtor da classe MyIterator. Inicia o ponteiro interno a partir de um ponteiro bruto
			* @param[in] ptr Ponteiro a ser atribuido
			*/
			MyIterator( jv::node< value_type >& ptr = nullptr );

			/**
			* @brief Destrutor da classe MyIterator.
			*/
			~MyIterator() = default;

			/**
			* @brief Informa o shared_ptr interno do Iterador
			* @return Shared_ptr interno do Iterador
			*/
			node_pointer get_pointer ();

			/**
			* @brief Informa o shared_ptr interno do Iterador
			* @return Shared_ptr interno do Iterador versão constante
			*/
			const_node_pointer get_pointer () const;

			/**
			* @brief Sobrecarga do operador ++ de pré-incremento
			* @return Iterador incrementado
			*/
			self_type operator++(void);

			/**
			* @brief Sobrecarga do operador ++ de pós-incremento
			* @return Iterador incrementado
			*/
			self_type operator++(int);

			/**
			* @brief Sobrecarga do operador -- de pré-incremento
			* @return Iterador decrementado
			*/
			self_type operator--(void);

			/**
			* @brief Sobrecarga do operador -- de pós-incremento
			* @return Iterador decrementado
			*/
			self_type operator--(int);

			/**
			* @brief Sobrecarga do operador +
			* @param[in] num valor a ser somado
			* @return Novo iterador
			*/
			self_type operator+( size_type num );

			/**
			* @brief Sobrecarga do operador -
			* @param[in] num valor a ser subtraido
			* @return Novo iterador
			*/
			self_type operator-( size_type num );

			/**
			* @brief Sobrecarga do operador -
			* @param[in] itrt Iterador a ser subtraido
			* @return Distancia entre os dois iteradores
			*/
			difference_type operator-( self_type itrt );

			/**
			* @brief Sobrecarga do operador * para derreferenciar o ponteiro interno
			* @return Referencia para o conteudo do ponteiro interno
			*/
			reference operator*(void);

			/**
			* @brief Sobrecarga do operador * para derreferenciar o ponteiro interno, mas não é possivel alterar seu valor
			* @return Referencia constante para o conteudo do ponteiro interno
			*/
			const_reference operator*(void) const;

			/**
			* @brief Sobrecarga do operador != para comparar dois iteradores
			* @param[in] other Iterador a ser comparado
			* @return true se os iteradores são diferentes, false caso contrário
			*/
			bool operator!=(const self_type& other) const;

			/**
			* @brief Sobrecarga do operador == para comparar dois iteradores
			* @param[in] other Iterador a ser comparado
			* @return true se os iteradores são iguais, false caso contrário
			*/
			bool operator==(const self_type& other) const;

			/**
			* @brief Sobrecarga do operador == para comparar um iteradores com um ponteiro
			* @param[in] other Ponteiro a ser comparado
			* @return true se o iterador e o ponteiro são diferentes, false caso contrário
			*/
			bool operator!=(const_node_pointer other) const;

			/**
			* @brief Sobrecarga do operador == para comparar um iteradores com um ponteiro
			* @param[in] other Ponteiro a ser comparado
			* @return true se o iterador e o ponteiro são iguais, false caso contrário
			*/
			bool operator==(const_node_pointer other) const;
	};

	template < class value_type >
	class lista; // Declaração antecipada da classe lista

	template < typename value_type > // Definição antecipada do template para o operador de inserção
	std::ostream& operator<< ( std::ostream&, lista<value_type> & );

	template < typename value_type > // Definição antecipada do template para o metodo swap
	void swap ( lista< value_type >&, lista<value_type> & );

	/**
	* @brief Um tipo simplificado de lista duplamente encadeada com sentinelas
	* @tparam T Tipo do valor que será utilizado para o template da lista
	*/
	template < class T >
	class lista
	{
		public:
			typedef T value_type;
			typedef std::size_t size_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef std::shared_ptr< node< value_type > > node_pointer;
			typedef std::shared_ptr< const node< value_type > > const_node_pointer;
			typedef std::ptrdiff_t difference_type;
			using iterator = MyIterator< value_type >;
			using const_iterator = MyIterator< value_type >;

		protected:
			node_pointer m_head;
			node_pointer m_tail;
			size_t m_size;

		public:
			//								===========================
			//								===== SPECIAL MEMBERS =====

			/**
			* @brief Construtor vazio da lista.
			*/
			lista ();

			/**
			* @brief Construtor da lista, com um valor inicial de capacidade
			* @param[in] count Quantidade de elementos a serem criados
			* @param[in] value Valor dos elementos a serem criados
			*/
			explicit lista ( size_type count, value_type value = value_type() );

			/**
			* @brief Construtor da lista, com base em um intervalo 
			* @param[in] first Inicio do intervalor
			* @param[in] last Fim do intervalo
			*/
			template < typename InputItr >
			lista ( InputItr first, InputItr last);

			/**
			* @brief Construtor cópia da lista
			* @param[in] other lista a ser copiado
			*/
			lista ( const lista & other );

			/**
			* @brief Construtor da lista a partir de uma lista inicializadora
			* @param[in] ilist Lista a ser utilizada
			*/
			lista ( std::initializer_list< value_type > ilist );

			/**
			* @brief Destrutor da lista
			*/
			~lista();

			/**
			* @brief Sobrecarga do operador = a partir de outra lista
			* @param[in] other lista a ser atribuida
			* @return A lista já modificada
			*/
			lista& operator=( const lista& other );

			/**
			* @brief Sobrecarga do operador = a partir de uma lista inicializadora
			* @param[in] ilist lista a ser atribuida
			* @return A lista já modificada
			*/
			lista& operator=( std::initializer_list< value_type > ilist );

			/**
			* @brief Sobrecarga do operador == para comparar listas
			* @param[in] other lista a ser comparada
			* @return true se as listas são iguais, false caso contrário
			*/
			bool operator==( const lista& other );

			/**
			* @brief Sobrecarga do operador != para comparar listas
			* @param[in] other lista a ser comparada
			* @return true se as listas são diferentes, false caso contrário
			*/
			bool operator!=( const lista& other );

			/**
			* @brief Substitui todos os elementos da lista pelo elemento indicado
			* @param[in] value Elemento a ser utilizado
			*/
			void assign( const_reference value);

			/**
			* @brief Substitui todos os elementos da lista pelos elementos da lista inicializadora
			* @param[in] ilist Lista inicializadora a ser utilizada
			*/
			void assign( std::initializer_list< value_type > ilist );

			/**
			* @brief Substitui todos os elementos da lista pelos do intervalo indicado
			* @details Se o fim do intervalo for alcançado, os proximos elementos da lista 
			* serão substituidos pela lista novamente, de maneira repetitiva até a lista ficar completo
			* @param[in] first Inicio do intervalo
			* @param[in] last Fim do intervalo
			*/
			template < typename InputItr >
			void assign( InputItr first, InputItr last);

			//								==========================
			//								===== Element access =====

			/**
			* @brief Acessa o elemento na posição indicada
			* @param[in] pos Posição do elemento que se deseja acessar
			* @return Retorna uma referencia para o elemento na posição indicada
			*/
			reference at ( size_type pos );

			/**
			* @brief Acessa o elemento na posição indicada
			* @param[in] pos Posição do elemento que se deseja acessar
			* @return Retorna uma referencia constante para o elemento na posição indicada
			*/
			const_reference at ( size_type pos ) const;

			/**
			* @brief Acessa o ultimo elemento da lista
			* @return Retorna uma referencia para o ultimo elemento da lista
			*/
			reference back( void );

			/**
			* @brief Acessa o primeiro elemento da lista
			* @return Retorna uma referencia para o primeiro elemento da lista
			*/
			reference front(void);

			/**
			* @brief Acessa o primeiro elemento da lista, mas não é possivel alterar o seu valor
			* @return Retorna uma referencia constante para o primeiro elemento da lista
			*/
			const_reference back( void ) const;

			/**
			* @brief Acessa o primeiro elemento da lista, mas não é possivel alterar o seu valor
			* @return Retorna uma referencia constante para o primeiro elemento da lista
			*/
			const_reference front( void ) const;

			//								=====================
			//								===== Iterators =====

			/**
			* @brief Cria e retorna um iterador a partir do endereço do primeiro elemento da lista
			* @return Iterador para o primeiro elemento da lista
			*/
			iterator begin( void );

			/**
			* @brief Cria e retorna um iterador a partir do endereço do ultimo elemento da lista
			* @return Iterador para o ultimo elemento da lista
			*/
			iterator end( void );

			/**
			* @brief Cria e retorna um iterador constante a partir do endereço do primeiro elemento da lista
			* @return Iterador para o primeiro elemento da lista
			*/
			const_iterator cbegin( void ) const;

			/**
			* @brief Cria e retorna um iterador constante a partir do endereço do ultimo elemento da lista
			* @return Iterador para o ultimo elemento da lista
			*/
			const_iterator cend( void ) const;

			//								====================
			//								===== Capacity =====

			/**
			* @brief Verifica se a lista possui algum elemento, isto é o tamanho lógico é 0
			* @return true se ele não está vazio, false caso esteja
			*/
			bool empty( void ) const;

			/**
			* @brief Acessa e retorna o tamanho lógico da lista
			* @return tamanho lógico da lista
			*/
			size_type size( void ) const;

			//								=====================
			//								===== Modifiers =====

			/**
			* @brief Zera o numero de elementos da lista
			*/
			void clear( void );

			/**
			* @brief Insere o elemento indicado na posição indicada pelo iterador
			* @param[in] itrt Iterador que indica a posição
			* @param[in] value Elemento a ser inserido
			* @return Iterador que indica a posição do elemento inserido ( a mesma que foi passada )
			*/
			iterator insert( iterator itrt, const_reference value );

			/**
			* @brief Insere todos os elementos indicados do intervalo indicado na lista
			* a partir posição indicada pelo iterador
			* @param[in] itrt Iterador que indica a posição inicial
			* @param[in] first Inicio do intevalo indicado
			* @param[in] last Fim do intevalo indicado
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			template < typename InputItr >
			iterator insert( iterator itrt, InputItr first, InputItr last);

			/**
			* @brief Insere todos da lista inicializadora indicada na lista
			* a partir posição indicada pelo iterador
			* @param[in] itrt Iterador que indica a posição inicial
			* @param[in] ilist Lista inicializadora
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			iterator insert( iterator itrt, std::initializer_list< value_type > ilist );

			/**
			* @brief Insere o elemento indicado na posição indicada pelo iterador
			* @param[in] pos Posição onde será inserido o elemento
			* @param[in] value Elemento a ser inserido
			* @return Iterador que indica a posição do elemento inserido ( a mesma que foi passada )
			*/
			iterator insert( size_type pos, const_reference value );

			/**
			* @brief Insere todos os elementos indicados do intervalo indicado na lista
			* a partir posição indicada pelo iterador
			* @param[in] pos Posição inicial
			* @param[in] first Inicio do intevalo indicado
			* @param[in] last Fim do intevalo indicado
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			template < typename InputItr >
			iterator insert( size_type pos, InputItr first, InputItr last);

			/**
			* @brief Insere todos da lista inicializadora indicada na lista
			* a partir posição indicada pelo iterador
			* @param[in] pos Posição inicial
			* @param[in] ilist Lista inicializadora
			* @return Iterador que indica a posição do ultimo elemento inserido
			*/
			iterator insert( size_type pos, std::initializer_list< value_type > ilist );

			/**
			* @brief Retira da lista os elementos no intervalo indicado
			* @param[in] first Inicio do intervalo
			* @param[in] last Fim do intervalo
			* @return Retorna um iterador para a ultima posição válida da lista
			*/
			iterator erase( iterator first, iterator last );

			/**
			* @brief Retira da lista o elemento da itrtição indicada
			* @param[in] pos Iterador para a posição do elemento a ser retirado
			* @return Retorna um iterador para a ultima posição válida da lista
			*/
			iterator erase( iterator itrt );

			/**
			* @brief Adiciona o elemento indicado ao inicio da lista
			* @param[in] valor a ser adicionado
			*/
			void push_front ( const_reference value );

			/**
			* @brief Adiciona o elemento indicado ao fim da lista
			* @param[in] valor a ser adicionado
			*/
			void push_back (const_reference value );

			/**
			* @brief Elimina o ultimo elemento da lista
			*/
			void pop_back ( void );

			/**
			* @brief Elimina o primeiro elemento da lista
			*/
			void pop_front ( void );

			/**
			* @brief Altera a quantidade de elementos na lista
			* @param[in] new_size Nova quantidade de elementos da lista
			*/
			void resize ( size_type new_size );

			/**
			* @brief Método swap da própria classe
			* @param[in] other Primeira lista a ser trocado
			*/
			void swap ( lista & other );

			//							============================
			//							===== Friend Functions =====

			/**
			* @brief Sobrecarga do método swap da std
			* @param[in] first_ Primeira lista a ser trocado
			* @param[in] second_ Segunda lista a ser trocado
			*/
			friend void swap ( lista< value_type > & first_, lista< value_type > & second_ )
			{
				jv::node< value_type > temp( first_.m_head );
				first_.m_head = second_.m_head;
				second_.m_head = temp;

				temp = first_.m_tail;
				first_.m_tail = second_.m_tail;
				second_.m_tail = temp;
			}

			/**
			* @brief Sobrecarga do operador <<
			* @param[in] o Ostream alvo
			* @param[in] lista_alvo Lista que terá os elementos impressos
			* @return Ostream com os elementos da lista e o tamanho dela
			*/
			friend std::ostream& operator<< ( std::ostream& o, lista<value_type> & lista_alvo)
			{
				o << "[ ";
				for ( auto i = lista_alvo.begin(); i != lista_alvo.end(); ++i)
				{
					o << *i << " ";
				}
				//o << "]\t Tamanho: " << lista_alvo.size() << std::endl;
				o << "]";
				return o;
			}
	};
}

#include "Node.inl"
#include "MyIterator.inl"
#include "lista.inl"

#endif