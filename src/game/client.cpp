//client.cpp
#include "client.hpp"

void cClient::work()
{
	while( running )
	{

	}
}

cClient::cClient( std::unique_ptr< table > _objectTable ) :
	objectTable( move( objectTable ) )
{
	player = std::make_unique( objectTable[ "entity" ][ "player" ] );
	camera = std::make_unique( new cCamera( player->pos, player->board ) );
}

cClient::cClient()
{
	
}
