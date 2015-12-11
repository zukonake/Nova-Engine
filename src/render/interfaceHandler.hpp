//interfaceHandler.hpp
#ifndef INTERFACEHANDLER_HPP
#define INTERFACEHANDLER_HPP
#include <string>
#include <vector>
#include <memory>
#include <SDL2/SDL.h>
//
#include <typedef.hpp>
#include <position.hpp>
#include <camera.hpp>
#include <render/interface.hpp>

class cInterfaceHandler
{
	friend class cClient;
	typedef std::vector< std::unique_ptr< cInterface > >interfaceVector;

	std::unique_ptr< SDL_Window > screen;
	std::shared_ptr< SDL_Renderer > renderer;
	std::unique_ptr< cCamera > camera;
	std::vector< cInterface > interfaceVector;
public:
	render();
	clear();
	refresh();

	cInterfaceHandler( uint screenWidth, uint screenHeight, std::string windowTitle );
	~cInterfaceHandler();
};

#endif
