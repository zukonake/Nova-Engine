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
	typedef std::vector< std::unique_ptr< cClient > > clientArray;

	bool running;
	fixedTable objectTable;
	std::string gameTitle;
	std::string datasetName;
	clientArray clients;

	void initializeObjects();

	cGame() {};
	void operator=( cServer const& ) = delete;
	cServer( cServer const& ) = delete;
public:
	void initialize( std::shared_ptr< cLuaWrapper > luaWrapper );
	void connectClient( std::unique_ptr< cClient > target );
	void work();

	static cServer& newInstance( std::string _datasetName );
};

#endif
