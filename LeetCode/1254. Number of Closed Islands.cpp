/*
Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.

 

Example 1:



Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
Output: 2
Explanation: 
Islands in gray are closed because they are completely surrounded by water (group of 1s).
Example 2:



Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
Output: 1
Example 3:

Input: grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
Output: 2
 
 
 */
 
 class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {

        //ignore edgeside  0's, which could not make any closed island
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(r==0 || c==0 || r==grid.size()-1 || c ==grid[0].size()-1){
                        dfs(grid,r,c);
                }
            }
        }

        //now work on remaining 0's
        //this is same as number of diconnectged graph
        int result=0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c] == 0){
                    result++;
                    dfs(grid,r,c);
                }
                
            }
        }
        return result;
    }

    void dfs(vector<vector<int>>& grid, int r, int c){

        if(r<0 || c<0 || r>grid.size()-1 || c>grid[0].size()-1 || grid[r][c]==1) return ;

        grid[r][c]=1;

        dfs(grid,r-1,c);
        dfs(grid,r,c-1);
        dfs(grid,r+1,c);
        dfs(grid,r,c+1);
    }
};
