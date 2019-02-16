#include "subset.h"

#include <cstring>

namespace Generator
{

Subset::Subset(uint n)
    : m_n(n)
    , m_current(0)
    , m_countCached(false)
    , m_assigned(nullptr)
{

}

Subset::~Subset()
{
    if (m_assigned)
        delete[] m_assigned;
}

std::vector<uint> Subset::next()
{
    std::vector<uint> result;

    if (!hasNext())
        return result;

    for(uint i = 0 ; i < m_n; ++i)
    {
        uint current = 1 << i;
        if((current & m_current) == current)
            result.push_back(i);
    }
    ++m_current;
    return result;
}

bool Subset::hasNext()
{
    if (m_current + 1 > count())
        return false;
    return true;
}

uint Subset::count()
{
    if (!m_countCached)
    {
        m_count = 1;
        for(uint i = 0 ; i < m_n; ++i)
            m_count *= 2;
        // count cache
        m_countCached = true;
    }
    return m_count;
}

void Subset::reset()
{
    m_current = 0;
}

bool Subset::assign(const char *ptr)
{
    size_t sourceLen = strlen(ptr);
    if (sourceLen < m_n)
        return false;
    if (m_assigned)
        delete[] m_assigned;
    m_assigned = new char[sizeof(char)*sourceLen + sizeof(char)];
    m_assignedLength = sourceLen;
    strcpy(m_assigned, ptr);
    return true;
}

bool Subset::isAssigned() const
{
    return m_assigned;
}

char Subset::assignedAt(uint idx)
{
    if (isAssigned() && idx < m_assignedLength)
    {
        return m_assigned[idx];
    }
    return '\0';
}

} // namespace Genrator

std::ostream &operator <<(std::ostream &stream, std::vector<uint> p)
{
    for(uint item : p)
        stream << item << ' ';
    return stream;
}
