#ifndef COMBINATION_H
#define COMBINATION_H

#include "subset.h"

namespace Generator{

class Combination : public Subset
{
public:
    Combination(uint n, uint m);

    virtual std::vector<uint> next() override;
    virtual bool hasNext() override;
    virtual uint count() override;
    virtual void reset() override;

private:
    uint factorial(uint from);

private:
    uint m_m;
    uint m_iterated;
};

} // namespace Generator
#endif // COMBINATION_H
