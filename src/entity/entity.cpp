//entity.cpp
#include "entity.cpp"

bool cEntity::move( uint16_t targetPosX, uint16_t targetPosY );
{
	if( targetPosX <= 0 || targetPosX >= board->width || targetPosY <= 0 || targetPosY >= board->height )
	{
		return false;
	}
	else
	{
		posX = targetPosX;
		posY = targetPosY;
		return true;
	}
}

cEntity::cEntity( cLuaTable luaToCpp, cLuaTable* objectList ) :
	board( objectList->get( "board" )->get( luaToCpp.get< std::string >( "board" ) ) ),
	subtype( objectList->get( "entitySubtype" )->get( luaToCpp.get< std::string >( "subtype" ) ) ),
	control( objectList->get( "entityControl" )->get( luaToCpp.get< std::string >( "control" ) ) ),
	posX( luaToCpp.get< uint16_t >( "posX" ) ),
	posY( luaToCpp.get< uint16_t >( "posY" ) ),
	name( luaToCpp.get< std::string >( "name" ) ),
	componentList( luaToCpp.get< cLuaTable >( "component" ) )
{
	
}

cEntity( std::string _name, cBoard _board, cLuaTable _componentList, uint16_t _posX = 0, uint16_t _posY = 0 ) :
	name( _name ),
	board( _board ),
	componentList( _componentList ),
	posX( _poxX ),
	posY( _posY )
{

}
