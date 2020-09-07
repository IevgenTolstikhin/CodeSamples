#include <gtest/gtest.h>

#include "Utils.h"

TEST(UtilsTest, SimpleTestCase) {
    CUtils utils;

    ASSERT_EQ(10, utils.GetMaxFrames());
    ASSERT_EQ(10, utils.GetMaxItems());
}
