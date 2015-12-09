//block.cpp
#include "block.hpp"
#include <boost/any.hpp>

void cBlock::render( cInterface* interface, uint posX, uint posY )
{
	//TODO
}

cBlock( cBlockSubtype* _subtype ) :
	subtype( _subtype ),
{

}

cBlock( table luaToCpp, table* objectTable ) :
	subtype( boost::any_cast< blockSubtype* >( luaToCpp[ "subtype" ] ));
{

}
