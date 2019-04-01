#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <memory>
#include "Game.h"

//class CGame;
class CPlayer
{
public:
    CPlayer( const std::string& name );
    CPlayer( ) = delete;
    ~CPlayer( ) = default;

    CGame* GetGame( ) const;
    std::string GetName( ) const;

private:
    std::string sName;
    std::unique_ptr< CGame > pgGame;
};

#endif  //__PLAYER_H__
