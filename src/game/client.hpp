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

	std::shared_ptr< table > objectTable;
	std::shared_ptr< cEntity > player;
	cInterfaceHandler interfaceHandler;

	void work();
	void render();
	void connectServer( std::shared_ptr< table > _objectTable, std::string gameTitle = "Unnamed" );
public:

	//cClient( std::unique_ptr< table > _objectTable, uint screenWidth = 800, uint screenHeight = 640 );
	cClient( uint screenWidth = 800, uint screenHeight = 640, std::string windowTitle = "Unnamed" );
};

#endif
