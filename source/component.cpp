//component.cpp
#include "component.hpp"

template < typename componentType >
cComponent<componentType>::operator componentType()
{
	return ( componentType )value;
}

template < typename componentType >
componentType cComponent< componentType >::returnValue()
{
	return value;
}

template < typename componentType >
cComponent<componentType>::cComponent( std::string _name, componentType _value ) :
	name( _name ),
	value( _value )
{
	
}
