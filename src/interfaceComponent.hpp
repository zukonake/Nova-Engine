//interfaceComponent.hpp
#ifndef INTERFACECOMPONENT_HPP
#define INTERFACECOMPONENT_HPP
#include <string>
#include <SDL2/SDL.h>
#include "typedef.hpp"

class cInterfaceComponent
{
	std::string script;
	SDL_Texture* texture;
	void render();
	cInterfaceComponent::cInterfaceComponent( table luaToCpp, table* objectList );
};

#endif
