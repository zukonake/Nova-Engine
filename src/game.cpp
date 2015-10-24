//game.cpp
#include "game.hpp"
#include "lua/luaTable.hpp"
#include "lua/luaWrapper.hpp"
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

void cGame::initializeObjects()
{
	objectList.set< std::vector< cTile* >* >( cLuaEntry( "tile", new std::vector< cTile* >() );
	objectList.set< std::vector< cBlockSubtype* >* >( cLuaEntry( "blockSubtype", new std::vector< cBlockSubtype* >() );
	objectList.set< std::vector< cBlock* >* >( cLuaEntry( "block", new std::vector< cBlock* >() );
	objectList.set< std::vector< cInterface* >* >( cLuaEntry( "interface", new std::vector< cInterface* >() );
	objectList.set< std::vector< cBoardGenerator* >* >( cLuaEntry( "boardGenerator", new std::vector< cBoardGenerator* >() );
	objectList.set< std::vector< cBoard* >* >( cLuaEntry( "board", new std::vector< cBoard* >() );
	objectList.set< std::vector< cEntity* >* >( cLuaEntry( "entity", new std::vector< cEntity* >() );
	objectList.set< std::vector< cEntityControl* >* >( cLuaEntry( "entityControl", new std::vector< cEntityControl* >() );
	//working dir is probably bin/debug or bin/release depending on situation so ../../ fits
	luaWrapper = cLuaWrapper();
	luaWrapper.openScript( global::configPath + "config.lua" );
	global::datasetPath = luaWrapper.getVariable< std::string >( "dataset" );
	std::string objectsToLoad = luaWrapper.getTable( "objectsToLoad" );
	//TODO load global variables
	luaWrapper.openScript(  extPath + "lua/listFiles.lua" );
	for( uint16_t i = 0; i < objectsToLoad.size(); i++ )
	{
		cLuaTable fileList = luaWrapper.runFunction< cLuaTable >( "listFiles", global::configPath + "dataset/" + datasetPath + objectsToLoad.value< std::string >( std::to_string( i ) ) );
		for( uint16_t iA = 0; iA < fileList.size(); iA++ )
		{
			luaWrapper.openScript( global::configPath + "dataset/" + datasetPath + objectsToLoad.value< std::string >( std::to_string( i ) ) + fileList[ iA ] );
			std::string tableName = luaWrapper.getTable( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			if( objectsToLoad[ i ] == "tile" )
			{
				objectList.get( "tile" )->push_back( new cTile( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "blockSubtype" )
			{
				objectList.get( "blockSubtype" )->push_back( new cBlockSubtype( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "block" )
			{
				objectList.get( "block" )->push_back( new cBlock( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "interface" )
			{
				objectList.get( "interface" )->push_back( new cInterface( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "boardGenerator" )
			{
				objectList.get( "boardGenerator" )->push_back( new cBoardGenerator( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "board" )
			{
				objectList.get( "board" )->push_back( new cBoard( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "entitySubtype" )
			{
				objectList.get( "entitySubtype" )->push_back( new cEntitySubtype( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "entity" )
			{
				objectList.get( "entity" )->push_back( new cEntity( luaWrapper.getTable( tableName ) ) );
			}
			else if( objectsToLoad[ i ] == "entityControl" )
			{
				objectList.get( "entityControl" )->push_back( new cEntityControl( luaWrapper.getTable( tableName ) ) );
			}
		}
	}
}

}

cGame::cGame()
{
	initializeObjects();
}
