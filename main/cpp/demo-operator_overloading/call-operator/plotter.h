#pragma once
#ifndef PLOTTER_H
#define PLOTTER_H

#include <functional>

template <typename T>

class Plotter
{
public:
        Plotter();
        virtual ~Plotter();
        // Old way
        std::string plot(const std::function<T(T)>& f, T from = 0.0, T to = 1.0, T n = 10) const;
        // New way
        std::string operator()(const std::function<T(T)>& f, T from = 0.0, T to = 1.0, T n = 10) const;

private:
        double granularity = 0.01;
};

#endif // PLOTTER_H
