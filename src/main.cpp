#include "grid.hpp"
#include "agent.hpp"
#include "pathfinding.hpp"
#include <iostream>
#include <ctime>

int main() {
    srand(time(0));

    int width = 20;
    int height = 20;
    double obstacle_percentage = 0.2;  // 20% obstacles

    Grid grid(width, height, obstacle_percentage);

    int startX = rand() % height;
    int startY = rand() % width;
    int goalX = rand() % height;
    int goalY = rand() % width;

    while (grid.isObstacle(startX, startY) || grid.isObstacle(goalX, goalY)) {
        startX = rand() % height;
        startY = rand() % width;
        goalX = rand() % height;
        goalY = rand() % width;
    }

    grid.setAgent(startX, startY);
    grid.setGoal(goalX, goalY);

    grid.display();

    Agent agent(startX, startY);

    if (Pathfinding::bfs(grid, agent, goalX, goalY)) {
        std::cout << "Path found using BFS!" << std::endl;
    } else {
        std::cout << "No path found using BFS." << std::endl;
    }

    if (Pathfinding::dfs(grid, agent, goalX, goalY)) {
        std::cout << "Path found using DFS!" << std::endl;
    } else {
        std::cout << "No path found using DFS." << std::endl;
    }

    return 0;
}
