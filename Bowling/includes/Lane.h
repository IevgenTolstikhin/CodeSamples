#ifndef __LANE_H__
#define __LANE_H__

#include <vector>
#include <memory>
#include <random>
#include <string>

#include "Utils.h"
#include "Player.h"

//class CUtils;
//class CPlayer;
class CLane
{
public:
    CLane( unsigned );
    CLane( ) = delete;
    ~CLane( ) = default;
    void Play( );
    void ModifyPlayer( unsigned, const std::string& );
    void AddPlayer( const std::string& );
    void WaitForKick( unsigned );
    std::vector< std::shared_ptr< CPlayer > > getPlayersList() const;
    unsigned getAmountOfItems() const;
    unsigned getAmountOfPlayers() const;

private:
    std::vector< std::shared_ptr< CPlayer > > vpPlayer;
    std::unique_ptr< CUtils > puUtil;

    std::random_device rd;
    std::mt19937 gen;
    unsigned m_uAmountOfItems;
    unsigned m_uAmountOfPlayers;
};

#endif  //__LANE_H_
