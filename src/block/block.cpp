//block.cpp
#include <boost/any.hpp>
//
#include "block.hpp"

void cBlock::render( cInterface* interface, uint posX, uint posY )
{
	//TODO
}

cBlock::cBlock( cBlockSubtype* _subtype ) :
	subtype( _subtype ),
{

}

cBlock::cBlock( table luaToCpp, table* objectTable ) :
	subtype( boost::any_cast< blockSubtype* >( luaToCpp[ "subtype" ] ));
{

}
