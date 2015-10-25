//global.hpp
#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include <map>
#include <boost/any.hpp>
#include <string>
#include <cstdint>
#include "lua/luaTable.hpp"

namespace global
{
	typedef std::map< std::string, boost::any > table;
	typedef uint16_t uint;
	extern const std::string configPath;
	extern std::string datasetPath;
}

#endif
