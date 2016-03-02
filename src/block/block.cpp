//block.cpp
#include <boost/any.hpp>
//
#include "block.hpp"

void cBlock::render( std::shared_ptr< cInterface > interface, cPosition pos )
{
	//TODO
	tileset->renderRect()
}

cBlock::cBlock( std::shared_ptr< cBlockSubtype > _subtype ) :
	subtype( _subtype ),
{

}

cBlock::cBlock( table luaToCpp, std::shared_ptr< table > objectTable ) :
	subtype( boost::any_cast< std::shared_ptr< blockSubtype > >( luaToCpp[ "subtype" ] ));
{

}
