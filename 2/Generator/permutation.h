#pragma once

#include <vector>

namespace Generator
{


class Permutation
{
public:
    Permutation(int n);

    void reset(int n);
    int count();

    std::vector<int> next();

private:
    enum class Direction : bool
    {
        Left,
        Right
    };

    int factorial(int from);
    bool findMobile(int *out);
    int pointsTo(int from);
    void invertAllMoreThen(int base);

private:
    int m_n;
    std::vector<int> m_permutation;
    std::vector<Direction> m_directions;
    // cache
    int m_count;
    bool m_countCached;
};


} // namespace Generator
