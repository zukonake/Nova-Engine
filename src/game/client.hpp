//client.hpp
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
//
#include <typedef.hpp>
#include <entity/entity.hpp>
#include <render/camera.hpp>

class cClient
{
	friend class cServer;
	std::unique_ptr< table > objectTable;
	std::unique_ptr< cEntity > player;
	std::unique_ptr< cCamera > camera;
	cInterfaceHandler interfaceHandler;

	void work();
	void render();
public:
	cClient( std::unique_ptr< table > _objectTable );
};

#endif
