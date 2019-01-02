#include "TagData.h"

bool
operator>( const TDATA& lhs, const TDATA& rhs )
{
    return lhs.priority > rhs.priority;
}
