/*****************************************************************************
 * graph.cpp
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
#include "graph.h"

#include <queue>
#include <set>
#include <algorithm>

namespace Graph
{

std::vector<int> bfs(const Utils::Matrix &matrix)
{
    std::vector<int> result;
    std::queue<int> queue;
    queue.push(0);
    while(!queue.empty())
    {
        int currentVertex = queue.front();
        queue.pop();
        result.push_back(currentVertex);
        for(size_t i = 0; i < matrix.size(); ++i)
        {
            if (matrix[currentVertex][i] == 1)
            {
                if (std::find(result.begin(), result.end(), i) == result.end())
                    queue.push(i);
            }
        }
    }
    return result;
}

std::vector<int> dfs(const Utils::Matrix &matrix)
{

}

} // namespace Graph
