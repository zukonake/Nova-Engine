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
	std::unique_ptr< table > objectTable;
	std::string gameTitle;
	std::string datasetName;
	clientArray clients;

	void initializeObjects();
	void initializeVariables();

	cGame() {};
	void operator=( cServer const& ) = delete;
	cServer( cServer const& ) = delete;
public:

	static cServer& newInstance();

	void initialize();
	void connectClient( std::unique_ptr< cClient > target );
	void work();
};

#endif
