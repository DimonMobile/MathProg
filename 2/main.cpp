#include <iostream>

#include "Generator/permutation.h"

int main()
{
    Generator::Permutation generator(9);
    for (int i = 0 ; i < generator.count(); ++i)
    {
        std::vector<int> res = generator.next();
        for(size_t j = 0 ; j < res.size(); ++j)
            std::cout << res[j] << ' ';
        std::cout << std::endl;
    }

    return 0;
}
