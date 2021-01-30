/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 

Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        unordered_set<int> rows;
        unordered_set<int> cols;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j =0; j<matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(int i =0; i< matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                
                if(rows.find(i) != rows.end() || cols.find(j) !=  cols.end() ){
                    matrix[i][j] = 0;
                    
                }
                
            }
        }
        
        
    }
};
