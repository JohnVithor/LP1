/**
* @file		lista.inl
* @brief	Implementação do métodos da classe jv::lista
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	25/10/2017
* @date		28/10/2017	
*/

#include "lista.hpp"
#include <iostream>
#include <initializer_list>
//											===========================
//											===== SPECIAL MEMBERS =====

template < typename value_type >
jv::lista< value_type >::lista()
		:m_head( std::make_shared< jv::node< value_type > >() )
		,m_tail( std::make_shared< jv::node< value_type > >() )
		,m_size( 0 )
{
	m_head->set_previous();
	m_head->set_next( m_tail );
	m_tail->set_previous( m_head );
	m_tail->set_next();
}

template < typename value_type >
jv::lista< value_type >::lista( size_type count, value_type value )
		:m_head( std::make_shared< jv::node< value_type > >() )
		,m_tail( std::make_shared< jv::node< value_type > >() )
		,m_size( count )
{
	m_head->set_previous();
	m_head->set_next( m_tail );
	m_tail->set_previous( m_head );
	m_tail->set_next();

	node_pointer temp( m_head );
	while(count-- > 0)
	{
		node_pointer aux = std::make_shared< jv::node< value_type > >( value, temp, temp->get_next() );
		temp->get_next()->set_previous( aux );
		temp->set_next( aux );
		temp = temp->get_next();
	}
}

template < typename value_type >
template < typename InputItr >
jv::lista< value_type >::lista ( InputItr first, InputItr last)
		:m_head( std::make_shared< jv::node< value_type > >() )
		,m_tail( std::make_shared< jv::node< value_type > >() )
		,m_size( 0 )
{
	m_head->set_previous();
	m_head->set_next( m_tail );
	m_tail->set_previous( m_head );
	m_tail->set_next();

	while( first != last )
	{
		push_back( *first );
		++first;
	}
}

template < typename  value_type >
jv::lista< value_type >::lista ( const jv::lista< value_type > & other)
		:m_head( std::make_shared< jv::node< value_type > >() )
		,m_tail( std::make_shared< jv::node< value_type > >() )
		,m_size( 0 )
{
	m_head->set_previous();
	m_head->set_next( m_tail );
	m_tail->set_previous( m_head );
	m_tail->set_next();

	for( auto it( other.cbegin() ); it != other.cend(); ++it )
	{
		push_back( *it );
	}
}

template < typename  value_type >
jv::lista< value_type >::lista ( std::initializer_list< value_type > ilist )
		:m_head( std::make_shared< jv::node< value_type > >() )
		,m_tail( std::make_shared< jv::node< value_type > >() )
		,m_size( 0 )
{
	m_head->set_previous();
	m_head->set_next( m_tail );
	m_tail->set_previous( m_head );
	m_tail->set_next();

	for( auto it( ilist.begin() ); it != ilist.end(); ++it )
	{
		push_back( *it );
	}
}


template <typename  value_type >
jv::lista< value_type >::~lista()
{
	m_head = m_head->get_next();

	while ( m_head != m_tail )
	{
		m_head->get_previous()->set_next();
		m_head->set_previous();
		m_head = m_head->get_next();
		--m_size;
	}
	m_head->get_previous()->set_next();
	m_tail->set_previous();
}


template < typename value_type >
jv::lista< value_type >& jv::lista< value_type >::operator=( const lista& other )
{
	clear();

	for( auto it( other.cbegin() ); it != other.cend(); ++it )
	{
		push_back( *it );
	}
	return *this;
}

template < typename value_type >
jv::lista< value_type >& jv::lista< value_type >::operator=( std::initializer_list< value_type > ilist )
{
	clear();

	for( auto it( ilist.begin() ); it != ilist.end(); ++it )
	{
		push_back( *it );
	}
	return *this;
}

template < typename value_type >
bool jv::lista< value_type >::operator==( const lista& other )
{
	if( m_size != other.m_size )
	{
		return false;
	}
	else
	{
		auto it1( cbegin() );
		auto it2( other.cbegin() );
		while ( it1 != cend() )
		{
			if( *it1 != *it2 )
			{
				return false;
			}
			++it1;
			++it2;
		}
	}

	return true;
}

template < typename value_type >
bool jv::lista< value_type >::operator!=( const lista& other )
{
	return !( *this == other);
}
template <typename value_type >
void jv::lista< value_type >::assign( const_reference value )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}
	node_pointer temp = m_head->get_next();
	while ( temp != this->m_tail )
	{
		temp->set_value(value);
		temp = temp->get_next();
	}
}

