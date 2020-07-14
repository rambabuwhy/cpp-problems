/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

 

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int R = dungeon.size();
        int C = dungeon[0].size();

        vector<vector<int> > dp(R + 1, vector<int>(C + 1, INT_MAX));
        dp[R][C - 1] = 1;
        dp[R - 1][C] = 1;
        for (int i = R - 1; i >= 0; i--) {
            for (int j = C - 1; j >= 0; j--) {
                int Min = min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                dp[i][j] = Min <= 0 ? 1 : Min;
            }
        }
        return dp[0][0];  
    }
};
