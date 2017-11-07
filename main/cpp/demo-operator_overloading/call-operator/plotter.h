#pragma once
#ifndef PLOTTER_H
#define PLOTTER_H

#include <functional>

template <typename T>

class Plotter
{
public:
        Plotter() =default;
        virtual ~Plotter() =default;
        // Old way
        std::string plot(const std::function<T(T)>& f, T from = 0.0, T to = 1.0, unsigned int n = 10) const;
        // New way
        std::string operator()(const std::function<T(T)>& f, T from = 0.0, T to = 1.0, unsigned int n = 10) const;
};

#endif // PLOTTER_H
