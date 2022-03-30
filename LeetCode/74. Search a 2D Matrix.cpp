/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
 

Example 1:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:


Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
*/

class Solution {
public:
    //he input matrix m x n could be considered as a sorted array of length m x n.
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(matrix.size() == 0) return false;
        
        int M = matrix.size();
        int N = matrix[0].size();
        int left=0, right=(M*N)-1;
        while( left <= right ) {
            
            int mid = left + ( right - left) /2;
            int row_index = mid/N;
            int col_index = mid%N;
            int element = matrix[row_index][col_index];   //row =  m/N  ;  coloumn = m%N;
            
            if( element == target ) return true;            
            else if( element < target) left = mid + 1;
            else right = mid - 1;
        }
        return false;        
    }
};
