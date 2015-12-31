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
	cDataset dataset;
	std::string gameTitle;
	std::string datasetName;
	boardVector boards;
	entityVector entities;
	clientVector clients;

	cGame() {};
	void operator=( cServer const& ) = delete;
	cServer( cServer const& ) = delete;
public:
	void connectClient( std::shared_ptr< cClient > target );
	void disconnectClient( std::shared_ptr< cClient > target );
	void work();
	std::shared_ptr< cBoard > getBoard( uint index );
	std::shared_ptr< cEntity > getEntity( uint index );

	static cServer& newInstance( std::string _datasetName );
};

#endif
