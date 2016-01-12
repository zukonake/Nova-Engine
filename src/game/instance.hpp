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
	typedef std::vector< std::shared_ptr< cBoard > > boardVector;
	typedef std::vector< std::shared_ptr< cEntity > > entityVector;

	boardVector boards;
	entityVector entities;
public:
	std::shared_ptr< cEntity > getEntity( uint index );
	std::shared_ptr< cBoard > getBoard( uint index );
	void addEntity( std::shared_ptr< cEntity > target );
	void addBoard( std::shared_ptr< cBoard > target );
	void removeEntity( uint index );
	void removeEntity( std::shared_ptr< cEntity > target );
	void removeBoard( uint index );
	void removeBoard( std::shared_ptr< cBoard > target );

	cInstance();
}

#endif
