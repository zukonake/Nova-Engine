//componentHandler.cpp

#include "componentHandler.hpp"

template < typename componentType >
int16_t returnComponentIndex( std::string componentName )
{
	for( uint16_t i = 0; i < componentList.size(); i++ )
	{
		if( static_cast< cComponent< componentType >* >( componentList[i] )->name == componentName )
		{
			return i;
		}
	}
	return -1;
}

template < typename componentType >
bool isComponentPresent( std::string componentName )
{
	if( returnComponentIndex< componentType >( componentName ) == -1 )
	{
		return false;
	}
	return true;
}

template < typename componentType >
componentType* returnComponentValue( std::string componentName )
{
	if( not isComponentPresent< componentType >( componentName ) )
	{
		return NULL;
	}
	return static_cast< cComponent< componentType >* >( component )->value;
}


template < typename componentType >
bool setComponentValue( std::string componentName, componentType newValue )
{
	if( not isComponentPresent< componentType >( componentName ) )
	{
		return false
	}
	static_cast< cComponent< componentType >* >( componentList[ returnComponentIndex< componentType >( componentName ) ] )->value = newValue;
	return true;
}

bool deleteComponent( std:;string componentName )
{
	if( not is componentPresent< componentType >( componentName ) )
	{
		return false
	}
	componentList.erase( returnComponentIndex< componentType >( componentName ) )
	return true;
}

template < typename componentType >
bool insertComponent( cComponent* component )
{
	if( isComponentPresent< componentType >( componentName ) )
	{
		return false;
	}
	componentList.push_back( component );
	return true;
}
