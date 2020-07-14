/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
*/
class Solution {
public:
    int numSquares(int n) {
        
        if (n <= 0) return 0;
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j*j <= i; j++)
            {
                dp[i] = min(dp[i], dp[i - j*j] + 1);
            }
        }
        
        return dp[n];        
    }
};
