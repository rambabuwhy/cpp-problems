/*

Given an m x n integers matrix, return the length of the longest increasing path in matrix.

From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

Example 1:


Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:


Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
Example 3:

Input: matrix = [[1]]
Output: 1

*/

class Solution {
public:
    
    vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int result = 0;
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size()));
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                int curr_max = util(matrix, cache,i,j);
                result = max(result, curr_max);
            }
        }
                             
        return result;
    }
    
    int util(vector<vector<int>>& matrix, vector<vector<int>> &cache, int i, int j){
        
        if(cache[i][j] != 0 ) {
            return cache[i][j];
        }
        
        for( auto d:dir){
            
            int x = i + d[0];
            int y = j + d[1];
            
            
            if(x >=0 && x < matrix.size() && y>=0 && y < matrix[0].size()) {
                
                if(matrix[x][y] > matrix[i][j]) {
                    cache[i][j] = max (cache[i][j], util(matrix, cache, x, y));
                }
            }
            
        }
                                  
        return ++cache[i][j];
    }
};
