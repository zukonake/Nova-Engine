//dataset.hpp
#ifndef DATASET_HPP
#define DATASET_HPP

#include <memory>
#include <string>
//
#include <typedef.hpp>
#include <lua/luaWrapper.hpp>

class cDataset
{
	fixedTable objectTable;
	cDataset( std::string path, std::shared_ptr< cLuaWrapper > luaWrapper );
};

#endif
