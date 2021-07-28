/*

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

Example 1:


Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
Example 2:

Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int rowsize = board.size();
        int colsize = board[0].size();
        
        vector<vector<int>> row(rowsize, vector<int>(rowsize, 0));
        vector<vector<int>> col(colsize, vector<int>(colsize, 0));
        vector<vector<int>> box(rowsize, vector<int>(rowsize, 0));
        
        for(int i=0; i<rowsize; i++){
            for(int j=0; j<colsize; j++){
                
                if(board[i][j] == '.') continue;
                
                //get number in box and use it as index. 
                //set 1 to its index  for its row, col and box.
                //if already 1 exist then return false
                // -'0' to get int and -1 to adjust to 0th index
                int num = board[i][j]-'0'-1;
                
                //get box index:  i/3 * 3 ->  row + j/3 coloum
                int k = (i/3)*3 + (j/3);
                
                //verify if already exist => 1: exist  0: does not exist
                if(row[i][num] || col[j][num] || box[k][num]) { 
                    return false;
                }
                
                //fill 1 :  insert ith row num col  as 1 
                row[i][num] = 1;
                col[j][num] = 1;
                box[k][num] = 1;  
            }
        }
        return true;
    }
};
