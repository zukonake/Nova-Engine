//interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <SDL2/SDL.h>
#include "typedef.hpp"
#include "interfaceComponent.hpp"

class cInterface
{
	std::vector< interfaceComponent > componentTable;
	SDL_Rect* rectangle.
	SDL_Texture* texture;
public:
	void render();
	void clear();
	void refresh();
	cInterface( table luaToCpp, table* objectList );
	cInterface( table _componentTable, uint _posX, uint _posY, uint _width, uint _height );
	~cInterface();
};

#endif
