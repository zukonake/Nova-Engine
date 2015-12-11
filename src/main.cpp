#include <memory>
//
#include <game/server.hpp>
#include <game/client.hpp>

int main( int argc, char argv[] )
{
	cServer localserver = cServer::newInstance();
	localserver.initialize();
	localserver.connectClient( std::make_unique( new cClient() ) );
	localserver.work(); //TODO
	return 0;
}
