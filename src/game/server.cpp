//server.cpp

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

void cServer::initializeObjects( std::shared_ptr< cLuaWrapper > luaWrapper )
{
	
}

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

void cServer::initialize( std::shared_ptr< cLuaWrapper > luaWrapper )
{
	initializeObjects( luaWrapper );
}

void cServer:connectClient( std::shared_ptr< cClient > target )
{
	target->connectServer( objectTable );
	clients.push_back( target );
}

static cServer& cServer::newInstance( std::string _datasetName )
{
	datasetName = _datasetName;
	static cGame instance;
	return instance;
}
