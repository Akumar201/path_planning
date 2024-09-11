#include "pathfinding.hpp"

bool Pathfinding::bfs(Grid& grid, Agent& agent, int goalX, int goalY) {
    int startX = agent.getX();
    int startY = agent.getY();
    
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));
    
    q.push({startX, startY});
    visited[startX][startY] = true;
    
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        
        if (x == goalX && y == goalY) {
            return true;
        }

        // Check all four directions (up, down, left, right)
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;
            
            if (newX >= 0 && newX < grid.getHeight() && newY >= 0 && newY < grid.getWidth()
                && !visited[newX][newY] && !grid.isObstacle(newX, newY)) {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    return false;  // No path found
}

bool Pathfinding::dfs(Grid& grid, Agent& agent, int goalX, int goalY) {
    int startX = agent.getX();
    int startY = agent.getY();
    
    std::stack<std::pair<int, int>> s;
    std::vector<std::vector<bool>> visited(grid.getHeight(), std::vector<bool>(grid.getWidth(), false));
    
    s.push({startX, startY});
    visited[startX][startY] = true;
    
    while (!s.empty()) {
        auto [x, y] = s.top();
        s.pop();
        
        if (x == goalX && y == goalY) {
            return true;
        }

        // Check all four directions (up, down, left, right)
        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (auto [dx, dy] : directions) {
            int newX = x + dx;
            int newY = y + dy;
            
            if (newX >= 0 && newX < grid.getHeight() && newY >= 0 && newY < grid.getWidth()
                && !visited[newX][newY] && !grid.isObstacle(newX, newY)) {
                s.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
    
    return false;  // No path found
}
