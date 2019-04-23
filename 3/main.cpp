/*****************************************************************************
 * main.cpp
 *
 * Created: 13.04.2019 2019 by d.plotnikov
 *
 * Copyright © 2019 Dmitry Plotnikov. All rights reserved.
 *
 * This file may be distributed under the terms of GNU Public License version
 * 3 (GPL v3) as defined by the Free Software Foundation (FSF). A copy of the
 * license should have been included with this file, or the project in which
 * this file belongs to. You may also find the details of GPL v3 at:
 * http://www.gnu.org/licenses/gpl-3.0.txt
 *
 * If you have any questions regarding the use of this file, feel free to
 * contact the author of this file, or the owner of the project in which
 * this file belongs to.
*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>

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
    param.resize(6);
    for(std::vector<T> &innerVector : param)
        innerVector.resize(6);

    for(size_t i = 0 ; i < param.size(); ++i)
    {
        param[i][0] = static_cast<T>(i);
        param[0][i] = static_cast<T>(i);
    }

    // first column
    param[1][1] = Constants::infinity;
    param[2][1] = Constants::variantId;
    param[3][1] = Constants::variantId + 2;
    param[4][1] = Constants::variantId + 17;
    param[5][1] = 93 - Constants::variantId;

    // second column
    param[1][2] = 2 * Constants::variantId;
    param[2][2] = Constants::infinity;
    param[3][2] = 3 * Constants::variantId;
    param[4][2] = 58 - Constants::variantId;
    param[5][2] = 66 + Constants::variantId;

    // third column
    param[1][3] = 21 + Constants::variantId;
    param[2][3] = 15 + Constants::variantId;
    param[3][3] = Constants::infinity;
    param[4][3] = 4 * Constants::variantId;
    param[5][3] = 52;

    // fourth column
    param[1][4] = Constants::infinity;
    param[2][4] = 68 - Constants::variantId;
    param[3][4] = 86;
    param[4][4] = Constants::infinity;
    param[5][4] = 13 + Constants::variantId;

    // fifth columnt
    param[1][5] = Constants::variantId;
    param[2][5] = 84 - Constants::variantId;
    param[3][5] = 49 + Constants::variantId;
    param[4][5] = 3 * Constants::variantId;
    param[5][5] = Constants::infinity;
}

std::vector<T> getMinRowVector(std::vector<std::vector<T>> &source)
{
    std::vector<T> result;
    result.reserve(source.size());
    result.push_back(0);
    for(size_t i = 1 ; i < source.size(); ++i)
    {
        size_t minIdx = 1;
        for(size_t j = 1 ; j < source[i].size(); ++j)
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
    result.push_back(0);
    for(size_t i = 1 ; i < source[0].size(); ++i)
    {
        size_t minIdx = 1;
        for(size_t j = 1 ; j < source.size(); ++j)
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
        for(size_t i = 0 ; i < source.size(); ++i)
            std::cout << std::setw(7) << source[i] << std::endl;
    }
    else
    {
        std::cout << "\n\t***Horizontal vector***" << std::endl;
        for(size_t i = 0 ; i < source.size(); ++i)
            std::cout << std::setw(7) << source[i];
    }
    std::cout << std::endl;
}

void reductRows(std::vector<std::vector<T>> &source, const std::vector<T> by)
{
    for(size_t i = 1 ; i < by.size(); ++i)
        for(size_t j = 1 ; j < source[i].size(); ++j)
            if (source[i][j] != Constants::infinity)
                source[i][j] -= by[i];
}

void reductColumns(std::vector<std::vector<T>> &source, const std::vector<T> by)
{
    for(size_t i = 1 ; i < by.size(); ++i)
        for(size_t j = 1 ; j < source[0].size(); ++j)
            if (source[j][i] != Constants::infinity)
                source[j][i] -= by[i];
}

void deleteMinZero(std::vector<std::vector<T>> &source)
{
    std::vector<std::vector<T>> d(source.size());
    for(size_t i = 0 ; i < d.size(); ++i)
        d[i].resize(sourc e.size());

    for(size_t i = 0 ; i < d.size(); ++i)
    {
        d[i][0] = static_cast<T>(i);
        d[0][i] = static_cast<T>(i);
    }

    for(size_t i = 1; i < d.size(); ++i)
        for(size_t j = 1; j < d.size(); ++j)
            d[i][j] = -1;

    for(size_t i = 1; i < source.size(); ++i)
        for(size_t j = 1; j < source.size(); ++j)
            if (source[i][j] == 0)
            {
                size_t minRowIdx = 1;
                size_t minColumnIdx = 1;
                for(size_t row = 1; row < source.size(); ++row)
                    if ( (source[row][j] < source[minRowIdx][j] && row != i) || minRowIdx == i)
                        minRowIdx = row;

                for(size_t column = 1; column < source.size(); ++column)
                    if ((source[i][column] < source[i][minColumnIdx] && column != j) || minColumnIdx == j)
                        minColumnIdx = column;

                d[i][j] = source[i][minColumnIdx] + source[minRowIdx][j];
            }

    std::pair<size_t, size_t> maxIdx = std::make_pair(1, 1);
    for(size_t i = 1 ; i < d.size(); ++i)
        for(size_t j = 1 ; j < d.size(); ++j)
            if ( (d[i][j] != -1 && d[i][j] > d[maxIdx.first][maxIdx.second]) || d[maxIdx.first][maxIdx.second] == -1 )
            {
                maxIdx.first = i;
                maxIdx.second = j;
            }

    printMatrix(d);
    std::cout << source[maxIdx.first][0] << " - > " << source[0][maxIdx.second] << std::endl;

    T row = source[maxIdx.first][0];
    T column = source[0][maxIdx.second];
    size_t foundRow = -1;
    size_t foundColmn = -1;
    for(size_t i = 1; i < source.size(); ++i)
        if (source[0][i] == row)
        {
            foundRow = i;
            break;
        }

    for(size_t i = 1; i < source.size(); ++i)
        if (source[0][i] == column)
        {
            foundColmn = i;
            break;
        }

    if (foundColmn != -1 && foundRow != -1)
        source[foundColmn][foundRow] = Constants::infinity;

    source.erase(source.begin() + maxIdx.first);
    for(std::vector<T> &inVector : source)
        inVector.erase(inVector.begin() + maxIdx.second);



}

int main()
{
    std::vector<std::vector<T>> sourceMatrix;
    prepareMatrix(sourceMatrix);

    for(int i = 0 ; i < 5; ++i)
    {
        printMatrix(sourceMatrix);
        std::vector<T> rowVector = getMinRowVector(sourceMatrix);
        printVector(rowVector, true);
        reductRows(sourceMatrix, rowVector);
        printMatrix(sourceMatrix);
        std::vector<T> columnVector = getMinColumnVector(sourceMatrix);
        printVector(columnVector);
        reductColumns(sourceMatrix, columnVector);
        printMatrix(sourceMatrix);
        deleteMinZero(sourceMatrix);
    }
    return 0;
}
