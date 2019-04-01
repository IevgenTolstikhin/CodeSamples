#define BOOST_TEST_MODULE FrameTest testcases

#ifdef WIN32
#include <boost/test/unit_test.hpp>
#else
#include <boost/test/included/unit_test.hpp>
#endif

#include "Frame.h"
#include "Utils.h"

BOOST_AUTO_TEST_SUITE (FrameTest)

BOOST_AUTO_TEST_CASE(InitFrameTestCase)
{
    CFrame frame;
    BOOST_CHECK_EQUAL(frame.GetFirstTrialItems(), 0);
    BOOST_CHECK_EQUAL(frame.GetSecondTrialItems(), 0);
    BOOST_CHECK(frame.GetCurrentTrialNumber() == TRIAL_NUMBER::ZERO);
    BOOST_CHECK_EQUAL(frame.Get10thFrame(), false);
    BOOST_CHECK(frame.GetFlags() == FLAGS::NOTHING);
}

BOOST_AUTO_TEST_CASE(SetGetFirstTrialTestCase)
{
    CFrame frame;
    frame.SetFirstTrialItems(8);
    BOOST_CHECK_EQUAL(frame.GetFirstTrialItems(), 8);
}

BOOST_AUTO_TEST_CASE(SetGetSecondTrialTestCase)
{
    CFrame frame;
    frame.SetSecondTrialItems(6);
    BOOST_CHECK_EQUAL(frame.GetSecondTrialItems(), 6);
}

BOOST_AUTO_TEST_CASE(SetGetCurrentTrialTestCase)
{
    CFrame frame;
    frame.SetCurrentTrialNumber(TRIAL_NUMBER::THIRD);
    BOOST_CHECK(frame.GetCurrentTrialNumber() == TRIAL_NUMBER::THIRD);
}

BOOST_AUTO_TEST_CASE(SetGet10thFrameTestCase)
{
    CFrame frame;
    frame.Set10thFrame(true);
    BOOST_CHECK_EQUAL(frame.Get10thFrame(), true);
}

BOOST_AUTO_TEST_CASE(SetGetFlagTestCase)
{
    CFrame frame;
    frame.SetFlags(FLAGS::SPARE);
    BOOST_CHECK(frame.GetFlags() == FLAGS::SPARE);

    frame.SetFlags(FLAGS::STRIKE);
    BOOST_CHECK(frame.GetFlags() == FLAGS::STRIKE);
}

BOOST_AUTO_TEST_SUITE_END()
