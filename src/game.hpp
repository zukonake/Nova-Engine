//game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "typedef.hpp"
#include "lua/luaWrapper.hpp"

class cGame
{
	void initializeObjects();
	bool running;
	cLuaWrapper* luaWrapper;
	cEntity* player;
	table* objectTable;
	cGame();
};

#endif
