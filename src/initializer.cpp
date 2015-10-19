//initializer.cpp
#include "initializer.hpp"
#include <sstream>
#include "lua/luaTable.hpp"
#include "global.hpp"
#include "game.hpp"
#include "tile.hpp"
#include "blockSubtype.hpp"
#include "block.hpp"
#include "interface.hpp"
#include "board.hpp"
#include "entitySubtype.hpp"
#include "entity.hpp"
#include "ai.hpp"
#include "boardGenerator.hpp"

cInitializer::cInitializer( lua_state* L, cGame* game )
{
	//working dir is probably bin/debug or bin/release depending on situation so ../../ fits
	cLuaWrapper luaWrapper;
	luaWrapper.openScript( "../../config/config.lua" );
	global::datasetPath = luaWrapper.getVariable< std::string >( "dataset" );
	global::objectsToLoad = luaWrapper.getTable( "objectsToLoad" );
	//TODO load global variables
	luaWrapper.openScript( "../../ext/lua/listFiles.lua" );
	for( uint16_t i = 0; i < global::objectsToLoad.size(); i++ )
	{
		cLuaTable fileList = luaWrapper.runFunction< cLuaTable >( "listFiles", "../../config/dataset/" + datasetPath + global::objectsToLoad.returnEntryValue< std::string >( std::to_string( i ) ) );
		for( uint16_t iA = 0; iA < fileList.size(); iA++ )
		{
			luaWrapper.openScript( "../../config/dataset/" + datasetPath + global::objectsToLoad[ i ] + fileList[ iA ] );
			std::string tableName = luaWrapper.getTable( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			if( global::objectsToLoad[ i ] == "tile" )
			{
				game->tileList.synchronizeEntry< tile* >( new tile( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "blockSubtype" )
			{
				game->blockSubtypeList.synchronizeEntry< cBlockSubtype* >( new cBlockSubtype( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "block" )
			{
				game->blockList.synchronizeEntry< cBlock* >( new cBlock( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "interface" )
			{
				game->blockSubtypeList.synchronizeEntry< cInterface* >( new cInterface( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "board" )
			{
				game->blockSubtypeList.synchronizeEntry< cBoard* >( new cBoard( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "entitySubtype" )
			{
				game->blockSubtypeList.synchronizeEntry< cEntitySubtype* >( new cEntitySubtype( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "entity" )
			{
				game->blockSubtypeList.synchronizeEntry< cEntity* >( new cEntity( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "ai" )
			{
				game->blockSubtypeList.synchronizeEntry< cAi* >( new cAi( luaWrapper.getTable( tableName ) ) );
			}
			else if( global::objectsToLoad[ i ] == "boardGenerator" )
			{
				game->blockSubtypeList.synchronizeEntry< cBoardGenerator* >( new cBoardGenerator( luaWrapper.getTable( tableName ) ) );
			}
		}
	}
}
