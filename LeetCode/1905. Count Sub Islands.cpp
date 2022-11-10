/*
You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.

 

Example 1:


Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.
Example 2:


Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

*/


class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        //if you find extra 1 in grid2 make all 0's in that island
        //if 1 in grid2 and 0 in grid1  then make all 0's in grid2; these are not subset
        for(int r=0; r<grid1.size(); r++){
            for(int c=0; c<grid1[0].size(); c++){
                if(grid2[r][c]==1 && grid1[r][c]==0){
                    dfs(grid1,grid2,r,c);
                }
            }
        }

        //remaing 1's in grid2 are sub islands,  just count it
        int result=0;
        for(int r=0; r<grid1.size(); r++){
            for(int c=0; c<grid1[0].size(); c++){
                if(grid2[r][c]==1){
                    result++;
                    dfs(grid1,grid2,r,c);
                }
            }
        }

        return result;
        
    }

    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int r, int c){

        if(r<0 || c<0 || r>grid2.size()-1 || c>grid2[0].size()-1 || grid2[r][c]==0){
            return;
        }
        grid2[r][c]=0;

        dfs(grid1,grid2,r-1,c);
        dfs(grid1,grid2,r,c-1);
        dfs(grid1,grid2,r+1,c);
        dfs(grid1,grid2,r,c+1);
    }
};
