#include <cstdint>
#include <iostream>
#include "solution.h"

int main()
{
    std::vector<std::vector<int>> values = {{1,1,1,1}, {1,1,1,1}, {1,1,1,1}};
    Solution solution;
    auto result = solution.getNumPaths(values);
    std::cout << "A 4 x 3 matrix with all values of 1 has " << result << " paths from top left to bottom right." << std::endl << std::endl;

    for(auto path : solution._traversePathResults)
    {
        std::cout << path.first << " : result " << (path.second ? "true" : "false") << std::endl;
    }

    std::cin.get();
}
