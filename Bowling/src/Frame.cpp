#include "Frame.h"

// Setters
void
CFrame::SetFirstTrialItems( unsigned short uValue )
{
    uFirstTrialItems = uValue;
}

void
CFrame::SetSecondTrialItems( unsigned short uValue )
{
    uSecondTrialItems = uValue;
}

void
CFrame::SetCurrentTrialNumber( TRIAL_NUMBER uValue )
{
    uCurrentTrialNumber = uValue;
}

void
CFrame::Set10thFrame( bool bValue )
{
    b10thFrame = bValue;
}

void
CFrame::SetFlags( const FLAGS& flag )
{
    fFlags = flag;
}

// Getters
unsigned short
CFrame::GetFirstTrialItems( ) const
{
    return uFirstTrialItems;
}

unsigned short
CFrame::GetSecondTrialItems( ) const
{
    return uSecondTrialItems;
}

TRIAL_NUMBER
CFrame::GetCurrentTrialNumber( ) const
{
    return uCurrentTrialNumber;
}

bool
CFrame::Get10thFrame( ) const
{
    return b10thFrame;
}

FLAGS
CFrame::GetFlags( ) const
{
    return fFlags;
}

std::string
CFrame::GetFlagsToString( ) const
{
    switch ( fFlags )
    {
    case FLAGS::NOTHING:
        return "NOTHING";
    case FLAGS::SPARE:
        return "SPARE";
    case FLAGS::STRIKE:
        return "STRIKE";
    }

    return "Undefined";
}
