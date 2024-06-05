#include <vector>
#include <set>
#include <sstream>
#include "task.h"

std::vector<Point> findTomatoFence(std::vector<Point> tomatoes) {
    std::set<std::pair<int, int>> tomatoSet;
    for (const auto& tomato : tomatoes) {
        tomatoSet.insert({tomato.x, tomato.y});
    }

    std::vector<Point> fenceTomatoes;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    for (const auto& tomato : tomatoes) {
        for (int i = 0; i < 4; ++i) {
            int nx = tomato.x + dx[i];
            int ny = tomato.y + dy[i];
            if (tomatoSet.count({nx, ny}) == 0) {
                fenceTomatoes.push_back({tomato.x, tomato.y});
                break;
            }
        }
    }

    return fenceTomatoes;
}