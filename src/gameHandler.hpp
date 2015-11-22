//gameHandler.hpp
#ifndef GAMEHANDLER_HPP
#define GAMEHANDLER_HPP

#include <string>
#include "game.hpp"

class cGameHandler
{
	cGame* game;
	cGameHandler();
	friend std::istream& operator>>( istream& os, cGameHandler& gameHandler );
	friend std::ostream& operator<<( ostream& os, const cGameHandler& gameHandler );
};

std::istream& operator>>( istream& os, cGameHandler& gameHandler );
std::ostream& operator<<( ostream& os, const cGameHandler& gameHandler );

int main( int argv, char argc[] )
{
	return 0;
}

#endif
