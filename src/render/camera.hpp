//camera.hpp
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <typedef.hpp>
#include <render/interface.hpp>
#include <board/board.hpp>

class cCamera
{
	uint posX;
	uint posY;
	cBoard* board;
public:
	bool move( uint _posX, uint _posY, cBoard* _board );
	void render( cInterface* interface, uint fov, uint posX, uint posY );
	cCamera( uint _posX, uint _posY, cBoard* _board );
};

#endif
