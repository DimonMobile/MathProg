#ifndef ACCOMODATION_H
#define ACCOMODATION_H

#include <vector>

typedef unsigned int uint;

namespace Generator
{

class Permutation;
class Combination;

class Accomodation
{
public:
    Accomodation(uint n, uint m);
    ~Accomodation();

    void reset();
    std::vector<uint> next();
    uint count();

private:
    uint factorial(uint from);

private:
    Generator::Combination *m_combinationGenerator;
    Generator::Permutation *m_permutationGenerator;
    std::vector<uint> m_currentCombination;
    int m_currentPermutation;
    uint m_m, m_n;
    //cache
    uint m_count;
    bool m_countCached;
};

} // namespace Generator

#endif // ACCOMODATION_H
