#include <iostream>

#include "Generator/Task/knapsack_s.h"
#include "Generator/Task/boat.h"

int main()
{
    int V = 1000;
    short n = 6, m = 3;
    int v[] = {100, 200, 300, 400, 500, 150};
    int c[] = {10, 15, 20, 25, 30, 25};
    short r[6];
    std::cout << "Sum: " << Generator::Task::boat(V,m,n, v,c, r) << std::endl;
    return 0;
}
