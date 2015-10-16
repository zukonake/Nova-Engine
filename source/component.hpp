//component.hpp
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

template < class componentType >

class cComponent
{
	friend class componentHandler;
	std::string name;
	componentType value;
	cComponent();
}

#endif
