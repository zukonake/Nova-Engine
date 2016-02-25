//blockSubtype.hpp
#ifndef BLOCKSUBTYPE_HPP
#define BLOCKSUBTYPE_HPP

#include <string>
//
#include <typedef.hpp>
#include <render/tileset.hpp>

class cBlockSubtype
{
	friend class cBlock;
	friend class cGame;
	friend class cCamera;
	std::string name;
	bool isPassable;
	cTileset* tileset;
	cPosition tilesetPos;
	cBlockSubtype( std::string _name, bool _isPassable, cTileset* _tileset, cPosition _tilestPos );
	cBlockSubtype( table luaToCpp, table* objectTable );
};

#endif
