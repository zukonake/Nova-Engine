//tileset.cpp
#include "tileset.hpp"
#include "global.hpp"

void cTileset::renderRect( SDL_Rect* sRectangle, SDL_Rect* dRectangle, SDL_Renderer* renderer )
{
	SDL_RenderCopy( renderer, texture, sRectangle, dRectangle );
}

cTileset::cTileset( SDL_Texture* _texture ) :
	texture( _texture )
{

}
