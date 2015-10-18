//component.hpp
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <string>

class cComponentInterface
{
	public:
	virtual bool someFunction() { return true;}
};

template < typename componentType >
class cComponent : public cComponentInterface
{
	public:
	std::string name;
	componentType value;
	operator componentType();
	public:
	componentType returnValue();
	bool someFunction() { return false;}
	cComponent( std::string _name, componentType _value );
};

#endif
