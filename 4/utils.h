/*****************************************************************************
 * utils.h
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
#ifndef UTILS_H
#define UTILS_H

#include <memory>

namespace Utils
{
    template<typename T>
    T min(const T &p1, const T &p2, const T &p3)
    {
        T firstMin = (p1 < p2) ? p1 : p2;
        return (firstMin < p3) ? firstMin : p3;
    }

    template<typename T = char>
    std::unique_ptr<T> createString(const size_t len)
    {
        if (len <= 0)
            return std::unique_ptr<T>();
        std::unique_ptr<T> result(new T[len]);
        for(size_t i = 0 ; i < len; ++i)
            result.get()[i] = (rand() % 2 == 0) ? ('a' + rand() % ('z' - 'a') ) : ('A' + rand() % ('Z' - 'A'));
        return result;
    }
} // namespace Utils

#endif // UTILS_H
