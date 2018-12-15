/**
* @file		MyIterator.inl
* @brief	Implementação do métodos da classe jv::MyIterator 
* @details	
*
* @author	João Vítor Venceslau Coelho
* @since	25/10/2017
* @date		28/10/2017	
*/

#include "lista.hpp"
#include <cassert> // assert

typedef std::size_t size_type;

typedef std::ptrdiff_t difference_type;

template < typename value_type >
using node_pointer = std::shared_ptr< jv::node< value_type > >;

template < typename value_type >
using const_node_pointer = std::shared_ptr< const jv::node< value_type > >;

template < typename value_type >
using iterator = jv::MyIterator< value_type >;

template < typename value_type >
using const_iterator = jv::MyIterator< value_type >;

//									========= MyIterator =========

template < typename value_type >
jv::MyIterator< value_type >::MyIterator( node_pointer ptr)
		: m_ptr(ptr)
{ /* Vazio */ }

template < typename value_type >
jv::MyIterator< value_type >::MyIterator( jv::node< value_type >& ptr)
		: m_ptr( std::make_shared< jv::node< value_type > >( ptr ) )
{ /* Vazio */ }

template < typename value_type >
node_pointer< value_type > jv::MyIterator< value_type >::get_pointer ()
{
	return m_ptr;
}

template < typename value_type >
const_node_pointer< value_type > jv::MyIterator< value_type >::get_pointer () const
{
	return m_ptr;
}

template < typename value_type >
iterator<value_type> jv::MyIterator< value_type >::operator++(void)
{
	assert( m_ptr != nullptr );
	//std::cout << " antes :" << m_ptr->get_value() << std::endl;
	m_ptr = m_ptr->get_next();
	//std::cout << " depois :" <<  m_ptr->get_value() << std::endl;
	return *this;
}

template < typename value_type >
iterator<value_type> jv::MyIterator< value_type >::operator++(int)
{
	assert( m_ptr != nullptr );
	iterator< value_type > temp( *this );
	m_ptr = m_ptr->get_next();
	return temp;
}

template < typename value_type >
iterator<value_type> jv::MyIterator< value_type >::operator--(void)
{
	assert( m_ptr != nullptr );
	m_ptr = m_ptr->get_previous();
	return *this;
}

template < typename value_type >
iterator<value_type> jv::MyIterator< value_type >::operator--(int)
{
	assert( m_ptr != nullptr );
	iterator< value_type > temp( *this );
	m_ptr = m_ptr->get_previous();
	return temp;
}

template < typename value_type >
iterator<value_type> jv::MyIterator< value_type >::operator+( size_type num )
{
	iterator<value_type> temp = *this;
	for ( size_type i = 0; i < num; ++i)
	{
		assert( temp.m_ptr != nullptr );
		temp.m_ptr = (temp.m_ptr)->get_next();
	}
	return temp;
}

template < typename value_type >
iterator<value_type> jv::MyIterator< value_type >::operator-( size_type num )
{
	iterator<value_type> temp = *this;
	for ( size_type i = 0; i < num; ++i)
	{
		assert( temp.m_ptr != nullptr );
		temp.m_ptr = (temp.m_ptr)->get_previous();
	}
	return temp;
}

template < typename value_type >
difference_type jv::MyIterator< value_type >::operator-( iterator<value_type> itrt )
{
	difference_type count = 0;
	iterator<value_type> temp = itrt;
	while ( temp != *this and temp != nullptr )
	{
		temp.m_ptr = (temp.m_ptr)->get_previous();
		++count;
	}

	if ( temp == nullptr )
	{
		temp = itrt;
		count = 0;
		while ( temp != *this )
		{
			temp.m_ptr = (temp.m_ptr)->get_next();
			++count;
		}
	}

	return count;
}

template < typename value_type >
value_type& jv::MyIterator< value_type >::operator*(void)
{
	assert( m_ptr != nullptr );
	return m_ptr->get_value();
}

template < typename value_type >
const value_type& jv::MyIterator< value_type >::operator*(void) const
{
	assert( m_ptr != nullptr );
	return m_ptr->get_value();
}

template < typename value_type >
bool jv::MyIterator< value_type >::operator==(const iterator< value_type >& other) const
{
	return m_ptr == other.m_ptr;
}

template < typename value_type >
bool jv::MyIterator< value_type >::operator!=(const iterator< value_type >& other) const
{
	return m_ptr != other.m_ptr;
}

template < typename value_type >
bool jv::MyIterator< value_type >::operator==(const_node_pointer other) const
{
	return m_ptr == other;
}

template < typename value_type >
bool jv::MyIterator< value_type >::operator!=(const_node_pointer other) const
{
	return m_ptr != other;
}