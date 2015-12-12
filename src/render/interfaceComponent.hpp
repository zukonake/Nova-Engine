//interfaceComponent.hpp
#ifndef INTERFACECOMPONENT_HPP
#define INTERFACECOMPONENT_HPP
#include <string>
#include <memory>
#include <SDL2/SDL.h>
//
#include <typedef.hpp>

class cInterfaceComponent
{
	friend class cInterface;

	std::string script;
	SDL_Rect sourceArea;
	SDL_Rect renderArea;

	void render( std::shared_ptr< SDL_Renderer > renderer, std::shared_ptr< SDL_Texture > texture );

	cInterfaceComponent::cInterfaceComponent( table luaToCpp, std::shared_ptr< table > objectTable );
};

#endif
