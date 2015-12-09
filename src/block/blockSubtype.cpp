//blockSubtype.cpp
#include "blockSubtype.hpp"
#include <boost/any.hpp>

cBlockSubtype::cBlockSubtype( std::string _name, bool _isPassable, cTileset* _tileset, cPosition _tilesetPos ) :
	name( _name ),
	isPassable( _isPassable ),
	tileset( _tileset ),
	tilesetPos( _tilesetPos)
{

}

cBlockSubtype::cBlockSubtype( table luaToCpp, table* objectTable ) :
	name( boost::any_cast< std::string >( luaToCpp[ "name" ] )),
	isPassable( boost::any_cast< bool >( luaToCpp[ "isPassable" ] )),
	tileset( boost::any_cast< cTileset* >( luaToCpp[ "tileset" ] )),
	name( boost::any_cast< cPosition >( luaToCpp[ "tilesetPos" ] ))
{

}
