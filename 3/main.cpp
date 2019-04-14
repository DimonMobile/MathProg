/*
 * File created 14.04.2019
 *
 * This project created by Plotnikov Dmitry | mobik.dimka@gmail.com
 * and placed at https://github.com/DimonMobile/MathProg
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>

typedef int T;

namespace Constants
{
    int const variantId = 9;
    T   const infinity  = std::numeric_limits<T>::max();
} // namespace Constants

namespace Global
{
} // namespace Global


void printMatrix(const std::vector<std::vector<T>> &param)
{
    std::cout << "\n\t***Source Matrix***" << std::endl;
    for(const auto &i : param)
    {
        for (const auto &j : i)
            std::cout << std::setw(7) << (j == Constants::infinity ? "INF" : std::to_string(j));
        std::cout << std::endl;
    }
}

void prepareMatrix(std::vector<std::vector<T>> &param)
{
    param.resize(5);
    for(std::vector<T> &innerVector : param)
        innerVector.resize(5);

    // first column
    param[0][0] = Constants::infinity;
    param[1][0] = Constants::variantId;
    param[2][0] = Constants::variantId + 2;
    param[3][0] = Constants::variantId + 17;
    param[4][0] = 93 - Constants::variantId;

    // second column
    param[0][1] = 2 * Constants::variantId;
    param[1][1] = Constants::infinity;
    param[2][1] = 3 * Constants::variantId;
    param[3][1] = 58 - Constants::variantId;
    param[4][1] = 66 + Constants::variantId;

    // third column
    param[0][2] = 21 + Constants::variantId;
    param[1][2] = 15 + Constants::variantId;
    param[2][2] = Constants::infinity;
    param[3][2] = 4 * Constants::variantId;
    param[4][2] = 52;

    // fourth column
    param[0][3] = Constants::infinity;
    param[1][3] = 68 - Constants::variantId;
    param[2][3] = 86;
    param[3][3] = Constants::infinity;
    param[4][3] = 13 + Constants::variantId;

    // fifth columnt
    param[0][4] = Constants::variantId;
    param[1][4] = 84 - Constants::variantId;
    param[2][4] = 49 + Constants::variantId;
    param[3][4] = 3 * Constants::variantId;
    param[4][4] = Constants::infinity;
}

int main()
{
    std::vector<std::vector<T>> sourceMatrix;
    prepareMatrix(sourceMatrix);
    printMatrix(sourceMatrix);
    return 0;
}
