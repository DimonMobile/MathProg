#ifndef SUBSET_H
#define SUBSET_H

#include <vector>
#include <ostream>

typedef unsigned int uint;

namespace Generator
{

class Subset
{
public:
    Subset(const Subset &another) = delete;
    Subset &operator = (const Subset &another) = delete;

    Subset(uint n);
    virtual ~Subset();

    //! Returns vector of subset indexes and iterates to next subset
    virtual std::vector<uint> next();
    //! Returns false if next iteration is impossible
    virtual bool hasNext();
    //! Returns possible count of combinations
    virtual uint count();
    //! Reset generator
    virtual void reset();
    //! Associate generator indexes to char array. It's affects output and return false in case of error.
    bool assign(const char *ptr);
    //! Checks for existance of assotiated string
    bool isAssigned() const;
    char assignedAt(uint idx);

protected:
    uint m_n;
    uint m_current;
    // count cache
    bool m_countCached;
    uint m_count;

    char* m_assigned;
    size_t m_assignedLength;
};


} // namespace Generator

std::ostream &operator << (std::ostream &stream, std::vector<uint> p);

#endif // SUBSET_H
