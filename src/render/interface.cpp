//interface.cpp
#include "interface.hpp"

void cInterface::render( SDL_Renderer* renderer )
{
	SDL_RenderCopy( renderer, texture, NULL, NULL );
	for( auto i : components )
	{
		components[i]->render();
	}
}

cInterface::cInterface( table luaToCpp, std::shared_ptr< table > objectTable ) :
	rectangle( std::make_unique( new SDL_Rect ) );
	rectangle.x( boost::any_cast< uint >( luaToCpp["screenPos.x"] ) ),
	rectangle.y( boost::any_cast< uint >( luaToCpp["screenPos.y"] ) ),
	rectangle.w( boost::any_cast< uint >( luaToCpp["width"] ) ),
	rectangle.h( boost::any_cast< uint >( luaToCpp["height"] ) ),
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
