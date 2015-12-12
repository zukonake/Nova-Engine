//interface.cpp
#include "interface.hpp"

void cInterface::render( SDL_Renderer* renderer )
{
	if( !hidden )
	{
		for( auto i : components )
		{
			components[i]->render( renderer, texture );
		}
	}
}

cInterface::cInterface( table luaToCpp, std::shared_ptr< table > objectTable ) :
	renderArea( SDL_Rect() );
	renderArea.x( boost::any_cast< uint >( luaToCpp["renderArea.x"] ) ),
	renderArea.y( boost::any_cast< uint >( luaToCpp["renderArea.y"] ) ),
	renderArea.w( boost::any_cast< uint >( luaToCpp["renderArea.width"] ) ),
	renderArea.h( boost::any_cast< uint >( luaToCpp["renderArea.height"] ) ),
{
	auto rawLuaComponents = boost::any_cast< table >( luaToCpp["components"] )
	for( auto i : rawLuaComponents )
	{
		components.push_back( cInterfaceComponent( rawLuaComponents, objectTable ) );
	}
}

cInterface::~cInterface()
{
	SDL_DestroyTexture( texture );
}
