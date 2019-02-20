#include <iostream>
#include <iomanip>
#include <ctime>

#include "Generator/Task/salesman.h"

#define N 13

int main()
{
    uint d[N][N];
    std::cout << "*\tSource array: " << std::endl;
    for(int i = 0 ; i < N; ++i)
    {
        for(int j = 0 ; j < N; ++j)
        {
            if (rand() % 12*12 <= 2)
            {
                d[i][j] = Generator::Constants::infinity;
                std::cout << std::setw(5) << "INF";
            }
            else
            {
                d[i][j] = rand() % 290 + 10;
                std::cout << std::setw(5) << d[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << "*\tTask resolving: " << std::endl;

    for(int i = 5; i <= 12; ++i)
    {
        uint r[N];
        clock_t startTime = clock();

        std::cout << std::setw(3) << i << " " << Generator::Task::salesman(i, reinterpret_cast<const uint*>(d), r) << " ";
        std::cout << std::setw(8) << (clock() - startTime) / static_cast<double>(CLOCKS_PER_SEC) << std::endl;
    }
    return 0;
}
