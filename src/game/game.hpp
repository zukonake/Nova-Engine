//game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
//
#include <typedef.hpp>
#include <lua/luaWrapper.hpp>
#include <render/camera.hpp>
#include <render/interfaceHandler.hpp>

class cGame
{
	friend std::istream& operator>>( istream& os, cGame& game ); //load
	friend std::ostream& operator<<( ostream& os, const cGame& game ); //save
	void initializeObjects();
	bool running;
	cLuaWrapper* luaWrapper;
	cEntity* player;
	cCamera* camera;
	cInterfaceHandler interfaceHandler;
	table* objectTable;
	std::string gameTitle;
	int work();
public:
	cGame();
};

#endif
