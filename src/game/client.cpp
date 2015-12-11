//client.cpp
#include "client.hpp"

void cClient::work()
{
	while( running )
	{

	}
}

void cClient::connectServer( std::shared_ptr< table > _objectTable, std::string windowTitle )
{
	objectTable = _objectTable,
	player = boost::any_cast< std::shared_ptr< cEntity > >( objectTable[ "entity" ][ "player" ] ),
	interfaceHandler.camera = std::make_unique( new cCamera( player->pos, player->board ) );
	interfaceHandler.windowTitle = windowTitle;
}

cClient::cClient( uint screenWidth = 800, uint screenHeight = 640, std::string windowTitle = "Unnamed" )
{
	interfaceHandler = cInterfaceHandler( screenWidth, screenHeight, windowTitle );
}
