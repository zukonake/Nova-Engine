//interfaceComponent.cpp
#include "interfaceComponent.hpp"

void cInterfaceComponent::render( std::shared_ptr< SDL_Renderer > renderer, std::shared_ptr< SDL_Texture > texture )
{
	SDL_RenderCopy( renderer, texture, sourceArea, renderArea ); //TODO script
}

cInterfaceComponent::cInterfaceComponent( table luaToCpp, std::shared_ptr< table > objectTable ) :
	sourceArea( SDL_Rect() ),
	sourceArea.x( boost::any_cast< uint >( luaToCpp[ "sourceArea.x" ] ) ),
	sourceArea.y( boost::any_cast< uint >( luaToCpp[ "sourceArea.y" ] ) ),
	sourceArea.w( boost::any_cast< uint >( luaToCpp[ "sourceArea.width" ] ) ),
	sourceArea.h( boost::any_cast< uint >( luaToCpp[ "sourceArea.height" ] ) ),
	renderArea( SDL_Rect() ),
	renderArea.x( boost::any_cast< uint >( luaToCpp[ "renderArea.x" ] ) ),
	renderArea.y( boost::any_cast< uint >( luaToCpp[ "renderArea.y" ] ) ),
	renderArea.w( boost::any_cast< uint >( luaToCpp[ "renderArea.width" ] ) ),
	renderArea.h( boost::any_cast< uint >( luaToCpp[ "renderArea.height" ] ) ),
	script( boost::any_cast< std::string >( luaToCpp[ "script" ] ) )
{

}
