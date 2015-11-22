//gameHandler.cpp
#include "gameHandler.hpp"

uint16_t cGameHandler::work()
{
	while( game->running == true )
	{
		game->renderInterfaces();
		choice();
		game->clearInterfaces();
	}
	return 0;
}

cGameHandler::cGameHandler() :
	game( new cGame() )
{

}

std::istream& operator>>( istream& os, cGameHandler& gameHandler )
{
	//load game
}

std::ostream& operator<<( ostream& os, const cGameHandler& gameHandler )
{
	//save game
}
