/**
* @file		lista_ordenada.inl
* @brief	Implementação do métodos da classe jv::lista_ordenada
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	28/10/2017
* @date		28/10/2017	
*/

#include "lista_ordenada.hpp"
#include <iostream>
//											===========================
//											===== SPECIAL MEMBERS =====

template < typename value_type >
jv::lista_ordenada< value_type >::lista_ordenada()
		:jv::lista< value_type >()
	{ /* Vazio */ }

template < typename value_type >
jv::lista_ordenada< value_type >::lista_ordenada( size_type count, value_type value )
		:jv::lista< value_type >( count, value )
	{ /* Vazio */ }

template < typename value_type >
template < typename InputItr >
jv::lista_ordenada< value_type >::lista_ordenada ( InputItr first, InputItr last)
{
	this->m_head->set_previous();
	this->m_head->set_next( this->m_tail );
	this->m_tail->set_previous( this->m_head );
	this->m_tail->set_next();

	while( first != last )
	{
		insert( *first );
		++first;
	}
}

template < typename  value_type >
jv::lista_ordenada< value_type >::lista_ordenada ( const jv::lista_ordenada< value_type > & other)
{
	this->m_head->set_previous();
	this->m_head->set_next( this->m_tail );
	this->m_tail->set_previous( this->m_head );
	this->m_tail->set_next();

	for( auto it( other.cbegin() ); it != other.cend(); ++it )
	{
		insert( *it );
	}
}

template < typename  value_type >
jv::lista_ordenada< value_type >::lista_ordenada ( std::initializer_list< value_type > ilist )
{
	this->m_head->set_previous();
	this->m_head->set_next( this->m_tail );
	this->m_tail->set_previous( this->m_head );
	this->m_tail->set_next();

	for( auto it( ilist.begin() ); it != ilist.end(); ++it )
	{
		insert( *it );
	}
}

//										=====================
//										===== Modifiers =====

template < typename value_type >
iterator< value_type > jv::lista_ordenada< value_type >::insert ( const_reference value )
{
	iterator it = this->begin() ;
	while ( value >= *it and it != this->end() )
	{
		++it;
	}

	node_pointer new_node = std::make_shared< jv::node< value_type > >( value );
	new_node->set_next( it.get_pointer() );
	new_node->set_previous( it.get_pointer()->get_previous() );

	it.get_pointer()->get_previous()->set_next( new_node );
	it.get_pointer()->set_previous( new_node );

	++(this->m_size);
	
	return iterator( new_node );
}

template < typename value_type >
template < typename InputItr >
iterator< value_type > jv::lista_ordenada< value_type >::insert ( InputItr first, InputItr last)
{
	iterator itrt = insert( *first++ );
	while( first != last )
	{
		itrt = insert( *first++ );
	}
	return itrt;
}

template <typename value_type >
iterator< value_type > jv::lista_ordenada< value_type >::insert ( std::initializer_list< value_type > ilist)
{
	iterator itrt = insert( *(ilist.begin()) );
	for (auto i = ilist.begin()+1; i != ilist.end(); ++i )
	{
		itrt = insert( *i );
	}
		
	return itrt;
}