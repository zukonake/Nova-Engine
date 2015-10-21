//interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <ncurses.h>
#include "lua/luaTable.hpp"

class cInterface
{
	std::string name;
	luaTable componentList;
	WINDOW* nCursesWindow;
	void print();
	// void refresh(); not sure if needed
	cInterface( cLuaTable _componentList, std::string _name, uint16_t _posX, uint16_t _posY, uint16_t _width, uint16_t _height, char _hBorder, char _vBorder );
};

#endif
