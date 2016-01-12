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
	typedef std::vector< cClient > clientVector;

	clientVector clients;
	bool running;
	cDataset dataset;
	std::string gameTitle;
	std::string datasetName;
	cInstance instance
public:
	void connectClient( std::shared_ptr< cClient > target );
	void disconnectClient( std::shared_ptr< cClient > target );
	void work();

	cServer( std::string _datasetName );
};

#endif