template <typename value_type >
void jv::lista< value_type >::assign( std::initializer_list< value_type > ilist )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}

	node_pointer temp = m_head->get_next();
	auto elemento_atual = ilist.begin();

	while ( temp != this->m_tail )
	{
		temp->set_value( *elemento_atual );
		temp = temp->get_next();
		++elemento_atual;

		if (elemento_atual == ilist.end())
		{
			elemento_atual = ilist.begin();
		}
	}

}

template < typename value_type >
template < typename InputItr >
void jv::lista< value_type >::assign( InputItr first, InputItr last )
{
	if ( empty() )
	{
		throw std::out_of_range("assign() -> A lista está vazia!");
	}

	node_pointer temp = m_head->get_next();
	auto elemento_atual = first;

	while ( temp != this->m_tail )
	{
		temp->set_value( *elemento_atual );
		temp = temp->get_next();
		++elemento_atual;

		if (elemento_atual == last)
		{
			elemento_atual = first;
		}
	}
}

//											==========================
//											===== Element access =====

template < typename value_type >
reference<value_type> jv::lista< value_type >::at ( size_type pos )
{
	if ( empty() )
	{
		throw std::out_of_range("at() -> A lista está vazia!");
	}
	if ( pos > m_size )
	{
		throw std::out_of_range("at() -> Acesso fora da lista!");
	}
	size_type count = 0;
	auto it = m_head->get_next();
	while ( count < pos )
	{
		it = it->get_next();
		++count;
	}
	return it->get_value();
}

template < typename value_type >
const_reference<value_type> jv::lista< value_type >::at ( size_type pos ) const
{
	if ( empty() )
	{
		throw std::out_of_range("at() -> A lista está vazia!");
	}
	if ( pos > m_size )
	{
		throw std::out_of_range("at() -> Acesso fora da lista!");
	}

	size_type count = 0;
	auto it = m_head->get_next();
	while ( count < pos )
	{
		it = it->get_next();
		++count;
	}
	return it->get_value();
}

template < typename value_type >
reference<value_type> jv::lista< value_type >::back( void )
{
	if ( empty() )
	{
		throw std::out_of_range("back() -> A lista está vazia!");
	}
	return m_tail->get_previous()->get_value();
}

template < typename value_type >
reference<value_type> jv::lista< value_type >::front(void)
{
	if ( empty() )
	{
		throw std::out_of_range("front() -> A lista está vazia!");
	}
	return m_head->get_next()->get_value();
}

template < typename value_type >
const_reference<value_type> jv::lista< value_type >::back( void ) const
{
	if ( empty() )
	{
		throw std::out_of_range("back() -> A lista está vazia!");
	}
	return m_tail->get_previous()->get_value();
}

template < typename value_type >
const_reference<value_type> jv::lista< value_type >::front( void ) const
{
	if ( empty() )
	{
		throw std::out_of_range("front() -> A lista está vazia!");
	}
	return m_head->get_next()->get_value();
}

//											=====================
//											===== Iterators =====

template < typename value_type >
iterator< value_type > jv::lista< value_type >::begin( void )
{
	return iterator( m_head->get_next() );
}

template < typename value_type >
iterator< value_type > jv::lista< value_type >::end( void )
{
	return iterator( m_tail );
}

template < typename value_type >
const_iterator< value_type > jv::lista< value_type >::cbegin( void ) const
{
	return const_iterator( m_head->get_next() );
}

template < typename value_type >
const_iterator< value_type > jv::lista< value_type >::cend( void ) const
{
	return const_iterator( m_tail );
}

//										====================
//										===== Capacity =====

template < typename value_type >
size_type jv::lista< value_type >::size( void ) const
{
	return m_size;
}

template < typename value_type >
bool jv::lista< value_type >::empty ( void ) const
{
	return m_size == 0;
}

//										=====================
//										===== Modifiers =====

template <typename value_type >
void jv::lista< value_type >::clear ( void )
{
	m_head = m_head->get_next();

	while ( m_head != m_tail )
	{
		m_head->get_previous()->set_next();
		m_head->set_previous();
		m_head = m_head->get_next();
		--m_size;
	}
	m_tail->set_previous();
	m_size = 0;
	m_head->set_next( m_tail );
	m_tail->set_previous( m_head );
}

