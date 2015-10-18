//initializer.cpp
#include "initializer.hpp"
#include "lua/luaTable.hpp"
#include "global.hpp"

cInitializer::cInitializer(lua_state* L)
{
	cLuaWrapper luaWrapper;
	luaWrapper.openScript( "../../config/globals.lua" );
	//TODO load global variables
	luaWrapper.openScript( "../../ext/lua/listFiles.lua" );
	luaWrapper.runFunction< cLuaTable >( "listFiles", "tile" );
	
	//TODO list and read files and send them to constructors
}
