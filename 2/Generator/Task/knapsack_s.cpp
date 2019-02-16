#include "Generator/subset.h"

namespace Generator
{
namespace Task
{

int knapsack_s(int V, short n, const int *v, const int *c, short *m)
{
    Generator::Subset generator(static_cast<uint>(n));
    uint maxSum = 0;
    std::vector<uint> topResult;
    while(generator.hasNext())
    {
        std::vector<uint> current = generator.next();
        uint currentSum = 0, currentWeight = 0;
        for(uint item : current)
        {
            currentSum += static_cast<uint>(v[item] * c[item]);
            currentWeight += static_cast<uint>(v[item]);
        }
        if (maxSum < currentSum && currentWeight <= static_cast<uint>(V))
        {
            maxSum = currentSum;
            topResult = current;
        }
    }
    for(int i = 0 ; i < n; ++i)
        m[i] = 0;
    for(uint item : topResult)
        m[item] = 1;
    return static_cast<int>(maxSum);
}


} // namespace Task
} // namespace Generator
