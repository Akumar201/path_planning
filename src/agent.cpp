#include "agent.hpp"

Agent::Agent(int startX, int startY)
    : x(startX), y(startY) {}

int Agent::getX() const {
    return x;
}

int Agent::getY() const {
    return y;
}
