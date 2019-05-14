/*****************************************************************************
 * %{Cpp:License:FileName}
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
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>

#include "recursion.h"
#include "dynamic.h"
#include "utils.h"

namespace Constants
{
    const size_t stringSequenceLength = 250;
    const double stringLengthDivisors[] = {1 / 25., 1 / 20., 1 / 15., 1 / 10., 1 / 5., 1 / 2., 1.};
} // namespace Constants

void livenshteinMeat()
{
    int testCount = static_cast<int>(sizeof(Constants::stringLengthDivisors) / sizeof(double));
    std::cout << "\tTesting, pending tests:\t" << testCount << std::endl;

    auto tuple = Utils::createString(Constants::stringSequenceLength);

    std::unique_ptr<char> ptr1(std::get<0>(tuple).release());
    std::unique_ptr<char> ptr2(std::get<1>(tuple).release());

    int testsPassed = 0;

    for(int i = 0 ; i < testCount; ++i)
    {
        clock_t startR = clock();

        int firstLength = static_cast<int>(Constants::stringSequenceLength * Constants::stringLengthDivisors[i]);
        int secondLength = static_cast<int>(round(Constants::stringSequenceLength * (5 / 6.0) * Constants::stringLengthDivisors[i]));

        std::cout << std::setw(3) << i + 1 << " passing[" << std::setw(3) << firstLength << ',' << std::setw(3) << secondLength << ']';

        int resultR = Recursion::livenshtein(   ptr1.get(), firstLength
                                            ,   ptr2.get(), secondLength);
        long elapsedR = clock() - startR;

        clock_t startD = clock();
        int resultD = Dynamic::livenshtein(     ptr1.get(), firstLength
                                            ,   ptr2.get(), secondLength);
        long elapsedD = clock() - startD;

        bool passed = false;
        if (resultR == resultD)
        {
            std::cout << " OK   - ";
            ++testsPassed;
            passed = true;
        }
        else
        {
            std::cout << "FAIL  - ";
        }

        std::cout << "clocs[r/d]:" << std::setw(8) << elapsedR << '/' << std::setw(8) << elapsedD << ", result:" << std::setw(10) << resultR;
        if (!passed)
            std::cout << std::setw(10) << resultD;
        std::cout << std::endl;
    }
    std::cout << "\tCompleted\t" << testsPassed << '/' << testCount << " tests passed" << std::endl;
}

int main()
{
    livenshteinMeat();
    return 0;
}
