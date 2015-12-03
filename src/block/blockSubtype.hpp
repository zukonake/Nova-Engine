//blockSubtype.hpp
#ifndef BLOCKSUBTYPE_HPP
#define BLOCKSUBTYPE_HPP

#include <string>

class cBlockSubtype
{
	friend class cBlock;
	std::string name;
	bool isPassable;
	cBlockSubtype( std::string _name, bool _isPassable )
};

#endif
