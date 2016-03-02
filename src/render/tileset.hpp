//tileset.hpp
#ifndef TILESET_HPP
#define TILESET_HPP
#include <SDL2/SDL.h>
//
#include <typedef.hpp>

class cTileset
{
	std::shared_ptr< SDL_Texture > texture;
public:
	void renderRect( std::shared_ptr< SDL_Rect > sRectangle, std::shared_ptr< SDL_Rect > dRectangle, std::shared_ptr< SDL_Renderer > renderer );
	cTileset( std::shared_ptr< SDL_Texture > _texture );
};

#endif
