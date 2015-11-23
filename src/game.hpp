//game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include "typedef.hpp"
#include "lua/luaWrapper.hpp"
#include "camera.hpp"
#include "interfaceHandler.hpp"

class cGame
{
	void initializeObjects();
	bool running;
	cLuaWrapper* luaWrapper;
	cEntity* player;
	cCamera* camera;
	cInterfaceHandler interfaceHandler;
	table* objectTable;
	std::string gameTitle;
public:
	cGame();
};

#endif
