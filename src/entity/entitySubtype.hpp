//entitySubtype.hpp
#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include "typedef.hpp"
#include "tile.hpp"

class cEntitySubtype
{
	cTile* tile;
	table componentTable;
	cEntitySubtype( cTile* _tile );
};

#endif
