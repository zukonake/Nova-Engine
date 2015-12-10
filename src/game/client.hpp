//client.hpp
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <typedef.hpp>
#include <entity/entity.hpp>

class cClient
{
	friend class cServer;
	table* objectTable;
	cEntity* player;
	std::unique_ptr< cCamera > camera;
	cInterfaceHandler interfaceHandler;
	cClient();
};

#endif
