/*
Problem Statement:
Given a grid of dimension nxm containing 0s and 1s. Find the unit area of the largest region of 1s.
Region of 1's is a group of 1's connected 8-directionally (horizontally, vertically, diagonally).
*/

/*
Algorithm:
 1. Keep Visited Array to track of visited entries
 2. Do DFS, and try to reach as much 1s possible in all 8 directions
 */

/*
Problem/Solution Link:
    * https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/ 
*/

class Solution
{
    public:
    vector<vector<int>> neighbors = { {-1, -1}, {-1, 0}, {-1, +1},
                                      {0, -1}, {0, +1},
                                      {+1, -1}, {+1, 0}, {+1, +1} };
                                      
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int maxArea = 0;
        
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == 1 && visited[row][col] == false)
                {
                    maxArea = max(maxArea, calculateMaxArea(grid, visited, row, col));
                }
            }
        }
        return maxArea;
    }
    
    int calculateMaxArea(vector<vector<int>> &grid, vector<vector<bool>> &visited,
                         int row, int col)
    {
        if(row < 0 || col < 0 || 
           row >= grid.size() || col >= grid[0].size() || 
           grid[row][col] == 0 ||
           visited[row][col] == true)
        {
           return 0;
        }
        
        visited[row][col] = true;
        int area = 1;
        
        for(int neigh = 0; neigh < neighbors.size(); neigh++)
        {
            area += calculateMaxArea(grid, 
                                     visited, 
                                     row + neighbors[neigh][0],
                                     col + neighbors[neigh][1]);
        }
        return area;
    }
};