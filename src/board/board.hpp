//board.hpp
#ifndef BOARD_HPP
#define BOARD_HPP

#include <string>
#include <vector>
//
#include <typedef.hpp>
#include <block/block.hpp>
#include <board/boardGenerator.hpp>

class cBoard
{
	friend class cEntity;
	friend class cGame;

	typedef std::vector < std::shared_ptr< cBlock > > blockVector;

	blockVector blocks;
	std::shared_ptr< cBoardGenerator > generator;
	std::string name;
	uint height;
	uint width;
	void generate();
public:
	bool canTeleport( const cPosition& targetPos );
	std::shared_ptr< cBlock > getBlock( cPosition targetPosition );
private:
	cBoard( blockVector _blocks, std::shared_ptr< cBoardGenerator > _generator, std::string _name, uint _height, uint _width);
	cBoard( table luaToCpp, std::shared_ptr< table > objectTable );
};

#endif
