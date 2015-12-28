//dataset.cpp
#include "dataset.hpp"
#include <global.hpp>

cDataset::cDataset( std::string path, std::shared_ptr< cLuaWrapper > luaWrapper )
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
				objectTable[ "tileset" ][ tableName ] = std::make_shared< cTileset >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "blockSubtype" )
			{
				objectTable[ "blockSubtype" ][ tableName ] = std::make_shared< cBlockSubtype >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "block" )
			{
				objectTable[ "block" ][ tableName ] = std::make_shared< cBlock >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "boardGenerator" )
			{
				objectTable[ "boardGenerator" ][ tableName ] = std::make_shared< cBoardGenerator >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "board" )
			{
				objectTable[ "board" ][ tableName ] = std::make_shared< cBoard >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "entitySubtype" )
			{
				objectTable[ "entitySubtype" ][ tableName ] = std::make_shared< cEntitySubtype >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "entityAction" )
			{
				objectTable[ "entityAction" ][ tableName ] = std::make_shared< cEntityAction >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "entityControl" )
			{
				objectTable[ "entityControl" ][ tableName ] = std::make_shared< cEntityControl >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "entity" )
			{
				objectTable[ "entity" ][ tableName ] = std::make_shared< cEntity >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "interfaceComponent" )
			{
				objectTable[ "interfaceComponent" ][ tableName ] = std::make_shared< cInterfaceComponent >( luaToCpp, &objectTable );
			}
			else if( global::objectsToLoad[ i ] == "interface" )
			{
				objectTable[ "interface" ][ tableName ] = std::make_shared< cInterface >( luaToCpp, &objectTable );
			}
		}
	}
}
