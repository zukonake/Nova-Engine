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
	std::unique_ptr< cLuaWrapper > luaWrapper;
	std::shared_ptr< table > objectTable;
	std::string gameTitle;
	std::string datasetName;
	clientArray clients;

	void initializeObjects();
	void initializeVariables();

	cGame() {};
	void operator=( cServer const& ) = delete;
	cServer( cServer const& ) = delete;
public:
	void initialize();
	void connectClient( std::unique_ptr< cClient > target );
	void work();

	static cServer& newInstance();
};

#endif
