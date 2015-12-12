//camera.hpp
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <memory>
//
#include <typedef.hpp>
#include <board/board.hpp>
#include <render/interface.hpp>

class cCamera
{
	cPosition boardPos;
	std::shared_ptr< cBoard > board;
public:
	void render( std::shared_ptr< cInterface > interface, cPosition screenPos, uint fov );

	cCamera( std::unique_ptr< cBoard > _board, cPosition _boardPos );
};

/*
cCamera exceptions:
	> 01 - Invalid board pointer
*/

#endif
