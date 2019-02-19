#ifndef ACCOMODATION_H
#define ACCOMODATION_H

#include "combination.h"
#include "permutation.h"

namespace Generator
{

class Accomodation
{
public:
    Accomodation(uint n, uint m);
    ~Accomodation();

private:
    Generator::Combination *m_combinationGenerator;
    Generator::Permutation *m_permutationGenerator;
};

} // namespace Generator

#endif // ACCOMODATION_H
