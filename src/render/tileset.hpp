//tileset.hpp
#ifndef TILESET_HPP
#define TILESET_HPP
#include <SDL2/SDL.h>
//
#include <typedef.hpp>

class cTileset
{
	SDL_Texture* texture;
public:
	void renderRect( SDL_Rect* rectangle, SDL_Renderer* renderer );
	cTileset( SDL_Texture* _texture );
};

#endif
