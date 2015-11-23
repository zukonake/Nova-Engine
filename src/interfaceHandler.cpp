//interfaceHandler.cpp
#include <ncurses.h>
#include "interfaceHandler.hpp"

void cInterfaceHandler::render()
{
	for(int i = 0; i < interfaceVector.size(); i++ )
	{
		interfaceVector[i]->render();
	}
}

void cInterfaceHandler::clear()
{
	for(int i = 0; i < interfaceVector.size(); i++ )
	{
		interfaceVector[i]->clear();
	}
}

void cInterfaceHandler::refresh()
{
	for(int i = 0; i < interfaceVector.size(); i++ )
	{
		interfaceVector[i]->refresh();
	}
}

cInterfaceHandler::cInterfaceHandler(std::string windowTitle, uint _width, uint _height )
{
	SDL_Init( SDL_INIT_EVERYTHING ); //TODO specify
	screen = SDL_CreateWindow( windowTitle.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		1366, 768, 0 ); //check args( 0 )
	renderer = SDL_CreateRenderer( screen, -1, 0 ); //TODO check args
	SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0 );
	SDL_RenderClear( renderer );
	SDL_RenderPresent( renderer );
}

cInterfaceHandler::~cInterfaceHandler()
{
	endwin();
}
