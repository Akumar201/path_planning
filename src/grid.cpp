#include "grid.hpp"

Grid::Grid(int width, int height, double obstacle_percentage)
    : width(width), height(height), obstacle_percentage(obstacle_percentage) {
    grid.resize(height, std::vector<char>(width, '.'));  // Initialize grid with empty spaces
    generateObstacles();
}

void Grid::generateObstacles() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (dis(gen) < obstacle_percentage) {
                grid[i][j] = 'O';  // Place an obstacle
            }
        }
    }
}

void Grid::setAgent(int x, int y) {
    grid[x][y] = 'A';  // Set agent position
}

void Grid::setGoal(int x, int y) {
    grid[x][y] = 'G';  // Set goal position
}

bool Grid::isObstacle(int x, int y) const {
    return grid[x][y] == 'O';
}

void Grid::display() const {
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << std::endl;
    }
}
