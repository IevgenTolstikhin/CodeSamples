#define BOOST_TEST_MODULE TagData testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "TagData.h"

BOOST_AUTO_TEST_SUITE (TagDataTest)

BOOST_AUTO_TEST_CASE(EqualCheckCase)
{
    TDATA data1 {0, 1, 2, L"Some text"};
    TDATA data2 {0, 2, 3, L"Some other text"};
    BOOST_CHECK( !( data1 > data2) );
}

BOOST_AUTO_TEST_CASE(GreaterCheckCase)
{
    TDATA data1 {2, 1, 2, L"Some text"};
    TDATA data2 {1, 2, 3, L"Some other text"};
    BOOST_CHECK( data1 > data2 );
}

BOOST_AUTO_TEST_SUITE_END()
