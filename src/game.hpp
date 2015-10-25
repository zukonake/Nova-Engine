//game.hpp
#ifndef GAME_HPP
#define GAME_HPP

#include <vector>
#include <string>
#include <map>
#include <boost/any.hpp>

class cGame
{
	void initializeObjects();
	std::map< std::string, std::vector< boost::any >* > objectList;
	cGame();
};

#endif
