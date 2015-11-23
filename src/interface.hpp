//interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include "typedef.hpp"

class cInterface
{
	table componentTable;
	uint posX;
	uint posY;
	SDL_Texture* texture;
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
