/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

*/


class Solution {
public:
    void numIslandsUtil(vector<vector<char>>& grid, int r, int c){
        
        grid[r][c] = '0';
        if(r-1 >= 0 && grid[r-1][c] == '1') numIslandsUtil(grid,r-1,c);
        
        if(r+1 < grid.size() && grid[r+1][c] == '1') numIslandsUtil(grid,r+1,c);
        
        if(c-1 >= 0 && grid[r][c-1] == '1') numIslandsUtil(grid,r,c-1);
        
        if(c+1 < grid[0].size() && grid[r][c+1] == '1') numIslandsUtil(grid,r,c+1);
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if(grid.size() <= 0) return result;
        
        int rows = grid.size();
        int cols = grid[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(grid[r][c] == '1'){
                    result ++;
                    numIslandsUtil(grid, r, c);
                    
                }
                
            }
        }
        return result;
        
    }
};
