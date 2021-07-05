/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int r =0 ; r < board.size(); r++){
            for(int c=0; c < board[0].size(); c++ ){
                if(dfs(r,c,board,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    vector<vector<int>> dir = {{0,-1},{-1,0},{0,1},{1,0}};
    
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int index){
        
        if(index >= word.size()) return true;
        
        if(r < 0 || r > board.size()-1 || c < 0 || c > board[0].size()-1 || (word[index] != board[r][c])) {
            return false;
        }
        
        //to eliminate loop in current word. we need to replace the letter later for other word
        board[r][c] = '#';
        for(int i = 0; i < 4; i++) {  
            if(dfs(r+dir[i][0], c+dir[i][1], board, word, index+1)) return true; 
        }
        
        board[r][c] = word[index];
        return false;
    }
};
