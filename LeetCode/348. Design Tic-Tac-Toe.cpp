/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.

*/

class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        total = n;
        R.resize(n);
        C.resize(n);
        ld = 0;
        rd = 0;
        
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        
        int add = 0;
        if(player == 1) add = 1;
        if(player == 2) add = -1;
        
        if(row == col) ld = ld + add;
        if(row == total -col -1) rd = rd + add;
        
        R[row] = R[row] + add;
        C[col] = C[col] + add;
        
        if( abs(R[row]) == total ||
            abs(C[col]) == total ||
            abs(ld) == total ||
            abs(rd) == total     ) {
            
            return player;
        }
        
        return 0;
        
        
        
    }
    
private:
    vector<int> R;
    vector<int> C;
    int ld,rd,total;
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
