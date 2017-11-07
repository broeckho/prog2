#pragma once

class Distance
{
public:
        Distance(int x, int y) : fromX(x), fromY(y) {}
        int operator()(int x, int y) const;

private:
        int fromX, fromY;
};

