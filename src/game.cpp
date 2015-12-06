//game.cpp
#include "game.hpp"
#include "typedef.hpp"
#include "global.hpp"
#include "game.hpp"
#include "tile.hpp"
#include "blockSubtype.hpp"
#include "block.hpp"
#include "interface.hpp"
#include "boardGenerator.hpp"
#include "board.hpp"
#include "entitySubtype.hpp"
#include "entityControl.hpp"
#include "entity.hpp"

void cGame::initializeGlobals()
{
	luaWrapper->openScript( global::configPath + "config.lua" );
	global::datasetPath = luaWrapper->getVariable< std::string >( "dataset" );
}

void cGame::initializeObjects()
{
	objectTable.insert( std::pair< std::string, table >( "tile", new table ) );
	objectTable.insert( std::pair< std::string, table >( "blockSubtype", new table ) );
	objectTable.insert( std::pair< std::string, table >( "block", new table ) );
	objectTable.insert( std::pair< std::string, table >( "interface", new table ) );
	objectTable.insert( std::pair< std::string, table >( "boardGenerator", new table ) );
	objectTable.insert( std::pair< std::string, table >( "board", new table ) );
	objectTable.insert( std::pair< std::string, table >( "entity", new table ) );
	objectTable.insert( std::pair< std::string, table >( "entityControl", new table ) );
	luaWrapper->openScript( "lua/listFiles.lua" );
	std::vector< std::string >objectsToLoad = luaWrapper->getGlobal< std::vector< std::string > >( "objectsToLoad" );
	for( uint16_t i = 0; i < objectsToLoad.size(); i++ )
	{
		std::vector< std::string > fileList = luaWrapper->runFunction< std::vector< std::string > >( "listFiles", global::configPath + "dataset/" + datasetPath + objectsToLoad[ i ] );
		for( uint16_t iA = 0; iA < fileList.size(); iA++ )
		{
			luaWrapper->openScript( global::configPath + "dataset/" + datasetPath + objectsToLoad[ i ] + fileList[ iA ] );
			std::string tableName = luaWrapper->getGlobal< std::string >( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			table luaToCpp = luaWrapper->getGlobal< table >( tableName );
			if( objectsToLoad[ i ] == "tile" )
			{
				objectTable[ "tile" ][ tableName ] = new cTile( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "blockSubtype" )
			{
				objectTable[ "blockSubtype" ][ tableName ] = new cBlockSubtype( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "block" )
			{
				objectTable[ "block" ][ tableName ] = new cBlock( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "interface" )
			{
				objectTable[ "interface" ][ tableName ] = new cInterface( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "boardGenerator" )
			{
				objectTable[ "boardGenerator" ][ tableName ] = new cBoardGenerator( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "board" )
			{
				objectTable[ "board" ][ tableName ] = new cBoard( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "entitySubtype" )
			{
				objectTable[ "entitySubtype" ][ tableName ] = new cEntitySubtype( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "entityControl" )
			{
				objectTable[ "entityControl" ][ tableName ] = new cEntityControl( luaToCpp, &objectTable );
			}
			else if( objectsToLoad[ i ] == "entity" )
			{
				objectTable[ "entity" ][ tableName ] = new cEntity( luaToCpp, &objectTable );
			}
		}
	}
	player = objectTable[ "entity" ][ "player" ];
	camera = new cCamera( player->[ "posX" ], player->componentTable[ "posY" ], player->board );
}

int cGame::work()
{
	while( running == true )
	{
		interfaceHandler->render();
		interfaceHandler->choice();
		interfaceHandler->clear();
	}
	return 0;
}

cGame::cGame()
{
	luaWrapper = new cLuaWrapper;
	initializeGlobals();
	initializeObjects();
	work();
}

std::istream& operator>>( istream& os, cGame& game ); //load
std::ostream& operator<<( ostream& os, const cGame& game ); //save
