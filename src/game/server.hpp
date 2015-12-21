//game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <memory>
//
#include <typedef.hpp>
#include <lua/luaWrapper.hpp>
#include <game/client.hpp>

class cServer
{
	typedef std::vector< std::unique_ptr< cClient > > clientVector;
	typedef std::vector< std::shared_ptr< cEntity > > entityVector;
	typedef std::vector< std::shared_ptr< cBoard > > boardVector;

	bool running;
	fixedTable objectTable;
	std::string gameTitle;
	std::string datasetName;
	boardVector boards;
	entityVector entities;
	clientVector clients;

	void initializeObjects();

	cGame() {};
	void operator=( cServer const& ) = delete;
	cServer( cServer const& ) = delete;
public:
	void initialize( std::shared_ptr< cLuaWrapper > luaWrapper );
	void connectClient( std::unique_ptr< cClient > target );
	void work();
	std::shared_ptr< cBoard > getBoard( uint id );
	std::shared_ptr< cEntity > getEntity( std::string name );
	std::shared_ptr< cClient > getClient( std::string name );

	static cServer& newInstance( std::string _datasetName );
};

#endif
