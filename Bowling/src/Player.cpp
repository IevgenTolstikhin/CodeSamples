#include "Player.h"
#include "Game.h"

CPlayer::CPlayer( const std::string& name )
    : sName( name )
    , pgGame( std::make_unique<CGame>() )
{
}

// Getters
CGame* CPlayer::GetGame( ) const
{
    return pgGame.get();
}

std::string CPlayer::GetName( ) const
{
    return sName;
}
