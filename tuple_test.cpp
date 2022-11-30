#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "tuple.h"

TEST(chapter_one, tuple_with_w1_is_point) {
    auto t = Tuple(4.3, -4.2, 3.1, 1.0);
    EXPECT_EQ(4.3, t.X());
    EXPECT_EQ(-4.2, t.Y());
    EXPECT_EQ(3.1, t.Z());
    EXPECT_EQ(1.0, t.W());
    EXPECT_TRUE(t.IsPoint());
    EXPECT_FALSE(t.IsVector());
}

TEST(chapter_one, tuple_with_w0_is_vector) {
    auto t = Tuple(4.3, -4.2, 3.1, 0.0);
    EXPECT_EQ(4.3, t.X());
    EXPECT_EQ(-4.2, t.Y());
    EXPECT_EQ(3.1, t.Z());
    EXPECT_EQ(0.0, t.W());
    EXPECT_FALSE(t.IsPoint());
    EXPECT_TRUE(t.IsVector());
}

TEST(chapter_one, point_function_creates_point) {
    auto expected = Tuple(4, -4, 3, 1);
    auto actual = Point(4, -4, 3);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, vector_function_creates_vector) {
    auto expected = Tuple(4, -4, 3, 0);
    auto actual = Vector(4, -4, 3);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, adding_two_tuples) {
    auto expected = Tuple(1,1,6,1);
    auto actual = Tuple(3,-2,5,1) + Tuple(-2,3,1,0);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, subtracting_two_points) {
    auto expected = Vector(-2,-4,-6);
    auto actual = Point(3,2,1) - Point(5,6,7);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, subtracting_vector_from_point) {
    auto expected = Point(-2,-4,-6);
    auto actual = Point(3,2,1) - Vector(5,6,7);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, subtracting_two_vectors) {
    auto expected = Vector(-2,-4,-6);
    auto actual = Vector(3,2,1) - Vector(5,6,7);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, subtracting_vector_from_zero_vector) {
    auto expected = Vector(-1,2,-3);
    auto actual = Vector(0,0,0) - Vector(1,-2,3);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, negating_tuple) {
    auto expected = Tuple(-1,2,-3,4);
    auto actual = -Tuple(1,-2,3,-4);
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, multiplying_tuple_by_scalar) {
    auto expected = Tuple(3.5,-7,10.5,-14);
    auto actual = Tuple(1,-2,3,-4) * 3.5;
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, computing_magnitude_of_vector) {
    std::vector<std::tuple<double, Tuple>> testData{
        std::tuple<double, Tuple>(1, Vector(1,0,0)),
        std::tuple<double, Tuple>(1, Vector(0,1,0)),
        std::tuple<double, Tuple>(1, Vector(0,0,1)),
        std::tuple<double, Tuple>(sqrt(14), Vector(1,2,3)),
        std::tuple<double, Tuple>(sqrt(14), Vector(-1,-2,-3)),
    };
    for(auto tt: testData) {
        auto expected = std::get<0>(tt);
        auto actual = std::get<1>(tt).Magnitude();
        EXPECT_EQ(expected, actual);
    }
}

TEST(chapter_one, normalizing_vectors) {
    std::vector<std::tuple<Tuple, Tuple>> testData{
        std::tuple<Tuple, Tuple>(Vector(1,0,0), Vector(4,0,0)),
        std::tuple<Tuple, Tuple>(Vector(1.0f/sqrt(14), 2.0f/sqrt(14), 3.0f/sqrt(14)), Vector(1,2,3)),
    };
    for(auto tt: testData) {
        auto expected = std::get<0>(tt);
        auto actual = std::get<1>(tt).Normalized();
        EXPECT_EQ(expected, actual);
    }
}

TEST(chapter_one, magnitude_of_normalized_vector) {
    auto expected = 1;
    auto actual = Vector(1,2,3).Normalized().Magnitude();
    EXPECT_EQ(expected, actual);
}

TEST(chapter_one, dot_product_of_two_tuples) {
    auto expected = 20;
    auto actual = Vector(1,2,3) * Vector(2,3,4);
    EXPECT_EQ(expected, actual);
}
