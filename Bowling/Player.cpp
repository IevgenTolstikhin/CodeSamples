#include "Player.h"

CPlayer::CPlayer( const std::string& name )
    : sName( name )
    , pgGame( new CGame )
{
}

CPlayer::CPlayer( )
    : CPlayer( "" )
{
}

// Getters
std::shared_ptr< CGame >
CPlayer::GetGame( ) const
{
    return pgGame;
}
std::string
CPlayer::GetName( ) const
{
    return sName;
}