//block.hpp
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>
#include <string>
//
#include <typedef.hpp>
#include <position.hpp>
#include <render/interface.hpp>
#include <block/blockSubtype.hpp>

class cBlock
{
	friend class cBoard;
	friend class cGame::initializeObjects();
	friend class cCamera::render();
	cBlockSubtype* subtype;
	void render( cInterface* interface, cPosition pos );
	cBlock( cBlockSubtype* _subtype );
	cBlock( table luaToCpp, table* objectTable );
};

#endif
