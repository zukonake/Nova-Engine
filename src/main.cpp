/*
	Nova-Engine Copyright (C) 2015 zukonake

		This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public
		License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any
		later version.

		This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
		implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public
		License for more details.

		You should have received a copy of the GNU General Public License along with this program;
		if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

	https://github.com/Nevseis/Nova-Engine
*/
#include <memory>
#include <unistd.h>
#include <string>
//
#include <game/server.hpp>
#include <game/client.hpp>


int main( int argc, char argv[] )
{
	chdir( global::workingDirectory ); //Change working dir to root of project.
	cLuaWrapper luaWrapper = cLuaWrapper::newInstance();

	luaWrapper.openScript( global::configPath + "server.lua" );
	auto datasetPath = luaWrapper.getVariable< std::string >( "dataset" );
	cServer localserver = cServer::newInstance( datasetPath );
	localserver.initialize( std::make_shared< cLuaWrapper >( luaWrapper ) );

	luaWrapper.openScript( global::configPath + "client.lua" );
	auto windowWidth = luaWrapper.getVariable< uint >( "windowWidth" );
	auto windowHeight = luaWrapper.getVariable< uint >( "windowHeight" );
	auto windowTitle = luaWrapper.getVariable< std::string >( "windowTitle" );
	localserver.connectClient( std::make_unique< cClient >( windowWidth, windowHeight, windowTitle ) );
	localserver.work();
	return 0;
}
