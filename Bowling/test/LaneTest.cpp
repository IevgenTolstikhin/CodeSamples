#define BOOST_TEST_MODULE LaneTest testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "Lane.h"

BOOST_AUTO_TEST_SUITE (LaneTest)

BOOST_AUTO_TEST_CASE(InitLaneTestCase)
{
    CLane lane(1);
    BOOST_CHECK_EQUAL(lane.getPlayersList().at(0)->GetName(), "Player0");
    BOOST_CHECK_EQUAL(lane.getAmountOfPlayers(), 1);
    BOOST_CHECK_EQUAL(lane.getAmountOfItems(), 0);
}

BOOST_AUTO_TEST_CASE(PlayTestCase)
{
    //TODO
}

BOOST_AUTO_TEST_SUITE_END()
