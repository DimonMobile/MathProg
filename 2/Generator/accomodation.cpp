#include "accomodation.h"

namespace Generator
{

Accomodation::Accomodation(uint n, uint m)
{
    m_combinationGenerator = new Generator::Combination(n, m);
    m_permutationGenerator = new Generator::Permutation(static_cast<int>(n));
}

Accomodation::~Accomodation()
{
    delete m_combinationGenerator;
    delete m_permutationGenerator;
}


} // namespace Generator
