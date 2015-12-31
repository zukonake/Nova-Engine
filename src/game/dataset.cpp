//dataset.cpp
#include "dataset.hpp"
#include <cassert>
//
#include <global.hpp>

cDataset::cDataset( std::string path, std::shared_ptr< cLuaWrapper > luaWrapper )Tileset
{
	objectTable[ "tileset" ] = table();
	objectTable[ "blockSubtype" ] = table();
	objectTable[ "block" ] = table();
	objectTable[ "boardGenerator" ] = table();
	objectTable[ "board" ] = table();
	objectTable[ "entitySubtype" ] = table();
	objectTable[ "entityAction" ] = table();
	objectTable[ "entityControl" ] = table();
	objectTable[ "entity" ] = table();
	objectTable[ "interfaceComponent" ] = table();
	objectTable[ "interface" ] = table();
	luaWrapper->openScript( global::workingDirectory + "src/lua/scripts/listFiles.lua" );
	for( auto i : global::objectsToLoad )
	{
		auto fileList = luaWrapper->runFunction< std::vector< std::string > >( "listFiles",
			global::configPath + "dataset/" + datasetPath + global::objectsToLoad[ i ] );
		for( auto iA : fileList )
		{
			luaWrapper->openScript( global::configPath + "dataset/" + datasetPath + global::objectsToLoad[ i ] + fileList[ iA ] );
			std::string tableName = luaWrapper->getGlobal< std::string >( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			table luaToCpp = luaWrapper->getGlobal< table >( tableName );
			if( global::objectsToLoad[ i ] == "tileset" )
			{
				objectTable[ "tileset" ].emplace( tablename, cTileset( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "blockSubtype" )
			{
				objectTable[ "blockSubtype" ].emplace( tablename, cBlockSubtype( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "block" )
			{
				objectTable[ "block" ].emplace( tablename, cBlock( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "boardGenerator" )
			{
				objectTable[ "boardGenerator" ].emplace( tablename, cBoardGenerator( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "board" )
			{
				objectTable[ "board" ].emplace( tablename, cBoard( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entitySubtype" )
			{
				objectTable[ "entitySubtype" ].emplace( tablename, cEntitySubtype( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entityAction" )
			{
				objectTable[ "entityAction" ].emplace( tablename, cEntityAction( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entityControl" )
			{
				objectTable[ "entityControl" ].emplace( tablename, cEntityControl( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "entity" )
			{
				objectTable[ "entity" ].emplace( tablename, cEntity( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "interfaceComponent" )
			{
				objectTable[ "interfaceComponent" ].emplace( tablename, cInterfaceComponent( luaToCpp, &objectTable ) );
			}
			else if( global::objectsToLoad[ i ] == "interface" )
			{
				objectTable[ "interface" ].emplace( tablename, cInterface( luaToCpp, &objectTable ) );
			}
		}
	}
}

table& operator[]( const std::string key )
{
	assert( objectTable.find( key ) != objectTable.end() ); //Assert that the key exists.
	return objectTable;
}
