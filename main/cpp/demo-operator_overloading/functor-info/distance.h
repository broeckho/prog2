#pragma once
#ifndef DISTANCE_H
#define DISTANCE_H

class Distance
{
public:
        Distance(int x, int y) : fromX(x), fromY(y) {}
        int operator()(int x, int y) const;

private:
        int fromX, fromY;
};

#endif // DISTANCE_H
