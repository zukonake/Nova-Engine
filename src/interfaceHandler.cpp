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

cInterfaceHandler::cInterfaceHandler( uint _width, uint _height )
{
	initscr();
	keypad( stdscr, TRUE );
	start_color(); //TODO check for color support
	resizeterm( _width, _height );
}

cInterfaceHandler::~cInterfaceHandler()
{
	endwin();
}
