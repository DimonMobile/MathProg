/*****************************************************************************
 * dynamic.cpp
 *
 * Created: 24.04.2019 2019 by d.plotnikov
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
#include "dynamic.h"
#include <cmath>
#include <memory>
#include <cstring>

#include "utils.h"

namespace Dynamic
{

int livenshtein(const char *s1, int len1, const char *s2, int len2)
{
    if (len1 == 0 || len2 == 0)
        return static_cast<int>(abs(len1-len2));

    int **d = new int*[len1+1];
    for(int i = 0 ; i < len1+1; ++i)
    {
        d[i] = new int[len2+1];
    }

    for(int i = 0 ; i <= len1; ++i) d[i][0] = i;
    for(int i = 0 ; i <= len2; ++i) d[0][i] = i;

    for(int i = 1; i < len1 + 1; ++i)
        for(int j = 1; j < len2 + 1; ++j)
            d[i][j] = Utils::min(d[i-1][j] + 1, d[i][j-1] + 1, d[i-1][j-1] + (s1[i-1] == s2[j-1] ? 0 : 1));
    int result = d[len1][len2];
    for(int i = 0 ; i < len1; ++i)
        delete[] d[i];
    delete[] d;
    return result;
}

int lcs_length(const char *s1, const char *s2)
{
    int len1 = static_cast<int>(strlen(s1));
    int len2 = static_cast<int>(strlen(s2));

    int **d = new int*[len1];
    for(int i = 0 ; i < len1; ++i)
    {
        d[i] = new int[len2];
        memset(d[i], 0, sizeof(int) * len2);
    }
    for(int i = 0 ; i < len1; ++i)
    {
        for(int j = 0 ; j < len2; ++j)
        {
            int top = (i - 1 < 0) ? 0 : d[i-1][j];
            int left = (j - 1 < 0) ? 0 : d[i][j-1];
            int max = std::max(left, top);
            d[i][j] = (s1[i] == s2[j]) ? max + 1 : max;
        }
    }
    return d[len1-1][len2-1];
}

} // namespace Dynamic
