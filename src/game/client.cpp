//client.cpp
#include "client.hpp"

void cClient::work()
{
	while( running )
	{

	}
}

void cClient::connectServer( std::shared_ptr< table > _objectTable )
{
	objectTable = _objectTable,
	player = boost::any_cast< std::shared_ptr< cEntity >( objectTable[ "entity" ][ "player" ] ),
	interfaceHandler.camera = std::make_unique( new cCamera( player->pos, player->board ) );
}
/*
cClient::cClient( std::unique_ptr< table > _objectTable, uint screenWidth = 800, uint screenHeight = 640, std::string windowTitle = "Unnamed" ) :
	objectTable( objectTable )
{
	interfaceHandler = interfaceHandler( screenWidth, screenHeight, windowTitle );
	player = std::make_shared( objectTable[ "entity" ][ "player" ] );
	interfaceHandler.camera = std::make_unique( new cCamera( player->pos, player->board ) );
}*/

cClient::cClient( uint screenWidth = 800, uint screenHeight = 640, std::string windowTitle = "Unnamed" )
{
	interfaceHandler = interfaceHandler( screenWidth, screenHeight, windowTitle );
}
