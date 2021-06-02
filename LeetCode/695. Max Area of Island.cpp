/*
You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

The area of an island is the number of cells with a value 1 in the island.

Return the maximum area of an island in grid. If there is no island, return 0.

 

Example 1:


Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: The answer is not 11, because the island must be connected 4-directionally.
Example 2:

Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0

*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int result = 0;
        vector<vector<bool>> visit(grid.size(),vector<bool>(grid[0].size(),false));
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] == 1){
                    int currArea = dfs(grid, visit, r, c);
                    result = max(result, currArea);
                }
            }
        }
        return result;
    }
    
    int dfs (vector<vector<int>>& grid, vector<vector<bool>>  &visit, int r, int c){
        
        //sanity
        if( r < 0 || r >= grid.size() 
           || c < 0 || c >= grid[0].size() 
           || visit[r][c]==true || grid[r][c] != 1){
            return 0;
        }
        
        //mark as visited
        visit[r][c] = true;
        grid[r][c] = 0;
        
        //4 directions
        return 1 +  
            dfs(grid, visit, r, c+1) 
            +  dfs(grid, visit, r, c-1)
            +  dfs(grid, visit, r-1, c) 
            +  dfs(grid, visit, r+1, c); 
    }
};
