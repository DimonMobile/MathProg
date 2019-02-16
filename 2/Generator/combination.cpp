#include "combination.h"

namespace Generator{


Combination::Combination(uint n, uint m)
    : Subset (n)
    , m_m(m)
    , m_iterated(0)
{

}

std::vector<uint> Combination::next()
{
    std::vector<uint> result;

    if (!hasNext())
        return result;

    do
    {
        result.clear();
        for(uint i = 0 ; i < m_n; ++i)
        {
            uint current = 1 << i;
            if (current & m_current)
                result.push_back(i);
        }
        ++m_current;
    }while(result.size() != m_m);
    ++m_iterated;
    return result;
}

bool Combination::hasNext()
{
    if (m_iterated == count())
        return false;
    return true;
}

uint Combination::count()
{
    if (!m_countCached)
    {
        m_count = factorial(m_n) / (factorial(m_m) * factorial(m_n-m_m));
        m_countCached = true;
    }
    return m_count;
}

void Combination::reset()
{
    Subset::reset();
    m_iterated = 0;
}

uint Combination::factorial(uint from)
{
    uint result = 1;
    for(uint i = 2 ; i <= from; ++i)
        result *= i;
    return result;
}

} // namespace Generator
