//game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>

class cGame
{
	void initializeObjects();
	std::vector< cTile* > tileList;
	std::vector< cBlockSubtype* > blockSubtypeList;
	std::vector< cBlock* > blockList;
	std::vector< cInterface* > interfaceList;
	std::vector< cBoardGenerator* > boardGeneratorList;
	std::vector< cBoard* > boardList;
	std::vector< cEntity* > entityList;
	std::vector< cEntityControl* > entityControlList;
	cGame();
};

#endif
