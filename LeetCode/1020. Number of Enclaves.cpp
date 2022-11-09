/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 
 
 */


class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {

        //fill 0 in every 1 of edge, but dont count
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if( r==0 || c==0 || r==grid.size()-1 || c == grid[0].size()-1 ){
                    if (grid[r][c] !=0 ) {
                        dfs(grid,r,c);
                    }
                }
                
            }
        }

        //count remaining 1's
        int result=0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if( grid[r][c] !=0){
                    result=result + dfs(grid,r,c);
                }
                
            }
        }
        return result;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r<0 || c<0 || r>grid.size()-1|| c>grid[0].size()-1 || grid[r][c] == 0){
            return 0;
        }

        grid[r][c]=0;
        return 1+dfs(grid,r-1,c)+ dfs(grid,r,c-1) + dfs(grid,r+1,c) +  dfs(grid,r,c+1);
    }
};
