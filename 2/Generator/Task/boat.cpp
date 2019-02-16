#include "Generator/combination.h"

namespace Generator
{
namespace Task
{

int boat(int V, short m, short n, const int *v, const int *c, short *r)
{
    Generator::Combination generator(static_cast<uint>(n), static_cast<uint>(m));
    uint maxPrice = 0;
    std::vector<uint> topResult;
    while(generator.hasNext())
    {
        uint currentPrice = 0, currentWeight = 0;
        std::vector<uint> current = generator.next();
        for(uint item : current)
        {
            currentPrice += static_cast<uint>(c[item]);
            currentWeight += static_cast<uint>(v[item]);
        }
        if (currentWeight <= static_cast<uint>(V) && currentPrice > maxPrice)
        {
            maxPrice = currentPrice;
            topResult = current;
        }
    }

    for(int i = 0 ; i < n; ++i)
        r[i] = 0;
    for(uint item : topResult)
        r[item] = 1;

    return static_cast<int>(maxPrice);
}

} // namespace Task
} // namespace Generator
