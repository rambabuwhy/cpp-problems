/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> dp(numRows);

        for (int i = 0; i < numRows; i++) {
            dp[i] = vector<int>(i + 1);
            dp[i][0] = dp[i][i] = 1;
  
            for (int j = 1; j < i; j++)
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
        }
        
        return dp;
    
        
    }
};
