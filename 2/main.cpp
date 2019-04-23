#include <iostream>
#include <iomanip>
#include <ctime>

#include "Generator/Task/salesman.h"

#define N 5

int main()
{
    uint d[N][N];

    d[0][0] = Generator::Constants::infinity;
    d[1][0] = 9;
    d[2][0] = 11;
    d[3][0] = 26;
    d[4][0] = 84;

    d[0][1] = 18;
    d[1][1] = Generator::Constants::infinity;;
    d[2][1] = 27;
    d[3][1] = 49;
    d[4][1] = 75;

    d[0][2] = 30;
    d[1][2] = 24;
    d[2][2] = Generator::Constants::infinity;
    d[3][2] = 36;
    d[4][2] = 52;

    d[0][3] = Generator::Constants::infinity;
    d[1][3] = 59;
    d[2][3] = 86;
    d[3][3] = Generator::Constants::infinity;
    d[4][3] = 22;

    d[0][4] = 9;
    d[1][4] = 75;
    d[2][4] = 58;
    d[3][4] = 27;
    d[4][4] = Generator::Constants::infinity;


    uint r[N];
    std::cout << Generator::Task::salesman(5, reinterpret_cast<const uint*>(d), r) << std::endl;

    return 0;
}
