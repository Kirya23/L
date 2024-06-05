#include <gtest/gtest.h>
#include "task.h"

std::vector<Point> findTomatoFence(std::vector<Point> tomatoes);

TEST(FindTomatoFenceTest, EmptyInput) {
    std::vector<Point> tomatoes;
    std::vector<Point> result = findTomatoFence(tomatoes);
    EXPECT_TRUE(result.empty());
}

TEST(FindTomatoFenceTest, SingleTomato) {
    std::vector<Point> tomatoes = {{0, 0}};
    std::vector<Point> result = findTomatoFence(tomatoes);
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0].x, 0);
    EXPECT_EQ(result[0].y, 0);
}

TEST(FindTomatoFenceTest, MultipleTomates) {
    std::vector<Point> tomatoes = {{0, 0}, {1, 0}, {0, 1}, {1, 1}, {2, 0}};
    std::vector<Point> result = findTomatoFence(tomatoes);
    EXPECT_EQ(result.size(), 5);
    for (const auto& point : result) {
        EXPECT_TRUE(point.x == 0 || point.x == 1 || point.x == 2);
        EXPECT_TRUE(point.y == 0 || point.y == 1);
    }
}