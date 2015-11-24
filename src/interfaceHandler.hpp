//interfaceHandler.hpp
#ifndef INTERFACEHANDLER_HPP
#define INTERFACEHANDLER_HPP
#include <vector>
#include <SDL2/SDL.h>
#include "typedef.hpp"
#include "interface.hpp"

class cInterfaceHandler
{
	uint width;
	uint height;
	SDL_Window* screen;
	SDL_Renderer* renderer;
public:
	std::vector< cInterface > interfaceVector;
	render();
	clear();
	refresh();
	cInterfaceHandler( uint _width, uint _height );
	~cInterfaceHandler();
};

#endif
