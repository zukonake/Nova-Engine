//componentHandler.cpp

#include "componentHandler.hpp"

template < typename componentType >
cComponent< componentType >& returnComponent( std::string componentName )
{
	for( uint16_t i = 0; i < componentList.size(); i++ )
	{
		if( static_cast< cComponent< componentType >* >( componentList[i] )->name == componentName )
		{
			return componentList[i];
		}
	}
	return NULL;
}

bool isComponentPresent( std::string componentName )
{
	if( returnComponent( componentName ) == NULL )
	{
		return false;
	}
	return true;
}

template < typename componentType >
componentType* returnComponentValue( std::string componentName )
{
	if( not isComponentPresent )
	{
		return NULL;
	}
	return static_cast< cComponent< componentType >* >( component )->value;
}


template < typename componentType >
bool setComponentValue( std::string componentName, componentType newValue )
{
	if( not isComponentPresent( componentName ) )
	{
		return false
	}
	cComponent< componentType >& component = returnComponent( componentName )
	
	return true;
}
