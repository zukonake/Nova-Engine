//game.cpp
#include "game.hpp"
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
	objectList.insert( "tile", new std::vector< cTile* >() );
	objectList.insert( "blockSubtype", new std::vector< cBlockSubtype* >() );
	objectList.insert( "block", new std::vector< cBlock* >() );
	objectList.insert( "interface", new std::vector< cInterface* >() );
	objectList.insert( "boardGenerator", new std::vector< cBoardGenerator* >() );
	objectList.insert( "board", new std::vector< cBoard* >() );
	objectList.insert( "entity", new std::vector< cEntity* >() );
	objectList.insert( "entityControl", new std::vector< cEntityControl* >() );
	//working dir is probably bin/debug or bin/release depending on situation so ../../ fits
	luaWrapper = cLuaWrapper();
	luaWrapper.openScript( global::configPath + "config.lua" );
	global::datasetPath = luaWrapper.getVariable< std::string >( "dataset" );
	std::vector< std::string >objectsToLoad = luaWrapper.getGlobal< std::vector< std::string > >( "objectsToLoad" );
	//TODO load global variables
	luaWrapper.openScript( extPath + "lua/listFiles.lua" );
	for( uint16_t i = 0; i < objectsToLoad.size(); i++ )
	{
		std::vector< std::string >fileList = luaWrapper.runFunction< std::vector< std::string > >( "listFiles", global::configPath + "dataset/" + datasetPath + objectsToLoad[ i ] );
		for( uint16_t iA = 0; iA < fileList.size(); iA++ )
		{
			luaWrapper.openScript( global::configPath + "dataset/" + datasetPath + objectsToLoad[ i ] + fileList[ iA ] );
			std::string tableName = luaWrapper.getGlobal< std::string >( fileList[ iA ].substr( 0, fileList[ iA ].size() - 4 ) ); //filename without .lua
			if( objectsToLoad[ i ] == "tile" )
			{
				objectList[ "tile" ]->push_back( new cTile( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "blockSubtype" )
			{
				objectList[ "blockSubtype" ]->push_back( new cBlockSubtype( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "block" )
			{
				objectList[ "block" ]->push_back( new cBlock( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "interface" )
			{
				objectList[ "interface" ]->push_back( new cInterface( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "boardGenerator" )
			{
				objectList[ "boardGenerator" ]->push_back( new cBoardGenerator( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "board" )
			{
				objectList[ "board" ]->push_back( new cBoard( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "entitySubtype" )
			{
				objectList[ "entitySubtype" ]->push_back( new cEntitySubtype( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "entityControl" )
			{
				objectList[ "entityControl" ]->push_back( new cEntityControl( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ), &objectList );
			}
			else if( objectsToLoad[ i ] == "entity" )
			{
				objectList[ "entity" ]->push_back( new cEntity( luaWrapper.getGlobal< std::map< std::string, boost::any >( tableName ) ) , &objectList );
			}
		}
	}
}

cGame::cGame()
{
	initializeObjects();
}
