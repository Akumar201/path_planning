#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <random>
#include <iostream>

class Grid {
public:
    Grid(int width, int height, double obstacle_percentage);
    void display() const;
    bool isObstacle(int x, int y) const;
    void setAgent(int x, int y);
    void setGoal(int x, int y);

    // Getter methods for width and height
    int getWidth() const { return width; }
    int getHeight() const { return height; }

private:
    int width;
    int height;
    double obstacle_percentage;
    std::vector<std::vector<char>> grid;  // 'O' for obstacle, 'A' for agent, 'G' for goal, '.' for empty space
    
    void generateObstacles();
};

#endif
