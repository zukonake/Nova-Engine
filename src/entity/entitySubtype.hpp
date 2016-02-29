//entitySubtype.hpp
#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <memory>
//
#include <typedef.hpp>
#include <render/tile.hpp>

class cEntitySubtype
{
	//TODO tileset
	table componentTable;
	cPosition tilesetPos;
	cTileset* tileset;
	cEntitySubtype( table luaToCpp );
};

#endif

