/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.

*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> copy(board);
        
              
        vector<int> dir = {0,1,-1};
        
        for(int row = 0; row < board.size(); row++){
            for(int col = 0; col < board[0].size(); col++){
                
                
                //four directions
                int liveNeighbors =0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        
                        //if it is 1
                        if(! (dir[i] == 0 && dir[j] == 0)) {
                            int dr = row + dir[i];
                            int dc = col + dir[j];
                            
                            
                            if(     (dr < board.size() && dr >= 0) && 
                                    (dc < board[0].size() && dc >=0) && 
                                    (copy[dr][dc] == 1 )) {
                                                              
                                liveNeighbors ++;
                            }
                                
                        }
                        
                    }
                }
                
                //rule 1 or 3
                if(copy[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)){
                    board[row][col]=0;
                }
                
                //rule 4
                if(copy[row][col] == 0 && liveNeighbors == 3){
                    board[row][col] = 1;
                }
                
            }
        }
        
    }
};
