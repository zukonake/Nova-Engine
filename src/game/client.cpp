//client.cpp
#include "client.hpp"

void cClient::work()
{
	while( running )
	{

	}
}

void cClient::connectServer( std::shared_ptr< fixedTable > _objectTable, std::string windowTitle )
{
	objectTable = _objectTable;
	player = boost::any_cast< std::shared_ptr< cEntity > >( (*objectTable)[ "entity" ][ "player" ] );
	interfaceHandler->camera = std::make_unique< cCamera >( player );
	interfaceHandler->windowTitle = windowTitle;
}

cClient::cClient( uint screenWidth = 800, uint screenHeight = 640, std::string windowTitle = "Unnamed" )
{
	interfaceHandler = std::make_unique< cInterfaceHandler >( screenWidth, screenHeight, windowTitle );
}
