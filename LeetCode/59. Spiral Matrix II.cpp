/*

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>  result(n, vector<int>(n));
        
        
        int RowStart  = 0, RowEnd = n-1;
        int ColoumStart  = 0, ColoumEnd = n-1;
        
        int count = 1;
        
        while(RowStart <= RowEnd  &&  ColoumStart <=  ColoumEnd){
            
            //left to right
            for(int i = ColoumStart; i<=ColoumEnd; i++)
            result[RowStart][i]=  count++;
            
            RowStart++;
            
            //top to bottom
            for(int i = RowStart; i<=RowEnd; i++)
            result[i][ColoumEnd] = count++;
            
            ColoumEnd--;
            
            //right to left
            for(int i = ColoumEnd; i>=ColoumStart; i--)
            if(RowStart <= RowEnd) result[RowEnd][i] = count++;
            
            
            RowEnd--;
            
            //bottom to top
            for(int i = RowEnd; i>= RowStart  ; i--)
            if(ColoumStart <= ColoumEnd) result[i][ColoumStart] = count++;
            
            ColoumStart++;
            
            
            
            
        }
        
        return result;
            
        
        
        
    }
};
