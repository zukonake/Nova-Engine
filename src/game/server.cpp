//server.cpp

#include "server.hpp"

void cServer::initializeVariables()
{
	luaWrapper->openScript( global::configPath + "config.lua" );
	datasetPath = luaWrapper->getVariable< std::string >( "dataset" );
}

void cGame::initializeObjects()
{
	objectTable[ "tileset" ] = table();
	objectTable[ "blockSubtype" ] = table();
	objectTable[ "block" ] = table();
	objectTable[ "boardGenerator" ] = table();
	objectTable[ "board" ] = table();
	objectTable[ "entitySubtype" ] = table();
	objectTable[ "entity" ] = table();
	objectTable[ "entityAction" ] = table();
	objectTable[ "entityControl" ] = table();
	objectTable[ "interfaceComponent" ] = table();
	objectTable[ "interface" ] = table();
	luaWrapper->openScript( workingDirectory + "src/lua/scripts/listFiles.lua" );
	for( auto i : global::objectsToLoad )
	{
		auto fileList = luaWrapper->runFunction< std::vector< std::string > >( "listFiles",
			global::workingDirectory + global::configPath + "dataset/" + datasetPath + global::objectsToLoad[ i ] );
		for( auto iA : fileList )
		{
			luaWrapper->openScript( global::configPath + "dataset/" + datasetPath + global::objectsToLoad[ i ] + fileList[ iA ] );
			std::string tableName = luaWrapper->getGlobal< std::string >( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			table luaToCpp = luaWrapper->getGlobal< table >( tableName );
			if( global::objectsToLoad[ i ] == "tileset" )
			{
				objectTable[ "tileset" ][ tableName ] = std::make_shared< cTileset >( new cTileset( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "blockSubtype" )
			{
				objectTable[ "blockSubtype" ][ tableName ] = std::make_shared< cBlockSubtype >( new cBlockSubtype( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "block" )
			{
				objectTable[ "block" ][ tableName ] = std::make_shared< cBlock >( new cBlock( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "boardGenerator" )
			{
				objectTable[ "boardGenerator" ][ tableName ] = std::make_shared< cBoardGenerator >( new cBoardGenerator( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "board" )
			{
				objectTable[ "board" ][ tableName ] = std::make_shared< cBoard >( new cBoard( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entitySubtype" )
			{
				objectTable[ "entitySubtype" ][ tableName ] = std::make_shared< cEntitySubtype >( new cEntitySubtype( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entity" )
			{
				objectTable[ "entity" ][ tableName ] = std::make_shared< cEntity >( new cEntity( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entityAction" )
			{
				objectTable[ "entityAction" ][ tableName ] = std::make_shared< cEntityAction >( new cEntityAction( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entityControl" )
			{
				objectTable[ "entityControl" ][ tableName ] = std::make_shared< cEntityControl >( new cEntityControl( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "interfaceComponent" )
			{
				objectTable[ "interfaceComponent" ][ tableName ] = std::make_shared< cInterfaceComponent >( new cInterfaceComponent( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "interface" )
			{
				objectTable[ "interface" ][ tableName ] = std::make_shared< cInterface >( new cInterface( luaToCpp, &objectTable ) );
			}
		}
	}
}

int cGame::work()
{
	while( running )
	{
		interfaceHandler->render();
		interfaceHandler->choice();
		interfaceHandler->clear();
	}
	return 0;
}

cGame::cGame()
{
	luaWrapper = std::make_unique< cLuaWrapper >( new cLuaWrapper );
	initializeVariables();
	initializeObjects();
	work();
}

std::istream& operator>>( istream& os, cGame& game )
{
	//load
}

std::ostream& operator<<( ostream& os, const cGame& game )
{
	//save
}
