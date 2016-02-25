//block.hpp
#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <cstdint>
#include <string>
//
#include <typedef.hpp>
#include <render/interface.hpp>
#include <block/blockSubtype.hpp>

class cBlock
{
	friend class cBoard;
	friend class cGame;
	friend class cCamera;
	cBlockSubtype* subtype;
	void render( cInterface* interface, cPosition pos );
	cBlock( cBlockSubtype* _subtype );
	cBlock( table luaToCpp, table* objectTable );
};

#endif
