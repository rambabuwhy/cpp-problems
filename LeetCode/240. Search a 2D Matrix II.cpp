/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int r = matrix.size()-1;
        int c = 0;
        
        while(c<matrix[0].size() && r >=0){
            
            if(matrix[r][c] > target){
                r--;
            }
            else if(matrix[r][c] < target){
                c++;
            }
            else{
                return true;
            }
            
        }
        
        return false;
        
    }
};
