//server.cpp
#include <cassert>
#include <algorithm>
//
#include "server.hpp"
#include <render/tileset.hpp>
#include <block/blockSubtype.hpp>
#include <block/block.hpp>
#include <board/boardGenerator.hpp>
#include <board/board.hpp>
#include <entity/entitySubtype.hpp>
#include <entity/entity.hpp>
#include <entity/entityAction.hpp>
#include <entity/entityControl.hpp>
#include <render/interfaceComponent.hpp>
#include <render/interface.hpp>

void cServer::work()
{
	while( running )
	{
		interfaceHandler->render();
		interfaceHandler->choice();
		interfaceHandler->clear();
	}
	return 0;
}

void cServer::connectClient( std::shared_ptr< cClient > target )
{
	target->connectServer( dataset );
	clients.push_back( target );
}

void cServer::disconnectClient( std::shared_ptr< cClient > target )
{
	auto iterator = std::find( clients.begin(), clients.end(), target );
	assert( iterator != clients.end() ); //Assert that the client is connected
	clients[ iterator ]->disconnectServer();
	clients.erase( iterator );
}

std::shared_ptr< cBoard > cServer::getBoard( uint index )
{
	return entities[ id ];
}

std::shared_ptr< cEntity > cServer::getEntity( uint index )
{
	return entities[ id ];
}

static cServer& cServer::newInstance( std::string _datasetName )
{
	datasetName = _datasetName;
	static cGame instance;
	return instance;
}
