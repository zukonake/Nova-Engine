//typedef.hpp
#ifndef TYPEDEF_HPP
#define TYPEDEF_HPP

#include <string>
#include <map>
#include <boost/any.hpp>
#include <cstdint>

typedef std::map< std::string, boost::any > table;
typedef uint16_t uint;
struct cPosition
{
	uint x;
	uint y;
	cPosition( uint _x, uint _y ) : x( _x ), y( _y );
}

#endif
