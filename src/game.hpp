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
	table* objectTable;
	cGame();
};

#endif
