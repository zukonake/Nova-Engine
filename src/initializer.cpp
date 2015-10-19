//initializer.cpp
#include "initializer.hpp"
#include <fstream>
#include "lua/luaTable.hpp"
#include "global.hpp"
#include "game.hpp"
#include "tile.hpp"

cInitializer::cInitializer( lua_state* L, cGame* game )
{
	//working dir is probably bin/debug or bin/release depending on situation so ../../ fits
	cLuaWrapper luaWrapper;
	luaWrapper.openScript( "../../config/config.lua" );
	global::datasetPath = luaWrapper.getVariable< std::string >( "dataset" );
	global::objectsToLoad = luaWrapper.getArray< std::string >( "objectsToLoad" ); //TODO cLuaWrapper::getArray( std::string name );
	//TODO load global variables
	luaWrapper.openScript( "../../ext/lua/listFiles.lua" );
	for( uint16_t i = 0; i < global::objectsToLoad; i++ )
	{
		cLuaTable fileList = luaWrapper.runFunction< cLuaTable >( "listFiles", "../../config/dataset/" + datasetPath + global::objectsToLoad[ i ] );
		for( uint16_t iA = 0; iA < fileList.size(); iA++ )
		{
			luaWrapper.openScript( "../../config/dataset/" + datasetPath + global::objectsToLoad[ i ] + fileList[ iA ] );
			if( global::objectsToLoad[ i ] == "tile" )
			{ //Pushes a tile from fileList[ iA ] string - .lua
				game->tileList.push_back( tile( luaWrapper.getTable( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ) ) );
			}
			else if( global::objectsToLoad[ i ] == "" )
			{ //Pushes a tile from fileList[ iA ] string - .lua
				game->tileList.push_back( tile( luaWrapper.getTable( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ) ) );
			}
			//TODO more objects
		}
	}
	//TODO list and read files and send them to constructors
}
