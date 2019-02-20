#include "accomodation.h"

#include "combination.h"
#include "permutation.h"

namespace Generator
{

Accomodation::Accomodation(uint n, uint m)
{
    m_n = n; m_m = m;
    m_combinationGenerator = new Generator::Combination(n, m);
    m_permutationGenerator = new Generator::Permutation(static_cast<int>(m));
    reset();
}

Accomodation::~Accomodation()
{
    delete m_combinationGenerator;
    delete m_permutationGenerator;
}

void Accomodation::reset()
{
    m_countCached = false;
    m_currentPermutation = m_permutationGenerator->count();
}

std::vector<uint> Accomodation::next()
{
    if (m_permutationGenerator->count() == m_currentPermutation)
    {
        m_currentCombination = m_combinationGenerator->next();
        m_currentPermutation = 0;
        m_permutationGenerator->reset(static_cast<int>(m_m));
    }

    std::vector<int> genPerm = m_permutationGenerator->next();
    std::vector<uint> result(genPerm.size());
    for(size_t i = 0 ; i < genPerm.size(); ++i)
    {
        result[i] = m_currentCombination[genPerm[i]];
    }
    ++m_currentPermutation;
    return result;
}

uint Accomodation::count()
{
    if (!m_countCached)
    {
        m_count = factorial(m_n) / factorial(m_n-m_m);
        m_countCached = true;
    }
    return m_count;
}

uint Accomodation::factorial(uint from)
{
    uint result = 1;
    for(uint i = 2 ; i <= from; ++i)
        result *= i;
    return result;
}


} // namespace Generator
