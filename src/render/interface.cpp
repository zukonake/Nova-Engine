//interface.cpp
#include "interface.hpp"

void cInterface::render( SDL_Renderer* renderer )
{
	SDL_RenderCopy( renderer, texture, NULL, NULL );
	for( auto iterator : componentVector )
	{
		componentVector[i]->render();
	}
}

cInterface::cInterface( table luaToCpp, table* objectList ) :
	componentTable( boost::any_cast< table >( luaToCpp["component"] ) ),
	rectangle( std::make_unique( new SDL_Rect ) );
	rectangle.x( boost::any_cast< uint >( luaToCpp["screenPos.x"] ) ),
	rectangle.y( boost::any_cast< uint >( luaToCpp["screenPos.y"] ) ),
	rectangle.w( boost::any_cast< uint >( luaToCpp["width"] ) ),
	rectangle.h( boost::any_cast< uint >( luaToCpp["height"] ) ),
{

}

cInterface::~cInterface()
{
	SDL_DestroyTexture( texture );
}
