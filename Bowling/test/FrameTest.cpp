#include <gtest/gtest.h>

#include "Frame.h"
#include "Utils.h"

TEST(FrameTest, InitFrameTestCase)
{
    CFrame frame;
    ASSERT_EQ(frame.GetFirstTrialItems(), 0);
    ASSERT_EQ(frame.GetSecondTrialItems(), 0);
    ASSERT_TRUE(frame.GetCurrentTrialNumber() == TRIAL_NUMBER::FIRST);
    ASSERT_FALSE(frame.Get10thFrame());
    ASSERT_TRUE(frame.GetFlags() == FLAGS::NOTHING);
}

TEST(FrameTest, SetGetFirstTrialTestCase)
{
    CFrame frame;
    frame.SetFirstTrialItems(8);
    ASSERT_EQ(frame.GetFirstTrialItems(), 8);
}

TEST(FrameTest, SetGetSecondTrialTestCase)
{
    CFrame frame;
    frame.SetSecondTrialItems(6);
    ASSERT_EQ(frame.GetSecondTrialItems(), 6);
}

TEST(FrameTest, SetGetCurrentTrialTestCase)
{
    CFrame frame;
    frame.SetCurrentTrialNumber(TRIAL_NUMBER::THIRD);
    ASSERT_TRUE(frame.GetCurrentTrialNumber() == TRIAL_NUMBER::THIRD);
}

TEST(FrameTest, SetGet10thFrameTestCase)
{
    CFrame frame;
    frame.Set10thFrame(true);
    ASSERT_TRUE(frame.Get10thFrame());
}

TEST(FrameTest, SetGetFlagTestCase)
{
    CFrame frame;
    frame.SetFlags(FLAGS::SPARE);
    ASSERT_TRUE(frame.GetFlags() == FLAGS::SPARE);

    frame.SetFlags(FLAGS::STRIKE);
    ASSERT_TRUE(frame.GetFlags() == FLAGS::STRIKE);
}
