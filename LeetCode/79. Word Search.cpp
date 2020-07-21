/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
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
    
    bool dfs(int r, int c, vector<vector<char>>& board, string word, int index){
        
        if(index >= word.size() ){
            return true;
        }
        
        if(r < 0 || r > board.size()-1 ||
           c < 0 || c > board[0].size()-1 || 
           (word[index] != board[r][c])){
            
            return false;
        }
        
        board[r][c] = '#';
        
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        
        for(int i = 0; i < 4; i++){
            if(dfs(r+dr[i], c+dc[i], board, word, index+1)){
                return true;
            }
        }
        
        board[r][c] = word[index];
        return false;
    }
};
