/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.
*/
class Solution {
public:
    
    //dfs for border candidates 
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (board[i][j] == 'O') {
            board[i][j] = 'A';
            if (i > 1) dfs(board, i - 1, j);
            if (j > 1) dfs(board, i, j - 1);
            if (i + 1 < board.size()) dfs(board, i + 1, j);
            if (j + 1 < board[0].size()) dfs(board, i, j + 1);
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int row = board.size();
        int col = board[0].size();
        
        //first coloumn and last coloumn
        for (int i = 0; i < row; ++i) {
            dfs(board, i, 0);             
            dfs(board, i, col - 1);      
        }
        
        //first row and last row
        for (int j = 1; j < col - 1; ++j) {
            dfs(board, 0, j);             
            dfs(board, row - 1, j);       
        }
        
        //verify remaining 
        for (int i = 0; i < row; ++i){
            for (int j = 0; j < col; ++j){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                } 
                else if (board[i][j] == 'A') {
                        board[i][j] = 'O';
                }
            }
        }
        
    }
};
