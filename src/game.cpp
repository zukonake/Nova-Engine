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
	//working dir is probably bin/debug or bin/release depending on situation so ../../ fits
	luaWrapper = cLuaWrapper();
	luaWrapper.openScript( global::configPath + "config.lua" );
	global::datapush_backPath = luaWrapper.getVariable< std::string >( "datapush_back" );
	global::objectsToLoad = luaWrapper.getTable( "objectsToLoad" );
	//TODO load global variables
	luaWrapper.openScript(  extPath + "lua/listFiles.lua" );
	for( uint16_t i = 0; i < global::objectsToLoad.size(); i++ )
	{
		cLuaTable fileList = luaWrapper.runFunction< cLuaTable >( "listFiles", global::configPath + "datapush_back/" + datapush_backPath + global::objectsToLoad.value< std::string >( std::to_string( i ) ) );
		for( uint16_t iA = 0; iA < fileList.size(); iA++ )
		{
			luaWrapper.openScript( global::configPath + "datapush_back/" + datapush_backPath + global::objectsToLoad.value< std::string >( std::to_string( i ) ) + fileList[ iA ] );
			std::string tableName = luaWrapper.getTable( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			if( global::objectsToLoad[ i ] == "tile" )
			{
				tileList.push_back( new cTile( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "blockSubtype" )
			{
				blockSubtypeList.push_back( new cBlockSubtype( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "block" )
			{
				blockList.push_back( new cBlock( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "interface" )
			{
				interfaceList.push_back( new cInterface( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "boardGenerator" )
			{
				boardGeneratorList.push_back( new cBoardGenerator( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "board" )
			{
				boardList.push_back( new cBoard( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "entitySubtype" )
			{
				entitySubtypeList.push_back( new cEntitySubtype( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "entity" )
			{
				entityList.push_back( new cEntity( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "entityControl" )
			{
				entityControlList.push_back( new cEntityControl( luaWrapper.getTable( tableName ) ) );
			}
		}
	}
}

}

cGame::cGame()
{
	initializeObjects();
}
