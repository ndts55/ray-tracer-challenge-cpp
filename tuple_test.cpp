#include <iostream>
#include <gtest/gtest.h>
#include "tuple.h"

TEST(chapter_one, tuple_with_w1_is_point) {
    auto t = Tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_EQ(4.3, t.x());
    EXPECT_EQ(-4.2, t.y());
    EXPECT_EQ(3.1, t.z());
    EXPECT_EQ(1.0, t.w());
    EXPECT_TRUE(t.isPoint());
    EXPECT_FALSE(t.isVector());
}

TEST(chapter_one, tuple_with_w0_is_vector) {
    auto t = Tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_EQ(4.3, t.x());
    EXPECT_EQ(-4.2, t.y());
    EXPECT_EQ(3.1, t.z());
    EXPECT_EQ(0.0, t.w());
    EXPECT_FALSE(t.isPoint());
    EXPECT_TRUE(t.isVector());
}

TEST(chapter_one, point_function_creates_point) {
    auto expected = Tuple(4, -4, 3, 1);
    auto actual = point(4, -4, 3);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, vector_function_creates_vector) {
    auto expected = Tuple(4, -4, 3, 0);
    auto actual = vector(4, -4, 3);
    EXPECT_EQ(expected, actual);
}
