#include <iostream>
#include <iomanip>

#include "auxil.h"

#define CYCLE 1000000

int main()
{
    double av1 = 0, av2 = 0;
    clock_t t1 = 0, t2 = 0;
    auxil::start();
    t1 = clock();
    for(int i = 0 ; i < CYCLE; ++i)
    {
        av1 += auxil::iget(-100, 100);
        av2 += auxil::dget(-100, 100);
    }
    t2 = clock();

    std::cout << "Cycles: " << std::setw(10) << CYCLE << std::endl;
    std::cout << "Average int: " << av1/CYCLE << std::endl;
    std::cout << "Average double: " << av2/CYCLE << std::endl;
    std::cout << "Duration: " << (t2-t1)
              << " -> " << (t2-t1)/static_cast<double>(CLOCKS_PER_SEC) << " sec." << std::endl;
    return 0;
}
