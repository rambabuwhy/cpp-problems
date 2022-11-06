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

    void dfs(vector<vector<char>>& grid, int r, int c){

        if(grid[r][c] == '0') return;
        grid[r][c] = '0';

        if(r>0)  dfs(grid, r-1,c);
        if(c>0)  dfs(grid, r,c-1);
        if(r<grid.size()-1)  dfs(grid, r+1,c);
        if(c<grid[0].size()-1) dfs(grid, r,c+1);
    }
    int numIslands(vector<vector<char>>& grid) {

        int count=0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){

                if (grid[i][j] == '1'){
                    dfs(grid, i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
