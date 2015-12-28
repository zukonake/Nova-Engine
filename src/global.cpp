//global.cpp
#include "global.hpp"

using namespace global
{
	workingDirectory = "../../";
	configPath = workingDirectory .. "config/";
	objectTypes = {
		"tileset",
		"blockSubtype",
		"block",
		"boardGenerator",
		"board",
		"entitySubtype",
		"entity",
		"entityAction",
		"entityControl",
		"interfaceComponent",
		"interface" };

}
