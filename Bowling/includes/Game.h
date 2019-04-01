#ifndef __GAME_H__
#define __GAME_H__

#include <memory>
#include <vector>
#include "Frame.h"
#include "Utils.h"

//class CUtils;
class CGame
{
public:
    CGame( );
    ~CGame( ) = default;

    CFrame* GetCurrentFrame( ) const;
    CFrame* GetFrame( unsigned short nFrameNumber ) const;
    unsigned short GetCurrentFrameNumber( ) const;
    unsigned short GetRestOfItems( ) const;
    unsigned GetTotal( ) const;

    void ModifyCurrentTrialNumber( );
    void IncCurrentFrame( );
    void UpdateRestOfItems( );
    void GameOver( );

    std::shared_ptr< CUtils > GetUtils() const;

private:
    std::shared_ptr< CUtils > puUtil;
    unsigned short uCurrentFrameNumber;
    unsigned short uRestOfItems;
    unsigned uTotal;
    std::vector< std::shared_ptr< CFrame > > vpFrames;
};

#endif  //__GAME_H__
