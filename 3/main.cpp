/*
 * File created 14.04.2019
 * implementation of algorithm described here: http://galyautdinov.ru/post/zadacha-kommivoyazhera
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
    // reserved for future implementation
} // namespace Global


void printMatrix(const std::vector<std::vector<T>> &param)
{
    std::cout << "\n\t***Matrix***" << std::endl;
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

std::vector<T> getMinRowVector(std::vector<std::vector<T>> &source)
{
    std::vector<T> result;
    result.reserve(source.size());
    for(size_t i = 0 ; i < source.size(); ++i)
    {
        size_t minIdx = 0;
        for(size_t j = 0 ; j < source[i].size(); ++j)
            if (source[i][j] < source[i][minIdx])
                minIdx = j;
        result.push_back(source[i][minIdx]);
    }
    return result;
}

// !WARNING: supposed that vector has at least one row, in other case Undefined behaviour
std::vector<T> getMinColumnVector(std::vector<std::vector<T>> &source)
{
    std::vector<T> result;
    result.reserve(source[0].size());
    for(size_t i = 0 ; i < source[0].size(); ++i)
    {
        size_t minIdx = 0;
        for(size_t j = 0 ; j < source.size(); ++j)
            if (source[j][i] < source[minIdx][i])
                minIdx = j;
        result.push_back(source[minIdx][i]);
    }
    return result;
}

void printVector(const std::vector<T> &source, bool vertical = false)
{
    if (vertical)
    {
        std::cout << "\n\t***Vertical vector***" << std::endl;
        for(const auto &i : source)
            std::cout << std::setw(7) << i << std::endl;
    }
    else
    {
        std::cout << "\n\t***Horizontal vector***" << std::endl;
        for(const auto &i : source)
            std::cout << std::setw(7) << i;
    }
    std::cout << std::endl;
}

void reductRows(std::vector<std::vector<T>> &source, const std::vector<T> by)
{
    for(size_t i = 0 ; i < by.size(); ++i)
        for(size_t j = 0 ; j < source[i].size(); ++j)
            if (source[i][j] != Constants::infinity)
                source[i][j] -= by[i];
}

void reductColumns(std::vector<std::vector<T>> &source, const std::vector<T> by)
{
    for(size_t i = 0 ; i < by.size(); ++i)
        for(size_t j = 0 ; j < source.size(); ++j)
            if (source[j][i] != Constants::infinity)
                source[j][i] -= by[i];
}

int main()
{
    std::vector<std::vector<T>> sourceMatrix;
    prepareMatrix(sourceMatrix);

    printMatrix(sourceMatrix);
    std::vector<T> rowVector = getMinRowVector(sourceMatrix);
    printVector(rowVector, true);
    reductRows(sourceMatrix, rowVector);
    printMatrix(sourceMatrix);
    std::vector<T> columnVector = getMinColumnVector(sourceMatrix);
    printVector(columnVector);
    reductColumns(sourceMatrix, columnVector);
    printMatrix(sourceMatrix);
    return 0;
}
