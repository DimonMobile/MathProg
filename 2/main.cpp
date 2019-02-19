#include <iostream>

#include "Generator/Task/salesman.h"

#define N 5

int main()
{
    const uint d[N][N] = {
        { 0, 45, Generator::Constants::infinity, 25, 50},
        {45, 0, 55, 20, 100},
        {70, 20, 0, 10, 30},
        {80, 10, 40, 0, 10},
        {30, 50, 20, 10, 0}
    };
    uint r[N];

    std::cout << Generator::Task::salesman(N, reinterpret_cast<const uint*>(d), r) << std::endl;

    return 0;
}
