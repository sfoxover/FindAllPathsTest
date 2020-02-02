#include <string>
#include <cstdint>
#include <map>
#include <vector>
#include <iostream> 
#include <sstream>
#include <assert.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution();

    // Possible paths values
    std::vector<std::vector<int>> _values;

    // Map of traversed path and result
    std::map<string, bool> _traversePathResults;

    // Test if all points are valid and store result on map
    bool TryTraversePath(std::vector<std::pair<int, int>> points)
    {
        string pointsKey;
        bool traverse = true;
        for(auto point : points)
        {
            int row = point.first;
            int col = point.second;
            if(!pointsKey.empty())
                pointsKey += " ";
            std::stringstream buffer;
            buffer << col << "," << row;
            pointsKey += buffer.str();
           
            assert(col < _values.size() && row < _values[0].size());
            if(col < _values.size() && row < _values[0].size())
            {
                // Test if point has a valid value
                if(_values[col][row] == 1)
                {
                    continue;
                }
            }
            traverse = false;
        }
        // Store result in map
        assert(_traversePathResults.find(pointsKey) == _traversePathResults.end());
        _traversePathResults[pointsKey] = traverse;

        return traverse;
    }

    // Recursive call to find path points from top left to bottom right
    void GetPathPoints(int maxRow, int maxCol, std::vector<std::pair<int, int>> pairs, std::pair<int, int> currentPt)
    {
        // Add current point
        pairs.push_back(currentPt);

        // Botton of matrix
        if(currentPt.second == maxCol)
        {
            // Move to right
            for(int x=currentPt.first; x<maxRow; x++)
            {
                pairs.push_back({++currentPt.first, currentPt.second});
            }
            TryTraversePath(pairs);
        }
        // Right side of matrix
        else if(currentPt.first == maxRow)
        {
            // Move to bottom
            for(int y=currentPt.second; y<maxCol; y++)
            {
                pairs.push_back({currentPt.first, ++currentPt.second});
            }
            TryTraversePath(pairs);
        }
        else
        {
            // Move 1 right
            GetPathPoints(maxRow, maxCol, pairs, std::pair(currentPt.first + 1, currentPt.second));

            // Move 1 down
            GetPathPoints(maxRow, maxCol, pairs, std::pair(currentPt.first, currentPt.second + 1));
        }        
    }

    // Return number of valid paths found
    int getNumPaths(std::vector<std::vector<int>> values)
    {
        if(values.empty() || values.size() < 2 || values[0].size() < 2)
            return 0;

        // Store valid point paths
        _values = values;

        int rowSize = (int)values[0].size();
        int colSize = (int)values.size();
        std::pair<int, int> currentPt({0,0});
        std::vector<std::pair<int, int>> points;

        // Call recursively for all paths and store path results in map
        GetPathPoints(rowSize-1, colSize-1, points, currentPt);

        // Find all successful paths
        int result = 0;
        for(auto path : _traversePathResults)
        {
            if(path.second)   
                result ++;
        }
        return result;
    }
};