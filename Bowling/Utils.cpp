#include "Utils.h"
#include <iostream>

CUtils::CUtils( )
    : MAX_FRAMES( 10 )
    , MAX_ITEMS( 10 )
{
}

void
CUtils::Log( const std::string& sPlayerName, const std::string& sData )
{
    std::cout << "Trace info for " << sPlayerName << ": " << sData << std::endl;
    /*std::ofstream outputFile("Bowling.log", std::ofstream::out | std::ofstream::app);

    if(outputFile)
    {
        outputFile << data << std::endl;
        outputFile.close();
    }*/
}

void
CUtils::Log( const std::string& sData )
{
    std::cout << "Trace info: " << sData << std::endl;
    /*std::ofstream outputFile("Bowling.log", std::ofstream::out | std::ofstream::app);

    if(outputFile)
    {
        outputFile << data << std::endl;
        outputFile.close();
    }*/
}

unsigned
CUtils::GetMaxFrames( ) const
{
    return MAX_FRAMES;
}
unsigned
CUtils::GetMaxItems( ) const
{
    return MAX_ITEMS;
}