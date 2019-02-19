#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

typedef enum class _TRIAL_NUMBER_
{
    FIRST,
    SECOND,
    THIRD
} TRIAL_NUMBER;

class CUtils
{
    const unsigned MAX_FRAMES;
    const unsigned MAX_ITEMS;

public:
    CUtils( );
    void Log( const std::string&, const std::string& );
    void Log( const std::string& );

    unsigned GetMaxFrames( ) const;
    unsigned GetMaxItems( ) const;
};

#endif  //__UTILS_H__