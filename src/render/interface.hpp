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
	std::unique_ptr< SDL_Rect > rectangle.
	std::unique_ptr< SDL_Texture > texture;

	void render( std::shared_ptr< SDL_Renderer > renderer );
public:
	cInterface( table luaToCpp, std::shared_ptr< table > objectList );
	~cInterface();
};

#endif
