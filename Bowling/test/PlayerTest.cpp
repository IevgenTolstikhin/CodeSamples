#include <gtest/gtest.h>

#include "Player.h"

TEST(PlayerTest, InitPlayerTestCase)
{
    CPlayer player("Player0");
    ASSERT_EQ(player.GetName(), "Player0");

    //Should be default game from the very beginning
    ASSERT_EQ(player.GetGame()->GetCurrentFrameNumber(), 0);
    ASSERT_EQ(player.GetGame()->GetRestOfItems(), 10);
    ASSERT_EQ(player.GetGame()->GetTotal(), 0);

    //Should be default frame from the very beginning
    ASSERT_EQ(player.GetGame()->GetFrame(0)->GetFirstTrialItems(), 0);
    ASSERT_EQ(player.GetGame()->GetFrame(0)->GetSecondTrialItems(), 0);
    ASSERT_TRUE(player.GetGame()->GetFrame(0)->GetCurrentTrialNumber() == TRIAL_NUMBER::FIRST);
    ASSERT_FALSE(player.GetGame()->GetFrame(0)->Get10thFrame());
    ASSERT_TRUE(player.GetGame()->GetFrame(0)->GetFlags() == FLAGS::NOTHING);
}
