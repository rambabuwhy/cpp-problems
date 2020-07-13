/*

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int R = grid.size();
        int C = grid[0].size();
        int up = 0, down =0, left =0, right =0;
        int result = 0;
        
        for(int r = 0; r<R; r++){
            for(int c = 0; c<C; c++){
                
                if(grid[r][c] == 1){
                
                    //top 
                    if(r == 0) up = 0 ;
                    else up = grid[r-1][c];

                    //left
                    if(c == 0) left = 0;
                    else left = grid[r][c-1];

                    //right

                    if(c == C-1)  right = 0;
                    else right = grid[r][c+1];

                    //down
                    if(r == R-1) down = 0;
                    else down = grid[r+1][c];

                    result = result + ( 4 - (up+down+left+right));
                }
                
                
            }
        }
        
        return result;
        
    }
};
