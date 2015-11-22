//interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <ncurses.h>
#include "typedef.hpp"

class cInterface
{
	table componentTable;
	uint posX;
	uint posY;
	WINDOW* window;
	char hBorder;
	char vBorder;
public:
	uint width;
	uint height;
	void render();
	void clear();
	void refresh();
	cInterface( table luaToCpp, table* objectList );
	cInterface( table _componentTable, uint _posX, uint _posY, uint _width, uint _height, char _hBorder, char _vBorder );
	~cInterface();
};

#endif
