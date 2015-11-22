//interfaceHandler.hpp
#ifndef INTERFACEHANDLER_HPP
#define INTERFACEHANDLER_HPP

#include <vector>
#include "typedef.hpp"
#include "interface.hpp"

class cInterfaceHandler
{
	uint width;
	uint height;
public:
	std::vector< cInterface > interfaceVector;
	render();
	clear();
	refresh();
	cInterfaceHandler( uint _width, uint _height );
	~cInterfaceHandler();
};

#endif
