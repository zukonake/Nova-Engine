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
	std::shared_ptr< cBlockSubtype > subtype;
	void render( std::shared_ptr< cInterface > interface, cPosition pos );
	cBlock( std::shared_ptr< cBlockSubtype > _subtype );
	cBlock( table luaToCpp, std::shared_ptr< table > objectTable );
};

#endif
