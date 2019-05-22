/*****************************************************************************
 * utils.cpp
 *
 * Created: 20.05.2019 2019 by d.plotnikov
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
#include "utils.h"

namespace Utils
{

Matrix generateMatrix()
{
    typedef std::vector<int> IntVector;
    Matrix result;
    result.resize(5);
    for(IntVector &vector : result)
        vector.resize(5);

    result[0][1] = 1;
    result[1][3] = 1;
    result[1][2] = 1;
    result[3][0] = 1;
    result[3][4] = 1;
    result[4][0] = 1;
    result[4][4] = 1;

    return result;
}

IncidenceList matrixToIncidenceList(const Matrix &matrix)
{
    IncidenceList result;
    for(size_t i = 0 ; i < matrix.size(); ++i)
    {
        List currentList;
        currentList.push_back(static_cast<int>(i));
        for(size_t j = 0 ; j < matrix[i].size(); ++j)
        {
            if (matrix[i][j] != 0)
                currentList.push_back(j);
        }
        result.push_back(currentList);
    }
    return result;
}

Matrix incidenceListToMatrix(const IncidenceList &incidenceList)
{
    Matrix result;
    result.resize(incidenceList.size());
    for(auto &vec : result)
        vec.resize(result.size());
    for(auto it = incidenceList.begin(); it != incidenceList.end(); ++it)
    {
        int currentVertex = 0;
        for(auto jt = it->begin(); jt != it->end(); ++jt)
        {
            if (jt == it->begin())
            {
                currentVertex = *jt;
            }
            else
            {
                result[currentVertex][*jt] = 1;
            }
        }
    }
    return result;
}

} // namespace Utils
