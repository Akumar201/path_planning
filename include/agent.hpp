#ifndef AGENT_HPP
#define AGENT_HPP

class Agent {
public:
    Agent(int startX, int startY);
    int getX() const;
    int getY() const;

private:
    int x, y;
};

#endif
