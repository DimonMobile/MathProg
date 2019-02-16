#include "permutation.h"

namespace Generator
{

Permutation::Permutation(int n)
{
    reset(n);
}

void Permutation::reset(int n)
{
    m_countCached = false;
    m_n = n;
    m_permutation.clear();
    m_directions.clear();
    m_permutation.reserve(static_cast<size_t>(n));
    m_directions.reserve(static_cast<size_t>(n));
    for(int i = 0 ; i < n; ++i)
    {
        m_permutation.push_back(i);
        m_directions.push_back(Direction::Left);
    }
}

int Permutation::count()
{
    if (!m_countCached)
    {
        m_count = factorial(m_n);
        m_countCached = true;
    }
    return m_count;
}

std::vector<int> Permutation::next()
{
    int resultIdx;
    if (findMobile(&resultIdx))
    {
        int pointToIdx = pointsTo(resultIdx);
        std::swap(m_permutation[static_cast<size_t>(resultIdx)], m_permutation[static_cast<size_t>(pointToIdx)]);
        std::swap(m_directions[static_cast<size_t>(resultIdx)], m_directions[static_cast<size_t>(pointToIdx)]);
        if (findMobile(&resultIdx))
        {
            invertAllMoreThen(resultIdx);
        }
    }
    return m_permutation;
}

int Permutation::factorial(int from)
{
    int result = 1;
    for(int i = 2 ; i <= from; ++i)
        result *= i;
    return result;
}

bool Permutation::findMobile(int *out)
{
    size_t maxIdx = 0;
    bool someWhatFind = false;
    for(size_t i = 0 ; i < static_cast<size_t>(m_n); ++i)
    {
        if (m_permutation[i] > m_permutation[maxIdx])
        {
            if (m_directions[i] == Direction::Left )
            {
                if (static_cast<int>(i) - 1 >= 0 && m_permutation[i-1] < m_permutation[i])
                {
                    maxIdx = i;
                    someWhatFind = true;
                }
            }
            else // m_directions[i] == Direction::Right
            {
                if (i + 1 < static_cast<size_t>(m_n) && m_permutation[i+1] < m_permutation[i] )
                {
                    maxIdx = i;
                    someWhatFind = true;
                }
            }
        }
    }
    if (someWhatFind)
    {
        *out = static_cast<int>(maxIdx);
        return true;
    }
    return false;
}

int Permutation::pointsTo(int from)
{
    if (m_directions[static_cast<size_t>(from)] == Direction::Left)
        return from - 1;
    else
        return from + 1;
}

void Permutation::invertAllMoreThen(int base)
{
    for(size_t i = 0 ; i < static_cast<size_t>(m_n); ++i)
        if (static_cast<size_t>(base) != i && m_permutation[i] > m_permutation[static_cast<size_t>(base)])
            m_directions[i] = (m_directions[i] == Direction::Left) ? Direction::Right : Direction::Left;
}

} // namespace Generator
