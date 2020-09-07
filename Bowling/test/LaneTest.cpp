#include <gtest/gtest.h>

#include "Lane.h"

TEST(LaneTest, InitLaneTestCase)
{
    CLane lane(1);
    ASSERT_EQ(lane.getPlayersList().at(0)->GetName(), "Player0");
    ASSERT_EQ(lane.getAmountOfPlayers(), 1);
    ASSERT_EQ(lane.getAmountOfItems(), 0);
}

TEST(LaneTest, PlayTestCase)
{
    CLane lane(1);
    lane.Play();
}
