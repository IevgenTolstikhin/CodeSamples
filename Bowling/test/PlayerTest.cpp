#define BOOST_TEST_MODULE PlayerTest testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "Player.h"

BOOST_AUTO_TEST_SUITE (PlayerTest)

BOOST_AUTO_TEST_CASE(InitPlayerTestCase)
{
    CPlayer player("John");
    BOOST_CHECK_EQUAL(player.GetName(), "John");

    //Should be default game from the very beginning
    BOOST_CHECK_EQUAL(player.GetGame()->GetCurrentFrameNumber(), 0);
    BOOST_CHECK_EQUAL(player.GetGame()->GetRestOfItems(), 10);
    BOOST_CHECK_EQUAL(player.GetGame()->GetTotal(), 0);

    //Should be default frame from the very beginning
    BOOST_CHECK_EQUAL(player.GetGame()->GetFrame(0)->GetFirstTrialItems(), 0);
    BOOST_CHECK_EQUAL(player.GetGame()->GetFrame(0)->GetSecondTrialItems(), 0);
    BOOST_CHECK(player.GetGame()->GetFrame(0)->GetCurrentTrialNumber() == TRIAL_NUMBER::ZERO);
    BOOST_CHECK_EQUAL(player.GetGame()->GetFrame(0)->Get10thFrame(), false);
    BOOST_CHECK(player.GetGame()->GetFrame(0)->GetFlags() == FLAGS::NOTHING);
}

BOOST_AUTO_TEST_SUITE_END()