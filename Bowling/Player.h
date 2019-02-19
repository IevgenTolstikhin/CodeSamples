#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <memory>
#include "Game.h"

class CPlayer
{
    std::string sName;
    std::shared_ptr< CGame > pgGame;

public:
    CPlayer( const std::string& name );
    CPlayer( );

    std::shared_ptr< CGame > GetGame( ) const;
    std::string GetName( ) const;
};

#endif  //__PLAYER_H__