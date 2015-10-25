//entity.cpp
#include "entity.cpp"

bool cEntity::move( uint targetPosX, uint targetPosY );
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

cEntity::cEntity( table luaToCpp, table* objectTable ) :
	board( boost::any_cast< cBoard* >( objectTable[ "board" ][ boost::any_cast< std::string >( luaToCpp[ "board" ] ) ] ) ),
	subtype( boost::any_cast< cEntitySubtype >( objectTable[ "entitySubtype" ][ boost::any_cast< std::string >( luaToCpp[ "subtype" ] ) ] ) ),
	control( boost::any_cast< cEntityControl >( objectTable[ "entityControl" ][ boost::any_cast< std::string >( luaToCpp[ "control" ] ) ] ) ),
	posX( boost::any_cast< uint16_t >( luaToCpp[ "posX" ] ) ),
	posY( boost::any_cast< uint16_t >( luaToCpp[ "posY" ] ) ),
	name( boost::any_cast< std::string >( luaToCpp[ "name" ] ) ),
	componentTable( boost::any_cast< table >( luaToCpp[ "component" ] ) )
{
	
}

cEntity( std::string _name, cBoard _board, table _componentTable, uint16_t _posX = 0, uint16_t _posY = 0 ) :
	name( _name ),
	board( _board ),
	componentTable( _componentTable ),
	posX( _poxX ),
	posY( _posY )
{

}
