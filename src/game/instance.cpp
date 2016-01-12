#include <algorithm>
#include <cassert>
//
#include "instance.cpp"

int getEntityIndex( std::shared_ptr< cEntity > target )
{
	auto index = std::find( entities.begin(), entities.end(), target );
	cassert( entities.size() - 1 >= index && index >= 0 );
	if( 
}

std::shared_ptr< cEntity > cInstance::getEntity( uint index )
{
	assert( entities.size() - 1 >= index && index >= 0 );
	return entities[ index ];
}

std::shared_ptr< cBoard > cInstance::getBoard( uint index )
{	
	assert( boards.size() - 1 >= index && index >= 0 );
	return boards[ index ];
}

void cInstance::addEntity( std::shared_ptr< cEntity > target )
{
	entities.push_back( target );
	return;
}

void cInstance::addBoard( std::shared_ptr< cBoard > target )
{
	boards.push_back( target );
	return;
}

void cInstance::removeEntity( uint index )
{
	assert( entities.size() - 1 >= index && index >= 0 );
	entities.erase( index );
	return;
}

void cInstance::removeEntity( std::shared_ptr< cEntity > target )
{
	int* index = std::find( entities.begin(), entities.end(), target );
	
}

void cInstance::removeBoard( uint index )
{
	
}

void cInstance::removeBoard( std::shared_ptr< cBoard > target )
{
	
}
