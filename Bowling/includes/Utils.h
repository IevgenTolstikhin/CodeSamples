#ifndef __UTILS_H__
#define __UTILS_H__

#include <string>

enum class TRIAL_NUMBER
{
    ZERO,
    FIRST,
    SECOND,
    THIRD
};

class CUtils
{
public:
    CUtils( ) = default;
    ~CUtils( ) = default;
    void Log( const std::string&, const std::string& );
    void Log( const std::string& );

    unsigned GetMaxFrames( ) const;
    unsigned GetMaxItems( ) const;

private:
    constexpr static unsigned MAX_FRAMES = 10;
    constexpr static unsigned MAX_ITEMS = 10;
};

#endif  //__UTILS_H__
