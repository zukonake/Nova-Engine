//interfaceHandler.cpp
#include <ncurses.h>
//
#include "interfaceHandler.hpp"

void cInterfaceHandler::render()
{
	for(auto iterator : interfaceVector )
	{
		interfaceVector[i]->render();
	}
}

void cInterfaceHandler::clear()
{
	SDL_RenderClear( renderer );
}

void cInterfaceHandler::refresh()
{
	SDL_RenderPresent( renderer );
}

cInterfaceHandler::cInterfaceHandler( uint _screenWidth, uint _screenHeight, std::string windowTitle = "Unnamed" )
{
	SDL_Init( SDL_INIT_EVERYTHING ); //TODO specify
	screen = SDL_CreateWindow(
		windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		screenWidth,
		screenHeight,
		0 ); //check args( 0 )
	renderer = SDL_CreateRenderer( screen, -1, 0 ); //TODO check args
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
	SDL_RenderClear( renderer );
	SDL_RenderPresent( renderer );
}

cInterfaceHandler::~cInterfaceHandler()
{
	endwin();
}
