#include "auxil.h"

#include <cstdlib>
#include <ctime>

namespace auxil
{
    void start()
    {
        srand(static_cast<uint>(time(nullptr)));
    }

    double dget(double rmin, double rmax)
    {
        return static_cast<double>(rand()) / RAND_MAX * (rmax-rmin) + rmin;
    }

    int iget(int rmin, int rmax)
    {
        return static_cast<int>(dget(rmin, rmax));
    }
} // namespace auxil
