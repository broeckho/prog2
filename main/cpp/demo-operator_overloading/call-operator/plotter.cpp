#include "../../demo-operator_overloading/call-operator/plotter.h"

#include <cmath>
#include <limits>
#include <string>
#include <vector>

template <typename T>
Plotter<T>::Plotter()
{
}

template <typename T>
Plotter<T>::~Plotter()
{
}

template <typename T>
std::string Plotter<T>::plot(const std::function<T(T)>& f, T from, T to, T n) const
{
        std::vector<std::pair<T, T>> lines;
        T delta = (to - from) / (T)n;
        for (T i = from; i <= to; i += delta) {
                lines.push_back(std::make_pair(i, f(i)));
        }

        T mininf = -std::numeric_limits<double>::infinity();
        T maxinf = std::numeric_limits<double>::infinity();
        T maxx = mininf, maxy = mininf, minx = maxinf, miny = maxinf;
        for (auto& p : lines) {
                if (p.first < minx)
                        minx = p.first;
                if (p.first > maxx)
                        maxx = p.first;
                if (p.second < miny)
                        miny = p.second;
                if (p.second > maxy)
                        maxy = p.second;
        }
        T size = 1000;
        T maxrange = (maxx - minx) < (maxy - miny) ? (maxy - miny) : (maxx - minx);
        T imagex = size * (maxx - minx) / maxrange;
        T imagey = size * (maxy - miny) / maxrange;
        T scale = 0.95 * (imagex / (maxx - minx));
        T DCx = scale * ((minx + maxx) / 2);
        T DCy = scale * ((miny + maxy) / 2);
        T dx = (imagex / 2) - DCx;
        T dy = (imagey / 2) - DCy;

        std::string result;

        for (T i = 0; i < lines.size(); i++) {
                result += "(" + std::to_string(lines[i].first * scale + dx) + "," +
                          std::to_string(lines[i].second * scale + dy) + ")\n";
        }
        return result;
}

template <typename T>
std::string Plotter<T>::operator()(const std::function<T(T)>& f, T from, T to, T n) const
{
        return plot(f, from, to, n);
}

template class Plotter<double>;
