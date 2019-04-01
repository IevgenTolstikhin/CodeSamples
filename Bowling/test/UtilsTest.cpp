#define BOOST_TEST_MODULE UtilsTest testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "Utils.h"

BOOST_AUTO_TEST_SUITE (UtilsTest)

BOOST_AUTO_TEST_CASE(SimpleTestCase)
{
    CUtils utils;
    BOOST_CHECK_EQUAL(utils.GetMaxFrames(), 10);
    BOOST_CHECK_EQUAL(utils.GetMaxItems(), 10);
}

BOOST_AUTO_TEST_SUITE_END()
