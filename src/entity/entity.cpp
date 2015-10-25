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
	board( boost::any_cast< cBoard* >( objectList[ "board" ][ luaToCpp[ "board" ] ] ) ),
	subtype( boost::any_cast< cEntitySubtype >( objectList[ "entitySubtype" ][ luaToCpp[ "subtype" ] ] ) ),
	control( boost::any_cast< cEntityControl >( objectList[ "entityControl" ][ luaToCpp[ "control" ] ] ) ),
	posX( boost::any_cast< uint16_t >( luaToCpp[ "posX" ] ) ),
	posY( boost::any_cast< uint16_t >( luaToCpp[ "posY" ] ) ),
	name( boost::any_cast< std::string >( luaToCpp[ "name" ] ) ),
	componentList( boost::any_cast< std::map< std::string, boost::any > >(luaToCpp[ "component" ] ) )
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
