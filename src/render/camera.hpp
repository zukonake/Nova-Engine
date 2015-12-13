//camera.hpp
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <memory>
//
#include <typedef.hpp>
#include <board/board.hpp>
#include <entity/entity.hpp>
#include <render/interface.hpp>

class cCamera
{
	std::shared_ptr< cPosition > boardPos;
	std::shared_ptr< cBoard > board;
public:
	void render( std::shared_ptr< cInterface > interface, cPosition screenPos, uint fov );
	cCamera( std::shared_ptr< cBoard > _board, std::shared_ptr< cPosition > _boardPos );
	cCamera( std::shared_ptr< cEntity > wrapTarget );
};

/*
cCamera exceptions:
	> 01 - Invalid board pointer.
	> 02 - Invalid wrapTarget pointer.
	> 03 - Non-existent block rendered.
*/

#endif
