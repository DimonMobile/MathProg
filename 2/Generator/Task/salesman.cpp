#include "salesman.h"

#include "Generator/permutation.h"

#include <iostream>


namespace Generator
{
namespace Task
{

int salesman(int n, const uint *d, uint *r)
{
    Generator::Permutation generator(n-1);

    std::vector<int> minSequence;
    uint minSum = 0;
    bool isFirstSum = true;

    for(int i = 0 ; i < generator.count(); ++i)
    {
        std::vector<int> permutation = generator.next();
        for(size_t j = 0 ; j < permutation.size(); ++j)
            ++permutation[j];
        uint currentSum = d[0*n + permutation[0]];
        if (currentSum != Constants::infinity)
        {
            for(size_t j = 1 ; j < permutation.size(); ++j)
            {
                if (d[ permutation[j-1]*n + permutation[j] ] == Constants::infinity)
                {
                    currentSum = Constants::infinity;
                    break;
                }
                else
                    currentSum += d[ permutation[j-1]*n + permutation[j] ];
            }
            if (currentSum != Constants::infinity)
                currentSum += d[permutation[static_cast<size_t>(permutation.size()-1)]*n + 0];

            if (isFirstSum)
            {
                minSum = currentSum;
                minSequence = permutation;
                isFirstSum = false;
            }
            else if (currentSum < minSum)
            {
                minSum = currentSum;
                minSequence = permutation;
            }
        }
    }
    for(size_t i = 0 ; i < minSequence.size();++i)
        r[i] = static_cast<uint>(minSequence.at(i));
    return static_cast<int>(minSum);
}

} // namespace Salesman
} // namespace Generator
