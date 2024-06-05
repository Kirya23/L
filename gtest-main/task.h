#ifndef TASK_H
#define TASK_H

#include <vector>

struct Point {
    int x;
    int y;
};

std::vector<Point> findTomatoFence(std::vector<Point> tomatoes);

#endif