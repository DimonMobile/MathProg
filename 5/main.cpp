/*****************************************************************************
 * %{Cpp:License:FileName}
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
#include <iostream>
#include <sstream>

#include "utils.h"
#include "graph.h"

std::ostream & operator << (std::ostream &stream, const std::vector<int> &vec)
{
    for(size_t i = 0 ; i < vec.size(); ++i)
        stream << vec[i] << ((i == vec.size() - 1) ? '\n' : ',');
    return stream;
}


int main()
{
    using namespace Utils;
    Matrix sourceMatrix = generateMatrix();
    std::cout << "BFS: " << Graph::bfs(sourceMatrix) << std::endl;
    std::cout << "DFS: " << Graph::dfs(sourceMatrix) << std::endl;
    return 0;
}
