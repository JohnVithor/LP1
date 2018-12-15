/**
* @file		Node.inl
* @brief	Implementação do métodos da classe jv::node
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	25/10/2017
* @date		28/10/2017	
*/

#include "lista.hpp"
//#include <iostream>

template < typename value_type >
using node_pointer = std::shared_ptr< jv::node< value_type > >;

template < typename value_type >
using const_node_pointer = std::shared_ptr< const jv::node< value_type > >;

template < typename value_type >
using reference = value_type&;

template < typename value_type >
using const_reference = const value_type&;

//									========= Node =========

template < typename value_type >
jv::node< value_type >::node()
		:m_value()
		,m_previous( nullptr )
		,m_next( nullptr )
		{ /* Vazio */ }

template <typename  value_type >
jv::node< value_type >::node( value_type  value)
		:m_value( value )
		,m_previous( nullptr )
		,m_next( nullptr )
		{ /* Vazio */ }

template <typename  value_type >
jv::node< value_type >::node ( value_type value, node_pointer previous_ptr, node_pointer next_ptr )
		:m_value( value )
		,m_previous( previous_ptr )
		,m_next( next_ptr )
		{ /* Vazio */ }

template <typename  value_type >
jv::node< value_type >::node ( jv::node< value_type > &alvo )
		:m_value( alvo.value )
		,m_previous( alvo.previous_ptr )
		,m_next( alvo.next_ptr )
		{ /* Vazio */ }

template < typename value_type >
jv::node< value_type >::~node()
{
	m_previous.reset();
	m_next.reset();
}

template < typename value_type >
jv::node< value_type >& jv::node< value_type >::operator=( const jv::node< value_type >& other )
{
	m_value = other.m_value;
	m_previous = other.m_previous;
	m_next = other.m_next;
}

template <typename  value_type >
reference< value_type > jv::node< value_type >::get_value() 
{
	return m_value;
}

template <typename  value_type >
void jv::node< value_type >::set_value ( value_type value)
{
	m_value = value;
}

template <typename  value_type >
node_pointer< value_type >& jv::node< value_type >::get_next() 
{
	return m_next;
}

template <typename  value_type >
void jv::node< value_type >::set_next ( node_pointer next_ptr)
{
	m_next = next_ptr;
}

template <typename  value_type >
node_pointer< value_type >& jv::node< value_type >::get_previous() 
{
	return m_previous;
}

template <typename  value_type >
void jv::node< value_type >::set_previous ( node_pointer previous_ptr)
{
	m_previous = previous_ptr;
}

template <typename  value_type >
std::ostream& operator<< (std::ostream &o, jv::node< value_type > const &n)
{
	o << n.m_value;
	return o;
}

template <typename  value_type >
reference< value_type > jv::node< value_type >::operator* ()
{
	return m_value;
}

template < typename value_type >
bool jv::node< value_type >::operator==( const jv::node< value_type > & other) const
{
	if ( m_next != other.m_next or m_previous != other.m_previous or m_value != other.m_value )
	{
		return false;
	}

	return true;
}

template < typename value_type >
bool jv::node< value_type >::operator!=( const jv::node< value_type > & other) const
{
	return !(*this == other);
}