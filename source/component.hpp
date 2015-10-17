//component.hpp
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

template < typename componentType >

class cComponent
{
	friend class componentHandler;
	std::string name;
	componentType value;
	operator componentType();
	public:
	componentType returnValue();
	componentType setValue();
	cComponent( std::string _name, componentType _value );
};

#endif
