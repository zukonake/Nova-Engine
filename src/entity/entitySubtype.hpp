//entitySubtype.hpp
#ifndef ENTITYSUBTYPE_HPP
#define ENTITYSUBTYPE_HPP

#include <memory>
//
#include <typedef.hpp>
#include <tile.hpp>

class cEntitySubtype
{
	//TODO tileset
	table componentTable;
	cEntitySubtype( std::shared_ptr< cTile > _tile );
};

#endif
