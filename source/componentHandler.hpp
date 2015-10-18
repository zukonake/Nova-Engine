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
	uint16_t returnComponentIndex( std::string componentName );
	public:
	template < typename componentType >
	bool isComponentPresent( std::string componentName );
	template < typename componentType >
	componentType returnComponentValue( std::string componentName );
	template < typename componentType >
	bool setComponentValue( std::string componentName, componentType newValue );
	template < typename componentType >
	bool deleteComponent( std::string componentName );
	template < typename componentType >
	bool insertComponent( cComponent* component );
	cComponentHandler();
}

#endif
