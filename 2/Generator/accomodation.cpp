#include "accomodation.h"

#include "combination.h"
#include "permutation.h"

namespace Generator
{

Accomodation::Accomodation(uint n, uint m)
{
    m_combinationGenerator = new Generator::Combination(n, m);
    m_permutationGenerator = new Generator::Permutation(static_cast<int>(m));
}

Accomodation::~Accomodation()
{
    delete m_combinationGenerator;
    delete m_permutationGenerator;
}

void Accomodation::reset()
{
    m_currentPermutation = m_permutationGenerator->count();
}

std::vector<int> Accomodation::next()
{
//    if (m_currentPermutation == m_permutationGenerator->count())
//    {
//        m_currentPermutation = 0;
//        m_combinationGenerator->next();
//    }
}


} // namespace Generator
