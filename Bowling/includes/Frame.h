#ifndef __FRAME_H__
#define __FRAME_H__

#include <string>
#include "Utils.h"

enum class FLAGS
{
    NOTHING,
    SPARE,
    STRIKE
};

class CFrame
{
public:
    CFrame( ) = default;
    ~CFrame( ) = default;

    void SetFirstTrialItems( unsigned short uValue );
    void SetSecondTrialItems( unsigned short uValue );
    void SetCurrentTrialNumber( TRIAL_NUMBER uValue );
    void Set10thFrame( bool bValue );
    void SetFlags( const FLAGS& flag );

    unsigned short GetFirstTrialItems( ) const;
    unsigned short GetSecondTrialItems( ) const;
    TRIAL_NUMBER GetCurrentTrialNumber( ) const;
    bool Get10thFrame( ) const;
    FLAGS GetFlags( ) const;
    std::string GetFlagsToString( ) const;

private:
    unsigned short uFirstTrialItems = 0;
    unsigned short uSecondTrialItems = 0;
    TRIAL_NUMBER uCurrentTrialNumber = TRIAL_NUMBER::ZERO;
    FLAGS fFlags = FLAGS::NOTHING;
    bool b10thFrame = false;
};

#endif  //__FRAME_CPP__
