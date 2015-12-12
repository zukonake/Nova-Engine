//interface.hpp
#ifndef INTERFACE_HPP
#define INTERFACE_HPP
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
//
#include <typedef.hpp>
#include <render/interfaceComponent.hpp>

class cInterface
{
	friend class cInterfaceHandler;
	typedef std::vector< cInterfaceComponent > componentVector;

	componentVector components;
	SDL_Rect renderArea;
	std::shared_ptr< SDL_Texture > texture;
	bool hidden;

	void render( std::shared_ptr< SDL_Renderer > renderer );

	cInterface( table luaToCpp, std::shared_ptr< table > objectTable );
	~cInterface();
};

#endif
