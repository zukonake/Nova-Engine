//interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <SDL2/SDL.h>
//
#include <typedef.hpp>
#include <render/interfaceComponent.hpp>

class cInterface
{
	friend class cInterfaceHandler;
	std::vector< interfaceComponent > componentVector;
	SDL_Rect* rectangle.
	SDL_Texture* texture;
public:
	void render();
	cInterface( table luaToCpp, table* objectList );
	cInterface( table _componentTable, uint _posX, uint _posY, uint _width, uint _height );
	~cInterface();
};

#endif
