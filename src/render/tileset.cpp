//tileset.cpp
#include "tileset.hpp"

void cTileset::renderRect( std::shared_ptr< SDL_Rect > sRectangle, std::shared_ptr< SDL_Rect > dRectangle, std::shared_ptr< SDL_Renderer > renderer )
{
	SDL_RenderCopy( renderer.get(), texture.get(), sRectangle.get(), dRectangle.get() );
}

cTileset::cTileset( std:shared_ptr< SDL_Texture > _texture ) :
	texture( _texture )
{

}
