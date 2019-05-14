/*****************************************************************************
 * recursion.cpp
 *
 * Created: 23.04.2019 2019 by d.plotnikov
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

#include "recursion.h"
#include "utils.h"

#include <cmath>
#include <iostream>
#include <iomanip>

namespace Recursion
{
    int livenshtein(const char *s1, int len1, const char *s2, int len2, int deep)
    {
        if (len1 == 1 && len2 == 1 && s1[0] == s2[0])
        {
            if (deep != -1)
                std::cout << std::setw(deep*8) << "" << std::string(s1, len1) << ", " << std::string(s2, len2) << " -> " << 0 << std::endl;
            return 0;
        }
        else if (len1 == 0)
        {
            if (deep != -1)
                std::cout << std::setw(deep*8) << "" << std::string(s1, len1) << ", " << std::string(s2, len2) << " -> " << len2 << std::endl;
            return len2;
        }
        else if (len2 == 0)
        {
            if (deep != -1)
                std::cout << std::setw(deep*8) << "" << std::string(s1, len1) << ", " << std::string(s2, len2) << " -> " << len1 << std::endl;
            return len1;
        }

        int minDistance = Utils::min(
                        livenshtein(s1, len1-1, s2, len2, (deep != -1) ? deep + 1 : -1)
                    ,   livenshtein(s1, len1, s2, len2-1, (deep != -1) ? deep + 1 : -1)
                    ,   livenshtein(s1, len1-1, s2, len2 - 1, (deep != -1) ? deep + 1 : -1)) + ((s1[len1-1] == s2[len2-1]) ? 0 : 1);

        if (deep != -1)
            std::cout << std::setw(deep*8) << "" << std::string(s1, len1) << ", " << std::string(s2, len2) << " -> " << minDistance << std::endl;
        return minDistance;
    }

    int lcs_length(const char *s1, const char *s2)
    {
        if (*s1 == '\0' || *s2 == '\0')
            return 0;
        else if (*s1 == *s2)
            return lcs_length(s1 + 1, s2 + 1) + 1;
        else
            return std::max(lcs_length(s1 + 1, s2), lcs_length(s1, s2 + 1));
    }

} // Recursion
