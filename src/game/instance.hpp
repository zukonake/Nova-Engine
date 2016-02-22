#ifndef INSTANCE_HPP
#define INSTANCE_HPP

#include <memory>
#include <vector>
//
#include <typedef.hpp>
#include <board/board.hpp>
#include <entity/entity.hpp>

class cInstance
{
	typedef std::vector< std::shared_ptr< cEntity > > entityVector;

	entityVector entities;
public:
	std::shared_ptr< cEntity > getEntity( uint index );
	std::shared_ptr< cBoard > board;
	void addEntity( std::shared_ptr< cEntity > target );
	void removeEntity( uint index );
	void removeEntity( std::shared_ptr< cEntity > target );
	cInstance( std::shared_ptr< cBoard> _board );
}

#endif
