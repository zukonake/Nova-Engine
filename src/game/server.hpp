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
	friend std::istream& operator>>( istream& os, cGame& game ); //load
	friend std::ostream& operator<<( ostream& os, const cGame& game ); //save
	typedef std::vector< std::unique_ptr< cClient > > clientArray;
	void initializeObjects();
	bool running;
	std::unique_ptr< cLuaWrapper > luaWrapper;
	std::unique_ptr< table > objectTable;
	std::string gameTitle;
	std::string datasetPath;
	clientArray clients;
	int work();
	bool connectClient( clientArray target );
public:
	cGame();
};

std::istream& operator>>( istream& os, cGame& game ); //load
std::ostream& operator<<( ostream& os, const cGame& game ); //save

#endif
