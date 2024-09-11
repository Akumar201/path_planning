#ifndef PATHFINDING_HPP
#define PATHFINDING_HPP

#include "grid.hpp"
#include "agent.hpp"
#include <vector>
#include <queue>
#include <stack>
#include <utility>

class Pathfinding {
public:
    static bool bfs(Grid& grid, Agent& agent, int goalX, int goalY);
    static bool dfs(Grid& grid, Agent& agent, int goalX, int goalY);
};

#endif
