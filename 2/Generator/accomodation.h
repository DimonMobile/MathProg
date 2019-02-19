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
    std::vector<int> next();

private:
    Generator::Combination *m_combinationGenerator;
    Generator::Permutation *m_permutationGenerator;
    uint m_currentPermutation;
};

} // namespace Generator

#endif // ACCOMODATION_H
