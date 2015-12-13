//client.hpp
#ifndef CLIENT_HPP
#define CLIENT_HPP

#include <memory>
//
#include <typedef.hpp>
#include <entity/entity.hpp>
#include <render/camera.hpp>
#include <render/interfaceHandler.hpp>

class cClient
{
	friend class cServer;

	std::shared_ptr< fixedTable > objectTable;
	std::shared_ptr< cEntity > player;
	std::unique_ptr< cInterfaceHandler > interfaceHandler;
	bool running;

	void work();
	void render();
	void connectServer( std::shared_ptr< fixedTable > _objectTable, std::string gameTitle );
public:
	cClient( uint screenWidth, uint screenHeight, std::string windowTitle );
};

#endif
