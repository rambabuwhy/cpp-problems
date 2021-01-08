/*
Given a square matrix mat, return the sum of the matrix diagonals.

Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

Example 1:


Input: mat = [[1,2,3],
              [4,5,6],
              [7,8,9]]
Output: 25
Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
Notice that element mat[1][1] = 5 is counted only once.
Example 2:

Input: mat = [[1,1,1,1],
              [1,1,1,1],
              [1,1,1,1],
              [1,1,1,1]]
Output: 8
Example 3:

Input: mat = [[5]]
Output: 5

*/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        
        int result = 0;
        
        //(i,i)  
        for(int i = 0; i< mat.size(); i++)
        result = result + mat[i][i];
        
        //(i, n-i-1);
        for(int i =0; i<mat.size(); i++)
        result = result + mat[i][mat.size()-i-1];
        
        //if add size matrix: remove double addition of center element
        if(mat.size() %2 != 0)
        result = result - mat[mat.size()/2][mat.size()/2];
       
        return result;
        
    }
};