template < typename value_type >
iterator< value_type > jv::lista< value_type >::insert ( iterator it, const value_type& value )
{
	std::shared_ptr< jv::node< value_type > > new_node = std::make_shared< jv::node< value_type > >( value );
	
	new_node->set_next( it.get_pointer() );
	new_node->set_previous( it.get_pointer()->get_previous() );
	
	it.get_pointer()->get_previous()->set_next( new_node );
	it.get_pointer()->set_previous( new_node );
	
	++m_size;
	
	return iterator( new_node );
}

template < typename value_type >
iterator< value_type > jv::lista< value_type >::insert ( size_type pos, const value_type& value )
{
	return insert( begin() + pos, value);
}

template < typename value_type >
template < typename InputItr >
iterator< value_type > jv::lista< value_type >::insert ( iterator itrt, InputItr first, InputItr last)
{
	--last;
	while( last != first)
	{
		insert(itrt, *last);
		--last;
	}
		
	return itrt;
}

template < typename value_type >
template < typename InputItr >
iterator< value_type > jv::lista< value_type >::insert ( size_type pos, InputItr first, InputItr last)
{
	return insert ( begin() + pos, first, last );
}

template <typename value_type >
iterator< value_type > jv::lista< value_type >::insert ( iterator itrt, std::initializer_list< value_type > ilist)
{
	for (auto i = ilist.end(); i != ilist.begin(); --i )
	{
		insert(itrt, *i );
	}

	return itrt;
}

template <typename value_type >
iterator< value_type > jv::lista< value_type >::insert ( size_type pos, std::initializer_list< value_type > ilist)
{
	return insert( begin() + pos, ilist );
}

template < typename value_type >
iterator< value_type > jv::lista< value_type >::erase ( iterator first, iterator last )
{
	if ( empty() )
	{
		throw std::out_of_range("erase() -> A lista está vazia!");
	}

	while( first != last){
		++first;
		erase( first.get_pointer()->get_previous() );
	}

	return last;
}

template < typename value_type >
iterator< value_type > jv::lista< value_type >::erase ( iterator itrt )
{
	if ( empty() )
	{
		throw std::out_of_range("erase() -> A lista está vazia!");
	}

	node_pointer temp( itrt.get_pointer()->get_next() );

	temp->set_previous( itrt.get_pointer()->get_previous());
	itrt.get_pointer()->get_previous()->set_next( temp );

	itrt.get_pointer()->set_next();
	itrt.get_pointer()->set_previous();

	--m_size;

	return iterator( temp );
}

template <typename value_type >
void jv::lista< value_type >::push_front ( const_reference value )
{
	node_pointer new_node = std::make_shared< jv::node< value_type > >( value, m_head, m_head->get_next() );
	m_head->get_next()->set_previous( new_node );
	m_head->set_next( new_node );
	++m_size;
}

template < typename value_type >
void jv::lista< value_type >::push_back (const_reference value )
{
	node_pointer new_node = std::make_shared< jv::node< value_type > >( value, m_tail->get_previous(), m_tail );
	m_tail->get_previous()->set_next( new_node );
	m_tail->set_previous( new_node );
	++m_size;
}

template <typename value_type >
void jv::lista< value_type >::pop_back ( void )
{
	if ( empty() )
	{
		throw std::out_of_range("pop_back() -> A lista está vazia!");
	}

	m_tail->get_previous()->get_previous()->set_next( m_tail );

	node_pointer temp = m_tail->get_previous()->get_previous();
	m_tail->get_previous().reset();

	m_tail->set_previous( temp );
	--m_size;
}

template <typename value_type >
void jv::lista< value_type >::pop_front ( void )
{
	if ( empty() )
	{
		throw std::out_of_range("pop_front() -> A lista está vazia!");
	}

	m_head->get_next()->get_next()->set_previous( m_head );

	node_pointer temp = m_head->get_next()->get_next();
	m_head->get_next().reset();

	m_head->set_next( temp );
	--m_size;
}

template < typename value_type >
void jv::lista< value_type >::resize ( size_type new_size )
{
	while ( m_size > new_size )
	{
		pop_back();
	}
}

template <typename value_type>
void jv::lista<value_type>::swap ( lista< value_type > & other ) 
{
	jv::node< value_type > temp( *m_head );
	m_head = other.m_head;
	other.m_head = temp;

	temp = m_tail;
	m_tail = other.m_tail;
	other.m_tail = temp;
}