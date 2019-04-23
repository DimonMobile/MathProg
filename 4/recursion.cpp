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

namespace Recursion
{
    int livenshtein(const char *s1, int len1, const char *s2, int len2)
    {
        if (len1 == 1 && len2 == 1 && s1[0] == s2[0])
            return 0;
        else if (len1 == 0)
            return len2;
        else if (len2 == 0)
            return len1;

        return Utils::min(
                        livenshtein(s1, len1-1, s2, len2)
                    ,   livenshtein(s1, len1, s2, len2-1)
                    ,   livenshtein(s1, len1-1, s2, len2 - 1)) + ((s1[len1-1] == s2[len2-1]) ? 0 : 1);
    }

} // Recursion
