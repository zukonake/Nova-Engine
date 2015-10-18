//componentHandler.hpp
#ifndef COMPONENTHANDLER_HPP
#define COMPONENTHANDLER_HPP

#include <vector>
#include <string>
#include <memory>

#include "component.hpp"

class cComponentHandler
{
	std::vector < std::unique_ptr< cComponentInterface* > componentList;
	template < typename componentType >
	cComponent< componentType > returnComponent( std::string componentName );
	public:
	bool isComponentPresent( std::string componentName );
	template < typename componentType >
	componentType returnComponentValue( std::string componentName );
	template < typename componentType >
	bool setComponentValue( std::string componentName, componentType newValue );
	bool deleteComponent( std::string componentName );
	cComponentHandler();
}

#endif
